#ifndef WCSim_RootPmt_v0
#define WCSim_RootPmt_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootPmt_v0                                                        
//                                                                      
// This class contains information needed to be passed to reconstruction
//     routines.  It's just simple right now-- only the bare-bones  
//     WC info
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"

class WCSimRootPMT_v0 : public TObject {

protected:
  Int_t fTubeNo;
  //Int_t fLAPPDNo;
  Int_t fCylLoc;  // endcap1, wall, endcap2
  Float_t fOrientation[3];
  Float_t fPosition[3];

public:
  WCSimRootPMT_v0(){};
  WCSimRootPMT_v0(Int_t tubeNo, Int_t cylLoc, Float_t orientation[3], Float_t position[3]);
  virtual ~WCSimRootPMT_v0(){};

  virtual void  SetTubeNo(Int_t i) {fTubeNo=i;}
  //void  SetLAPPDNo(Int_t i) {fTubeNo=i;}
  virtual void  SetCylLoc(Int_t i) {fCylLoc=i;}
  virtual void  SetOrientation(Int_t i, Float_t f) {fOrientation[i]= ( (i<3) ? f : 0);}
  virtual void  SetPosition(Int_t i, Float_t f) {fPosition[i]= ( (i<3) ? f : 0);}

  virtual Int_t GetTubeNo() const {return fTubeNo;}
  //Int_t GetLAPPDNo() const {return fLAPPDNo;}
  virtual Int_t GetCylLoc() const {return fCylLoc;}
  virtual Float_t GetOrientation(Int_t i=0) const {return (i<3) ? fOrientation[i] : 0;}
  virtual Float_t GetPosition(Int_t i=0) const {return (i<3) ? fPosition[i] : 0;}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootPMT_v0,1)  //WCSimPMT structure
};


//////////////////////////////////////////////////////////////////////////

#endif
