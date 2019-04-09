////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <fstream>

#include "WCSimRootOptions_v3.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootOptions_v3)
#endif

UInt_t WCSimRootOptions_v3::GetCheckSum(){ return 3392166679; }

//______________________________________________________________________________
void WCSimRootOptions_v3::PopulateFileVersion()
{
  // Populate the WCSimVersion and CommitHash members
  
  // Retrieve the WCSimVersion number from file:
  std::string filepath = "WCSimVersion.txt"; // this file stores a double we can compare within code
  WCSimVersion = -1;
  std::ifstream fin(filepath.c_str());
  if(fin.is_open()){
    std::string tempstring;
    std::getline(fin,tempstring);
    WCSimVersion = atof(tempstring.c_str());
    fin.close();
  }
  if(WCSimVersion<0){
    std::cerr<<"Unable to read WCSim version file "<<filepath
          <<", please ensure the file exists and contains the current version number"<<std::endl;
    assert(false);
  }
  
  // we'll also retrieve the git commit hash
  filepath = "CommitHash.txt"; // this file stores the hash of the current commit
  CommitHash = "";
  fin.open(filepath.c_str());
  if(fin.is_open()){
    std::getline(fin,CommitHash);
    fin.close();
  }
  // But requiring the user to keep this file up-to-date is potentially risky.
  // We can try to update this file to the current HEAD straight from the git files.
  // These automatically track the current commit, so are more likely to be up to date.
  // step 1: check if we know where the source files are
  std::string command = "[ -z \"${WCSIMDIR}\" ]";
  int gotsourceloc = system(command.c_str());
  if(not gotsourceloc){
    std::cerr<<"WARNING: WCSIMDIR environmental variable not defined!"
             <<" Cannot check CommitHash is up-to-date!"
             <<" Please export the source files directory to WCSIMDIR"<<std::endl;
  } else {
    // step 2: try to see if we have the git repository and update the file if we do
    //  (it get stripped out before submitting to the grid, so we may not have the git directory)
    command = "cat ${WCSIMDIR}/.git/$(cat ${WCSIMDIR}/.git/HEAD | awk '{ print $2; }') > " + filepath;
    int fileupdated = system(command.c_str());
    // 0 if this worked (i.e. if we could access the file in .git), not 0 otherwise.
    if(fileupdated==0){
      std::cout<<"Updated 'CommitHash.txt' based on current HEAD"<<std::endl;
      // re-read the file with the updated hash
      fin.open(filepath.c_str());
      if(fin.is_open()){
        std::getline(fin,CommitHash);
        fin.close();
      }
    } else {
      //std::cerr<<"Update failed"<<std::endl;
    }
  }
  
  // if either method succeeded, we should have a commit hash now:
  if(CommitHash!=""){
    std::cout<<"Current WCSim commit hash is: "<<CommitHash<<std::endl;
  } else {
    std::cerr<<"Unable to read WCSim commit hash file "<<filepath
          <<", please ensure the file exists and contains the current commit hash"<<std::endl;
    assert(false);
  }
  
  // we could also, for completeness, check if there are any outstanding changes:
  if(gotsourceloc){
    command = "which git >> /dev/null";
    int dont_have_git = system(command.c_str());  // returns 0 if we *do* have git
    if(dont_have_git) return; // can't do anything more without git
    //command  = "(cd ${WCSIMDIR}/ && git diff --exit-code > /dev/null )";
    //int unstaged_changes = system(command.c_str());
    //command  = "(cd ${WCSIMDIR}/ && git diff --cached --exit-code > /dev/null )";
    //int staged_changes = system(command.c_str());
    //command = "(cd ${WCSIMDIR}/ && rm -f gitstatusstring.txt && git status -uno --porcelain > gitstatusstring.txt && [ -s gitstatusstring.txt ] && rm gitstatusstring.txt)";
    command = "(cd ${WCSIMDIR}/ && rm -f gitstatusstring.txt && git diff HEAD > gitstatusstring.txt && if [ -s gitstatusstring.txt ]; then /bin/false; fi )";
    int any_changes = system(command.c_str());
    if(any_changes){
      std::cerr<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! "<<std::endl;
      std::cerr<<"WARNING: THERE ARE UNCOMMITTED CHANGES TO THE SOURCE FILES"<<std::endl;
      std::cerr<<"    WCSimRootOptions_v3::CommitHash WILL NOT BE ACCURATE!"<<std::endl;
      std::cerr<<"       PLEASE COMMIT YOUR CHANGES AND REBUILD"<<std::endl;
      std::cerr<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! "<<std::endl;
    }
  }
}

//______________________________________________________________________________
void WCSimRootOptions_v3::Print(Option_t *) const
{
  std::cout
    << "WCSim version (git commit):"<<CommitHash << std::endl
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
    << "\tExtendDigitizerIntegrationWindow: " << ExtendDigitizerIntegrationWindow << std::endl
    << "Trigger options:" << std::endl
    << "\tTriggerClassName: " << TriggerClassName << std::endl
    << "\tMultiDigitsPerTrigger: " << MultiDigitsPerTrigger << std::endl
    << "NDigits-style trigger options:" << std::endl
    << "\tNDigitsThreshold: " << NDigitsThreshold << " digitized hits" << std::endl
    << "\tNDigitsWindow: " << NDigitsWindow << " ns" << std::endl
    << "\tNDigitsAdjustForNoise: " << NDigitsAdjustForNoise << std::endl
    << "\tNDigitsPreTriggerWindow: " << NDigitsPreTriggerWindow << " ns" << std::endl
    << "\tNDigitsPostTriggerWindow: " << NDigitsPostTriggerWindow << " ns" << std::endl
    << "\tPromptTriggerEnabled: " << enablePromptTrigger << std::endl
    << "\tPromptTriggerWindow: " << promptPostTriggerWindow << " ns" << std::endl
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
