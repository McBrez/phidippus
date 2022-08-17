// Standard includes
#include <cmath>
#include <string>

// Project includes
#include <kinematics.hpp>

namespace Kinematics
{
    Kinematics::Kinematics(std::shared_ptr<Logging::Logger> log) : log(log) {
		
		}

    int Kinematics::inverseKinematics(KinematicConfiguration &kinematicConfiguration, const Vector3f &endPos)
    {
        this->log->writeInfoEntry("Entered inverseKinematics().");
        // Calculate the angle of the tower.
        // First, check if the end position corresponds to an singularity.
        double angleTower;
        if (endPos[0] == 0.0 && endPos[1] == 0.0)
        {
            this->log->writeWarnEntry("End position corresponds to a singularity in z axis. Take the last known angle.");
            angleTower = kinematicConfiguration[0].getAngles()[2];      
        }
        else
        {
            angleTower = std::atan2(endPos[1], endPos[0]);
        }     

        // Calculate a bunch of helping values.
        double x = std::sqrt(endPos[0] * endPos[0] + endPos[1] * endPos[1]);
        double y = endPos[2];
        double l = std::sqrt(x * x + y * y);
        
        // Check if a solution exists.
        double lowerMargin = std::abs(kinematicConfiguration[1].getTrans().norm() - kinematicConfiguration[2].getTrans().norm());
				double upperMargin = kinematicConfiguration[1].getTrans().norm() + kinematicConfiguration[2].getTrans().norm();
        if(lowerMargin > l || upperMargin < l) {
				  this->log->writeWarnEntry("There exists no solution for the given end position.");
				  return -1;
				}
        
        double phi = std::atan2(y, x);
        double p =
            0.5 * (kinematicConfiguration[1].getTrans().norm() +
                   kinematicConfiguration[2].getTrans().norm() +
                   l);
        double r1 = (p - kinematicConfiguration[1].getTrans().norm());
        double r2 = (p - kinematicConfiguration[2].getTrans().norm());
        double r3 = (p - l);
        double r = std::sqrt((r1 * r2 * r3) / p);
        double alpha = 2 * std::atan(r / (p - kinematicConfiguration[1].getTrans().norm()));
        double beta = 2 * std::atan(r / (p - kinematicConfiguration[2].getTrans().norm()));

        double theta1 = phi + beta;
        double theta2 = -1.0 * alpha - beta;

        // Assign the values to the confiugration.
        kinematicConfiguration[0].targetAngles = Vector3f(0, 0, angleTower);
        kinematicConfiguration[1].targetAngles = Vector3f(0, theta1, 0);
        kinematicConfiguration[2].targetAngles = Vector3f(0, theta2, 0);

        this->log->writeInfoEntry(
				  std::string("Intermediate values of inverseKinematics():") + "\n" +
				  std::string("x : ") + std::to_string(x) + "\n" +
					std::string("y : ") + std::to_string(y) + "\n" +
					std::string("phi : ") + std::to_string(phi) + "\n" +
					std::string("l : ") + std::to_string(l) + "\n" +
					std::string("p : ") + std::to_string(p) + "\n" +
					std::string("r : ") + std::to_string(r) + "\n" + 
					std::string("alpha : ") + std::to_string(alpha) + "\n" +
					std::string("beta : ") + std::to_string(beta));

        return 1;
    }
}