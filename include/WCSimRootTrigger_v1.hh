#ifndef WCSim_RootTrigger_v1
#define WCSim_RootTrigger_v1

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootTrigger_v1                                              //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"
#include <vector>
#include "jhfNtuple.h"

#include "WCSimEnumerations.hh"
#include "WCSimRootEventHeader_v0.hh"
#include "WCSimRootPi0_v0.hh"
#include "WCSimRootTrack_v1.hh"
#include "WCSimRootCherenkovHit_v0.hh"
#include "WCSimRootCherenkovDigiHit_v0.hh"
#include "WCSimRootCherenkovHitTime_v0.hh"
#include "WCSimRootTrigger_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootTrigger_v1 : public WCSimRootTrigger_v0 {

protected:

public:
  WCSimRootTrigger_v1() : WCSimRootTrigger_v0(){};
  WCSimRootTrigger_v1(int a, int b) : WCSimRootTrigger_v0(a, b){};
  virtual ~WCSimRootTrigger_v1(){};
  
  virtual void Initialize();
  
  virtual WCSimRootTrack_v1         *AddTrack(Int_t ipnu, 
				   Int_t flag, 
				   Float_t m, 
				   Float_t p, 
				   Float_t E, 
				   Float_t p2,
				   Float_t E2,
				   Int_t startvol, 
				   Int_t stopvol, 
				   Float_t dir[3], 
				   Float_t pdir[3], 
				   Float_t pdir2[3], 
				   Float_t stop[3],
				   Float_t start[3],
				   Int_t parenttype,
				   Float_t time,
				   Float_t time2,
				   Int_t id);

  virtual Int_t GetVersion()         const { return 1; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootTrigger_v1,2) //WCSimRootEvent structure
};

#endif
