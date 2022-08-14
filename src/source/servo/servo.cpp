// Standard includes
#include <cmath>

// Project includes
#include <servo.hpp>

namespace servo
{
    Servo::Servo(std::shared_ptr<PCA9685> i2c, int servoId, double minAngle,
                 double maxAngle,
                 int minPwmValue,
                 int maxPwmValue) : i2cReference(i2c),
                                    servoId(servoId),
                                    minAngle(minAngle),
                                    maxAngle(maxAngle),
                                    minPwmValue(minPwmValue),
                                    maxPwmValue(maxPwmValue) {}

    void Servo::setAngle(double angle)
    {
        double factor = (angle - this->minAngle) / this->maxAngle;

        int pwmValue = std::floor(factor * (this->maxPwmValue - this->minPwmValue) + this->minPwmValue);

        this->i2cReference->setPWM(this->servoId, pwmValue);
    }
}
