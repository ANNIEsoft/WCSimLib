#ifndef WCSim_RootOptions_v3
#define WCSim_RootOptions_v3

//////////////////////////////////////////////////////////////////////////
//                                                                      
// WCSim_RootOptions_v3                                                 
//                                                                      
// This class contains run option information
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"
#include <string>

#include "WCSimEnumerations.hh"
#include "WCSimRootOptions_v2.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootOptions_v3 : public WCSimRootOptions_v2 {

public:

  WCSimRootOptions_v3(){};
  virtual ~WCSimRootOptions_v3(){};
  void Print(Option_t *option = "") const;
  void PopulateFileVersion(); // helper function to populate these members

  //General sets
  virtual void SetCommitHash(std::string iCommitHash){CommitHash=iCommitHash;}
  virtual void SetWCSimVersion(double iWCSimVersion){WCSimVersion=iWCSimVersion;}
  //General gets
  virtual double GetWCSimVersion(){return WCSimVersion;}
  virtual std::string GetCommitHash(){return CommitHash;}
  
  virtual Int_t GetVersion()         const { return 3; }
  static UInt_t GetCheckSum();

protected:
  //WCSim General
  std::string CommitHash;  // git tag of this commit
  double WCSimVersion;
  
  ClassDef(WCSimRootOptions_v3,1)  //WCSimRootEvent structure
};


#endif
