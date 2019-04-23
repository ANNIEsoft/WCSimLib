#ifndef WCSim_RootCherenkovDigiHit_wrapper
#define WCSim_RootCherenkovDigiHit_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCherenkovDigiHit_wrapper                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootCherenkovDigiHit_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootCherenkovDigiHit_wrapper {

protected:
  WCSimRootCherenkovDigiHit_v0* digi=nullptr;

public:
  WCSimRootCherenkovDigiHit_wrapper(WCSimRootCherenkovDigiHit_v0* digiin) : digi(digiin){};
//  WCSimRootCherenkovDigiHit_wrapper(){};

  inline Float_t     GetQ() const { return digi->GetQ();}
  inline Float_t     GetT() const { return digi->GetT();}
  inline Int_t       GetTubeId() const { return digi->GetTubeId();}
  inline std::vector<int> GetPhotonIds() const { return digi->GetPhotonIds(); }

  inline Int_t GetVersion()         const { return digi->GetVersion(); }
  inline UInt_t GetCheckSum()        const { return digi->GetCheckSum(); }
  inline const WCSimRootCherenkovDigiHit_v0* GetPtr() const { return digi; }
};

#endif
