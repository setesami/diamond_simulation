 /** \file TimingMaterialProperties.cc
  *  
  *
  *  $Date: 2015/06/24 21:04:09 $
  *  $Revision: 0.0 $
  *  \author Mohsen Naseri
  */
 
 #include "SimG4CMS/Forward/interface/TimingMaterialProperties.h"
 #include "G4LogicalVolumeStore.hh" 
 
 #include "FWCore/MessageLogger/interface/MessageLogger.h"
 
 #include "G4SystemOfUnits.hh"
 

     TimingMaterialProperties::TimingMaterialProperties(int DebugLevel) 
     : theMaterialTable(), theMPDebugLevel(0), 
     theMPT(),
     theAir(NULL), theSil(NULL), theGlass(NULL)
 {
     theMPDebugLevel = DebugLevel;
     
     /* *********************************************************************** */
     /* 
     define the materials for the PPS_timing_box, window_box and Lbar detectors.
         we need this to specify different properties for Timing
         detector, which is by default no longer possible in CMSSW due to
         the fact that all modules are made out of the same G4Material 
     */
     /* *********************************************************************** */
  
     //define G4Element as: new G4Element(const char * name,const char *symbol, int z.,float a);

     G4Element* nitrogen  = new G4Element("Nitrogen","N", 7., 14.007*g/mole);
     G4Element* oxygen  = new G4Element("Oxygen","O",8., 15.999*g/mole);
     G4Element* sodium  = new G4Element("Sodium","Na",11., 22.99*g/mole);
      G4Element* calcium  = new G4Element("Calcium","Ca",20., 40.078*g/mole);
      
     G4Element* argon  = new G4Element("Argon","Ar",18., 39.948*g/mole);
     G4Element* hydrogen  = new G4Element("Hydrogen","H",1., 1.00794*g/mole);
     G4Element* silicon = new G4Element("Silicon", "Si", 14., 28.09*g/mole );


     // define G4Material as: new G4Material(const char* name,float density,int n components); 
     theAir = new G4Material("Air",1.214*mg/cm3, 4);
     theAir->AddElement(nitrogen, 74.94*perCent);
     theAir->AddElement(oxygen, 23.69*perCent);
     theAir->AddElement(argon, 1.29*perCent);
     theAir->AddElement(hydrogen, 0.08*perCent);

     theSil = new G4Material("Quartz", 2.64*g/cm3, 2);
     theSil->AddElement(silicon, 46.748103*perCent);
     theSil->AddElement(oxygen , 53.251897*perCent);         

   
     theGlass = new G4Material("Glass",2.4*g/cm3, 4 );
     theGlass->AddElement( oxygen, 45.98*perCent);
     theGlass->AddElement(sodium, 9.6441*perCent);
     theGlass->AddElement(silicon, 33.6553*perCent);
     theGlass->AddElement(calcium, 10.7205*perCent);  

     // set the properties of the materials:
     
     setMaterialProperties();
 }
 



 TimingMaterialProperties::~TimingMaterialProperties()
 {
     if ( theAir != 0   )              { delete theAir;   }
     if ( theSil != 0   )              { delete theSil;   }
     if ( theGlass != 0 )              { delete theGlass; }
    /*if ( nitrogen != 0 )              { delete  nitrogen;}
     if ( oxygen != 0   )              { delete  oxygen;  }
     if ( sodium  != 0  )              { delete  sodium;  }
     if ( calcium != 0  )              { delete calcium ; }
     if ( argon   != 0  )              { delete  argon;   }
     if ( hydrogen  != 0)              { delete  hydrogen;}
     if ( silicon  != 0 )              { delete silicon ; }
     
    */


 }
 
 
 void TimingMaterialProperties::setMaterialProperties()
 {
     /* *********************************************************************** */
     /* 
     use this function to define material properties (like refraction
         index, absorptionlenght and so on) and add them to the 
         MaterialPropertiesTable. Finally set the MPT to a given Material.
     */
     /* *********************************************************************** */
 
     // get the MaterialTable as it is defined in OSCAR (CMSSW now)
         theMaterialTable = G4Material::GetMaterialTable();
 
     /* *********************************************************************** */
     /*
     Using the following code one can access the MaterialTable defined in
         OSCAR. This contains all the materials needed for the CMS detector,
         which are defined in the Geometry and DDD packages. COBRA takes care 
         of the proper conversion between a DDMaterial and a G4Material.
     */
     /* *********************************************************************** */
 
 //   if (theMPDebugLevel > 1)
 //     {
             // print the materialtable
//        std::cout << " **** here comes the material table **** "
  //       << *(G4Material::GetMaterialTable());
 //     }
 
     // define the MateriapropertiesTable for the desired Regions in the PPS timing deterctor.
     // LBar, Window_Box.
 
     const G4int nEntries = 10;
 
     // Photon energies
     G4double PhotonEnergy[nEntries] = {1.76*eV, 1.96*eV, 2.27*eV, 2.44*eV, 2.65*eV,
              3.06*eV, 3.71*eV, 4.50*eV, 5.19*eV, 5.79*eV };
 
     
/* *********************************************************************** */
     /*  set the refractive index for the Air to 1.0. This is       *
     *  needed to propagate the optical photons through the detector according *
         *  to Peter Gumplinger.                                                   */
     /* *********************************************************************** */ 


     // Refractive Index
     G4double RefractiveIndex_Air[nEntries] = { 1.00, 1.00, 1.00, 1.00, 1.00,
              1.00, 1.00, 1.00, 1.00, 1.00 };
     
 
     //               now  Quartz (SiO2) 


  G4double RefractiveIndex_Sil[nEntries] =
            {  1.455, 1.457, 1.460, 1.462, 1.464,
               1.470, 1.480, 1.496, 1.513, 1.534
            };
 
 

//      Window Glass PMT

  G4double RefractiveIndex_Glass[nEntries] =                    // was 1.70
            { 1.70, 1.70, 1.70, 1.70, 1.70,
              1.70, 1.70, 1.70, 1.70, 1.70
            };

            
 
     // Absorption Length
     ///////////////////////////////////
     G4double AbsorptionLength_Sil[nEntries] = {  0.5*m,  0.5*m,   0.5*m,    0.5*m,  0.5*m,
             0.5*m,  0.5*m,   0.5*m,    0.5*m,  0.5*m
             };
 
     
     // G4double AbsorptionLength_Glass[nEntries] =
    //       { .1*mm,  .1*mm,   .1*mm,  .1*mm,  .1*mm,.1*mm,  .1*mm,  .1*mm,  .1*mm,  .1*mm };

G4double AbsorptionLength_Glass[nEntries] =
           { 1*m,  1*m,   1*m,  1*m,  1*m, 1*m,  1*m,  1*m,  1*m,  1*m };
 
     // Absorption Length of the Air in the PPS_timing_box?
     //G4double AbsorptionLengthTAir[nEntries] = { 10 * m, 1.8 * m, 10 * m };
 
     
 
     // Reflectivity of the modules
    // G4double SiReflectivity[nEntries] = { 0.0, 0.0, 0.0 };
 
     // Efficiency of the modules
    // G4double TECEfficiency[nEntries] = { 0.9, 0.9, 0.9 };
    // G4double BarrelEfficiency[nEntries] = { 1.0, 1.0, 1.0 };
 
     // Reflectivity of the mirrors in the Alignment Tubes
     //G4double Reflectivity[nEntries] = { 0.05, 0.05, 0.05 };
 
     /* *********************************************************************** */
 
     /* *********************************************************************** */
     /* 
     define the materials for the PPS_timing, window_box and Lbar detectors in PPS timing detector.
         we need this to specify different properties for timing
         detector, which is by default no longer possible in CMSSW due to
         the fact that it is made out of the same G4Material 
     */
     /* *********************************************************************** */
 
     // set the options for the materials 
     {
         for(G4MaterialTable::const_iterator theMTEntry = theMaterialTable->begin();
         theMTEntry != theMaterialTable->end(); theMTEntry++) 
         {
             if(*theMTEntry)
             {
                 G4Material * theMaterial = const_cast<G4Material*>(*theMTEntry);
 
                 if (theMaterial->GetMaterialPropertiesTable())
                 { 
                     theMPT = theMaterial->GetMaterialPropertiesTable(); 
                 }
                 else
                 { 
                     theMPT = new G4MaterialPropertiesTable; 
                 }
 
             // properties of the Air
                 if ( theMaterial->GetName() == "Air" )
                 {
                      // set the refractive index
                     theMPT->AddProperty("RINDEX", PhotonEnergy, RefractiveIndex_Air, nEntries);
                     
                      // set the reflectivity
                      //theMPT->AddProperty("REFLECTIVITY", PhotonEnergy, SiReflectivity, nEntries);
                      // set the absorptionlength
                      //theMPT->AddProperty("ABSLENGTH", PhotonEnergy, AbsorptionLengthTAir, nEntries);
                     
 
                     // set the MaterialPropertiesTable
                     theMaterial->SetMaterialPropertiesTable(theMPT);
                 }
 
              // properties of the Quartz 
                 else if ( theMaterial->GetName() == "Quartz" )
                 {
                     
                     theMPT->AddProperty("RINDEX", PhotonEnergy, RefractiveIndex_Sil, nEntries);
                     theMPT->AddProperty("ABSLENGTH", PhotonEnergy, AbsorptionLength_Sil, nEntries);
                     //theMPT->AddProperty("EFFICIENCY", PhotonEnergy, TECEfficiency, nEntries);
 
                     
 
                     // set the MaterialPropertiesTable
                     theMaterial->SetMaterialPropertiesTable(theMPT);
                 }
 
             // properties of the GLASS_PLATE
                 else if (  theMaterial->GetName() == "Glass"  )
                 {
                     
                     theMPT->AddProperty("RINDEX", PhotonEnergy, RefractiveIndex_Glass, nEntries);
                     theMPT->AddProperty("ABSLENGTH", PhotonEnergy, AbsorptionLength_Glass, nEntries);
                     //theMPT->AddProperty("REFLECTIVITY", PhotonEnergy, SiReflectivity, nEntries);
                     //theMPT->AddProperty("EFFICIENCY", PhotonEnergy, BarrelEfficiency, nEntries);
 
                     
 
                     // set the MaterialPropertiesTable
                     theMaterial->SetMaterialPropertiesTable(theMPT);
                 }
                    
             }
         }
     }
 
     // loop over the logical volumes and set the material for the detectors
         const G4LogicalVolumeStore * theLogicalVolumeStore = G4LogicalVolumeStore::GetInstance();
     std::vector<G4LogicalVolume*>::const_iterator theLogicalVolume;
 
     for ( theLogicalVolume = theLogicalVolumeStore->begin(); theLogicalVolume != theLogicalVolumeStore->end(); theLogicalVolume++ )
       
         
     {

//         std::cout<<"theLogicalVolume)->GetName() ::"<<(*theLogicalVolume)->GetName()<<std::endl;

  //       std::cout<<"The debug level::"<<theMPDebugLevel<<std::endl;

         if ( (*theLogicalVolume)->GetName() == "PPS_timing_box"||(*theLogicalVolume)->GetName() == "PPS_timing_box_First"||(*theLogicalVolume)->GetName() == "PPS_timing_box_Second"  )
         {
         // set the material
             std::cout<<"Mohsen1 theLogicalVolume)->GetName() ::"<<(*theLogicalVolume)->GetName()<<std::endl;
             (*theLogicalVolume)->SetMaterial(theAir);
 
             if (theMPDebugLevel > 2)
             {
 
                 std::cout<<"Mohsen 2 theLogicalVolume)->GetName() ::"<<(*theLogicalVolume)->GetName()<<std::endl;
                 std::cout << "  AC1CMS: found a logical volume: " << (*theLogicalVolume)->GetName() << std::endl;
                 std::cout << "  AC1CMS: the logical volume material = " << (*theLogicalVolume)->GetMaterial()->GetName() << std::endl;
                 std::cout << "  AC1CMS: the MaterialPropertiesTable = " << std::endl;
                 (*theLogicalVolume)->GetMaterial()->GetMaterialPropertiesTable()->DumpTable();
             }
         }
         else if ((*theLogicalVolume)->GetName() == "Lbar"  )
         {
         // set the material
             (*theLogicalVolume)->SetMaterial(theSil);
 
             if (theMPDebugLevel > 2)
             {
                 std::cout << "  AC1CMS: found a logical volume: " << (*theLogicalVolume)->GetName() << std::endl;
                 std::cout << "  AC1CMS: the logical volume material = " << (*theLogicalVolume)->GetMaterial()->GetName() << std::endl;
                 std::cout << "  AC1CMS: the MaterialPropertiesTable = " << std::endl;
                 (*theLogicalVolume)->GetMaterial()->GetMaterialPropertiesTable()->DumpTable();
             }
         }
         else if ( (*theLogicalVolume)->GetName() == "window_box"  )
         {
         // set the material
             (*theLogicalVolume)->SetMaterial(theGlass);
 
             if (theMPDebugLevel > 2)
             {
                 std::cout << "  AC1CMS: found a logical volume: " << (*theLogicalVolume)->GetName() << std::endl;
                 std::cout << "  AC1CMS: the logical volume material = " << (*theLogicalVolume)->GetMaterial()->GetName() << std::endl;
                 std::cout << "  AC1CMS: the MaterialPropertiesTable = " << std::endl;
                 (*theLogicalVolume)->GetMaterial()->GetMaterialPropertiesTable()->DumpTable();
             }
         }
     }
 } // End of set material function.
