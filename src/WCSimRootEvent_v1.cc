// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootEvent_v1.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootEvent_v1)
#endif

UInt_t WCSimRootEvent_v1::GetCheckSum(){ return 4147785461; }

//_____________________________________________________________________________

void WCSimRootEvent_v1::Initialize()
{
  fEventList = new TObjArray_wrapper(10,0); // very rarely more than 10 subevents...
  fEventList->AddAt(new WCSimRootTrigger_v1(0,0),0);
  Current = 0;
}
