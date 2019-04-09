#ifndef WCSim_RootCaptureGamma_wrapper
#define WCSim_RootCaptureGamma_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCaptureGamma_wrapper                                    //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootCaptureGamma_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootCaptureGamma_wrapper {

private:
  WCSimRootCaptureGamma_v0* capturegamma=nullptr;

public:
  WCSimRootCaptureGamma_wrapper(WCSimRootCaptureGamma_v0* capturegammain) : capturegamma(capturegammain){};
//  WCSimRootCaptureGamma_wrapper(){};

  inline Int_t    GetID()           const { return capturegamma->GetID();}
  inline Float_t  GetE()            const { return capturegamma->GetE();}
  inline Float_t  GetDir(int i)     const { return capturegamma->GetDir(i);}

  inline int      GetCheckSum()     const { return capturegamma->GetCheckSum();}
  inline int      GetVersion()      const { return capturegamma->GetVersion();}
  inline const WCSimRootCaptureGamma_v0* GetPtr() const { return capturegamma; }

};

//////////////////////////////////////////////////////////////////////////

#endif


