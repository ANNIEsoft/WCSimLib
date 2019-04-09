#ifndef WCSim_RootTrack_v2
#define WCSim_RootTrack_v2

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootTrack_v2                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "WCSimRootTrack_v1.hh"

class WCSimRootTrack_v2 : public WCSimRootTrack_v1 {

protected:

  std::string fStartProcess;
  std::string fEndProcess;

public:
  WCSimRootTrack_v2() {}
  WCSimRootTrack_v2(Int_t ipnu, 
		  Int_t flag, 
		  Float_t m, 
		  Float_t p, 
		  Float_t E, 
		  Float_t endP, 
		  Float_t endE, 
		  Int_t startvol, 
		  Int_t stopvol, 
		  Float_t dir[3], 
		  Float_t pdir[3], 
		  Float_t pdir2[3],
		  Float_t stop[3], 
		  Float_t start[3], 
		  Int_t parenttype,
		  Float_t time,
		  Float_t endtime,
		  Int_t id,
		  std::string sProcess,
		  std::string eProcess);
  
  virtual ~WCSimRootTrack_v2() { }

  virtual std::string GetStartProcess(){return fStartProcess;}
  virtual std::string GetEndProcess(){return fEndProcess;}
  virtual void Clear(Option_t *option ="");

  virtual Int_t GetVersion()         const { return 2; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootTrack_v2,1)  
};


//////////////////////////////////////////////////////////////////////////

#endif
