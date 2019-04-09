#ifndef WCSim_RootEvent_wrapper
#define WCSim_RootEvent_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootEvent_wrapper                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootEvent_v0.hh"
#include "WCSimRootEvent_v1.hh"
#include "WCSimRootEvent_v2.hh"

//#include "WCSimRootTrigger_wrapper.hh"
class WCSimRootTrigger_wrapper;

//////////////////////////////////////////////////////////////////////////

class WCSimRootEvent_wrapper {
  protected:
  WCSimRootEvent_v0* evt=nullptr;

public:
  WCSimRootEvent_wrapper(WCSimRootEvent_v0* evtin) : evt(evtin){};
//  WCSimRootEvent_wrapper(){};

  inline void          Clear(Option_t *option =""){ evt->Clear(option); }
  inline void   Reset(Option_t *option =""){ evt->Reset(option); }
  inline Int_t GetCurrentIndex() { return evt->GetCurrentIndex(); }

  WCSimRootTrigger_wrapper GetTrigger(int number);
  // ^ must be defined in implementation file to prevent circular dependency
  //  - then the WCSimRootTrigger_wrapper.hh can be included in the implementation file
  // this only works because WCSimRootTrigger_wrapper does not own or contain a
  // WCSimRootEvent_wrapper, otherwise the compiler would need to know the size of a 
  // WCSimRootEvent_wrapper and WCSimRootTrigger_wrapper in a circular manner,
  // and this would be incalculable. Normally this is handed by using pointers or references.

  inline Int_t GetNumberOfEvents() const { return evt->GetNumberOfEvents();}
  inline Int_t GetNumberOfSubEvents() const { return evt->GetNumberOfSubEvents();}
  inline bool HasSubEvents() { return  evt->HasSubEvents(); } 
  inline void AddSubEvent() { evt->AddSubEvent(); }
  inline void Initialize() { evt->Initialize(); }
  inline void ReInitialize() { evt->ReInitialize(); }
  
  // so far no new methods introduced by later versions, only type changes in returns

  inline Int_t GetVersion()         const { return evt->GetVersion(); }
  inline Int_t GetCheckSum()        const { return evt->GetCheckSum(); }
  inline const WCSimRootEvent_v0* GetPtr() const { return evt; }

};


#endif
