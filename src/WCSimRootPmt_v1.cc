// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootPmt_v1.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootPMT_v1)
#endif

UInt_t WCSimRootPMT_v1::GetCheckSum(){ return 4181452933; }

//______________________________________________________________________________
WCSimRootPMT_v1::WCSimRootPMT_v1(Int_t tubeNo, Int_t cylLoc, Float_t orientation[3], Float_t position[3], std::string PMTType)
{
	fTubeNo = tubeNo;
	fCylLoc = cylLoc;
	fPmtTypeName = PMTType;
	int j = 0;
	for(j = 0; j < 3; j++) {
		fOrientation[j] = orientation[j];
		fPosition[j] = position[j];
	}
	// fOrientation = *(orientation);
	// fPositoin = *(position);
  // Create a WCSimRootPMT object.
}
