#ifndef WCSim_RootEventHeader_wrapper
#define WCSim_RootEventHeader_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootEventHeader_wrapper                                     //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootEventHeader_v0.hh"
#include "WCSimRootEventHeader_v1.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootEventHeader_wrapper {

protected:
  WCSimRootEventHeader_v0* head=nullptr;

public:
  WCSimRootEventHeader_wrapper(WCSimRootEventHeader_v0* headin) : head(headin) { }
//  WCSimRootEventHeader_wrapper(){};
  
  inline void   Set(Int_t i, Int_t r, Int_t d, Int_t s=1) { head->Set(i,r,d,s);}
  inline void SetDate(Int_t d) { head->SetDate(d); }
  inline Int_t  GetEvtNum() const { return head->GetEvtNum(); }
  inline Int_t  GetRun() const { return head->GetRun(); }
  inline Int_t  GetDate() const { return head->GetDate(); }
  inline Int_t GetSubEvtNumber() const { return head->GetSubEvtNumber();}
  
  ///////////////////
  // Version 1
  void   SetDirtFileName(TString namein);
  void   SetGenieFileName(TString namein);
  void   SetDirtEntryNum(Int_t numin);
  void   SetGenieEntryNum(Int_t numin);
  
  TString GetDirtFileName() const;
  TString GetGenieFileName() const;
  Int_t GetDirtEntryNum() const;
  Int_t GetGenieEntryNum() const;
  
  protected:  // these are the missing members introduced by v1
  TString fDirtFileName="unknown";
  TString fGenieFileName="unknown";
  Int_t   fDirtEntryNum=-1;
  Int_t   fGenieEntryNum=-1;
  ///////////////////
  public:
  
  inline Int_t GetVersion()         const { return head->GetVersion(); }
  inline UInt_t GetCheckSum()        const { return head->GetCheckSum(); }
  inline const WCSimRootEventHeader_v0* GetPtr() const { return head; }
};

#endif
