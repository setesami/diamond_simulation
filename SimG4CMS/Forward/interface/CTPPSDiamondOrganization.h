// ///////////////////////
// Author Seyed Mohsen Etesami
// //////////////////////////////

#ifndef Forward_CTPPSDiamondOrganization_h
#define Forward_CTPPSDiamondOrganization_h 


#include "globals.hh"
#include "SimG4CMS/Forward/interface/CTPPSDiamondVDetectorOrganization.h"
#include "G4Step.hh"

class CTPPSDiamondOrganization : public CTPPSDiamondVDetectorOrganization
{
 public:
  inline CTPPSDiamondOrganization();
  virtual ~CTPPSDiamondOrganization();

  uint32_t GetUnitID(const G4Step* aStep);
  uint32_t GetUnitID(const G4Step* aStep) const;
};


inline CTPPSDiamondOrganization :: CTPPSDiamondOrganization()
{}

#endif  //Forward_CTPPSDiamondOrganization_h
