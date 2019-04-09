// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include <TStopwatch.h>

#include "WCSimRootTrigger_v1.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootTrigger_v1)
#endif

UInt_t WCSimRootTrigger_v1::GetCheckSum(){ return 2723480849; }

void WCSimRootTrigger_v1::Initialize() //actually allocate memory for things in here
{
  // Create an WCSimRootTrigger_v1 object.
  // When the constructor is invoked for the first time, the class static
  // variable fgTracks is 0 and the TClonesArray fgTracks is created.
  // Sim. for the other TClonesArray
  TStopwatch* mystopw = new TStopwatch();

  // TClonesArray of WCSimRootTracks
  fTracks = new TClonesArray("WCSimRootTrack_v1", 10000);
  fNtrack = 0;

  // TClonesArray of WCSimRootCherenkovHits
  fCherenkovHits = new TClonesArray("WCSimRootCherenkovHit_v0", 
				    10000);
  fCherenkovHitTimes = new TClonesArray("WCSimRootCherenkovHitTime_v0", 
					10000);
  fNcherenkovhits = 0;
  fNcherenkovhittimes = 0;

  // TClonesArray of WCSimRootCherenkovDigiHits
  fCherenkovDigiHits = new TClonesArray("WCSimRootCherenkovDigiHit_v0", 
				       10000);
  fNcherenkovdigihits = 0;
  fSumQ = 0;

  fTriggerType = kTriggerUndefined;
  fTriggerInfo.clear();
  
  //  G4cout << " Time to allocate the TCAs :  Real = " << mystopw->RealTime() 
  //	    << " ; CPU = " << mystopw->CpuTime() << "\n";
  delete mystopw;
  

  IsZombie = false; // the memory has been allocated
}

//_____________________________________________________________________________

WCSimRootTrack_v1 *WCSimRootTrigger_v1::AddTrack(Int_t ipnu, 
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
					   Int_t id)
{
  // Add a new WCSimRootTrack_v1 to the list of tracks for this event.
  // To avoid calling the very time consuming operator new for each track,
  // the standard but not well know C++ operator "new with placement"
  // is called. If tracks[i] is 0, a new Track object will be created
  // otherwise the previous Track[i] will be overwritten.

  TClonesArray &tracks = *fTracks;
  WCSimRootTrack_v1 *track = 
    new(tracks[fNtrack++]) WCSimRootTrack_v1(ipnu,
					   flag,
					   m,
					   p,
					   E,
					   p2,
					   E2,
					   startvol,
					   stopvol,
					   dir,
					   pdir,
					   pdir2,
					   stop,
					   start,
					   parenttype,
					   time,
					   time2,
					   id);

  return track;
}
