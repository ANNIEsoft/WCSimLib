#ifndef WCSim_RootPmt_wrapper
#define WCSim_RootPmt_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootPmt_wrapper                                                
//                                                                      
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootPmt_v0.hh"
#include "WCSimRootPmt_v1.hh"

class WCSimRootPMT_wrapper {

protected:
  WCSimRootPMT_v0* thepmt=nullptr;
  WCSimRootPMT_v0 theactualpmt;

public:
  WCSimRootPMT_wrapper(const WCSimRootPMT_v0* thepmtin) : theactualpmt(*thepmtin){
    thepmt = &theactualpmt;
  };
//  WCSimRootPMT_wrapper(){};

  inline void  SetTubeNo(Int_t i) {thepmt->SetTubeNo(i);}
  inline void  SetCylLoc(Int_t i) {thepmt->SetCylLoc(i);}
  inline void  SetOrientation(Int_t i, Float_t f) {thepmt->SetOrientation(i,f);}
  inline void  SetPosition(Int_t i, Float_t f) {thepmt->SetPosition(i,f);}

  inline Int_t GetTubeNo() const {return thepmt->GetTubeNo();}
  inline Int_t GetCylLoc() const {return thepmt->GetCylLoc();}
  inline Float_t GetOrientation(Int_t i=0) const { return thepmt->GetOrientation(i);}
  inline Float_t GetPosition(Int_t i=0) const {return thepmt->GetPosition(i);}
  
  /////////////////////
  // Version 1
  void SetType(std::string PmtType);
  const char * GetName() const;
  
  protected:
  std::string fPmtTypeName;
  /////////////////////

  public:
  inline Int_t GetVersion()         const { return thepmt->GetVersion(); }
  inline UInt_t GetCheckSum()        const { return thepmt->GetCheckSum(); }
  inline const WCSimRootPMT_v0* GetPtr() const { return thepmt; }
};


//////////////////////////////////////////////////////////////////////////

#endif
