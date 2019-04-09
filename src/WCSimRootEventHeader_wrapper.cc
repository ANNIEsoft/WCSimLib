#include "WCSimRootEventHeader_wrapper.hh"

  ///////////////////
  // Version 1
  void   WCSimRootEventHeader_wrapper::SetDirtFileName(TString namein){
    WCSimRootEventHeader_v1* head1 = dynamic_cast<WCSimRootEventHeader_v1*>(head);
    if(head1){
      head1->SetDirtFileName(namein);
    }
    else { fDirtFileName = namein; }
  }
  
  void   WCSimRootEventHeader_wrapper::SetGenieFileName(TString namein){
    WCSimRootEventHeader_v1* head1 = dynamic_cast<WCSimRootEventHeader_v1*>(head);
    if(head1){
      head1->SetGenieFileName(namein);
    }
    else { fGenieFileName = namein; }
  }
  
  void   WCSimRootEventHeader_wrapper::SetDirtEntryNum(Int_t numin){
    WCSimRootEventHeader_v1* head1 = dynamic_cast<WCSimRootEventHeader_v1*>(head);
    if(head1){
      head1->SetDirtEntryNum(numin);
    }
    else { fDirtEntryNum = numin; }
  }
  
  void   WCSimRootEventHeader_wrapper::SetGenieEntryNum(Int_t numin){
    WCSimRootEventHeader_v1* head1 = dynamic_cast<WCSimRootEventHeader_v1*>(head);
    if(head1){
      head1->SetGenieEntryNum(numin);
    }
    else { fGenieEntryNum = numin; }
  }
  
  TString WCSimRootEventHeader_wrapper::GetDirtFileName() const {
    WCSimRootEventHeader_v1* head1 = dynamic_cast<WCSimRootEventHeader_v1*>(head);
    if(head1){
      return head1->GetDirtFileName();
    }
    else { return fDirtFileName; }
  }
  
  TString WCSimRootEventHeader_wrapper::GetGenieFileName() const {
    WCSimRootEventHeader_v1* head1 = dynamic_cast<WCSimRootEventHeader_v1*>(head);
    if(head1){
      return head1->GetGenieFileName();
    }
    else { return fGenieFileName; }
  }
  
  Int_t WCSimRootEventHeader_wrapper::GetDirtEntryNum() const {
    WCSimRootEventHeader_v1* head1 = dynamic_cast<WCSimRootEventHeader_v1*>(head);
    if(head1){
      return head1->GetDirtEntryNum();
    }
    else { return fDirtEntryNum; }
  }
  
  Int_t WCSimRootEventHeader_wrapper::GetGenieEntryNum() const {
    WCSimRootEventHeader_v1* head1 = dynamic_cast<WCSimRootEventHeader_v1*>(head);
    if(head1){
      return head1->GetGenieEntryNum();
    }
    else { return fGenieEntryNum; }
  }
