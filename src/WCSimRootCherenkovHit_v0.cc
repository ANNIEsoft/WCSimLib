// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootCherenkovHit_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootCherenkovHit_v0)
#endif

UInt_t WCSimRootCherenkovHit_v0::GetCheckSum(){ return 2966483403; }

//_____________________________________________________________________________

WCSimRootCherenkovHit_v0::WCSimRootCherenkovHit_v0(Int_t tubeID,
					     Int_t totalPe[2])
{
  // Create a WCSimRootCherenkovHit object and fill it with stuff

  fTubeID     = tubeID;
  fTotalPe[0] = totalPe[0];
  fTotalPe[1] = totalPe[1];
}

