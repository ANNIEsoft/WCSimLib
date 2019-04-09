#ifndef WCSim_RootTrigger_v2
#define WCSim_RootTrigger_v2

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootTrigger_v2                                              //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"
#include <vector>
#include <iostream>
#include "jhfNtuple.h"

#include "WCSimEnumerations.hh"
#include "WCSimRootEventHeader_v1.hh"
#include "WCSimRootPi0_v0.hh"
#include "WCSimRootTrack_v2.hh"
#include "WCSimRootCherenkovHit_v0.hh"
#include "WCSimRootCherenkovDigiHit_v0.hh"
#include "WCSimRootCherenkovHitTime_v0.hh"
#include "WCSimRootCapture_v0.hh"
#include "WCSimRootTrigger_v1.hh"

class WCSimRootEvent_v2;

//////////////////////////////////////////////////////////////////////////

class WCSimRootTrigger_v2 : public WCSimRootTrigger_v1 {

protected:
  WCSimRootEvent_v2*         fParentEvent; //! a link back to the parent, set when trigger is retrieved
  WCSimRootEventHeader_v1    fEvtHdr;  // The header
  TClonesArray        *fCaptures;            // Neutron capture info (default = not used)
  Int_t                fNcaptures;           // Number of tracks in the array

public:
  WCSimRootTrigger_v2();
  WCSimRootTrigger_v2(int a, int b) : WCSimRootTrigger_v1(a,b){};
  virtual ~WCSimRootTrigger_v2();
  
  virtual void Initialize();

  virtual void          Clear(Option_t *option ="");
  virtual void Print(int verbosity=0, int maxprimariestoprint=10, int maxtrackstoprint=10, int maxdigitstoprint=10, int maxphotonsperdigittoprint=5, int maxphotonstoprint=5);

  virtual void          SetCaptureParticle(Int_t parent,
                                   Int_t ipnu,
                                   Float_t time,
                                   Float_t vtx[3],
                                   Float_t dir[3],
                                   Float_t energy,
                                   Int_t id);
  virtual void          SetParentEvent(WCSimRootEvent_v2* parenteventin){ fParentEvent = parenteventin; }

  virtual WCSimRootEventHeader_v1 *GetHeader()               {return &fEvtHdr; }
  virtual WCSimRootEvent_v2*     GetParentEvent()        const {return fParentEvent;}

  virtual WCSimRootTrack_v2         *AddTrack(Int_t ipnu, 
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
				   Int_t id,
				   std::string sProcess,
				   std::string eProcess);

  virtual Int_t                   GetNcaptures() const {return fNcaptures; }
  virtual TClonesArray            *GetCaptures() const {return fCaptures;}

  virtual Int_t GetVersion()         const { return 2; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootTrigger_v2,2) //WCSimRootEvent structure
};

#endif
