#ifndef WCSim_RootTrack_v1
#define WCSim_RootTrack_v1

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootTrack_v1                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "WCSimRootTrack_v0.hh"

class WCSimRootTrack_v1 : public WCSimRootTrack_v0 {

protected:

  Float_t fP2;      // end mom magnitude
  Float_t fE2;      // end E (relativistic inc. mass^2)
  Float_t fPdir2[3]; // end mom
  Float_t fTime2;  // end time 

public:
  WCSimRootTrack_v1() {}
  WCSimRootTrack_v1(Int_t ipnu, 
		  Int_t flag, 
		  Float_t m, 
		  Float_t p, 
		  Float_t E, 
		  Float_t endE, 
		  Float_t endP, 
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
		 Int_t id);
  
  virtual ~WCSimRootTrack_v1() { }

  virtual Float_t   GetEndE() const { return fE2;}
  virtual Float_t   GetEndP() const { return fP2;}
  virtual Float_t   GetPdirEnd(Int_t i=0) {return (i<3) ? fPdir2[i] : 0;}
  virtual Float_t   GetStopTime() { return fTime2;}

  virtual Int_t GetVersion()         const { return 1; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootTrack_v1,1)  
};


//////////////////////////////////////////////////////////////////////////

#endif
