// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootEvent_v2.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootEvent_v2)
#endif

UInt_t WCSimRootEvent_v2::GetCheckSum(){ return 4147785461; }

//_____________________________________________________________________________

void WCSimRootEvent_v2::Initialize()
{
  fEventList = new TObjArray(10,0); // very rarely more than 10 subevents...
  fEventList->AddAt(new WCSimRootTrigger_v2(0,0),0);
  Current = 0;
}

void WCSimRootEvent_v2::Print(int verbosity, int maxtriggerstoprint, int maxprimariestoprint, int maxtrackstoprint, int maxdigitstoprint, int maxphotonsperdigittoprint, int maxphotonstoprint){
  int numtriggers = fEventList->GetEntriesFast();
  std::cout<<"This entry had "<<numtriggers<<" triggers"<<std::endl;
  for(int trigi=0; trigi<std::min(maxtriggerstoprint,numtriggers); trigi++){
    WCSimRootTrigger_v2* nexttrigger = this->GetTrigger(trigi);
    nexttrigger->Print(verbosity, maxprimariestoprint, maxtrackstoprint, maxdigitstoprint, maxphotonsperdigittoprint, maxphotonstoprint);
  }
}
