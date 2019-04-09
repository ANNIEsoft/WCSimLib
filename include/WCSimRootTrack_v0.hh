#ifndef WCSim_RootTrack_v0
#define WCSim_RootTrack_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootTrack_v0                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"

class WCSimRootTrack_v0 : public TObject {

protected:

  // See jhfNtuple.h for the meaning of these data members:
  Int_t   fIpnu;        
  Int_t   fFlag;        
  Float_t fM;
  Float_t fP;
  Float_t fE;
  Int_t   fStartvol;
  Int_t   fStopvol;
  Float_t fDir[3];
  Float_t fPdir[3];
  Float_t fStop[3];
  Float_t fStart[3];
  Int_t fParenttype;
  Float_t fTime;
  Int_t fId;

public:
  WCSimRootTrack_v0() {}
  WCSimRootTrack_v0(Int_t ipnu, 
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
		 Float_t time,Int_t id);
  
  virtual ~WCSimRootTrack_v0() { }

  virtual Int_t     GetIpnu() const { return fIpnu;}
  virtual Int_t     GetFlag() const { return fFlag;}
  virtual Float_t   GetM() const { return fM;}
  virtual Float_t   GetP() const { return fP;}
  virtual Float_t   GetE() const { return fE;}
  virtual Int_t     GetStartvol() { return fStartvol;}
  virtual Int_t     GetStopvol() { return fStopvol;}
  virtual Float_t   GetDir(Int_t i=0) {return (i<3) ? fDir[i] : 0;} 
  virtual Float_t   GetPdir(Int_t i=0) {return (i<3) ? fPdir[i] : 0;}
  virtual Float_t   GetStop(Int_t i=0) {return (i<3) ? fStop[i] : 0;}
  virtual Float_t   GetStart(Int_t i=0) {return (i<3) ? fStart[i] : 0;}
  virtual Int_t     GetParenttype(/*Int_t i=0*/) {return fParenttype;}
  virtual Float_t   GetTime() { return fTime;}
  virtual Int_t     GetId(){return fId;}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootTrack_v0,1)  
};


//////////////////////////////////////////////////////////////////////////

#endif
