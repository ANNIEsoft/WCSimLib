// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "TObjArray_wrapper.hh"
#include "TClassRef.h"
#include "WCSimRootTrigger_wrapper.hh"
#include "TStreamerInfo.h"
#include "TFile.h"
#include <iostream>

#ifndef REFLEX_DICTIONARY
ClassImp(TObjArray_wrapper)
#endif

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

