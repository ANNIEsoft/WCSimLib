// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootCherenkovDigiHit_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootCherenkovDigiHit_v0)
#endif

UInt_t WCSimRootCherenkovDigiHit_v0::GetCheckSum() { return 207338431; }

//_____________________________________________________________________________

WCSimRootCherenkovDigiHit_v0::WCSimRootCherenkovDigiHit_v0(Float_t q, 
						     Float_t t, 
						     Int_t tubeid,
						     std::vector<int> photon_ids)
{
  // Create a WCSimRootCherenkovDigiHit object and fill it with stuff

  fQ = q;
  fT = t;
  fTubeId = tubeid;
  fPhotonIds = photon_ids;
}
