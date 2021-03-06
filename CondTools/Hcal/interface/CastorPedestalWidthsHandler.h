#ifndef CastorPedestalWidthsHandler_h
#define CastorPedestalWidthsHandler_h

// Radek Ofierzynski, 27.02.2008
// Adapted for CASTOR by L. Mundim (26/03/2009)

#include <string>
#include <iostream>
#include <typeinfo>
#include <fstream>

#include "FWCore/Framework/interface/MakerMacros.h"
#include "CondCore/PopCon/interface/PopConSourceHandler.h"
 
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/EventSetup.h"
// user include files
#include "CondFormats/CastorObjects/interface/CastorPedestalWidths.h"
#include "CondFormats/DataRecord/interface/CastorPedestalWidthsRcd.h"
#include "CalibCalorimetry/CastorCalib/interface/CastorDbASCIIIO.h"


class CastorPedestalWidthsHandler : public popcon::PopConSourceHandler<CastorPedestalWidths>
{
 public:
  void getNewObjects();
  std::string id() const { return m_name;}
  ~CastorPedestalWidthsHandler();
  CastorPedestalWidthsHandler(edm::ParameterSet const &);

  void initObject(CastorPedestalWidths*);

 private:
  unsigned int sinceTime;
  edm::FileInPath fFile;
  CastorPedestalWidths* myDBObject;
  std::string m_name;

};
#endif
