#ifndef WCSim_RootOptions_v1
#define WCSim_RootOptions_v1

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootOptions_v1                                                 
//                                                                      
// This class contains run option information
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include <string>

#include "WCSimEnumerations.hh"
#include "WCSimRootOptions_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootOptions_v1 : public WCSimRootOptions_v0 {

public:

  WCSimRootOptions_v1(){};
  virtual ~WCSimRootOptions_v1(){};
  virtual void Print(Option_t *option = "") const;

  //WCSimWCDigitizer* sets
  virtual void SetExtendIntegrationWindow(bool iExtendDigitizerIntegrationWindow) {ExtendDigitizerIntegrationWindow = iExtendDigitizerIntegrationWindow;}
  //WCSimWCDigitizer* gets
  virtual bool   GetExtendDigitizerIntegrationWindow() {return ExtendDigitizerIntegrationWindow;}
  //WCSimWCTrigger* sets
  virtual void SetPromptTriggerEnabled(bool enablePromptTriggerin){ enablePromptTrigger = enablePromptTriggerin;}
  virtual void SetPromptPreTriggerWindow(int promptPreTriggerWindowin){ promptPreTriggerWindow = promptPreTriggerWindowin;}
  virtual void SetPromptPostTriggerWindow(int promptPostTriggerWindowin){ promptPostTriggerWindow = promptPostTriggerWindowin;}
  //WCSimWCTrigger* gets
  virtual bool   GetPromptTriggerEnabled(){ return enablePromptTrigger;}
  virtual int    GetPromptPreTriggerWindow(){ return promptPreTriggerWindow;}
  virtual int    GetPromptPostTriggerWindow(){ return promptPostTriggerWindow;}

  virtual Int_t GetVersion()         const { return 1; }
  static UInt_t GetCheckSum();

protected:
  bool   ExtendDigitizerIntegrationWindow;
  //prompt
  bool   enablePromptTrigger;
  int    promptPreTriggerWindow;  // ns
  int    promptPostTriggerWindow; // ns

  ClassDef(WCSimRootOptions_v1,1)  //WCSimRootEvent structure
};


#endif
