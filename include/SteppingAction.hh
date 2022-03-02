#ifndef STEPPINGACTION_HH
#define STEPPINGACTION_HH

#include "G4UserSteppingAction.hh"
#include "G4ParticleDefinition.hh"
#include "G4Step.hh"
#include "globals.hh"
#include "g4root.hh"

#include "EventAction.hh"
#include "DetectorConstruction.hh"

using namespace CLHEP;

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction();
    virtual ~SteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
};

#endif
