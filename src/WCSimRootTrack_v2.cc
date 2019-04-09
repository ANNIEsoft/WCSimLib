// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootTrack_v2.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootTrack_v2)
#endif

UInt_t WCSimRootTrack_v2::GetCheckSum(){ return 2062281733; }

//_____________________________________________________________________________

WCSimRootTrack_v2::WCSimRootTrack_v2(Int_t ipnu, 
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

  // Create a WCSimRootTrack_v2 object and fill it with stuff

  fIpnu = ipnu;
  fFlag = flag;
  fM = m;
  fP = p;
  fE = E;
  fP2 = p2;
  fE2 = E2;
  fStartvol = startvol;
  fStopvol = stopvol;
  int i;
  for (i=0;i<3;i++)
  {
    fDir[i] = dir[i]; 
    fPdir[i] = pdir[i]; 
    fPdir2[i] = pdir2[i]; 
    fStop[i] = stop[i]; 
    fStart[i] = start[i];
  }
  fParenttype = parenttype;
  fTime = time;
  fTime2 = time2;
  fId = id;
  fStartProcess = sProcess;
  fEndProcess = eProcess;
}

//_____________________________________________________________________________
void WCSimRootTrack_v2::Clear(Option_t* /*o*/){
  // must clear any datatypes that could potentially allocate memory
  fStartProcess.clear();
  fEndProcess.clear();
}
