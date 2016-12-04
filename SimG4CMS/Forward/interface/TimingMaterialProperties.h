#ifndef PPS_TimingMaterialProperties_h
#define PPS_TimingMaterialProperties_h

 /** \class TimingMaterialProperties
  *  Class to define custom material properties for PPS_timing detector with PPS_timing_box, window_box and Lbar sub detectorss.
  *
  *  $Date: 2015/06/24 21:01:00 $
  *  $Revision: 0.0 $
  *  \author Mohsen Naseri
  */
 
 #include "G4MaterialPropertiesTable.hh"
 #include "G4SDManager.hh"
 
 class TimingMaterialProperties
 {
  public:
     /// two different constructors to have more flexibility.
   TimingMaterialProperties(int DebugLevel);
  // TimingMaterialProperties();
     /// destructor
   ~TimingMaterialProperties();
 
  private:
     /// define optical properties of materials in the timing detector of PPS project
   void setMaterialProperties();
 
  private:
   const G4MaterialTable * theMaterialTable;
 
  private:
   int theMPDebugLevel;
   G4MaterialPropertiesTable * theMPT;
   G4Material * theAir;
   G4Material * theSil;
   G4Material * theGlass;
 };
 #endif
