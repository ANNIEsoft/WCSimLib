#ifndef WCSim_RootEventHeader_v0
#define WCSim_RootEventHeader_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootEventHeader_v0                                          //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"

//////////////////////////////////////////////////////////////////////////

class WCSimRootEventHeader_v0 {

protected:
  Int_t   fEvtNum;
  Int_t   fRun;
  Int_t   fDate;
  Int_t   fSubEvtNumber;

public:
  WCSimRootEventHeader_v0() : fEvtNum(0), fRun(0), fDate(0), fSubEvtNumber(1) { }
  virtual ~WCSimRootEventHeader_v0() { }
  virtual void   Set(Int_t i, Int_t r, Int_t d, Int_t s=1) { fEvtNum = i; fRun = r; fDate = d; fSubEvtNumber = s;}
  virtual void SetDate(Int_t d) { fDate=d; }
  virtual Int_t  GetEvtNum() const { return fEvtNum; }
  virtual Int_t  GetRun() const { return fRun; }
  virtual Int_t  GetDate() const { return fDate; }
  virtual Int_t GetSubEvtNumber() const { return fSubEvtNumber;}
  
  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootEventHeader_v0,2)  //WCSimRootEvent Header
};

#endif
