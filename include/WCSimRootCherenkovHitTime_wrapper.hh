#ifndef WCSim_RootCherenkovHitTime_wrapper
#define WCSim_RootCherenkovHitTime_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCherenkovHitTime_wrapper                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootCherenkovHitTime_v0.hh"

class WCSimRootCherenkovHitTime_wrapper {

protected:
  WCSimRootCherenkovHitTime_v0* hittime=nullptr;

public:
  WCSimRootCherenkovHitTime_wrapper(WCSimRootCherenkovHitTime_v0* hittimein) : hittime(hittimein){};
//  WCSimRootCherenkovHitTime_wrapper(){};
  
  inline Float_t   GetTruetime() { return hittime->GetTruetime();}
  inline Int_t     GetParentID() { return hittime->GetParentID();}

  inline Int_t GetVersion()         const { return hittime->GetVersion(); }
  inline Int_t GetCheckSum()        const { return hittime->GetCheckSum(); }
  inline const WCSimRootCherenkovHitTime_v0* GetPtr() const { return hittime; }
};

#endif
