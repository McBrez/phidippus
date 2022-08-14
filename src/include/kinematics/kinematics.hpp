#pragma once

// Project includes
#include <kinematic_configuration.hpp>

namespace Kinematics
{
    class Kinematics
    {
    public:
        int inverseKinematics(KinematicConfiguration &kinematicConfiguration, const Vector3f &endPos);
    };
}
