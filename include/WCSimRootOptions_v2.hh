#ifndef WCSim_RootOptions_v2
#define WCSim_RootOptions_v2

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootOptions_v2                                                 
//                                                                      
// This class contains run option information
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include <string>

#include "WCSimEnumerations.hh"
#include "WCSimRootOptions_v1.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootOptions_v2 : public WCSimRootOptions_v1 {

public:

  WCSimRootOptions_v2(){};
  virtual ~WCSimRootOptions_v2(){};
  void Print(Option_t *option = "") const;

  //WCSimWCDigitizer* sets
  virtual void SetDoPhotonIntegration(bool iDoPhotonIntegration) {DoPhotonIntegration = iDoPhotonIntegration;}
  //WCSimWCDigitizer* gets
  virtual bool   GetDoPhotonIntegration() {return DoPhotonIntegration;}
  
  virtual Int_t GetVersion()         const { return 2; }
  static UInt_t GetCheckSum();

protected:
  bool   DoPhotonIntegration;
  
  ClassDef(WCSimRootOptions_v2,1)  //WCSimRootEvent structure
};


#endif
