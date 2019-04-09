#ifndef WCSim_RootGeom_v1
#define WCSim_RootGeom_v1

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootGeom_v1                                                    
//                                                                      
// This class contains information needed to be passed to reconstruction
//     routines.  It's just simple right now-- only the bare-bones  
//     WC info
//////////////////////////////////////////////////////////////////////////

#include <map>
#include "TObject.h"
#include "TClonesArray.h"
#include "WCSimRootPmt_v0.hh"
#include "WCSimRootGeom_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootGeom_v1 : public WCSimRootGeom_v0 {

protected:

  std::vector<Float_t>   fWCPMTRadiusvec; // Vector of tank PMT radii, if more than one type
  std::vector<Int_t>     fWCNumPMTvec; // Vector of number of PMTs of each type, if more than one
  std::map<int, int>     fWCTubeIdvsColIndex; // maps a tubeID (key) to the index in fWCPMTRadiusvec etc.
  std::vector<std::vector<int> > fWCTubeIdsByCollection; // for a collection index (outer) to the TubeIDs in it
  std::vector<std::string> fWCPMTNamevec; // Vector of the PMT names associated with each collection

public:

  WCSimRootGeom_v1() : WCSimRootGeom_v0(){};
  virtual ~WCSimRootGeom_v1(){};

  // Sets and gets

  virtual void  AddPmtRadius(Float_t theradius){fWCPMTRadiusvec.push_back(theradius);}
  virtual void  AddPmtTypeCount(Int_t thenum){fWCNumPMTvec.push_back(thenum);}
  virtual void  AddPmtName(std::string thename){fWCPMTNamevec.push_back(thename);}
  virtual void  SetTubeIdType(int tubeNo, int index){
    fWCTubeIdvsColIndex.emplace(std::make_pair(tubeNo,index));
    if(index>=fWCTubeIdsByCollection.size()){
      fWCTubeIdsByCollection.resize(index+1,std::vector<int>{});
    }
    fWCTubeIdsByCollection.at(index).push_back(tubeNo);
  }
  
  virtual Float_t GetWCPMTRadiusAt(Int_t index){
    if(index>=fWCPMTRadiusvec.size()) return -1;
    return fWCPMTRadiusvec.at(index);
  }
  virtual std::string GetWCPMTNameAt(Int_t index){
    if(index>=fWCPMTNamevec.size()) return "INDEX_OUT_OF_BOUNDS";
    return fWCPMTNamevec.at(index);
  }
  virtual Int_t GetWCNumPMTsAt(Int_t index){
    if(index>=fWCNumPMTvec.size()) return -1;
    return fWCNumPMTvec.at(index);
  }
  virtual Int_t GetTubeIndex(Int_t tubeId){
    if(tubeId>=fWCTubeIdvsColIndex.size()) return -1;
    return fWCTubeIdvsColIndex.at(tubeId);
  }
  virtual std::vector<int> GetTubesInCollection(int collectionindex){
    if(collectionindex>=fWCTubeIdsByCollection.size()) return std::vector<int>{};
    return fWCTubeIdsByCollection.at(collectionindex);
  }

  virtual Int_t GetVersion()         const { return 1; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootGeom_v1,1)  //WCSimRootEvent structure
};


#endif
