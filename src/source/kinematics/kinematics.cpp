// Standard includes
#include <cmath>

// Project includes
#include <kinematics.hpp>

namespace Kinematics
{
    int Kinematics::inverseKinematics(KinematicConfiguration &kinematicConfiguration, const Vector3f &endPos)
    {
        // Calculate the angle of the tower.
        double angleTower;
        if (endPos[0] != 0.0 && endPos[1] != 0.0)
        {
            angleTower = std::atan2(endPos[0], endPos[1]);
        }
        else
        {
            angleTower = kinematicConfiguration[0].getAngles()[2];
        }

        // Calculate a bunch of helping values.
        double x = std::sqrt(endPos[0] * endPos[0] + endPos[1] * endPos[1]);
        double y = endPos[2];
        double phi = std::atan2(x, y);
        double l = std::sqrt(x * x + y * y);
        double p =
            0.5 * (kinematicConfiguration[1].getTrans().norm() +
                   kinematicConfiguration[2].getTrans().norm() +
                   l);
        double r =
            std::sqrt((
                          (p - kinematicConfiguration[1].getTrans().norm()) *
                          (p - kinematicConfiguration[2].getTrans().norm()) *
                          (p - l)) /
                      p);
        double alpha = 2 * atan(r / (p - kinematicConfiguration[1].getTrans().norm()));
        double beta = 2 * atan(r / (p - kinematicConfiguration[2].getTrans().norm()));

        double theta1 = phi + beta;
        double theta2 = -1.0 * alpha - beta;

        // Assign the values to the confiugration.
        kinematicConfiguration[0].targetAngles = Vector3f(0, 0, angleTower);
        kinematicConfiguration[1].targetAngles = Vector3f(0, theta1, 0);
        kinematicConfiguration[1].targetAngles = Vector3f(0, theta2, 0);

        return 1;
    }
}