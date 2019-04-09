#ifndef WCSim_RootGeom_v0
#define WCSim_RootGeom_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootGeom_v0                                                    
//                                                                      
// This class contains information needed to be passed to reconstruction
//     routines.  It's just simple right now-- only the bare-bones  
//     WC info
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"
#include "WCSimRootPmt_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootGeom_v0 : public TObject {

protected:

  static const Int_t     maxNumPMT = 40000;
  static const Int_t     maxNumLAPPD = 100;
  Float_t                fWCCylRadius;  // Radius of WC tank
  Float_t                fWCCylLength;  // Length of WC tank
  
  Int_t                  fgeo_type;  // mailbox or cylinder?

  Float_t                fWCPMTRadius; // Radius of PMT
  Int_t                  fWCNumPMT;   // Number of PMTs
  Float_t                fWCLAPPDRadius; // Radius of LAPPD
  Int_t                  fWCNumLAPPD;   // Number of LAPPDs
  Float_t                fMRDPMTRadius; // Radius of MRD PMTs
  Int_t                  fWCNumMrdPMT;  // Number of MRD PMTs
  Float_t                fFACCPMTRadius; //Radius of FACC PMTs
  Int_t                  fWCNumFaccPMT;  // Number of FACC PMTs
  Float_t                fWCOffset[3]; // Offset of barrel center in global coords
  Int_t                  fOrientation; //Orientation o detector, 0 is 2km horizontal, 1 is Upright

  // Could make a TClonesArray of PMTs but let's keep it simple
  //   since the arrays just won't be that large
  //WCSimRootPMT_v0          fPMTArray[maxNumPMT];  // Array of PMTs
  TClonesArray           *fPMTArray;
  TClonesArray           *fLAPPDArray;
  TClonesArray           *fMRDPMTArray;
  TClonesArray           *fFACCPMTArray;

public:

  WCSimRootGeom_v0();
  virtual ~WCSimRootGeom_v0();

  // Sets and gets

  virtual void  SetWCCylRadius(Float_t f) {fWCCylRadius=f;}
  virtual void  SetWCCylLength(Float_t f) {fWCCylLength=f;}

  virtual void SetGeo_Type(Int_t f){fgeo_type = f;}

  virtual void  SetWCNumPMT(Int_t i) {fWCNumPMT= i;}
  virtual void  SetWCPMTRadius(Float_t f) {fWCPMTRadius = f;}
  virtual void  SetWCNumLAPPD(Int_t i) {fWCNumLAPPD= i;}
  virtual void  SetWCLAPPDRadius(Float_t f) {fWCLAPPDRadius = f;}
  virtual void  SetWCNumMrdPMT(Int_t i) {fWCNumMrdPMT = i;}
  virtual void  SetMRDPMTRadius(Float_t f) {fMRDPMTRadius = f;}
  virtual void  SetWCNumFaccPMT(Int_t i) {fWCNumFaccPMT = i;}
  virtual void  SetFACCPMTRadius(Float_t f) {fFACCPMTRadius = f;}
  virtual void  SetWCOffset(Float_t x, Float_t y, Float_t z) 
           {fWCOffset[0]=x; fWCOffset[1]=y; fWCOffset[2] = z;}
  virtual void  SetPMT(Int_t i, Int_t tubeno, Int_t cyl_loc, Float_t rot[3], Float_t pos[3], bool expand=true);
  virtual void  SetLAPPD(Int_t i, Int_t lappdno, Int_t cyl_loc, Float_t rot[3], Float_t pos[3], bool expand=true);
  virtual void  SetOrientation(Int_t o) {fOrientation = o;}

  virtual Float_t GetWCCylRadius() const {return fWCCylRadius;}
  virtual Float_t GetWCCylLength() const {return fWCCylLength;}

  virtual Int_t GetGeo_Type() const {return fgeo_type;}
  

  virtual Int_t GetWCNumPMT() const {return fWCNumPMT;}
  virtual Float_t GetWCPMTRadius() const {return fWCPMTRadius;}
  virtual Int_t GetWCNumLAPPD() const {return fWCNumLAPPD;}
  virtual Float_t GetWCLAPPDRadius() const {return fWCLAPPDRadius;}
  virtual Int_t GetWCNumMRDPMT() const {return fWCNumMrdPMT;}
  virtual Float_t GetMRDPMTRadius() const {return fMRDPMTRadius;}
  virtual Int_t GetWCNumFACCPMT() const {return fWCNumFaccPMT;}
  virtual Float_t GetFACCPMTRadius() const {return fFACCPMTRadius;}
  virtual Float_t GetWCOffset(Int_t i) const {return (i<3) ? fWCOffset[i] : 0.;}
  virtual Int_t GetOrientation() { return fOrientation; }
  //WCSimRootPMT_v0 GetPMT(Int_t i){return *(new WCSimRootPMT_v0());}
  virtual const WCSimRootPMT_v0* GetPMT(Int_t i){return (WCSimRootPMT_v0*)(*fPMTArray)[i];}
  virtual const WCSimRootPMT_v0* GetLAPPD(Int_t i){return (WCSimRootPMT_v0*)(*fLAPPDArray)[i];}
  virtual const WCSimRootPMT_v0* GetMRDPMT(Int_t i){return (WCSimRootPMT_v0*)(*fMRDPMTArray)[i];}
  virtual const WCSimRootPMT_v0* GetFACCPMT(Int_t i){return (WCSimRootPMT_v0*)(*fFACCPMTArray)[i];} 

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootGeom_v0,1)  //WCSimRootEvent structure
};


#endif
