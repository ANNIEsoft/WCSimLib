#include "WCSimRootTrigger_wrapper.hh"

  ///////////////////////
  // Version 2  (nothing different in Version 1 but return types)
  void WCSimRootTrigger_wrapper::Print(int verbosity, int maxprimariestoprint, int maxtrackstoprint, int maxdigitstoprint, int maxphotonsperdigittoprint, int maxphotonstoprint){
    WCSimRootTrigger_v2* trig2 = dynamic_cast<WCSimRootTrigger_v2*>(trig);
    if(trig2){
      trig2->Print(verbosity, maxprimariestoprint, maxtrackstoprint, maxdigitstoprint, maxphotonsperdigittoprint, maxphotonstoprint);
    }
    else {
      /* XXX TODO DEFINE PRINT FUNCTION HERE XXX */
      std::cout<<"Print function to be implemented."<<std::endl;
    }
  };
  
  void WCSimRootTrigger_wrapper::SetCaptureParticle(Int_t parent,
                                                    Int_t ipnu,
                                                    Float_t time,
                                                    Float_t vtx[3],
                                                    Float_t dir[3],
                                                    Float_t energy,
                                                    Int_t id){
    WCSimRootTrigger_v2* trig2 = dynamic_cast<WCSimRootTrigger_v2*>(trig);
    if(trig2){
      trig2->SetCaptureParticle(parent, ipnu, time, vtx, dir, energy, id);
    }
    else { assert("not supported in this version of WCSim class."&&false); }
  }
  
  void WCSimRootTrigger_wrapper::SetParentEvent(WCSimRootEvent_v2* parenteventin){
    WCSimRootTrigger_v2* trig2 = dynamic_cast<WCSimRootTrigger_v2*>(trig);
    if(trig2){
      trig2->SetParentEvent(parenteventin);
    }
    else { fParentEvent = parenteventin; }
  }

  WCSimRootEvent_wrapper WCSimRootTrigger_wrapper::GetParentEvent() const {
    WCSimRootTrigger_v2* trig2 = dynamic_cast<WCSimRootTrigger_v2*>(trig);
    if(trig2){
      return WCSimRootEvent_wrapper(trig2->GetParentEvent());
    }
    else { return WCSimRootEvent_wrapper(fParentEvent); }
  }

  Int_t WCSimRootTrigger_wrapper::GetNcaptures() const {
    WCSimRootTrigger_v2* trig2 = dynamic_cast<WCSimRootTrigger_v2*>(trig);
    if(trig2){
      return trig2->GetNcaptures();
    }
    else { return fNcaptures; }
  }
  
  TClonesArray* WCSimRootTrigger_wrapper::GetCaptures() const {
    WCSimRootTrigger_v2* trig2 = dynamic_cast<WCSimRootTrigger_v2*>(trig);
    if(trig2){
      return trig2->GetCaptures();
    }
    else { return fCaptures;}
  }
