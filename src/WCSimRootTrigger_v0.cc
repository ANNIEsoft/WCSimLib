// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include <TStopwatch.h>

#include "WCSimRootTrigger_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootTrigger_v0)
#endif

UInt_t WCSimRootTrigger_v0::GetCheckSum(){ return 2723480849; }

//_____________________________________________________________________________

WCSimRootTrigger_v0::WCSimRootTrigger_v0()
{
  // Create an WCSimRootTrigger object.


  // WARNING : default constructor for ROOT : do not allocate memory
  // inside it or upon re-reading the object there will be a memory leak
  // TClonesArray of WCSimRootTracks
  fTracks = 0;
  fNtrack = 0;

  // TClonesArray of WCSimRootCherenkovHits
  fCherenkovHits = 0;
  fCherenkovHitTimes = 0;
  fNcherenkovhits = 0;
  fNcherenkovhittimes = 0;

  // TClonesArray of WCSimRootCherenkovDigiHits
  fCherenkovDigiHits = 0;
  fNcherenkovdigihits = 0;
  fSumQ = 0;

  fTriggerType = kTriggerUndefined;
  fTriggerInfo.clear();
  
  IsZombie = true;
  
}

WCSimRootTrigger_v0::WCSimRootTrigger_v0(int Number,int Subevt)
{
  this->Initialize();
  fEvtHdr.Set(Number,0,0,Subevt);
}

//copy constructor --> only shallow copy of preallocated objects ??


void WCSimRootTrigger_v0::Initialize() //actually allocate memory for things in here
{
  // Create an WCSimRootTrigger object.
  // When the constructor is invoked for the first time, the class static
  // variable fgTracks is 0 and the TClonesArray fgTracks is created.
  // Sim. for the other TClonesArray
  TStopwatch* mystopw = new TStopwatch();

  // TClonesArray of WCSimRootTracks
  fTracks = new TClonesArray("WCSimRootTrack_v0", 10000);
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

WCSimRootTrigger_v0::~WCSimRootTrigger_v0()
{
  // now we must do a bunch a deleting stuff...
  //Destroys all the TClonesArray.. Let's see if Ren'e Brun is right...

  TStopwatch* mystopw = new TStopwatch();

  mystopw->Start();

  if (!IsZombie) {

    fTracks->Delete();            
    fCherenkovHits->Delete();      
    fCherenkovHitTimes->Delete();   
    fCherenkovDigiHits->Delete();  
    
    delete   fTracks;            
    delete   fCherenkovHits;      
    delete   fCherenkovHitTimes;   
    delete   fCherenkovDigiHits; 
  }
  mystopw->Stop();

  //  G4cout << " Time to delete the TCAs :  Real = " << mystopw->RealTime() 
  //    << " ; CPU = " << mystopw->CpuTime() << "\n";

  delete mystopw;
  //Clear("C");
}


//_____________________________________________________________________________

void WCSimRootTrigger_v0::Clear(Option_t */*option*/)
{
  // To be filled in 
  // Filled in, by MF, 31/08/06  -> Keep all the alloc'ed memory but reset all
  // the indices to 0 in the TCAs.
  fNtrack = 0;

  // TClonesArray of WCSimRootCherenkovHits
  fNcherenkovhits = 0;
  fNcherenkovhittimes = 0;

  // TClonesArray of WCSimRootCherenkovDigiHits
  fNcherenkovdigihits = 0;
  fSumQ = 0;

  // remove whatever's in the arrays
  // but don't deallocate the arrays themselves

  fTracks->Delete();            
  fCherenkovHits->Delete();      
  fCherenkovHitTimes->Delete();   
  fCherenkovDigiHits->Delete();

  fTriggerType = kTriggerUndefined;
  fTriggerInfo.clear();

  IsZombie = false ; // we DO NOT deallocate the memory
}

//_____________________________________________________________________________

void WCSimRootTrigger_v0::Reset(Option_t */*option*/)
{
// Static function to reset all static objects for this event
// To be filled in
}

//_____________________________________________________________________________

void WCSimRootTrigger_v0::SetHeader(Int_t i, 
				  Int_t run, 
				  Int_t date,Int_t subevent)
{
  // Set the header values
  fEvtHdr.Set(i, run, date,subevent);
}

//_____________________________________________________________________________

void WCSimRootTrigger_v0::SetTriggerInfo(TriggerType_t trigger_type,
				      std::vector<Float_t> trigger_info)
{
  fTriggerType = trigger_type;
  fTriggerInfo = trigger_info;
}

//_____________________________________________________________________________

void WCSimRootTrigger_v0::SetPi0Info(Float_t pi0Vtx[3], 
				 Int_t   gammaID[2], 
				 Float_t gammaE[2],
				 Float_t gammaVtx[2][3])
{
  fPi0.Set(pi0Vtx, 
	   gammaID, 
	   gammaE,
	   gammaVtx);
}

//_____________________________________________________________________________

WCSimRootTrack_v0 *WCSimRootTrigger_v0::AddTrack(Int_t ipnu, 
					   Int_t flag, 
					   Float_t m, 
					   Float_t p, 
					   Float_t E, 
					   Int_t startvol, 
					   Int_t stopvol, 
					   Float_t dir[3], 
					   Float_t pdir[3], 
					   Float_t stop[3], 
					   Float_t start[3],
					   Int_t parenttype,
					   Float_t time,
					   Int_t id)
{
  // Add a new WCSimRootTrack to the list of tracks for this event.
  // To avoid calling the very time consuming operator new for each track,
  // the standard but not well know C++ operator "new with placement"
  // is called. If tracks[i] is 0, a new Track object will be created
  // otherwise the previous Track[i] will be overwritten.

  TClonesArray &tracks = *fTracks;
  WCSimRootTrack_v0 *track = 
    new(tracks[fNtrack++]) WCSimRootTrack_v0(ipnu,
					   flag,
					   m,
					   p,
					   E,
					   startvol,
					   stopvol,
					   dir,
					   pdir,
					   stop,
					   start,
					   parenttype,
					  time,id);

  return track;
}

//_____________________________________________________________________________

WCSimRootCherenkovHit_v0 *WCSimRootTrigger_v0::AddCherenkovHit(Int_t tubeID,std::vector<Float_t> truetime,std::vector<Int_t> primParID)
{
  // Add a new Cherenkov hit to the list of Cherenkov hits
  TClonesArray &cherenkovhittimes = *fCherenkovHitTimes;

  for (unsigned int i =0;i<truetime.size();i++)
  {
    fCherenkovHitCounter++;

    WCSimRootCherenkovHitTime_v0 *cherenkovhittime = 
      new(cherenkovhittimes[fNcherenkovhittimes++]) WCSimRootCherenkovHitTime_v0(truetime[i],primParID[i]);
  }

  Int_t WC_Index[2];
  WC_Index[0] = fNcherenkovhittimes-truetime.size(); //fCherenkovHitCounter-truetime.size();
  WC_Index[1] = truetime.size();

  TClonesArray &cherenkovhits = *fCherenkovHits;
 
  WCSimRootCherenkovHit_v0 *cherenkovhit
    = new(cherenkovhits[fNcherenkovhits++]) WCSimRootCherenkovHit_v0(tubeID,
								  WC_Index);

  return cherenkovhit;
}
//_____________________________________________________________________________

WCSimRootCherenkovDigiHit_v0 *WCSimRootTrigger_v0::AddCherenkovDigiHit(Float_t q, 
								 Float_t t, 
								 Int_t tubeid,
								 std::vector<int> photon_ids)
{
  // Add a new digitized hit to the list of digitized hits
  TClonesArray &cherenkovdigihits = *fCherenkovDigiHits;
  WCSimRootCherenkovDigiHit_v0 *cherenkovdigihit = 
    new(cherenkovdigihits[fNcherenkovdigihits++]) WCSimRootCherenkovDigiHit_v0(q, 
									    t, 
									    tubeid,
									    photon_ids);
 
  return cherenkovdigihit;
}
