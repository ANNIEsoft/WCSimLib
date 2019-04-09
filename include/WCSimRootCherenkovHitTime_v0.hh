#ifndef WCSim_RootCherenkovHitTime_v0
#define WCSim_RootCherenkovHitTime_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCherenkovHitTime_v0                                     //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"

class WCSimRootCherenkovHitTime_v0 : public TObject {

protected:
  // See jhfNtuple.h for the meaning of these data members:
  Float_t fTruetime;
  Int_t   fPrimaryParentID;

public:
  WCSimRootCherenkovHitTime_v0() {}
  WCSimRootCherenkovHitTime_v0(Float_t truetime,
			    Int_t   primaryParentID);
  virtual ~WCSimRootCherenkovHitTime_v0() { }

  virtual Float_t   GetTruetime() { return fTruetime;}
  virtual Int_t     GetParentID() { return fPrimaryParentID;}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootCherenkovHitTime_v0,1)  
};

#endif
