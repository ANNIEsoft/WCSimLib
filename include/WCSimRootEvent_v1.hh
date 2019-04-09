#ifndef WCSim_RootEvent_v1
#define WCSim_RootEvent_v1

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootEvent_v1                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"
#include "WCSimRootTrigger_v1.hh"
#include "WCSimRootEvent_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootEvent_v1 : public WCSimRootEvent_v0 {
public:
  WCSimRootEvent_v1() : WCSimRootEvent_v0(){};
  virtual ~WCSimRootEvent_v1(){};

  virtual WCSimRootTrigger_v1* GetTrigger(int number) { return (WCSimRootTrigger_v1*) (*fEventList)[number];}
  
  virtual void AddSubEvent() { 
    // be sure not to call the default constructor BUT the actual one
    WCSimRootTrigger_v1* tmp = dynamic_cast<WCSimRootTrigger_v1*>( (*fEventList)[0] );
    int num = tmp->GetHeader()->GetEvtNum();
    ++Current; 
    if ( Current > 9 ) fEventList->Expand(150);
    fEventList->AddAt(new WCSimRootTrigger_v1(num,Current),Current);
  }
  
  virtual void Initialize();

  virtual void ReInitialize() { // need to remove all subevents at the end, or they just get added anyway...
    for ( int i = fEventList->GetLast() ; i>=1 ; i--) {
      //      G4cout << "removing element # " << i << "...";
      WCSimRootTrigger_v1* tmp = 
	dynamic_cast<WCSimRootTrigger_v1*>(fEventList->RemoveAt(i));
      delete tmp;
      //G4cout <<"done !\n";
    }
    Current = 0;
    WCSimRootTrigger_v1* tmp = dynamic_cast<WCSimRootTrigger_v1*>( (*fEventList)[0]);
    tmp->Clear();
  }
  
  virtual Int_t GetVersion()         const { return 1; }
  static UInt_t GetCheckSum();

  protected:
  
  ClassDef(WCSimRootEvent_v1,1)

};


#endif
