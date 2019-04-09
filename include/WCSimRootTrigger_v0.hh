#ifndef WCSim_RootTrigger_v0
#define WCSim_RootTrigger_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootTrigger_v0                                              //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"
#include <vector>
#include "jhfNtuple.h"

#include "WCSimEnumerations.hh"
#include "WCSimRootEventHeader_v0.hh"
#include "WCSimRootPi0_v0.hh"
#include "WCSimRootTrack_v0.hh"
#include "WCSimRootCherenkovHit_v0.hh"
#include "WCSimRootCherenkovDigiHit_v0.hh"
#include "WCSimRootCherenkovHitTime_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootTrigger_v0 : public TObject {

protected:
  WCSimRootEventHeader_v0    fEvtHdr;  // The header
  // See jhfNtuple.h for the meaning of these data members:
  Int_t                fMode;
  Int_t                fNvtxs;
  Int_t                fVtxsvol[MAX_N_PRIMARIES];
  Float_t              fVtxs[MAX_N_PRIMARIES][3];
  Int_t                fVecRecNumber;       // "info event" number in inputvectorfile 
  Int_t                fJmu;
  Int_t                fJp;

  WCSimRootPi0_v0        fPi0;                // Pi0 info (default = not used)

  Int_t                fNpar;               // Number of particles
  Int_t                fNtrack;             // Number of tracks in the array
  TClonesArray         *fTracks;            //-> Array of WCSimRootTracks 

  Int_t                fNumTubesHit;        // Number of tubes hit
  Int_t                fNcherenkovhits;      // Number of hits in the array
  TClonesArray         *fCherenkovHits;      //-> Array of WCSimRootCherenkovHits

  Int_t                fCherenkovHitCounter;
  Int_t                fNcherenkovhittimes;      // Number of hits in the array
  TClonesArray         *fCherenkovHitTimes;      //-> Array of WCSimRootCherenkovHits

  Int_t                fNumDigitizedTubes;  // Number of digitized tubes
  Int_t                fNcherenkovdigihits;  // Number of digihits in the array
  Float_t              fSumQ;
  TClonesArray         *fCherenkovDigiHits;  //-> Array of WCSimRootCherenkovDigiHit's

  TriggerType_t        fTriggerType;         // Trigger algorithm that created this trigger
  std::vector<Float_t> fTriggerInfo;         // Information about how it passed the trigger (e.g. how many hits in the NDigits window)

  bool IsZombie;

public:
  WCSimRootTrigger_v0();
  WCSimRootTrigger_v0(int, int);
  virtual ~WCSimRootTrigger_v0();
  
  virtual void Initialize();

  virtual void          Clear(Option_t *option ="");
  static void   Reset(Option_t *option ="");

  virtual void          SetHeader(Int_t i, Int_t run, Int_t date,Int_t subevtn=1);
  virtual void          SetTriggerInfo(TriggerType_t trigger_type, std::vector<Float_t> trigger_info);
  virtual bool          IsASubEvent() {  return (fEvtHdr.GetSubEvtNumber()>=1); }
  virtual void          SetMode(Int_t i) {fMode = i;}
  virtual void          SetNvtxs(Int_t i) {fNvtxs = i;}
  virtual void          SetVtxvol(Int_t i) {fVtxsvol[0] = i;}
  virtual void          SetVtxsvol(Int_t i, Int_t v) {fVtxsvol[i] = v;}
  virtual void          SetVtx(Int_t i, Float_t f) {fNvtxs=1; fVtxs[0][i] = ( (i<3) ? f : 0);}
  virtual void          SetVtxs(Int_t n, Int_t i, Float_t f) {fVtxs[n][i]= ( (i<3) ? f : 0);}
  virtual void          SetVecRecNumber(Int_t i) {fVecRecNumber = i;}
  virtual void          SetJmu(Int_t i) {fJmu = i;}
  virtual void          SetJp(Int_t i) {fJp = i;}
  virtual void          SetNpar(Int_t i) {fNpar = i;}
  virtual void          SetNumTubesHit(Int_t i) {fNumTubesHit = i;}
  virtual void          SetSumQ(Float_t x){fSumQ = x;}
  virtual void          SetNumDigitizedTubes(Int_t i) {fNumDigitizedTubes = i;}
  virtual void          SetPi0Info(Float_t pi0Vtx[3], 
			   Int_t   gammaID[2], 
			   Float_t gammaE[2],
			   Float_t gammaVtx[2][3]);


  virtual WCSimRootEventHeader_v0 *GetHeader()               {return &fEvtHdr; }
  virtual WCSimRootPi0_v0       *GetPi0Info()                 {return &fPi0; }
  virtual Int_t               GetMode()               const {return fMode;}
  virtual Int_t               GetVtxvol()             const {return fVtxsvol[0];}
  virtual Float_t             GetVtx(Int_t i=0)             {return (i<3) ? fVtxs[0][i]: 0;}
  virtual Int_t               GetNvtxs()             const {return fNvtxs;}
  virtual Int_t               GetVtxsvol(Int_t i)             const {return fVtxsvol[i];}
  virtual Float_t             GetVtxs(Int_t n, Int_t i=0)             {return (i<3) ? fVtxs[n][i]: 0;}
  virtual Int_t               GetVecRecNumber()       const {return fVecRecNumber;}
  virtual Int_t               GetJmu()                const {return fJmu;}
  virtual Int_t               GetJp()                 const {return fJp;}
  virtual Int_t               GetNpar()               const {return fNpar;}
  virtual Int_t               GetNumTubesHit()        const {return fNumTubesHit;}
  virtual Int_t               GetNumDigiTubesHit()    const {return fNumDigitizedTubes;}
  virtual Int_t               GetNtrack()             const {return fNtrack; }
  virtual Int_t               GetNcherenkovhits()     const {return fNcherenkovhits; }
  virtual Int_t               GetNcherenkovhittimes() const {return fNcherenkovhittimes;}
  virtual Int_t               GetNcherenkovdigihits() const {return fNcherenkovdigihits;}
  virtual Float_t             GetSumQ()               const { return fSumQ;}
  virtual TriggerType_t       GetTriggerType()        const { return fTriggerType;}
  virtual std::vector<Float_t> GetTriggerInfo()        const { return fTriggerInfo;}

  virtual WCSimRootTrack_v0         *AddTrack(Int_t ipnu, 
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
				   Int_t id);

  virtual TClonesArray        *GetTracks() const {return fTracks;}

  virtual WCSimRootCherenkovHit_v0   *AddCherenkovHit(Int_t                tubeID,
					  std::vector<Float_t> truetime,
					  std::vector<Int_t>   primParID);
  virtual TClonesArray        *GetCherenkovHits() const {return fCherenkovHits;}
  virtual TClonesArray        *GetCherenkovHitTimes() const {return fCherenkovHitTimes;}

  virtual WCSimRootCherenkovDigiHit_v0   *AddCherenkovDigiHit(Float_t q, 
						   Float_t t, 
						   Int_t tubeid,
						   std::vector<int> photon_ids);
//  WCSimRootCherenkovDigiHit_v0   *AddCherenkovDigiHit(Float_t q, 
//						  Float_t t, 
//						  Int_t tubeid,
 //                                                 Float_t sumq);

  virtual TClonesArray            *GetCherenkovDigiHits() const {return fCherenkovDigiHits;}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootTrigger_v0,2) //WCSimRootEvent structure
};

#endif
