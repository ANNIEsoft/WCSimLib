#ifndef WCSim_RootPi0_wrapper
#define WCSim_RootPi0_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootPi0_wrapper                                             //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootPi0_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootPi0_wrapper {

protected:
  WCSimRootPi0_v0* pizero=nullptr;

public:
  WCSimRootPi0_wrapper(WCSimRootPi0_v0* pizeroin) : pizero(pizeroin) {}
//  WCSimRootPi0_wrapper(){};

  inline void Set(Float_t pi0Vtx[3],
	   Int_t   gammaID[2],
	   Float_t gammaE[2],
	   Float_t gammaVtx[2][3]){ pizero->Set(pi0Vtx, gammaID, gammaE, gammaVtx); }

  inline Float_t  GetPi0Vtx(int i)           const { return pizero->GetPi0Vtx(i); }
  inline Int_t    GetGammaID(int i)          const { return pizero->GetGammaID(i);}
  inline Float_t  GetGammaE(int i)           const { return pizero->GetGammaE(i);}
  inline Float_t  GetGammaVtx(int i, int j)  const { return pizero->GetGammaVtx(i,j);}

  inline Int_t GetVersion()         const { return pizero->GetVersion(); }
  inline Int_t GetCheckSum()        const { return pizero->GetCheckSum(); }
  inline const WCSimRootPi0_v0* GetPtr() const { return pizero; }
};

#endif
