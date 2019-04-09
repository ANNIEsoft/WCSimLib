#ifndef WCSim_RootCaptureGamma_v0
#define WCSim_RootCaptureGamma_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCaptureGamma_v0                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"

//////////////////////////////////////////////////////////////////////////

class WCSimRootCaptureGamma_v0 : public TObject {

protected:
  Int_t   fID;
  Float_t fEnergy;
  Float_t fDir[3];

public:
  WCSimRootCaptureGamma_v0() {}
  WCSimRootCaptureGamma_v0(Int_t id,
                        Float_t energy,
                        Float_t dir[3]
  );

  virtual ~WCSimRootCaptureGamma_v0() {}

  virtual Int_t    GetID()           const { return fID;}
  virtual Float_t  GetE()            const { return fEnergy;}
  virtual Float_t  GetDir(int i)     const { return (i<3) ? fDir[i]: 0;}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootCaptureGamma_v0,1)
};

//////////////////////////////////////////////////////////////////////////

#endif
