#ifndef WCSim_RootCherenkovHit_v0
#define WCSim_RootCherenkovHit_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCherenkovHit_v0                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"

class WCSimRootCherenkovHit_v0 : public TObject {

protected:
  Int_t fTubeID;
  Int_t fTotalPe[2];

public:
  WCSimRootCherenkovHit_v0() {}
  WCSimRootCherenkovHit_v0(Int_t tubeID,
			Int_t totalPe[2]);

  virtual ~WCSimRootCherenkovHit_v0() { }

  virtual Int_t GetTubeID()       const { return fTubeID;}
  virtual Int_t GetTotalPe(int i) const { return (i<2) ? fTotalPe[i]: 0;}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootCherenkovHit_v0,1)  
};

#endif
