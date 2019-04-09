#ifndef WCSim_RootEventHeader_v1
#define WCSim_RootEventHeader_v1

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootEventHeader_v1                                          //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TString.h"
#include "WCSimRootEventHeader_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootEventHeader_v1 : public WCSimRootEventHeader_v0 {

protected:
  
  TString fDirtFileName;
  TString fGenieFileName;
  Int_t   fDirtEntryNum;
  Int_t   fGenieEntryNum;

public:
  WCSimRootEventHeader_v1(){ fEvtNum = 0; fRun = 0; fDate = 0; fSubEvtNumber = 1; }
  virtual ~WCSimRootEventHeader_v1() { }
  
  virtual void   SetDirtFileName(TString namein){ fDirtFileName = namein; }
  virtual void   SetGenieFileName(TString namein){ fGenieFileName = namein; }
  virtual void   SetDirtEntryNum(Int_t numin){ fDirtEntryNum = numin; }
  virtual void   SetGenieEntryNum(Int_t numin){ fGenieEntryNum = numin; }
  
  virtual TString GetDirtFileName() const { return fDirtFileName; }
  virtual TString GetGenieFileName() const { return fGenieFileName; }
  virtual Int_t GetDirtEntryNum() const { return fDirtEntryNum; }
  virtual Int_t GetGenieEntryNum() const { return fGenieEntryNum; }
  
  virtual Int_t GetVersion()         const { return 1; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootEventHeader_v1,2)  //WCSimRootEvent Header
};

#endif
