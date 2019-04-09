#ifndef WCSim_RootCherenkovDigiHit_v0
#define WCSim_RootCherenkovDigiHit_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCherenkovDigiHit_v0                                     //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"

//////////////////////////////////////////////////////////////////////////

class WCSimRootCherenkovDigiHit_v0 : public TObject {

protected:
  // See jhfNtuple.h for the meaning of these data members:
  Float_t fQ;
  Float_t fT;
  Int_t fTubeId;
  std::vector<int> fPhotonIds;

public:
  WCSimRootCherenkovDigiHit_v0() {}
  WCSimRootCherenkovDigiHit_v0(Float_t q, Float_t t, Int_t tubeid, std::vector<int> photon_ids);

  virtual ~WCSimRootCherenkovDigiHit_v0() { }

  virtual Float_t     GetQ() const { return fQ;}
  virtual Float_t     GetT() const { return fT;}
  virtual Int_t       GetTubeId() const { return fTubeId;}
  virtual std::vector<int> GetPhotonIds() const { return fPhotonIds; }

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootCherenkovDigiHit_v0,2)  
};

#endif
