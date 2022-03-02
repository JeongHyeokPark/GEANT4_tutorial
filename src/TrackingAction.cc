#include <G4ParticleDefinition.hh>
#include <G4VProcess.hh>
#include <G4Track.hh>
#include <G4EventManager.hh>

#include "TrackingAction.hh"
#include "SteppingAction.hh"
#include "EventAction.hh"


TrackingAction::TrackingAction()
{
}

void  TrackingAction::PreUserTrackingAction( const G4Track *  )
{
}
