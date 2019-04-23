#ifndef WCSim_RootEvent_v0
#define WCSim_RootEvent_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootEvent_v0                                                //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"
#include "WCSimRootTrigger_v0.hh"
#include "TClassRef.h"


  class TObjArray_wrapper : public TObjArray{
    public:
    TObjArray_wrapper(int a, int b) : TObjArray(a,b){};
    TObjArray_wrapper(const TObjArray &a) : TObjArray(a){};
    ClassDef(TObjArray_wrapper,1)
  };
  
//////////////////////////////////////////////////////////////////////////

class WCSimRootEvent_v0 : public TObject {
public:
  WCSimRootEvent_v0();
  virtual ~WCSimRootEvent_v0();

  virtual void          Clear(Option_t *option ="");
  static void   Reset(Option_t *option ="");
  virtual Int_t GetCurrentIndex() { return Current;}

  //  WCSimRootTrigger_v0* GetTrigger(int number) { return fEventList[number];}
  virtual WCSimRootTrigger_v0* GetTrigger(int number) { return (WCSimRootTrigger_v0*) (*fEventList)[number];}

  virtual Int_t GetNumberOfEvents() const { return fEventList->GetEntriesFast();}
  virtual Int_t GetNumberOfSubEvents() const { return (fEventList->GetEntriesFast()-1);}
  virtual bool HasSubEvents() { return  (fEventList->GetEntriesFast() > 1); } 

  //Int_t GetNumberOfEvents() const { return fEventList.size();}
  //Int_t GetNumberOfSubEvents() const { return (fEventList.size()-1);}

  //void AddSubEvent() { fEventList.push_back(new WCSimRootTrigger_v0()); }
  virtual void AddSubEvent() { 
    // be sure not to call the default constructor BUT the actual one
    WCSimRootTrigger_v0* tmp = dynamic_cast<WCSimRootTrigger_v0*>( (*fEventList)[0] );
    int num = tmp->GetHeader()->GetEvtNum();
    ++Current; 
    if ( Current > 9 ) fEventList->Expand(150);
    fEventList->AddAt(new WCSimRootTrigger_v0(num,Current),Current);
  }
  
  /*  void ReInitialize() { // need to remove all subevents at the end, or they just get added anyway...
    std::vector<WCSimRootTrigger_v0*>::iterator  iter = fEventList.begin();
    ++iter; // do not delete the first event --> regular beaviour for this program ?
  */
  virtual void Initialize();

  virtual void ReInitialize() { // need to remove all subevents at the end, or they just get added anyway...
    for ( int i = fEventList->GetLast() ; i>=1 ; i--) {
      //      G4cout << "removing element # " << i << "...";
      WCSimRootTrigger_v0* tmp = 
	dynamic_cast<WCSimRootTrigger_v0*>(fEventList->RemoveAt(i));
      delete tmp;
      //G4cout <<"done !\n";
    }
    Current = 0;
    WCSimRootTrigger_v0* tmp = dynamic_cast<WCSimRootTrigger_v0*>( (*fEventList)[0]);
    tmp->Clear();
  }

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();

protected:
  //std::vector<WCSimRootTrigger_v0*> fEventList;
//  TObjArray* fEventList;
  TObjArray_wrapper *fEventList;
  Int_t Current;                      //!               means transient, not writable to file
  ClassDef(WCSimRootEvent_v0,1)

};


#endif
