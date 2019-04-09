#ifndef WCSim_RootPmt_v1
#define WCSim_RootPmt_v1

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootPmt_v1                                                        
//                                                                      
// This class contains information needed to be passed to reconstruction
//     routines.  It's just simple right now-- only the bare-bones  
//     WC info
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "WCSimRootPmt_v0.hh"

class WCSimRootPMT_v1 : public WCSimRootPMT_v0 {

protected:
  std::string fPmtTypeName;

public:
  WCSimRootPMT_v1() : WCSimRootPMT_v0(){};
  WCSimRootPMT_v1(Int_t tubeNo, Int_t cylLoc, Float_t orientation[3], Float_t position[3], std::string PmtType);
  virtual ~WCSimRootPMT_v1(){};

  virtual void SetType(std::string PmtType) {fPmtTypeName=PmtType;}

  virtual const char * GetName() const { return fPmtTypeName.c_str();}

  virtual Int_t GetVersion()         const { return 1; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootPMT_v1,1)  //WCSimPMT structure
};


//////////////////////////////////////////////////////////////////////////

#endif
