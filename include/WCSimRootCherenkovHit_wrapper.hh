#ifndef WCSim_RootCherenkovHit_wrapper
#define WCSim_RootCherenkovHit_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCherenkovHit_wrapper                                    //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootCherenkovHit_v0.hh"

class WCSimRootCherenkovHit_wrapper {

protected:
  WCSimRootCherenkovHit_v0* hit=nullptr;

public:
  WCSimRootCherenkovHit_wrapper(WCSimRootCherenkovHit_v0* hitin) : hit(hitin) {}
//  WCSimRootCherenkovHit_wrapper(){};

  inline Int_t GetTubeID()       const { return hit->GetTubeID();}
  inline Int_t GetTotalPe(int i) const { return hit->GetTotalPe(i);}

  inline Int_t GetVersion()         const { return hit->GetVersion(); }
  inline UInt_t GetCheckSum()        const { return hit->GetCheckSum(); }
  inline const WCSimRootCherenkovHit_v0* GetPtr() const { return hit; }
};

#endif
