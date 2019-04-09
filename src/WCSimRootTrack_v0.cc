// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootTrack_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootTrack_v0)
#endif

UInt_t WCSimRootTrack_v0::GetCheckSum(){ return 428008278; }

//_____________________________________________________________________________

WCSimRootTrack_v0::WCSimRootTrack_v0(Int_t ipnu, 
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
			       Float_t time,Int_t id)
{

  // Create a WCSimRootTrack_v0 object and fill it with stuff

  fIpnu = ipnu;
  fFlag = flag;
  fM = m;
  fP = p;
  fE = E;
  fStartvol = startvol;
  fStopvol = stopvol;
  int i;
  for (i=0;i<3;i++)
  {
    fDir[i] = dir[i]; 
    fPdir[i] = pdir[i]; 
    fStop[i] = stop[i]; 
    fStart[i] = start[i];
  }
  fParenttype = parenttype;
  fTime = time;
  fId = id;
}
