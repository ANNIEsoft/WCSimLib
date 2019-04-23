#ifndef WCSim_RootTrigger_wrapper
#define WCSim_RootTrigger_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootTrigger_wrapper                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include <cassert> 

#include "WCSimRootTrigger_v0.hh"
#include "WCSimRootTrigger_v1.hh"
#include "WCSimRootTrigger_v2.hh"

#include "WCSimRootEventHeader_wrapper.hh"
#include "WCSimRootPi0_wrapper.hh"
#include "WCSimRootTrack_wrapper.hh"
#include "WCSimRootCherenkovHit_wrapper.hh"
#include "WCSimRootCherenkovDigiHit_wrapper.hh"
#include "WCSimRootEvent_wrapper.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootTrigger_wrapper {

protected:
  WCSimRootTrigger_v0* trig=nullptr;

public:
  WCSimRootTrigger_wrapper(WCSimRootTrigger_v0* trigin) : trig(trigin){};
//  WCSimRootTrigger_wrapper(){};
  
  inline void Initialize(){ trig->Initialize(); }
  inline void Clear(Option_t *option =""){ trig->Clear(option); }
  inline void   Reset(Option_t *option =""){ trig->Reset(option); }

  inline void          SetHeader(Int_t i, Int_t run, Int_t date,Int_t subevtn=1)
      { trig->SetHeader(i,run,date,subevtn); }
  inline void          SetTriggerInfo(TriggerType_t trigger_type, std::vector<Float_t> trigger_info)
      { trig->SetTriggerInfo(trigger_type, trigger_info); }
  inline bool          IsASubEvent() {  return trig->IsASubEvent(); }
  inline void          SetMode(Int_t i) { trig->SetMode(i);}
  inline void          SetNvtxs(Int_t i) {trig->SetNvtxs(i);}
  inline void          SetVtxvol(Int_t i) {trig->SetVtxvol(i);}
  inline void          SetVtxsvol(Int_t i, Int_t v) {trig->SetVtxsvol(i,v);}
  inline void          SetVtx(Int_t i, Float_t f) {trig->SetVtx(i,f);}
  inline void          SetVtxs(Int_t n, Int_t i, Float_t f) {trig->SetVtxs(n,i,f);}
  inline void          SetVecRecNumber(Int_t i) {trig->SetVecRecNumber(i);}
  inline void          SetJmu(Int_t i) {trig->SetJmu(i);}
  inline void          SetJp(Int_t i) {trig->SetJp(i);}
  inline void          SetNpar(Int_t i) {trig->SetNpar(i);}
  inline void          SetNumTubesHit(Int_t i) {trig->SetNumTubesHit(i);}
  inline void          SetSumQ(Float_t x){trig->SetSumQ(x);}
  inline void          SetNumDigitizedTubes(Int_t i) {trig->SetNumDigitizedTubes(i);}
  inline void          SetPi0Info(Float_t pi0Vtx[3], 
			   Int_t   gammaID[2], 
			   Float_t gammaE[2],
			   Float_t gammaVtx[2][3]){ trig->SetPi0Info(pi0Vtx,gammaID, gammaE, gammaVtx); }


  inline WCSimRootEventHeader_wrapper GetHeader()   {return WCSimRootEventHeader_wrapper(trig->GetHeader());}
  inline WCSimRootPi0_wrapper       GetPi0Info()    {return WCSimRootPi0_wrapper(trig->GetPi0Info());}
  inline Int_t               GetMode()               const {return trig->GetMode();}
  inline Int_t               GetVtxvol()             const {return trig->GetVtxvol();}
  inline Float_t             GetVtx(Int_t i=0)             {return trig->GetVtx(i);}
  inline Int_t               GetNvtxs()              const {return trig->GetNvtxs();}
  inline Int_t               GetVtxsvol(Int_t i)     const {return trig->GetVtxsvol(i);}
  inline Float_t             GetVtxs(Int_t n, Int_t i=0)   {return trig->GetVtxs(n,i);}
  inline Int_t               GetVecRecNumber()       const {return trig->GetVecRecNumber();}
  inline Int_t               GetJmu()                const {return trig->GetJmu();}
  inline Int_t               GetJp()                 const {return trig->GetJp();}
  inline Int_t               GetNpar()               const {return trig->GetNpar();}
  inline Int_t               GetNumTubesHit()        const {return trig->GetNumTubesHit();}
  inline Int_t               GetNumDigiTubesHit()    const {return trig->GetNumDigiTubesHit();}
  inline Int_t               GetNtrack()             const {return trig->GetNtrack(); }
  inline Int_t               GetNcherenkovhits()     const {return trig->GetNcherenkovhits(); }
  inline Int_t               GetNcherenkovhittimes() const {return trig->GetNcherenkovhittimes();}
  inline Int_t               GetNcherenkovdigihits() const {return trig->GetNcherenkovdigihits();}
  inline Float_t             GetSumQ()               const { return trig->GetSumQ();}
  inline TriggerType_t       GetTriggerType()        const { return trig->GetTriggerType();}
  inline std::vector<Float_t> GetTriggerInfo()       const { return trig->GetTriggerInfo();}

  inline WCSimRootTrack_v0         *AddTrack(Int_t ipnu, 
				   Int_t flag, 
				   Float_t m, 
				   Float_t p, 
				   Float_t E, 
				   Int_t startvol, 
				   Int_t stopvol, 
				   Float_t dir[3], 
				   Float_t pdir[3], 
				   Float_t stop[3],
				   Float_t start[3],
				   Int_t parenttype,
				   Float_t time,
				   Int_t id)
  { return trig->AddTrack(ipnu,flag,m,p,E,startvol,stopvol,dir,pdir,stop,start,parenttype,time,id); }

  inline TClonesArray        *GetTracks() const {return trig->GetTracks();}

  inline WCSimRootCherenkovHit_v0   *AddCherenkovHit(Int_t                tubeID,
					  std::vector<Float_t> truetime,
					  std::vector<Int_t>   primParID)
  { return trig->AddCherenkovHit(tubeID,truetime,primParID); }
  inline TClonesArray        *GetCherenkovHits() const {return trig->GetCherenkovHits();}
  inline TClonesArray        *GetCherenkovHitTimes() const {return trig->GetCherenkovHitTimes();}

  inline WCSimRootCherenkovDigiHit_v0   *AddCherenkovDigiHit(Float_t q, 
						   Float_t t, 
						   Int_t tubeid,
						   std::vector<int> photon_ids)
  { return trig->AddCherenkovDigiHit(q,t,tubeid,photon_ids); }

  inline TClonesArray            *GetCherenkovDigiHits() const {return trig->GetCherenkovDigiHits();}
  
  ///////////////////////
  // Version 2  (nothing different in Version 1 but return types)
  void Print(int verbosity=0, int maxprimariestoprint=10, int maxtrackstoprint=10, int maxdigitstoprint=10, int maxphotonsperdigittoprint=5, int maxphotonstoprint=5);
  void          SetParentEvent(WCSimRootEvent_v2* parenteventin);
  void          SetCaptureParticle(Int_t parent,
                                   Int_t ipnu,
                                   Float_t time,
                                   Float_t vtx[3],
                                   Float_t dir[3],
                                   Float_t energy,
                                   Int_t id);
  
  WCSimRootEvent_wrapper   GetParentEvent() const;
  Int_t                    GetNcaptures()   const;
  TClonesArray*            GetCaptures()    const;
  
  protected:
  WCSimRootEvent_v2*         fParentEvent;    //! a link back to the parent, set when trigger is retrieved
  WCSimRootEventHeader_v1    fEvtHdr;         // The header
  TClonesArray        *fCaptures=nullptr;     // Neutron capture info (default = not used)
  Int_t                fNcaptures=-1000;      // Number of tracks in the array
  
  //////////////////////

  public:
  inline Int_t GetVersion()         const { return trig->GetVersion(); }
  inline UInt_t GetCheckSum()        const { return trig->GetCheckSum(); }
  inline const WCSimRootTrigger_v0* GetPtr() const { return trig; }
};

#endif
