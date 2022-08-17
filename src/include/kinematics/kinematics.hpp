#pragma once

// Standard includes
#include <memory>

// Eigen includes
#include <Dense>

// Project includes
#include <kinematic_configuration.hpp>
#include <logger.hpp>

using Eigen::Vector3f;

namespace Kinematics
{
    class KinematicConfiguration;

    class Kinematics
    {
    public:
        Kinematics(std::shared_ptr<Logging::Logger> log);
        int inverseKinematics(KinematicConfiguration &kinematicConfiguration, const Vector3f &endPos);
        
    private:
        std::shared_ptr<Logging::Logger> log;
    };
}
