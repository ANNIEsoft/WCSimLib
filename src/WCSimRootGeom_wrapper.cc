#include "WCSimRootGeom_wrapper.hh"

  ///////////////////////
  // Version 1
  Float_t WCSimRootGeom_wrapper::GetWCPMTRadiusAt(Int_t index){
    WCSimRootGeom_v1* geo1 = dynamic_cast<WCSimRootGeom_v1*>(geo);
    if(geo1){
      return geo1->GetWCPMTRadiusAt(index);
    }
    else { return -1000.; }  // TODO could fill this in
  }
  
  std::string WCSimRootGeom_wrapper::GetWCPMTNameAt(Int_t index){
    WCSimRootGeom_v1* geo1 = dynamic_cast<WCSimRootGeom_v1*>(geo);
    if(geo1){
      return geo1->GetWCPMTNameAt(index);
    }
    else { return "unknown"; }  // TODO could fill this in
  }
  
  Int_t WCSimRootGeom_wrapper::GetWCNumPMTsAt(Int_t index){
    WCSimRootGeom_v1* geo1 = dynamic_cast<WCSimRootGeom_v1*>(geo);
    if(geo1){
      return geo1->GetWCNumPMTsAt(index);
    }
    else { return -1000; }  // TODO could fill this in
  }
  
  Int_t WCSimRootGeom_wrapper::GetTubeIndex(Int_t tubeId){
    WCSimRootGeom_v1* geo1 = dynamic_cast<WCSimRootGeom_v1*>(geo);
    if(geo1){
      return geo1->GetTubeIndex(tubeId);
    }
    else { return -1000; }  // TODO could fill this in
  }
  
  std::vector<int> WCSimRootGeom_wrapper::GetTubesInCollection(int collectionindex){
    WCSimRootGeom_v1* geo1 = dynamic_cast<WCSimRootGeom_v1*>(geo);
    if(geo1){
      return geo1->GetTubesInCollection(collectionindex);
    }
    else { return std::vector<int>{}; }  // TODO could fill this in
  }
  ////////////////////////
  // Version 3
  std::vector<std::string> WCSimRootGeom_wrapper::GetPMTNames(){
    WCSimRootGeom_v3* geo3 = dynamic_cast<WCSimRootGeom_v3*>(geo);
    if(geo3){
      return geo3->GetPMTNames();
    }
    else { return std::vector<std::string>{}; }  // TODO could fill this in
  }
  
  std::vector<int> WCSimRootGeom_wrapper::GetWCNumPmts(){
    WCSimRootGeom_v3* geo3 = dynamic_cast<WCSimRootGeom_v3*>(geo);
    if(geo3){
      return geo3->GetWCNumPmts();
    }
    else { return std::vector<int>{}; }  // TODO could fill this in
  }
