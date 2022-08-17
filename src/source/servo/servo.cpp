// Standard includes
#include <cmath>

// Project includes
#include <servo.hpp>

namespace servo
{
    Servo::Servo(std::shared_ptr<Logging::Logger> log, std::shared_ptr<PCA9685> i2c, int servoId, double minAngle,
                 double maxAngle,
                 int minPwmValue,
                 int maxPwmValue) : log(log),
								                    i2cReference(i2c),
                                    servoId(servoId),
                                    minAngle(minAngle),
                                    maxAngle(maxAngle),
                                    minPwmValue(minPwmValue),
                                    maxPwmValue(maxPwmValue) {}

    void Servo::setAngle(double angle)
    {
        if(angle < this->minAngle || angle > this->maxAngle) {
				  this->log->writeWarnEntry(
					"Servo " + std::to_string(this->servoId) + " can not reach given angle of " + std::to_string(angle));
					return;
				}
    
        double factor = (angle - this->minAngle) / (this->maxAngle - this->minAngle);

        int pwmValue = std::floor(factor * (this->maxPwmValue - this->minPwmValue) + this->minPwmValue);

        this->log->writeInfoEntry(
				"Servo " + std::to_string(this->servoId) + " mapped angle " + std::to_string(angle) + 
				" to PWM value " + std::to_string(pwmValue) + ".");

        this->i2cReference->setPWM(this->servoId, pwmValue);
    }
}
