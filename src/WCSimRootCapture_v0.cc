// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootCapture_v0.hh"
#include "WCSimRootCaptureGamma_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootCapture_v0)
#endif

UInt_t WCSimRootCapture_v0::GetCheckSum() { return 832885328; }

//_____________________________________________________________________________
WCSimRootCapture_v0::WCSimRootCapture_v0(Int_t captureParent)
{
    fCaptureParent = captureParent;
    fNGamma = 0;
    fTotalGammaE = 0;
    fGammas = new TClonesArray("WCSimRootCaptureGamma_v0", 10);
    IsZombie=false;
}

//_____________________________________________________________________________

WCSimRootCapture_v0::~WCSimRootCapture_v0()
{
    if(!IsZombie) {
        fGammas->Delete();
        delete fGammas;
    }
}

//_____________________________________________________________________________

void WCSimRootCapture_v0::SetInfo(Float_t captureVtx[3],
                               Float_t captureT,
                               Int_t   captureNucleus)
{
    for (int i=0;i<3;i++) fCaptureVtx[i] = captureVtx[i];
    fCaptureT = captureT;
    fCaptureNucleus = captureNucleus;
}

//_____________________________________________________________________________

void WCSimRootCapture_v0::AddGamma(Int_t   gammaID,
                                Float_t gammaE,
                                Float_t gammaDir[3])
{
    TClonesArray &gammas = *fGammas;
    new(gammas[fNGamma]) WCSimRootCaptureGamma_v0(gammaID, gammaE, gammaDir);
    fTotalGammaE += gammaE;
    fNGamma++;
}

