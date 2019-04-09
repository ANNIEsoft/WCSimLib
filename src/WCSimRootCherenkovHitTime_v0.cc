// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootCherenkovHitTime_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootCherenkovHitTime_v0)
#endif

UInt_t WCSimRootCherenkovHitTime_v0::GetCheckSum(){ return 4155869363; }

//_____________________________________________________________________________

WCSimRootCherenkovHitTime_v0::WCSimRootCherenkovHitTime_v0(Float_t truetime,
						     Int_t primParID)
{
  // Create a WCSimRootCherenkovHitTime object and fill it with stuff
    fTruetime        = truetime; 
    fPrimaryParentID = primParID;
}
