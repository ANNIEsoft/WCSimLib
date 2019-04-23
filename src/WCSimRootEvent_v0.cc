// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootEvent_v0.hh"
// for TObjArray_wrapper
#include "WCSimRootTrigger_wrapper.hh"
#include "TStreamerInfo.h"
#include "TFile.h"
#include <iostream>

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootEvent_v0)
#endif

UInt_t WCSimRootEvent_v0::GetCheckSum(){ return 4147785461; }

//_____________________________________________________________________________

WCSimRootEvent_v0::WCSimRootEvent_v0()
{
  // default constructor : nothing happens
  //fEventList.push_back(new WCSimRootTrigger() ); //at least one event 
  // this is standard root practise for streaming ROOT objtecs : if memory is alloc'ed here,
  // it will be lost
  fEventList = 0;
  Current = 0;
}

void WCSimRootEvent_v0::Initialize()
{
  fEventList = new TObjArray_wrapper(10,0); // very rarely more than 10 subevents...
  fEventList->AddAt(new WCSimRootTrigger_v0(0,0),0);
  Current = 0;
}


WCSimRootEvent_v0::~WCSimRootEvent_v0()
{
  if (fEventList != 0) {
    for (int i = 0 ; i < fEventList->GetEntriesFast() ; i++) {
      delete (*fEventList)[i];
    }
    delete fEventList;
  }
  //  std::vector<WCSimRootTrigger_v0*>::iterator  iter = fEventList.begin();
  //for ( ; iter != fEventList.end() ; ++iter) delete (*iter);
  //Clear("");
}

void WCSimRootEvent_v0::Clear(Option_t* /*o*/)
{
  //nothing for now
}

void WCSimRootEvent_v0::Reset(Option_t* /*o*/)
{
  //nothing for now
}

//void WCSimRootEvent_v0::TObjArray_wrapper::Streamer(TBuffer &b)
void TObjArray_wrapper::Streamer(TBuffer &b)
{
   std::cout<<"EXECUTING TObjArray_wrapper STREAMER"<<std::endl;
   UInt_t R__s, R__c;
   Int_t nobjects;
   if (b.IsReading()) {
      Version_t v = b.ReadVersion(&R__s, &R__c);
      if (v > 2)
         TObject::Streamer(b);
      if (v > 1)
         fName.Streamer(b);

      if (GetEntriesFast() > 0) Clear();

      // figure out what's going to be in the file
      static TClassRef trigclassref;
      if(strcmp(trigclassref.GetClassName(),"")==0){
        TFile* thefile = dynamic_cast<TFile*>(b.GetParent());
        TStreamerInfo* sis=(TStreamerInfo*)thefile->GetStreamerInfoCache()->FindObject("WCSimRootTrigger");
        if(sis){
          UInt_t thecheck = sis->GetCheckSum();
          // now find out what version of WCSimRootTrigger this is and make the appropriate type
          if(thecheck==WCSimRootTrigger_v0::GetCheckSum()){
            trigclassref = TClassRef("WCSimRootTrigger_v0");
          } else if(thecheck==WCSimRootTrigger_v1::GetCheckSum()){
            trigclassref = TClassRef("WCSimRootTrigger_v1");
          } else if(thecheck==WCSimRootTrigger_v2::GetCheckSum()){
            trigclassref = TClassRef("WCSimRootTrigger_v0");
          } else {
            std::cerr<<"TObjArray_wrapper Error: Could not find WCSimRootTrigger version with checksum matching on-file class "<<thecheck<<std::endl;
            trigclassref = TClassRef("TObject");
          }
        } else {
          std::cerr<<"TObjArray_wrapper Error: Could not find WCSimRootTrigger in file "
                   <<thefile->GetName()<<std::endl;
          trigclassref = TClassRef("TObject");
        }
      }

      b >> nobjects;
      b >> fLowerBound;
      if (nobjects >= fSize) Expand(nobjects);
      fLast = -1;
      TObject *obj;
      for (Int_t i = 0; i < nobjects; i++) {
         obj = (TObject*) b.ReadObjectAny(trigclassref);   // override 'b.ReadObjectAny(TObject::Class());'
         if (obj) {
            fCont[i] = obj;
            fLast = i;
         }
      }
      Changed();
      b.CheckByteCount(R__s, R__c,TObjArray::IsA());
   } else {
      R__c = b.WriteVersion(TObjArray::IsA(), kTRUE);
      TObject::Streamer(b);
      fName.Streamer(b);
      nobjects = GetAbsLast()+1;
      b << nobjects;
      b << fLowerBound;

      for (Int_t i = 0; i < nobjects; i++) {
         b << fCont[i];
      }
      b.SetByteCount(R__c, kTRUE);
   }
}

