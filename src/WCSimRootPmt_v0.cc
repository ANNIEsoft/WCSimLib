// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootPmt_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootPMT_v0)
#endif

UInt_t WCSimRootPMT_v0::GetCheckSum(){ return 549081138; }

//______________________________________________________________________________
WCSimRootPMT_v0::WCSimRootPMT_v0(Int_t tubeNo, Int_t cylLoc, Float_t orientation[3], Float_t position[3])
{
	fTubeNo = tubeNo;
	fCylLoc = cylLoc;
	int j = 0;
	for(j = 0; j < 3; j++) {
		fOrientation[j] = orientation[j];
		fPosition[j] = position[j];
	}
	// fOrientation = *(orientation);
	// fPositoin = *(position);
  // Create a WCSimRootPMT object.
}
