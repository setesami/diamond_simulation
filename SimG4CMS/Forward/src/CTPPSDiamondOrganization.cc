// ////////////////////////////////////
// Author Seyed Mohsen Etesami
// //////////////////////////////////////////

#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include "SimG4CMS/Forward/interface/CTPPSDiamondOrganization.h"
#include "DataFormats/PPSDetId/interface/PPSTimingDetId.h"

#include "G4VPhysicalVolume.hh"
#include "G4VTouchable.hh"
#include "G4Step.hh"

#include <iostream>

//******************************************************************** Constructor and destructor
CTPPSDiamondOrganization :: ~CTPPSDiamondOrganization()
{
}


uint32_t CTPPSDiamondOrganization::GetUnitID(const G4Step* aStep) const
{
  return const_cast<CTPPSDiamondOrganization *>(this)->GetUnitID(aStep);
}


uint32_t CTPPSDiamondOrganization::GetUnitID(const G4Step* aStep)
{
  G4VPhysicalVolume* physVol;
//  unsigned int UNITA = 0;
  unsigned int arm = 0;
  unsigned int station = 0;
  unsigned int roman_pot = 0;
  unsigned int detector = 0;
  
  const G4VTouchable* touch = aStep->GetPreStepPoint()->GetTouchable();

  for(int ii = 0; ii < touch->GetHistoryDepth(); ii++ )
  {
    physVol = touch->GetVolume(ii);
    if(physVol->GetName() == "window_box")
//    if(physVol->GetName() == "Lbar")

    {
//      UNITA+=physVol->GetCopyNo();
      detector = physVol->GetCopyNo();
    }
   
// else if(physVol->GetName() == "RP_Cylinder_primary_vacuum") // The physical volume just after Station
 else if(physVol->GetName() =="PPS_timing_box"||physVol->GetName() == "PPS_timing_box_First"||physVol->GetName() == "PPS_timing_box_Second") // The physical volume just after Station

    {
//      UNITA+=10*physVol->GetCopyNo();
      int cpy_no = physVol->GetCopyNo();
      arm = (cpy_no/100)%10;
      station = (cpy_no/10)%10;
      roman_pot = cpy_no%10;

// PPS added
//   147_Left copynum=0,1,2,3,4,5    147_Right copynum=100,101,102,103,104,105
//   215_Left copynum=10    215_Right copynum=110
//   220_Left copynum=20,21,22,23,24,25    220_Right copynum=120,121,122,123,124,125
//  
  }

#ifdef SCRIVI
    edm::LogInfo("TotemRP") << "physVol=" << physVol->GetName()<< ", level=" << ii
	  << ", physVol->GetCopyNo()=" << physVol->GetCopyNo()<< endl;
#endif
  }
   
//std::cout<<"arm: "<<arm<<" station: "<<station<<" romanpot: "<<roman_pot<<" detector: "<<detector<<std::endl;
//std::cout<<"Raw Det ID: "<<PPSTimingDetId(arm, station, roman_pot, detector).rawId()<<std::endl;
//  return UNITA;

  return PPSTimingDetId(arm, station, roman_pot, detector).rawId(); //FIXME
}
