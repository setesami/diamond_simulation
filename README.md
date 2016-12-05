In order to run CTPPS simulation in CMSSW_8_1_0 follow these steps in terminal:
~~~~
source /afs/cern.ch/cms/cmsset_default.csh
cmsrel CMSSW_8_1_0_pre8
cd CMSSW_8_1_0_pre8/src
cmsenv
git cms-addpkg SimG4CMS/Forward
git remote add source git@github.com:setesami/diamond_simulation.git
git fetch --all
git checkout -b mohsen source/mohsen
git cms-addpkg SimG4Core/TotemRPProtonTransportParametrization/
git cms-addpkg SimG4Core/Application
git cms-addpkg DQM/CTPPS
git cms-addpkg DataFormats/DetId
git cms-addpkg DataFormats/PPSDetId
git cms-addpkg DataFormats/TotemRPDataTypes
git cms-addpkg Geometry/VeryForwardData
git cms-addpkg Geometry/VeryForwardGeometry/python
git cms-addpkg Geometry/VeryForwardProtonTransport/data
git cms-addpkg Geometry/VeryForwardRPTopology
git cms-addpkg SimTotem/RPDigiProducer
git cms-addpkg CondFormats/DataRecordIOMC/
git cms-addpkg IOMC/ParticleGuns
git cms-addpkg IOMC/EventVertexGenerators
git cms-addpkg TotemCondFormats/BeamOpticsParamsObjects
git cms-addpkg TotemCondFormats/DataRecord
git cms-addpkg TotemCondFormats/ProtonTransportFunctions
git cms-addpkg TotemCondFormats/DataRecord
git cms-addpkg CondFormats/DataRecord
git cms-addpkg Configuration/Generator
git cms-addpkg Configuration/Test
git cms-addpkg Configuration/TotemOpticsConfiguration
git cms-addpkg RecoCTPPS/TotemRPLocal


scram b -j 14

~~~~

