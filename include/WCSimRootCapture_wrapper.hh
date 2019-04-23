#ifndef WCSim_RootCapture_wrapper
#define WCSim_RootCapture_wrapper

//////////////////////////////////////////////////////////////////////////
//                                                                      //
//    WCSim_RootCapture_wrapper                                         //
//                                                                      //
//////////////////////////////////////////////////////////////////////////

#include "WCSimRootCapture_v0.hh"

//////////////////////////////////////////////////////////////////////////

class WCSimRootCapture_wrapper {

private:
WCSimRootCapture_v0* capture=nullptr;

public:
   WCSimRootCapture_wrapper(WCSimRootCapture_v0* capturein) : capture(capturein){};
//   WCSimRootCapture_wrapper(){};

   inline void SetInfo(Float_t captureVtx[3], Float_t captureT, Int_t   captureNucleus)
       { capture->SetInfo(captureVtx, captureT, captureNucleus); }

   inline void AddGamma(Int_t   gammaID, Float_t gammaE, Float_t gammaDir[3])
       { capture->AddGamma(gammaID, gammaE, gammaDir); }

   inline Int_t                   GetCaptureParent()   const { return capture->GetCaptureParent();}
   inline Float_t                 GetCaptureVtx(int i) const { return capture->GetCaptureVtx(i);}
   inline Int_t                   GetNGamma()          const { return capture->GetNGamma();}
   inline Float_t                 GetTotalGammaE()     const { return capture->GetTotalGammaE();}
   inline Float_t                 GetCaptureT()        const { return capture->GetCaptureT();}
   inline Int_t                   GetCaptureNucleus()  const { return capture->GetCaptureNucleus();}
   inline TClonesArray           *GetGammas()          const { return capture->GetGammas();}

   inline Int_t GetVersion()         const { return capture->GetVersion(); }
   inline UInt_t GetCheckSum()        const { return capture->GetCheckSum(); }
   inline const WCSimRootCapture_v0* GetPtr() const { return capture; }
};

////////////////////////////////////////////////////////////////////////////

#endif
