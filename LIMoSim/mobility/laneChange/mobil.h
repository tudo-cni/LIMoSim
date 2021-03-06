#ifndef LIMOSIM_MOBIL_H
#define LIMOSIM_MOBIL_H

#include "lanechangemodel.h"
#include "LIMoSim/mobility/roadperception.h"
#include "LIMoSim/mobility/followerModel/idm.h"

namespace LIMoSim
{

class MOBIL : public LaneChangeModel
{
public:
    MOBIL(Car *_car);

    double computeLeftLaneIncentive();
    double computeRightLaneIncentive();

    bool checkSafetyCondition(Lane *_lane, const PerceptionEntry &_follower);


private:
    RoadPerception *p_perception;
    IDM *p_idm;

    double m_maxDeceleration_mpss;
    double m_politeness;
    double m_changingThreshold_mpss;
    double m_rightLaneBias_mpss;
};

}


#endif // LIMOSIM_MOBIL_H
