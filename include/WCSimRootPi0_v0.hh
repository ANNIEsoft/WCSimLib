#ifndef WCSim_RootPi0_v0
#define WCSim_RootPi0_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootPi0_v0                                                  //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"

//////////////////////////////////////////////////////////////////////////

class WCSimRootPi0_v0 : public TObject {
  // this is a class used specifically for Pi0 events

protected:
  Float_t fPi0Vtx[3];
  Int_t   fGammaID[2];
  Float_t fGammaE[2];
  Float_t fGammaVtx[2][3];

public:
  WCSimRootPi0_v0() {}

  virtual ~WCSimRootPi0_v0() {}

  virtual void Set(Float_t pi0Vtx[3],
	   Int_t   gammaID[2],
	   Float_t gammaE[2],
	   Float_t gammaVtx[2][3]);

  virtual Float_t  GetPi0Vtx(int i)           const { return (i<3) ? fPi0Vtx[i]: 0;}
  virtual Int_t    GetGammaID(int i)          const { return (i<2) ? fGammaID[i]: 0;}
  virtual Float_t  GetGammaE(int i)           const { return (i<2) ? fGammaE[i]: 0;}
  virtual Float_t  GetGammaVtx(int i, int j)  const { return fGammaVtx[i][j];}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootPi0_v0,1)
};

#endif
