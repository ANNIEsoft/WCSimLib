////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include <iostream>

#include "WCSimRootOptions_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootOptions_v0)
#endif

UInt_t WCSimRootOptions_v0::GetCheckSum(){ return 2966866613; }

//______________________________________________________________________________
void WCSimRootOptions_v0::Print(Option_t *) const
{
  std::cout
    << "Detector construction:" << std::endl
    << "\tDetectorName: " << DetectorName << std::endl
    << "\tSavePi0: " << SavePi0 << std::endl
    << "\tPMTQEMethod: " << PMTQEMethod << std::endl
    << "\tPMTCollEff: " << PMTCollEff << std::endl
    << "Dark Noise options:" << std::endl
    << "\tPMTDarkRate: " << PMTDarkRate << " kHz" << std::endl
    << "\tConvRate: " << ConvRate << " kHz" << std::endl
    << "\tDarkHigh: " << DarkHigh << " ns" << std::endl
    << "\tDarkLow: " << DarkLow << " ns" << std::endl
    << "\tDarkWindow: " << DarkWindow << " ns" << std::endl
    << "\tDarkMode: " << DarkMode << std::endl
    << "Digitizer options:" << std::endl
    << "\tDigitizerClassName: " << DigitizerClassName << std::endl
    << "\tDigitizerDeadTime: " << DigitizerDeadTime << " ns" << std::endl
    << "\tDigitizerIntegrationWindow: " << DigitizerIntegrationWindow << " ns" << std::endl
    << "Trigger options:" << std::endl
    << "\tTriggerClassName: " << TriggerClassName << std::endl
    << "\tMultiDigitsPerTrigger: " << MultiDigitsPerTrigger << std::endl
    << "NDigits-style trigger options:" << std::endl
    << "\tNDigitsThreshold: " << NDigitsThreshold << " digitized hits" << std::endl
    << "\tNDigitsWindow: " << NDigitsWindow << " ns" << std::endl
    << "\tNDigitsAdjustForNoise: " << NDigitsAdjustForNoise << std::endl
    << "\tNDigitsPreTriggerWindow: " << NDigitsPreTriggerWindow << " ns" << std::endl
    << "\tNDigitsPostTriggerWindow: " << NDigitsPostTriggerWindow << " ns" << std::endl
    << "Save failures trigger options:" << std::endl
    << "\tSaveFailuresMode: " << SaveFailuresMode << std::endl
    << "\tSaveFailuresTime: " << SaveFailuresTime << " ns" << std::endl
    << "\tSaveFailuresPreTriggerWindow: " << SaveFailuresPreTriggerWindow << " ns" << std::endl
    << "\tSaveFailuresPostTriggerWindow: " << SaveFailuresPostTriggerWindow << " ns" << std::endl
    << "Tuning parameters:" << std::endl
    << "\tRayff: " << Rayff << std::endl
    << "\tBsrff: " << Bsrff << std::endl
    << "\tAbwff: " << Abwff << std::endl
    << "\tRgcff: " << Rgcff << std::endl
    << "\tMieff: " << Mieff << std::endl
    << "\tTvspacing: " << Tvspacing << std::endl
    << "\tTopveto: " << Topveto << std::endl
    << "Physics List Factory:" << std::endl
    << "\tPhysicsListName: " << PhysicsListName << std::endl
    << "WCSimPrimaryGeneratorAction" << std::endl
    << "\tVectorFileName: " << VectorFileName << std::endl
    << "\tGeneratorType: " << GeneratorType << std::endl
    << "WCSimPrimaryGeneratorAction" << std::endl
    << "\tRandomSeed: " << RandomSeed << std::endl
    << "\tRandomGenerator: " << WCSimEnumerations::EnumAsString(RandomGenerator) << std::endl
    << std::endl;
}
