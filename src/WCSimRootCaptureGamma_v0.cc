// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootCaptureGamma_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootCaptureGamma_v0)
#endif

UInt_t WCSimRootCaptureGamma_v0::GetCheckSum() { return 2914265870; }

//_____________________________________________________________________________

WCSimRootCaptureGamma_v0::WCSimRootCaptureGamma_v0(Int_t id,
                                             Float_t energy,
                                             Float_t *dir) {
    fID = id;
    fEnergy = energy;
    for(int i=0;i<3;i++) fDir[i] = dir[i];
}
