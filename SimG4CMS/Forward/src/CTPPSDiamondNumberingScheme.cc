// //////////////////////
// Author Seyed Mohsen Etesami setesami@cern.ch
// ////////////////////////////

#include "SimG4CMS/Forward/interface/CTPPSDiamondNumberingScheme.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

#include <iostream>
// #define debug

CTPPSDiamondNumberingScheme::CTPPSDiamondNumberingScheme(int i)
{
  edm::LogInfo("Diamond") << " Creating CTPPSDiamondNumberingScheme" << std::endl;
}

CTPPSDiamondNumberingScheme::~CTPPSDiamondNumberingScheme()
{
  edm::LogInfo("TotemRP") << " Deleting CTPPSDiamondNumberingScheme" << std::endl;
}
