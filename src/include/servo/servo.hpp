#pragma once

// Standard includes
#include <memory>

// Projeckt includes
#include <PCA9685.hpp>
#include <logger.hpp>

namespace servo
{
    class Servo
    {
    public:
        Servo(
            std::shared_ptr<Logging::Logger> log,
            std::shared_ptr<PCA9685> i2c,
            int servoId,
            double minAngle,
            double maxAngle,
            int minPwmValue,
            int maxPwmValue);

        void setAngle(double angle);

    private:
        double minAngle;
        double maxAngle;
        int minPwmValue;
        int maxPwmValue;
        double currentAngle;
        int currentPwmValue;
        int servoId;
        std::shared_ptr<PCA9685> i2cReference;
        std::shared_ptr<Logging::Logger> log;
    };
}