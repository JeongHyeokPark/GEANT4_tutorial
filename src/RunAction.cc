#include "RunAction.hh"
#include "EventAction.hh"
#include "G4EventManager.hh"

#include "G4UnitsTable.hh"
#include "G4SystemOfUnits.hh"

RunAction::RunAction()
:G4UserRunAction()
{
  tutorial_mode = true;
}

RunAction::~RunAction()
{
}

void RunAction::BeginOfRunAction(const G4Run* )
{
}

void RunAction::EndOfRunAction(const G4Run* )
{
}
