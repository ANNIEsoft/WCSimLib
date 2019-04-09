#include "WCSimRootOptions_wrapper.hh"

  /////////////////////////
  // Version 1
  void WCSimRootOptions_wrapper::SetExtendIntegrationWindow(bool iExtendDigitizerIntegrationWindow) {
    WCSimRootOptions_v1* opt1 = dynamic_cast<WCSimRootOptions_v1*>(opt);
    if(opt1){
      opt1->SetExtendIntegrationWindow(iExtendDigitizerIntegrationWindow);
    }
    else { ExtendDigitizerIntegrationWindow = iExtendDigitizerIntegrationWindow; }
  }
  
  bool   WCSimRootOptions_wrapper::GetExtendDigitizerIntegrationWindow() {
    WCSimRootOptions_v1* opt1 = dynamic_cast<WCSimRootOptions_v1*>(opt);
    if(opt1){
      return opt1->GetExtendDigitizerIntegrationWindow();
    }
    else { return ExtendDigitizerIntegrationWindow; }
  }
  
  void WCSimRootOptions_wrapper::SetPromptTriggerEnabled(bool enablePromptTriggerin){
    WCSimRootOptions_v1* opt1 = dynamic_cast<WCSimRootOptions_v1*>(opt);
    if(opt1){
      opt1->SetPromptTriggerEnabled(enablePromptTriggerin);
    }
    else { enablePromptTrigger = enablePromptTriggerin; }
  }
  
  void WCSimRootOptions_wrapper::SetPromptPreTriggerWindow(int promptPreTriggerWindowin){
    WCSimRootOptions_v1* opt1 = dynamic_cast<WCSimRootOptions_v1*>(opt);
    if(opt1){
      opt1->SetPromptPreTriggerWindow(promptPreTriggerWindowin);
    }
    else { promptPreTriggerWindow = promptPreTriggerWindowin; }
  }
  
  void WCSimRootOptions_wrapper::SetPromptPostTriggerWindow(int promptPostTriggerWindowin){
    WCSimRootOptions_v1* opt1 = dynamic_cast<WCSimRootOptions_v1*>(opt);
    if(opt1){
      opt1->SetPromptPostTriggerWindow(promptPostTriggerWindowin);
    }
    else { promptPostTriggerWindow = promptPostTriggerWindowin; }
  }
  
  bool   WCSimRootOptions_wrapper::GetPromptTriggerEnabled(){
    WCSimRootOptions_v1* opt1 = dynamic_cast<WCSimRootOptions_v1*>(opt);
    if(opt1){
      return opt1->GetPromptTriggerEnabled();
    }
    else { return false; }
  }
  
  int    WCSimRootOptions_wrapper::GetPromptPreTriggerWindow(){
    WCSimRootOptions_v1* opt1 = dynamic_cast<WCSimRootOptions_v1*>(opt);
    if(opt1){
      return opt1->GetPromptPreTriggerWindow();
    }
    else { return promptPreTriggerWindow; }
  }
  
  int    WCSimRootOptions_wrapper::GetPromptPostTriggerWindow(){
    WCSimRootOptions_v1* opt1 = dynamic_cast<WCSimRootOptions_v1*>(opt);
    if(opt1){
      return opt1->GetPromptPostTriggerWindow();
    }
    else { return promptPostTriggerWindow; }
  }
  
  ///////////////////////////
  // Version 2
  void WCSimRootOptions_wrapper::SetDoPhotonIntegration(bool iDoPhotonIntegration) {
    WCSimRootOptions_v2* opt2 = dynamic_cast<WCSimRootOptions_v2*>(opt);
    if(opt2){
      opt2->SetDoPhotonIntegration(iDoPhotonIntegration);
    }
    else { DoPhotonIntegration = iDoPhotonIntegration; }
  }
  
  bool   WCSimRootOptions_wrapper::GetDoPhotonIntegration() {
    WCSimRootOptions_v2* opt2 = dynamic_cast<WCSimRootOptions_v2*>(opt);
    if(opt2){
      return opt2->GetDoPhotonIntegration();
    }
    else { return DoPhotonIntegration; }
  }
  
  ////////////////////////////
  // Version 3
  void WCSimRootOptions_wrapper::SetCommitHash(std::string iCommitHash){
    WCSimRootOptions_v3* opt3 = dynamic_cast<WCSimRootOptions_v3*>(opt);
    if(opt3){ opt3->SetCommitHash(iCommitHash); }
    else {CommitHash=iCommitHash; }  // TODO could fill this in
  }
  
  void WCSimRootOptions_wrapper::SetWCSimVersion(double iWCSimVersion){
    WCSimRootOptions_v3* opt3 = dynamic_cast<WCSimRootOptions_v3*>(opt);
    if(opt3){ opt3->SetWCSimVersion(WCSimVersion); }
    else { WCSimVersion=iWCSimVersion; }  // TODO could fill this in
  }
  
  double WCSimRootOptions_wrapper::GetWCSimVersion(){
    WCSimRootOptions_v3* opt3 = dynamic_cast<WCSimRootOptions_v3*>(opt);
    if(opt3){
      return opt3->GetWCSimVersion();
    }
    else { return WCSimVersion;}  // TODO could fill this in
  }
  
  std::string WCSimRootOptions_wrapper::GetCommitHash(){
    WCSimRootOptions_v3* opt3 = dynamic_cast<WCSimRootOptions_v3*>(opt);
    if(opt3){
      return opt3->GetCommitHash();
    }
    else { return CommitHash; }  // TODO could fill this in
  }
