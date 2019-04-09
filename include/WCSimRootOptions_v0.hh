#ifndef WCSim_RootOptions_v0
#define WCSim_RootOptions_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootOptions_v0                                                 
//                                                                      
// This class contains run option information
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include <string>

#include "WCSimEnumerations.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootOptions_v0 : public TObject {

public:

  WCSimRootOptions_v0(){};
  virtual ~WCSimRootOptions_v0(){};
  virtual void Print(Option_t *option = "") const;

  //WCSimDetector* gets
  virtual void SetDetectorName(std::string iDetectorName) {DetectorName = iDetectorName;}
  virtual void SetSavePi0(bool iSavePi0) {SavePi0 = iSavePi0;}
  virtual void SetPMTQEMethod(bool iPMTQEMethod) {PMTQEMethod = iPMTQEMethod;}
  virtual void SetPMTCollEff(bool iPMTCollEff) {PMTCollEff = iPMTCollEff;}
  //WCSimDetector* sets
  virtual std::string GetDetectorName() {return DetectorName;}
  virtual bool   GetSavePi0() {return SavePi0;}
  virtual int    GetPMTQEMethod() {return PMTQEMethod;}
  virtual int    GetPMTCollEff() {return PMTCollEff;}
  //WCSimWCAddDarkNoise sets
  virtual void SetPMTDarkRate(double iPMTDarkRate) {PMTDarkRate = iPMTDarkRate;}
  virtual void SetConvRate(double iConvRate) {ConvRate = iConvRate;}
  virtual void SetDarkHigh(double iDarkHigh) {DarkHigh = iDarkHigh;}
  virtual void SetDarkLow(double iDarkLow) {DarkLow = iDarkLow;}
  virtual void SetDarkWindow(double iDarkWindow) {DarkWindow = iDarkWindow;}
  virtual void SetDarkMode(int iDarkMode) {DarkMode = iDarkMode;}
  //WCSimWCAddDarkNoise gets
  virtual double GetPMTDarkRate() {return PMTDarkRate;}
  virtual double GetConvRate() {return ConvRate;}
  virtual double GetDarkHigh() {return DarkHigh;}
  virtual double GetDarkLow() {return DarkLow;}
  virtual double GetDarkWindow() {return DarkWindow;}
  virtual int    GetDarkMode() {return DarkMode;}
  //WCSimWCDigitizer* sets
  virtual void SetDigitizerClassName(std::string iDigitizerClassName) {DigitizerClassName = iDigitizerClassName;}
  virtual void SetDigitizerDeadTime(int iDigitizerDeadTime) {DigitizerDeadTime = iDigitizerDeadTime;}
  virtual void SetDigitizerIntegrationWindow(int iDigitizerIntegrationWindow) {DigitizerIntegrationWindow = iDigitizerIntegrationWindow;}
  //WCSimWCDigitizer* gets
  virtual std::string GetDigitizerClassName() {return DigitizerClassName;}
  virtual int    GetDigitizerDeadTime() {return DigitizerDeadTime;}
  virtual int    GetDigitizerIntegrationWindow() {return DigitizerIntegrationWindow;}
  //WCSimWCTrigger* sets
  virtual void SetTriggerClassName(std::string itriggerClassName) {TriggerClassName = itriggerClassName;};
  virtual void SetMultiDigitsPerTrigger(bool imultiDigitsPerTrigger) {MultiDigitsPerTrigger = imultiDigitsPerTrigger;};
  //ndigits
  virtual void SetNDigitsThreshold(int indigitsThreshold) {NDigitsThreshold = indigitsThreshold;};
  virtual void SetNDigitsWindow(int indigitsWindow) {NDigitsWindow = indigitsWindow;};
  virtual void SetNDigitsAdjustForNoise(bool indigitsAdjustForNoise) {NDigitsAdjustForNoise = indigitsAdjustForNoise;};
  virtual void SetNDigitsPreTriggerWindow(int indigitsPreTriggerWindow) {NDigitsPreTriggerWindow = indigitsPreTriggerWindow;};
  virtual void SetNDigitsPostTriggerWindow(int indigitsPostTriggerWindow) {NDigitsPostTriggerWindow = indigitsPostTriggerWindow;};
  //savefailures
  virtual void SetSaveFailuresMode(int isaveFailuresMode) {SaveFailuresMode = isaveFailuresMode;};
  virtual void SetSaveFailuresTime(double isaveFailuresTime) {SaveFailuresTime = isaveFailuresTime;};
  virtual void SetSaveFailuresPreTriggerWindow(int isaveFailuresPreTriggerWindow) {SaveFailuresPreTriggerWindow = isaveFailuresPreTriggerWindow;};
  virtual void SetSaveFailuresPostTriggerWindow(int isaveFailuresPostTriggerWindow) {SaveFailuresPostTriggerWindow = isaveFailuresPostTriggerWindow;};
  //WCSimWCTrigger* gets
  virtual std::string GetTriggerClassName() {return TriggerClassName;}
  virtual bool   GetMultiDigitsPerTrigger() {return MultiDigitsPerTrigger;}
  //ndigits
  virtual int    GetNDigitsThreshold() {return NDigitsThreshold;}
  virtual int    GetNDigitsWindow() {return NDigitsWindow;}
  virtual bool   GetNDigitsAdjustForNoise() {return NDigitsAdjustForNoise;}
  virtual int    GetNDigitsPreTriggerWindow() {return NDigitsPreTriggerWindow;}
  virtual int    GetNDigitsPostTriggerWindow() {return NDigitsPostTriggerWindow;}
  //savefailures
  virtual int    GetSaveFailuresMode() {return SaveFailuresMode;}
  virtual double GetSaveFailuresTime() {return SaveFailuresTime;}
  virtual int    GetSaveFailuresPreTriggerWindow() {return SaveFailuresPreTriggerWindow;}
  virtual int    GetSaveFailuresPostTriggerWindow() {return SaveFailuresPostTriggerWindow;}
  //WCSimTuningParameters sets
  virtual void SetRayff(double iRayff) {Rayff = iRayff;}
  virtual void SetBsrff(double iBsrff) {Bsrff = iBsrff;}
  virtual void SetAbwff(double iAbwff) {Abwff = iAbwff;}
  virtual void SetRgcff(double iRgcff) {Rgcff = iRgcff;}
  virtual void SetMieff(double iMieff) {Mieff = iMieff;}
  virtual void SetTvspacing(double iTvspacing) {Tvspacing = iTvspacing;}
  virtual void SetTopveto(bool iTopveto) {Topveto = iTopveto;}
  //WCSimTuningParameters gets
  virtual double GetRayff() {return Rayff;}
  virtual double GetBsrff() {return Bsrff;}
  virtual double GetAbwff() {return Abwff;}
  virtual double GetRgcff() {return Rgcff;}
  virtual double GetMieff() {return Mieff;}
  virtual double GetTvspacing() {return Tvspacing;}
  virtual bool   GetTopveto() {return Topveto;}
  //WCSimPhysicsListFactory sets
  virtual void SetPhysicsListName(std::string iPhysicsListName) {PhysicsListName = iPhysicsListName;}
  //WCSimPhysicsListFactory gets
  virtual std::string GetPhysicsListName() {return PhysicsListName;}
  //WCSimPrimaryGeneratorAction sets
  virtual void SetVectorFileName(std::string iVectorFileName) {VectorFileName = iVectorFileName;}
  virtual void SetGeneratorType(std::string iGeneratorType) {GeneratorType = iGeneratorType;}
  //WCSimPrimaryGeneratorAction gets
  virtual std::string GetVectorFileName() {return VectorFileName;}
  virtual std::string GetGeneratorType() {return GeneratorType;}
  //WCSimRandomParameters sets
  virtual void SetRandomSeed(int iRandomSeed) {RandomSeed = iRandomSeed;}
  virtual void SetRandomGenerator(WCSimRandomGenerator_t iRandomGenerator) {RandomGenerator = iRandomGenerator;}
  //WCSimRandomParameters gets
  virtual int                    GetRandomSeed() {return RandomSeed;}
  virtual WCSimRandomGenerator_t GetRandomGenerator() {return RandomGenerator;}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();

protected:
  //WCSimDetector*
  std::string DetectorName;
  bool   SavePi0;
  int    PMTQEMethod;
  int    PMTCollEff;
  
  //WCSimWCAddDarkNoise
  double PMTDarkRate; // kHz
  double ConvRate; // kHz
  double DarkHigh; // ns
  double DarkLow; // ns
  double DarkWindow; // ns
  int    DarkMode;

  //WCSimWCDigitizer*
  std::string DigitizerClassName;
  int    DigitizerDeadTime; // ns
  int    DigitizerIntegrationWindow; // ns

  //WCSimWCTrigger*
  std::string TriggerClassName;
  bool   MultiDigitsPerTrigger;
  //ndigits
  int    NDigitsThreshold; // digitized hits
  int    NDigitsWindow; // ns
  bool   NDigitsAdjustForNoise;
  int    NDigitsPreTriggerWindow; // ns
  int    NDigitsPostTriggerWindow; // ns
  //savefailures
  int    SaveFailuresMode;
  double SaveFailuresTime; // ns
  int    SaveFailuresPreTriggerWindow; // ns
  int    SaveFailuresPostTriggerWindow; // ns

  //WCSimTuningParameters
  double Rayff;
  double Bsrff;
  double Abwff;
  double Rgcff;
  double Mieff;
  double Tvspacing;
  bool   Topveto;

  //WCSimPhysicsListFactory
  std::string PhysicsListName;

  //WCSimPrimaryGeneratorAction
  std::string VectorFileName;
  std::string GeneratorType;

  //WCSimRandomParameters
  int                    RandomSeed;
  WCSimRandomGenerator_t RandomGenerator;
  
  ClassDef(WCSimRootOptions_v0,1)  //WCSimRootEvent structure
};


#endif
