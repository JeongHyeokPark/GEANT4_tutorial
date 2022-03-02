#include "SteppingAction.hh"
#include "DetectorConstruction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4EventManager.hh"
#include "G4ParticleDefinition.hh"
#include "G4HadronicProcess.hh"
#include "G4DataInterpolation.hh"

using namespace CLHEP;

SteppingAction::SteppingAction()
  : G4UserSteppingAction()
{
}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step*)
{
}
