#include "WCSimRootTrack_wrapper.hh"

  /////////////////////
  // Version 1
  Float_t   WCSimRootTrack_wrapper::GetEndE() const {
    WCSimRootTrack_v1* thetrack1 = dynamic_cast<WCSimRootTrack_v1*>(thetrack);
    if(thetrack1){
      return thetrack1->GetEndE();
    }
    else { return -1000.;}
  }
  
  Float_t   WCSimRootTrack_wrapper::GetEndP() const {
    WCSimRootTrack_v1* thetrack1 = dynamic_cast<WCSimRootTrack_v1*>(thetrack);
    if(thetrack1){
      return thetrack1->GetEndP();
    }
    else { return -1000.; }
  }
  
  Float_t   WCSimRootTrack_wrapper::GetPdirEnd(Int_t i) {
    if(thetrack->GetVersion()>0){
      WCSimRootTrack_v1* thetrack1 = dynamic_cast<WCSimRootTrack_v1*>(thetrack);
      return thetrack1->GetPdirEnd(i);
    }
    else { return -1000.; }
  }
  
  Float_t   WCSimRootTrack_wrapper::GetStopTime() {
    WCSimRootTrack_v1* thetrack1 = dynamic_cast<WCSimRootTrack_v1*>(thetrack);
    if(thetrack1){
      return thetrack1->GetStopTime();
    }
    else { return -1000.; }
  }
  
  /////////////////////
  // Version 2
  std::string WCSimRootTrack_wrapper::GetStartProcess(){
    WCSimRootTrack_v2* thetrack2 = dynamic_cast<WCSimRootTrack_v2*>(thetrack);
    if(thetrack2){
      return thetrack2->GetStartProcess();
    }
    else { return "unknown"; }
  }
  
  std::string WCSimRootTrack_wrapper::GetEndProcess(){
    WCSimRootTrack_v2* thetrack2 = dynamic_cast<WCSimRootTrack_v2*>(thetrack);
    if(thetrack2){
      return thetrack2->GetEndProcess();
    }
    else { return "unknown"; }
  }
  
  void WCSimRootTrack_wrapper::Clear(Option_t *option){
    WCSimRootTrack_v2* thetrack2 = dynamic_cast<WCSimRootTrack_v2*>(thetrack);
    if(thetrack2){
      return thetrack2->Clear(option);
    }
    else { thetrack->Delete(); }
  }
  /////////////////////
