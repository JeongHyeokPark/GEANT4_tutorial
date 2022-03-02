#include "globals.hh"
#include <sstream>

#include "G4RunManager.hh"
#include "G4VisExecutive.hh"
#include "G4UImanager.hh"
#include "G4UIExecutive.hh"
#include "G4ProcessManager.hh"
#include "G4UIterminal.hh"
#include "G4UItcsh.hh"

#include "QGSP_BIC.hh"
#include "DetectorConstruction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"
#include "EventAction.hh"
#include "TrackingAction.hh"

#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv)
{
  //CLHEP::HepRandom::setTheSeed( time(0) );
  G4RunManager* runManager = new G4RunManager;

  runManager -> SetUserInitialization(new QGSP_BIC());
  runManager -> SetUserInitialization(new DetectorConstruction());
  runManager -> SetUserAction(new PrimaryGeneratorAction());
  runManager -> SetUserAction(new RunAction());
  runManager -> SetUserAction(new EventAction());
  runManager -> SetUserAction(new TrackingAction());
  runManager -> SetUserAction(new SteppingAction());
  runManager -> Initialize();

  G4VisManager* visManager = new G4VisExecutive;
  visManager -> Initialize();
  G4UImanager* UImanager = G4UImanager::GetUIpointer();


  if (argc > 1)
  {
    //G4UIExecutive* ui = new G4UIExecutive(argc, argv);
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UImanager -> ApplyCommand(command+fileName);
  }
  else if(argc <= 1) 
  {
    //G4UIExecutive* ui = new G4UIExecutive(argc, argv); // If you want to see GUI via QT, uncomment this line.
    auto ui = new G4UIterminal(new G4UItcsh); // Instead of QT, if you would like to see via OpenGL, uncomment this line.
    UImanager -> ApplyCommand("/control/execute vis.mac");
    ui -> SessionStart();
    delete ui;
  }

  delete visManager;
  delete runManager;
  return 0;
}
