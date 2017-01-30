// ////////////////////////////////
// Author 
// Seyed Mohsen Etesami setesami@cern.ch
///////////////////////////////////

#ifndef CTPPSDiamondVDetectorOrganization_h
#define CTPPSDiamondVDetectorOrganization_h

#include "G4Step.hh"
#include <cstdint>

class CTPPSDiamondVDetectorOrganization {

public:
  CTPPSDiamondVDetectorOrganization(){};
  virtual ~CTPPSDiamondVDetectorOrganization(){};   
  virtual uint32_t GetUnitID(const  G4Step* aStep) const =0;
  virtual uint32_t GetUnitIDCTPPS(const  G4Step* aStep) const =0;

};      


#endif  //CTPPSDiamondVDetectorOrganization_h
