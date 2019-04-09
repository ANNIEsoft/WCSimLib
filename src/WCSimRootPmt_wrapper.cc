#include "WCSimRootPmt_wrapper.hh"

  /////////////////////
  // Version 1
  void WCSimRootPMT_wrapper::SetType(std::string PmtType) {
    WCSimRootPMT_v1* thepmt1 = dynamic_cast<WCSimRootPMT_v1*>(thepmt);
    if(thepmt1){
      thepmt1->SetType(PmtType);
    }
    else { fPmtTypeName=PmtType; }
  }
  
  const char * WCSimRootPMT_wrapper::GetName() const {
    WCSimRootPMT_v1* thepmt1 = dynamic_cast<WCSimRootPMT_v1*>(thepmt);
    if(thepmt1){
      return thepmt1->GetName();
    }
    else { return fPmtTypeName.c_str(); }  // TODO could we fill this in from the parent?
  }
