// Based on Root test Event.cxx
////////////////////////////////////////////////////////////////////////

#include "WCSimRootGeom_v2.hh"

#ifndef REFLEX_DICTIONARY
ClassImp(WCSimRootGeom_v2)
#endif

UInt_t WCSimRootGeom_v2::GetCheckSum(){ return 4011682905; }

//______________________________________________________________________________
WCSimRootGeom_v2::WCSimRootGeom_v2()
{
  // Create a WCSimRootGeom_v2 object.
  fWCNumPMT = 0;
  fPMTArray = 0;
  fPMTArray = new TClonesArray("WCSimRootPMT_v1", 500);

  fWCNumLAPPD = 0;
  fLAPPDArray = 0;
  fLAPPDArray = new TClonesArray("WCSimRootPMT_v1", 500);

  fWCNumMrdPMT = 0;
  fMRDPMTArray = 0;
  fMRDPMTArray = new TClonesArray("WCSimRootPMT_v1", 500);

  fWCNumFaccPMT = 0;
  fFACCPMTArray = 0;
  fFACCPMTArray = new TClonesArray("WCSimRootPMT_v1", 500);

}

//______________________________________________________________________________
void WCSimRootGeom_v2::SetPMT(Int_t i, Int_t tubeno, Int_t cyl_loc, 
			    Float_t rot[3], Float_t pos[3], std::string PmtType, bool expand)
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
    WCSimRootPMT_v1 *jPMT = new((*pmtArray)[i]) WCSimRootPMT_v1(tubeno, cyl_loc, rot, pos, PmtType);
    //WCSimRootPMT_v1 jPMT = *(WCSimRootPMT_v1*)(*fPMTArray)[i];
    // jPMT.SetTubeNo(tubeno);
    // jPMT.SetCylLoc(cyl_loc);
    // int j;
    // for (j=0;j<3;j++){
    //   jPMT.SetOrientation(j,rot[j]);
    //   jPMT.SetPosition(j,pos[j]);
    // }

}

void WCSimRootGeom_v2::SetLAPPD(Int_t i, Int_t lappdno, Int_t cyl_loc, 
			    Float_t rot[3], Float_t pos[3], std::string PmtType, bool expand)
{
   if(expand) (*(fLAPPDArray)).ExpandCreate(i+2);

  // Set PMT values
   TClonesArray &LAPPDArray = *fLAPPDArray;
   WCSimRootPMT_v1 *jLAPPD = new(LAPPDArray[i]) WCSimRootPMT_v1(lappdno, cyl_loc, rot, pos, PmtType);
    //WCSimRootPMT_v1 jPMT = *(WCSimRootPMT_v1*)(*fPMTArray)[i];
    // jPMT.SetTubeNo(tubeno);
    // jPMT.SetCylLoc(cyl_loc);
    // int j;
    // for (j=0;j<3;j++){
    //   jPMT.SetOrientation(j,rot[j]);
    //   jPMT.SetPosition(j,pos[j]);
    // }

}

