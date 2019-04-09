#ifndef WCSim_RootOptions_wrapper
#define WCSim_RootOptions_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootOptions_wrapper                                            
//                                                                      
// This class contains run option information
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootOptions_v0.hh"
#include "WCSimRootOptions_v1.hh"
#include "WCSimRootOptions_v2.hh"
#include "WCSimRootOptions_v3.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootOptions_wrapper : public TObject {

protected:
  WCSimRootOptions_v0* opt=nullptr;

public:
  WCSimRootOptions_wrapper(WCSimRootOptions_v0* optin) : opt(optin){};
//  WCSimRootOptions_wrapper(){};
  
  inline void Print(Option_t *option = "") const{ opt->Print(option); }

  //WCSimDetector* gets
  inline void SetDetectorName(std::string iDetectorName) { opt->SetDetectorName(iDetectorName); }
  inline void SetSavePi0(bool iSavePi0) { opt->SetSavePi0(iSavePi0); }
  inline void SetPMTQEMethod(bool iPMTQEMethod) { opt->SetPMTQEMethod(iPMTQEMethod); }
  inline void SetPMTCollEff(bool iPMTCollEff) { opt->SetPMTCollEff(iPMTCollEff); }
  //WCSimDetector* sets
  inline std::string GetDetectorName() { return opt->GetDetectorName(); }
  inline bool   GetSavePi0() { return opt->GetSavePi0(); }
  inline int    GetPMTQEMethod() { return opt->GetPMTQEMethod(); }
  inline int    GetPMTCollEff() { return opt->GetPMTCollEff(); }
  //WCSimWCAddDarkNoise sets
  inline void SetPMTDarkRate(double iPMTDarkRate) { opt->SetPMTDarkRate(iPMTDarkRate); }
  inline void SetConvRate(double iConvRate) { opt->SetConvRate(iConvRate); }
  inline void SetDarkHigh(double iDarkHigh) { opt->SetDarkHigh(iDarkHigh); }
  inline void SetDarkLow(double iDarkLow) { opt->SetDarkLow(iDarkLow); }
  inline void SetDarkWindow(double iDarkWindow) { opt->SetDarkWindow(iDarkWindow); }
  inline void SetDarkMode(int iDarkMode) { opt->SetDarkMode(iDarkMode); }
  //WCSimWCAddDarkNoise gets
  inline double GetPMTDarkRate() { return opt->GetPMTDarkRate(); }
  inline double GetConvRate() { return opt->GetConvRate(); }
  inline double GetDarkHigh() { return opt->GetDarkHigh(); }
  inline double GetDarkLow() { return opt->GetDarkLow(); }
  inline double GetDarkWindow() { return opt->GetDarkWindow(); }
  inline int    GetDarkMode() { return opt->GetDarkMode(); }
  //WCSimWCDigitizer* sets
  inline void SetDigitizerClassName(std::string iDigitizerClassName) { opt->SetDigitizerClassName(iDigitizerClassName); }
  inline void SetDigitizerDeadTime(int iDigitizerDeadTime) { opt->SetDigitizerDeadTime(iDigitizerDeadTime); }
  inline void SetDigitizerIntegrationWindow(int iDigitizerIntegrationWindow) { opt->SetDigitizerIntegrationWindow(iDigitizerIntegrationWindow); }
  //WCSimWCDigitizer* gets
  inline std::string GetDigitizerClassName() { return opt->GetDigitizerClassName(); }
  inline int    GetDigitizerDeadTime() { return opt->GetDigitizerDeadTime(); }
  inline int    GetDigitizerIntegrationWindow() { return opt->GetDigitizerIntegrationWindow(); }
  //WCSimWCTrigger* sets
  inline void SetTriggerClassName(std::string itriggerClassName) { opt->SetTriggerClassName(itriggerClassName); };
  inline void SetMultiDigitsPerTrigger(bool imultiDigitsPerTrigger) { opt->SetMultiDigitsPerTrigger(imultiDigitsPerTrigger); };
  //ndigits
  inline void SetNDigitsThreshold(int indigitsThreshold) { opt->SetNDigitsThreshold(indigitsThreshold); };
  inline void SetNDigitsWindow(int indigitsWindow) { opt->SetNDigitsWindow(indigitsWindow); };
  inline void SetNDigitsAdjustForNoise(bool indigitsAdjustForNoise) { opt->SetNDigitsAdjustForNoise(indigitsAdjustForNoise); };
  inline void SetNDigitsPreTriggerWindow(int indigitsPreTriggerWindow) { opt->SetNDigitsPreTriggerWindow(indigitsPreTriggerWindow); };
  inline void SetNDigitsPostTriggerWindow(int indigitsPostTriggerWindow) { opt->SetNDigitsPostTriggerWindow(indigitsPostTriggerWindow); };
  //savefailures
  inline void SetSaveFailuresMode(int isaveFailuresMode) { opt->SetSaveFailuresMode(isaveFailuresMode); };
  inline void SetSaveFailuresTime(double isaveFailuresTime) { opt->SetSaveFailuresTime(isaveFailuresTime); };
  inline void SetSaveFailuresPreTriggerWindow(int isaveFailuresPreTriggerWindow) { opt->SetSaveFailuresPreTriggerWindow(isaveFailuresPreTriggerWindow); };
  inline void SetSaveFailuresPostTriggerWindow(int isaveFailuresPostTriggerWindow) { opt->SetSaveFailuresPostTriggerWindow(isaveFailuresPostTriggerWindow); };
  //WCSimWCTrigger* gets
  inline std::string GetTriggerClassName() { return opt->GetTriggerClassName(); }
  inline bool   GetMultiDigitsPerTrigger() { return opt->GetMultiDigitsPerTrigger(); }
  //ndigits
  inline int    GetNDigitsThreshold() { return opt->GetNDigitsThreshold(); }
  inline int    GetNDigitsWindow() { return opt->GetNDigitsWindow(); }
  inline bool   GetNDigitsAdjustForNoise() { return opt->GetNDigitsAdjustForNoise(); }
  inline int    GetNDigitsPreTriggerWindow() { return opt->GetNDigitsPreTriggerWindow(); }
  inline int    GetNDigitsPostTriggerWindow() { return opt->GetNDigitsPostTriggerWindow(); }
  //savefailures
  inline int    GetSaveFailuresMode() { return opt->GetSaveFailuresMode(); }
  inline double GetSaveFailuresTime() { return opt->GetSaveFailuresTime(); }
  inline int    GetSaveFailuresPreTriggerWindow() { return opt->GetSaveFailuresPreTriggerWindow(); }
  inline int    GetSaveFailuresPostTriggerWindow() { return opt->GetSaveFailuresPostTriggerWindow(); }
  //WCSimTuningParameters sets
  inline void SetRayff(double iRayff) { opt->SetRayff(iRayff); }
  inline void SetBsrff(double iBsrff) { opt->SetBsrff(iBsrff); }
  inline void SetAbwff(double iAbwff) { opt->SetAbwff(iAbwff); }
  inline void SetRgcff(double iRgcff) { opt->SetRgcff(iRgcff); }
  inline void SetMieff(double iMieff) { opt->SetMieff(iMieff); }
  inline void SetTvspacing(double iTvspacing) { opt->SetTvspacing(iTvspacing); }
  inline void SetTopveto(bool iTopveto) { opt->SetTopveto(iTopveto); }
  //WCSimTuningParameters gets
  inline double GetRayff() { return opt->GetRayff(); }
  inline double GetBsrff() { return opt->GetBsrff(); }
  inline double GetAbwff() { return opt->GetAbwff(); }
  inline double GetRgcff() { return opt->GetRgcff(); }
  inline double GetMieff() { return opt->GetMieff(); }
  inline double GetTvspacing() { return opt->GetTvspacing(); }
  inline bool   GetTopveto() { return opt->GetTopveto(); }
  //WCSimPhysicsListFactory sets
  inline void SetPhysicsListName(std::string iPhysicsListName) { opt->SetPhysicsListName(iPhysicsListName); }
  //WCSimPhysicsListFactory gets
  inline std::string GetPhysicsListName() { return opt->GetPhysicsListName(); }
  //WCSimPrimaryGeneratorAction sets
  inline void SetVectorFileName(std::string iVectorFileName) { opt->SetVectorFileName(iVectorFileName); }
  inline void SetGeneratorType(std::string iGeneratorType) { opt->SetGeneratorType(iGeneratorType); }
  //WCSimPrimaryGeneratorAction gets
  inline std::string GetVectorFileName() { return opt->GetVectorFileName(); }
  inline std::string GetGeneratorType() { return opt->GetGeneratorType(); }
  //WCSimRandomParameters sets
  inline void SetRandomSeed(int iRandomSeed) { opt->SetRandomSeed(iRandomSeed); }
  inline void SetRandomGenerator(WCSimRandomGenerator_t iRandomGenerator) { opt->SetRandomGenerator(iRandomGenerator); }
  //WCSimRandomParameters gets
  inline int                    GetRandomSeed() { return opt->GetRandomSeed(); }
  inline WCSimRandomGenerator_t GetRandomGenerator() { return opt->GetRandomGenerator(); }
  
  /////////////////////////
  // Version 1
  void SetExtendIntegrationWindow(bool iExtendDigitizerIntegrationWindow);
  void SetPromptTriggerEnabled(bool enablePromptTriggerin);
  void SetPromptPreTriggerWindow(int promptPreTriggerWindowin);
  void SetPromptPostTriggerWindow(int promptPostTriggerWindowin);
  
  bool   GetExtendDigitizerIntegrationWindow();
  bool   GetPromptTriggerEnabled();
  int    GetPromptPreTriggerWindow();
  int    GetPromptPostTriggerWindow();
  
  protected:
  bool   ExtendDigitizerIntegrationWindow=false;
  bool   enablePromptTrigger=false;
  int    promptPreTriggerWindow=0;  // ns
  int    promptPostTriggerWindow=0; // ns
  
  ///////////////////////////
  // Version 2
  public:
  void SetDoPhotonIntegration(bool iDoPhotonIntegration);
  bool GetDoPhotonIntegration();
  
  protected:
  bool   DoPhotonIntegration=true;
  
  ////////////////////////////
  // Version 3
  public:
  void SetCommitHash(std::string iCommitHash);
  void SetWCSimVersion(double iWCSimVersion);
  double GetWCSimVersion();
  std::string GetCommitHash();
  
  protected:
  //WCSim General
  std::string CommitHash="";  // git tag of this commit
  double WCSimVersion=-1000.0;
  ////////////////////////////

  public:
  inline Int_t GetVersion()         const { return opt->GetVersion(); }
  inline Int_t GetCheckSum()        const { return opt->GetCheckSum(); }
  inline const WCSimRootOptions_v0* GetPtr() const { return opt; }
};


#endif
