#ifndef WCSim_RootGeom_wrapper
#define WCSim_RootGeom_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootGeom_wrapper                                                    
//                                                                      
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootGeom_v0.hh"
#include "WCSimRootGeom_v1.hh"
#include "WCSimRootGeom_v2.hh"
#include "WCSimRootGeom_v3.hh"

#include "WCSimRootPmt_wrapper.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootGeom_wrapper {

protected:
  WCSimRootGeom_v0* geo=nullptr;

public:

  WCSimRootGeom_wrapper(WCSimRootGeom_v0* geoin) : geo(geoin){};
//  WCSimRootGeom_wrapper(){};

  // Sets and gets
  inline void  SetWCCylRadius(Float_t f) {geo->SetWCCylRadius(f);}
  inline void  SetWCCylLength(Float_t f) {geo->SetWCCylLength(f);}
  inline void SetGeo_Type(Int_t f){geo->SetGeo_Type(f);}
  inline void  SetWCNumPMT(Int_t i) {geo->SetWCNumPMT(i);}
  inline void  SetWCPMTRadius(Float_t f) {geo->SetWCPMTRadius(f);}
  inline void  SetWCNumLAPPD(Int_t i) {geo->SetWCNumLAPPD(i);}
  inline void  SetWCLAPPDRadius(Float_t f) {geo->SetWCLAPPDRadius(f);}
  inline void  SetWCNumMrdPMT(Int_t i) {geo->SetWCNumMrdPMT(i);}
  inline void  SetMRDPMTRadius(Float_t f) {geo->SetMRDPMTRadius(f);}
  inline void  SetWCNumFaccPMT(Int_t i) {geo->SetWCNumFaccPMT(i);}
  inline void  SetFACCPMTRadius(Float_t f) {geo->SetFACCPMTRadius(f);}
  inline void  SetWCOffset(Float_t x, Float_t y, Float_t z) {geo->SetWCOffset(x,y,z);}
  inline void  SetPMT(Int_t i, Int_t tubeno, Int_t cyl_loc, Float_t rot[3], Float_t pos[3], bool expand=true)
      { geo->SetPMT(i,tubeno,cyl_loc,rot,pos,expand); }
  inline void  SetLAPPD(Int_t i, Int_t lappdno, Int_t cyl_loc, Float_t rot[3], Float_t pos[3], bool expand=true)
      { geo->SetLAPPD(i, lappdno, cyl_loc, rot, pos, expand); }
  inline void  SetOrientation(Int_t o) {geo->SetOrientation(o);}
  inline Float_t GetWCCylRadius() const {return geo->GetWCCylRadius();}
  inline Float_t GetWCCylLength() const {return geo->GetWCCylLength();}
  inline Int_t GetGeo_Type() const {return geo->GetGeo_Type();}
  inline Int_t GetWCNumPMT() const {return geo->GetWCNumPMT();}
  inline Float_t GetWCPMTRadius() const {return geo->GetWCPMTRadius();}
  inline Int_t GetWCNumLAPPD() const {return geo->GetWCNumLAPPD();}
  inline Float_t GetWCLAPPDRadius() const {return geo->GetWCLAPPDRadius();}
  inline Int_t GetWCNumMRDPMT() const {return geo->GetWCNumMRDPMT();}
  inline Float_t GetMRDPMTRadius() const {return geo->GetMRDPMTRadius();}
  inline Int_t GetWCNumFACCPMT() const {return geo->GetWCNumFACCPMT();}
  inline Float_t GetFACCPMTRadius() const {return geo->GetFACCPMTRadius();}
  inline Float_t GetWCOffset(Int_t i) const {return geo->GetWCOffset(i);}
  inline Int_t GetOrientation() { return geo->GetOrientation(); }
  
  // TODO could we also populate the missing PMT members?
  WCSimRootPMT_wrapper GetPMT(Int_t i){
    WCSimRootPMT_wrapper w(geo->GetPMT(i));
    return w;
  }
  WCSimRootPMT_wrapper GetLAPPD(Int_t i){
    WCSimRootPMT_wrapper w(geo->GetLAPPD(i));
    return w;
  }
  WCSimRootPMT_wrapper GetMRDPMT(Int_t i){
    WCSimRootPMT_wrapper w(geo->GetMRDPMT(i));
    return w;
  }
  WCSimRootPMT_wrapper GetFACCPMT(Int_t i){
    WCSimRootPMT_wrapper w(geo->GetFACCPMT(i));
    return w;
  }
  
  ///////////////////////
  // Version 1
  Float_t GetWCPMTRadiusAt(Int_t index);
  std::string GetWCPMTNameAt(Int_t index);
  Int_t GetWCNumPMTsAt(Int_t index);
  Int_t GetTubeIndex(Int_t tubeId);
  std::vector<int> GetTubesInCollection(int collectionindex);
  ////////////////////////
  // Version 3
  std::vector<std::string> GetPMTNames();
  std::vector<int> GetWCNumPmts();
  /////////////////////////

  inline Int_t GetVersion()         const { return geo->GetVersion(); }
  inline Int_t GetCheckSum()        const { return geo->GetCheckSum(); }
  inline const WCSimRootGeom_v0* GetPtr() const { return geo; }
};


#endif
