#ifndef WCSim_RootGeom_v3
#define WCSim_RootGeom_v3

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootGeom_v3                                                    
//                                                                      
// This class contains information needed to be passed to reconstruction
//     routines.  It's just simple right now-- only the bare-bones  
//     WC info
//////////////////////////////////////////////////////////////////////////

#include <map>
#include "TObject.h"
#include "TClonesArray.h"
#include "WCSimRootPmt_v1.hh"
#include "WCSimRootGeom_v1.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootGeom_v3 : public WCSimRootGeom_v1 {

protected:

public:

  WCSimRootGeom_v3();
  virtual ~WCSimRootGeom_v3(){};

  // Sets and gets
  virtual void  SetPMT(Int_t i, Int_t tubeno, Int_t cyl_loc, Float_t rot[3], Float_t pos[3], std::string PmtType, bool expand=true);
  virtual void  SetLAPPD(Int_t i, Int_t lappdno, Int_t cyl_loc, Float_t rot[3], Float_t pos[3], std::string PmtType, bool expand=true);
  virtual std::vector<std::string> GetPMTNames(){
    return fWCPMTNamevec;
  }
  virtual std::vector<int> GetWCNumPmts(){
    if(fWCNumPMTvec.size()) return fWCNumPMTvec;
    return std::vector<int>{fWCNumPMT};
  }
  //WCSimRootPMT_v1 GetPMT(Int_t i){return *(new WCSimRootPMT_v1());}
  virtual const WCSimRootPMT_v1* GetPMT(Int_t i){return (WCSimRootPMT_v1*)(*fPMTArray)[i];}
  virtual const WCSimRootPMT_v1* GetLAPPD(Int_t i){return (WCSimRootPMT_v1*)(*fLAPPDArray)[i];}
  virtual const WCSimRootPMT_v1* GetMRDPMT(Int_t i){return (WCSimRootPMT_v1*)(*fMRDPMTArray)[i];}
  virtual const WCSimRootPMT_v1* GetFACCPMT(Int_t i){return (WCSimRootPMT_v1*)(*fFACCPMTArray)[i];}

  virtual Int_t GetVersion()         const { return 3; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootGeom_v3,1)  //WCSimRootEvent structure
};


#endif
