#ifndef WCSim_RootEvent_v2
#define WCSim_RootEvent_v2

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootEvent_v2                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"
#include "WCSimRootTrigger_v2.hh"
#include <iostream>
#include "WCSimRootEvent_v1.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootEvent_v2 : public WCSimRootEvent_v1 {
public:
  WCSimRootEvent_v2() : WCSimRootEvent_v1(){};
  virtual ~WCSimRootEvent_v2(){};

  virtual void Print(int verbosity=0, int maxtriggerstoprint=10, int maxprimariestoprint=10, int maxtrackstoprint=10, int maxdigitstoprint=10, int maxphotonsperdigittoprint=5, int maxphotonstoprint=5);

  //  WCSimRootTrigger_v2* GetTrigger(int number) { return fEventList[number];}
  virtual WCSimRootTrigger_v2* GetTrigger(int number) {
    WCSimRootTrigger_v2* thetrigger = (WCSimRootTrigger_v2*) (*fEventList)[number];
    thetrigger->SetParentEvent(this);
    return thetrigger;
  }

  virtual void AddSubEvent() { 
    // be sure not to call the default constructor BUT the actual one
    WCSimRootTrigger_v2* tmp = dynamic_cast<WCSimRootTrigger_v2*>( (*fEventList)[0] );
    int num = tmp->GetHeader()->GetEvtNum();
    ++Current; 
    if ( Current > 9 ) fEventList->Expand(150);
    fEventList->AddAt(new WCSimRootTrigger_v2(num,Current),Current);
  }
  
  virtual void Initialize();

  virtual void ReInitialize() { // need to remove all subevents at the end, or they just get added anyway...
    for ( int i = fEventList->GetLast() ; i>=1 ; i--) {
      //      G4cout << "removing element # " << i << "...";
      WCSimRootTrigger_v2* tmp = 
	dynamic_cast<WCSimRootTrigger_v2*>(fEventList->RemoveAt(i));
      delete tmp;
      //G4cout <<"done !\n";
    }
    Current = 0;
    WCSimRootTrigger_v2* tmp = dynamic_cast<WCSimRootTrigger_v2*>( (*fEventList)[0]);
    tmp->Clear();
  }
  
  virtual Int_t GetVersion()         const { return 2; }
  static UInt_t GetCheckSum();
  
  protected:
  
  ClassDef(WCSimRootEvent_v2,1)

};


#endif
