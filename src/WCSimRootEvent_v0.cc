// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootEvent_v0.hh"

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

