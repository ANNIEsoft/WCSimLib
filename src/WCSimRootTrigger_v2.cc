// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include <TStopwatch.h>

#include "WCSimRootTrigger_v2.hh"
#include "WCSimRootEvent_v2.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootTrigger_v2)
#endif

UInt_t WCSimRootTrigger_v2::GetCheckSum(){ return 2992115595; }

//_____________________________________________________________________________

WCSimRootTrigger_v2::WCSimRootTrigger_v2()
{
  // Create an WCSimRootTrigger_v2 object.

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
  
  // TClonesArray of Captures
  fCaptures = 0;

  // TClonesArray of WCSimRootCherenkovDigiHits
  fCherenkovDigiHits = 0;
  fNcherenkovdigihits = 0;
  fSumQ = 0;

  fTriggerType = kTriggerUndefined;
  fTriggerInfo.clear();
  
  fParentEvent = nullptr;
  
  IsZombie = true;
  
}

void WCSimRootTrigger_v2::Initialize() //actually allocate memory for things in here
{
  // Create an WCSimRootTrigger_v2 object.
  // When the constructor is invoked for the first time, the class static
  // variable fgTracks is 0 and the TClonesArray fgTracks is created.
  // Sim. for the other TClonesArray
  //TStopwatch* mystopw = new TStopwatch();

  // TClonesArray of WCSimRootTracks
  fTracks = new TClonesArray("WCSimRootTrack_v2", 10000);
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

  // TClonesArray of WCSimRootCaptures
  fCaptures = new TClonesArray("WCSimRootCapture_v0", 100);
  fNcaptures = 0;

  fTriggerType = kTriggerUndefined;
  fTriggerInfo.clear();
  
  //  std::cout << " Time to allocate the TCAs :  Real = " << mystopw->RealTime() 
  //	    << " ; CPU = " << mystopw->CpuTime() << "\n";
  //delete mystopw;
  

  IsZombie = false; // the memory has been allocated
}

//_____________________________________________________________________________

WCSimRootTrigger_v2::~WCSimRootTrigger_v2()
{
  // now we must do a bunch a deleting stuff...
  //Destroys all the TClonesArray.. Let's see if Ren'e Brun is right...

  //TStopwatch* mystopw = new TStopwatch();

  //mystopw->Start();

  if (!IsZombie) {

    fTracks->Delete();
    fCherenkovHits->Delete();      
    fCherenkovHitTimes->Delete();   
    fCherenkovDigiHits->Delete();  
    fCaptures->Delete();
    
    delete   fTracks;            
    delete   fCherenkovHits;      
    delete   fCherenkovHitTimes;   
    delete   fCherenkovDigiHits; 
    delete   fCaptures;
  }
  //mystopw->Stop();

  //  std::cout << " Time to delete the TCAs :  Real = " << mystopw->RealTime() 
  //    << " ; CPU = " << mystopw->CpuTime() << "\n";

  //delete mystopw;
  //Clear("C");
}


//_____________________________________________________________________________

void WCSimRootTrigger_v2::Clear(Option_t */*option*/)
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

  // TClonesArray of WCSimRootCaptures
  fNcaptures = 0;

  // remove whatever's in the arrays
  // but don't deallocate the arrays themselves

  fTracks->Clear("C");
  fCherenkovHits->Delete();      
  fCherenkovHitTimes->Delete();   
  fCherenkovDigiHits->Delete();
  fCaptures->Delete();

  fTriggerType = kTriggerUndefined;
  fTriggerInfo.clear();

  IsZombie = false ; // we DO NOT deallocate the memory
}

//_____________________________________________________________________________

WCSimRootTrack_v2 *WCSimRootTrigger_v2::AddTrack(Int_t ipnu, 
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
					   std::string eProcess)
{
  // Add a new WCSimRootTrack to the list of tracks for this event.
  // To avoid calling the very time consuming operator new for each track,
  // the standard but not well know C++ operator "new with placement"
  // is called. If tracks[i] is 0, a new Track object will be created
  // otherwise the previous Track[i] will be overwritten.

  TClonesArray &tracks = *fTracks;
  WCSimRootTrack_v2 *track = 
    new(tracks[fNtrack++]) WCSimRootTrack_v2(ipnu,
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
					   id,
					   sProcess,
					   eProcess);

  return track;
}

//_____________________________________________________________________________
void WCSimRootTrigger_v2::SetCaptureParticle(Int_t parent,
                                          Int_t ipnu,
                                          Float_t time,
                                          Float_t vtx[3],
                                          Float_t dir[3],
                                          Float_t energy,
                                          Int_t id)
{
    WCSimRootCapture_v0 * capture = 0;
    for(int i = 0; i<fCaptures->GetEntriesFast(); i++){
        if(((WCSimRootCapture_v0*)fCaptures->At(i))->GetCaptureParent() == parent)
            capture = (WCSimRootCapture_v0*)fCaptures->At(i);
    }
    if(capture == 0) {
        TClonesArray &captures = *fCaptures;
        capture = new(captures[fNcaptures++]) WCSimRootCapture_v0(parent);
    }
    if(ipnu==22) capture->AddGamma(id, energy, dir);
    else capture->SetInfo(vtx, time, ipnu);
}

//_____________________________________________________________________________
void WCSimRootTrigger_v2::Print(int verbosity, int maxprimariestoprint, int maxtrackstoprint, int maxdigitstoprint, int maxphotonsperdigittoprint, int maxphotonstoprint){

  // get the first trigger of this event, required for info on cherenkov hits
  WCSimRootTrigger_v2* firsttrig=fParentEvent->GetTrigger(0);
  
  std::cout<<"Trigger time : "<<fEvtHdr.GetDate()<<std::endl;
  std::cout<<"Number Primary Vertices : "<<fNvtxs<<std::endl;
  // loop over primary vertices. Usually just 1. Delayed triggers may report 0, so coerce to 1. 
  for(int primaryi=0; primaryi<std::max(1,std::min(maxprimariestoprint,fNvtxs)); primaryi++){
    std::cout<<"Primary vertex "<<primaryi<<" was at ("
        <<fVtxs[primaryi][0]<<", "<<fVtxs[primaryi][2]<<", "<<fVtxs[primaryi][2]<<")"<<std::endl;
  }
  
  //int numphotons = firsttrig->GetCherenkovHits()->GetEntries();  //<< applicable to entire event, not trigger
  // quick manual count of number of photons in digits within this trigger
  int numphotons = 0;
  for(int digiti=0; digiti<fNcherenkovdigihits; digiti++){
    WCSimRootCherenkovDigiHit_v0* digihit=(WCSimRootCherenkovDigiHit_v0*)(fCherenkovDigiHits->At(digiti));
    numphotons += digihit->GetPhotonIds().size();
  }
  std::cout<<"Num Tracks: "<<fNtrack<<std::endl
      <<"Num Digits: "<<fNcherenkovdigihits<<std::endl
      <<"Num Photons: " <<numphotons<<std::endl;
  
  // scan through the truth tracks
  for(int tracki=0; tracki<std::min(maxtrackstoprint,fNtrack); tracki++){
    WCSimRootTrack_v2* nextrack = (WCSimRootTrack_v2*)(fTracks->At(tracki));
    //Int_t     GetIpnu()             pdg
    //Int_t     GetFlag()             -1: neutrino primary, -2: neutrino target, 0: other
    //Float_t   GetM()                mass
    //Float_t   GetP()                momentum magnitude
    //Float_t   GetE()                energy (inc rest mass^2)
    //Float_t   GetEndE()             energy on stopping of particle tracking
    //Float_t   GetEndP()             momentum on stopping of particle tracking
    //Int_t     GetStartvol()         starting volume: 10 is tank, 20 is facc, 30 is mrd
    //Int_t     GetStopvol()          stopping volume: but these may not be set.
    //Float_t   GetDir(Int_t i=0)     momentum unit vector
    //Float_t   GetPdir(Int_t i=0)    momentum vector
    //Float_t   GetPdirEnd(Int_t i=0) direction vector on stop tracking
    //Float_t   GetStop(Int_t i=0)    stopping vertex x,y,z for i=0-2, in cm
    //Float_t   GetStart(Int_t i=0)   starting vertex x,y,z for i=0-2, in cm
    //Int_t     GetParenttype()       parent pdg, 0 for primary.
    //Float_t   GetTime()             trj->GetGlobalTime(); starting time of particle
    //Float_t   GetStopTime()
    //Int_t     GetId()               wcsim trackid
    // 
    //GetFlag=-1; neutrino.           This should be the neutrino. Only stop vertex is stored.
    //GetFlag=-2; primary target.     This is the target nucleus, or if none, a proton. Only stop vertex stored.
    //GetFlag= 0; any other track.    ALL PRIMARY TRACKS ALSO GET STORED HERE.
    std::cout<<"    Track "<<tracki<<"{"
        <<  " Flag: "<<nextrack->GetFlag()
        <<" | PDG: "<<nextrack->GetIpnu()
        <<" | ParentPDG: "<<nextrack->GetParenttype()
        <<" | sProc: "<<nextrack->GetStartProcess()
        <<" | eProc: "<<nextrack->GetEndProcess();
    if(verbosity){
      std::cout<<" | Start E: "<<nextrack->GetE()
          <<" | End E: "<<nextrack->GetEndE()
          <<" | Start Vtx: ("<<nextrack->GetTime()<<", "
          <<nextrack->GetStart(0)<<", "<<nextrack->GetStart(1)<<", "<<nextrack->GetStart(2)<<")"
          <<" | End Vtx: ("<<nextrack->GetStopTime()<<", "
          <<nextrack->GetStop(0)<<", "<<nextrack->GetStop(1)<<", "<<nextrack->GetStop(2)<<")";
    }
    std::cout<<" }"<<std::endl;
  }
  
  // loop over digits
  for(int digiti=0; digiti<std::min(maxdigitstoprint,fNcherenkovdigihits); digiti++){
    WCSimRootCherenkovDigiHit_v0* digihit=(WCSimRootCherenkovDigiHit_v0*)(fCherenkovDigiHits->At(digiti));
    std::vector<int> truephotonindices = digihit->GetPhotonIds();
    std::cout<<"      digit "<<digiti<<" at time "<<digihit->GetT()<<"ns has charge "<<digihit->GetQ()
        <<" from "<<truephotonindices.size()<<" true photons"<<std::endl;
    // loop over the photons
    for(int photoni=0; photoni<std::min(maxphotonsperdigittoprint,(int)truephotonindices.size()); photoni++){
      int thephotonsid = truephotonindices.at(photoni);
      WCSimRootCherenkovHitTime_v0 *thehittimeobject = 
        (WCSimRootCherenkovHitTime_v0*)firsttrig->GetCherenkovHitTimes()->At(thephotonsid);
      Int_t thephotonsparenttrackid = thehittimeobject->GetParentID();
     std::cout<<"        digit "<<digiti<<", photon "<<photoni<<" has truetime "<<thehittimeobject->GetTruetime()<<std::endl;
    }
  }
  
}
