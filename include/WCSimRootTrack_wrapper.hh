#ifndef WCSim_RootTrack_wrapper
#define WCSim_RootTrack_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootTrack_wrapper                                           //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootTrack_v0.hh"
#include "WCSimRootTrack_v1.hh"
#include "WCSimRootTrack_v2.hh"

class WCSimRootTrack_wrapper {

protected:
  WCSimRootTrack_v0* thetrack=nullptr;

public:
  WCSimRootTrack_wrapper(WCSimRootTrack_v0* thetrackin) : thetrack(thetrackin) {};
//  WCSimRootTrack_wrapper(){};

  inline Int_t     GetIpnu() const { return thetrack->GetIpnu();}
  inline Int_t     GetFlag() const { return thetrack->GetFlag();}
  inline Float_t   GetM() const { return thetrack->GetM();}
  inline Float_t   GetP() const { return thetrack->GetP();}
  inline Float_t   GetE() const { return thetrack->GetE();}
  inline Int_t     GetStartvol() { return thetrack->GetStartvol();}
  inline Int_t     GetStopvol() { return thetrack->GetStopvol();}
  inline Float_t   GetDir(Int_t i=0) {return thetrack->GetDir(i);} 
  inline Float_t   GetPdir(Int_t i=0) {return thetrack->GetPdir(i);}
  inline Float_t   GetStop(Int_t i=0) {return thetrack->GetStop(i);}
  inline Float_t   GetStart(Int_t i=0) {return thetrack->GetStart(i);}
  inline Int_t     GetParenttype(/*Int_t i=0*/) {return thetrack->GetParenttype();}
  inline Float_t   GetTime() { return thetrack->GetTime();}
  inline Int_t     GetId(){return thetrack->GetId();}
  
  /////////////////////
  // Version 1
  Float_t   GetEndE() const;
  Float_t   GetEndP() const;
  Float_t   GetPdirEnd(Int_t i=0);
  Float_t   GetStopTime();
  /////////////////////
  // Version 2
  std::string GetStartProcess();
  std::string GetEndProcess();
  void Clear(Option_t *option ="");
  /////////////////////

  inline Int_t GetVersion()         const { return thetrack->GetVersion(); }
  inline UInt_t GetCheckSum()        const { return thetrack->GetCheckSum(); }
  inline const WCSimRootTrack_v0* GetPtr() const { return thetrack; }
};


//////////////////////////////////////////////////////////////////////////

#endif
