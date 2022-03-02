#ifndef TRACKINGACTION_HH
#define TRACKINGACTION_HH                                                                                                                                                                            

#include <G4UserTrackingAction.hh>

class  G4Track;
class  G4LogicalVolume;
class  G4ParticleDefinition;


class  TrackingAction : public G4UserTrackingAction
{
    public:
        explicit TrackingAction();

    public:
        void  PreUserTrackingAction( const G4Track *  track );
        //void  BeginOfEventAction( void );

};

#endif

