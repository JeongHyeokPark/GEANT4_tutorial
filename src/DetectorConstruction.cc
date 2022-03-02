#include "DetectorConstruction.hh"

#include "G4MaterialPropertiesTable.hh"
#include "G4MaterialPropertyVector.hh"

#include "G4RunManager.hh"
#include "G4TransportationManager.hh"
#include "G4SubtractionSolid.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4GlobalMagFieldMessenger.hh"
#include "G4SDManager.hh"
#include "G4VisAttributes.hh"
#include "G4Color.hh"
#include "G4RotationMatrix.hh"

#include "G4DataInterpolation.hh"

#include "G4LogicalBorderSurface.hh"
#include "G4OpticalSurface.hh"

using namespace CLHEP;

DetectorConstruction::DetectorConstruction()
  : G4VUserDetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{  
  //Elements
  // G4Elements( name, symbol, Z number, A )
  G4Element* elH = new G4Element("H", "H", 1., 1.*g/mole);
  G4Element* elC = new G4Element("C", "C", 6., 12.*g/mole);
  G4Element* elN = new G4Element("N", "N", 7., 14.00674*g/mole);
  G4Element* elO = new G4Element("O", "O", 8., 15.9994*g/mole);

  G4double density = universe_mean_density;
  // G4Material( name, density, # of consisting atom, state )
  G4Material* Vacuum = new G4Material("Vacuum", density, 2);
  Vacuum->AddElement(elN, .7);
  Vacuum->AddElement(elO, .3);

  // World
  G4double world_size = 10*m;

  G4Box* solidWorld = new G4Box("World", 0.5*world_size, 0.5*world_size, 0.5*world_size);
  G4LogicalVolume* logicWorld = new G4LogicalVolume(solidWorld, Vacuum, "World");
  G4VPhysicalVolume* physWorld = new G4PVPlacement(0, G4ThreeVector(), logicWorld, "World", 0, false, -1, true);

  return physWorld;
}
