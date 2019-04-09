// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootGeom_v0.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootGeom_v0)
#endif

UInt_t WCSimRootGeom_v0::GetCheckSum(){ return 4011682905; }

//______________________________________________________________________________
WCSimRootGeom_v0::WCSimRootGeom_v0()
{
  // Create a WCSimRootGeom object.
  fWCNumPMT = 0;
  fPMTArray = 0;
  fPMTArray = new TClonesArray("WCSimRootPMT_v0", 500);

  fWCNumLAPPD = 0;
  fLAPPDArray = 0;
  fLAPPDArray = new TClonesArray("WCSimRootPMT_v0", 500);

  fWCNumMrdPMT = 0;
  fMRDPMTArray = 0;
  fMRDPMTArray = new TClonesArray("WCSimRootPMT_v0", 500);

  fWCNumFaccPMT = 0;
  fFACCPMTArray = 0;
  fFACCPMTArray = new TClonesArray("WCSimRootPMT_v0", 500);

}

//______________________________________________________________________________
WCSimRootGeom_v0::~WCSimRootGeom_v0()
{
  fPMTArray->Delete();
  delete fPMTArray;
  delete fLAPPDArray;
  delete fMRDPMTArray;
  delete fFACCPMTArray;
}

//______________________________________________________________________________
void WCSimRootGeom_v0::SetPMT(Int_t i, Int_t tubeno, Int_t cyl_loc, 
			    Float_t rot[3], Float_t pos[3], bool expand)
{
   TClonesArray* pmtArray;
   if (cyl_loc==4){ //mrd
     pmtArray = fMRDPMTArray;
   } else if (cyl_loc==5){ //facc
     pmtArray = fFACCPMTArray;
   } else {
     pmtArray = fPMTArray;
   }
   if(expand) pmtArray->ExpandCreate(i+2);

  // Set PMT values
  // TClonesArray &pmtArray = *fPMTArray;
    WCSimRootPMT_v0 *jPMT = new((*pmtArray)[i]) WCSimRootPMT_v0(tubeno, cyl_loc, rot, pos);
    //WCSimRootPMT_v0 jPMT = *(WCSimRootPMT_v0*)(*fPMTArray)[i];
    // jPMT.SetTubeNo(tubeno);
    // jPMT.SetCylLoc(cyl_loc);
    // int j;
    // for (j=0;j<3;j++){
    //   jPMT.SetOrientation(j,rot[j]);
    //   jPMT.SetPosition(j,pos[j]);
    // }

}

void WCSimRootGeom_v0::SetLAPPD(Int_t i, Int_t lappdno, Int_t cyl_loc, 
			    Float_t rot[3], Float_t pos[3], bool expand)
{
   if(expand) (*(fLAPPDArray)).ExpandCreate(i+2);

  // Set PMT values
   TClonesArray &LAPPDArray = *fLAPPDArray;
   WCSimRootPMT_v0 *jLAPPD = new(LAPPDArray[i]) WCSimRootPMT_v0(lappdno, cyl_loc, rot, pos);
    //WCSimRootPMT_v0 jPMT = *(WCSimRootPMT_v0*)(*fPMTArray)[i];
    // jPMT.SetTubeNo(tubeno);
    // jPMT.SetCylLoc(cyl_loc);
    // int j;
    // for (j=0;j<3;j++){
    //   jPMT.SetOrientation(j,rot[j]);
    //   jPMT.SetPosition(j,pos[j]);
    // }

}

