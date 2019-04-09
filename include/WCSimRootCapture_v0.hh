#ifndef WCSim_RootCapture_v0
#define WCSim_RootCapture_v0

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCapture_v0                                              //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "TObject.h"
#include "TClonesArray.h"

//////////////////////////////////////////////////////////////////////////

class WCSimRootCapture_v0 : public TObject {
// this is a class used specifically for neutron capture events

protected:
   Int_t          fCaptureParent;
   Float_t        fCaptureVtx[3];
   Int_t          fNGamma;
   Float_t        fTotalGammaE;
   Float_t        fCaptureT;
   Int_t          fCaptureNucleus;
   TClonesArray * fGammas;
   bool           IsZombie;

public:
   WCSimRootCapture_v0() {
             fGammas = 0;
             IsZombie = true;
           }
   WCSimRootCapture_v0(Int_t captureParent);

   virtual ~WCSimRootCapture_v0();

   virtual void SetInfo(Float_t captureVtx[3],
                Float_t captureT,
                Int_t   captureNucleus
   );

   virtual void AddGamma(Int_t   gammaID,
                 Float_t gammaE,
                 Float_t gammaDir[3]
   );

   virtual Int_t                   GetCaptureParent()   const { return fCaptureParent;}
   virtual Float_t                 GetCaptureVtx(int i) const { return (i<3) ? fCaptureVtx[i]: 0;}
   virtual Int_t                   GetNGamma()          const { return fNGamma;}
   virtual Float_t                 GetTotalGammaE()     const { return fTotalGammaE;}
   virtual Float_t                 GetCaptureT()        const { return fCaptureT;}
   virtual Int_t                   GetCaptureNucleus()  const { return fCaptureNucleus;}
   virtual TClonesArray           *GetGammas()          const { return fGammas;}

  virtual Int_t GetVersion()         const { return 0; }
  static UInt_t GetCheckSum();
  ClassDef(WCSimRootCapture_v0,1)
};

////////////////////////////////////////////////////////////////////////////

#endif
