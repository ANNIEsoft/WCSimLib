// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootPi0_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootPi0_v0)
#endif

UInt_t WCSimRootPi0_v0::GetCheckSum(){ return 236184223; }

//_____________________________________________________________________________

void WCSimRootPi0_v0::Set(Float_t pi0Vtx[3], 
			Int_t   gammaID[2], 
			Float_t gammaE[2],
			Float_t gammaVtx[2][3])
{
  for (int i=0;i<2;i++)
  {
    fGammaID[i] = gammaID[i];
    fGammaE[i]  = gammaE[i];
  }

  for (int j=0;j<3;j++)
  {
    fPi0Vtx[j]      = pi0Vtx[j];
    fGammaVtx[0][j] = gammaVtx[0][j];
    fGammaVtx[1][j] = gammaVtx[1][j];
  }
}
