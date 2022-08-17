#include <kinematics.hpp>
#include <servo.hpp>
#include <PCA9685.hpp>
#include <memory>
#include <unistd.h>
#include <iostream>
#include <file_logger.hpp>
#include <logger.hpp>
#include <util.hpp>

double toRadian(double degree)
{
    return M_PI / 180.0 * degree;
}

int main()
{
    // Initialize logger.
    std::shared_ptr<Logging::Logger> log(new Logging::FileLogger());
    log->writeInfoEntry("Logger has been initialized.");
    
    // Initialize Servo board.
    std::shared_ptr<PCA9685> i2c(new PCA9685(PCA9685::setupDevice(0x40)));
    i2c->setPWMFreq(100);
    log->writeInfoEntry("Servo board has been initialized.");

    Kinematics::Kinematics kinematics(log);

    Kinematics::Link link1 = Kinematics::Link(
        Kinematics::LinkType::LINK_TOWER,
        Vector3f(0, 0, toRadian(-90)),
        Vector3f(0, 0, toRadian(90)),
        Vector3f(0, 0, 0.1),
        Vector3f(0, 0, 0.1));
    Kinematics::Link link2 = Kinematics::Link(
        Kinematics::LinkType::LINK_TOWER,
        Vector3f(0, 0, toRadian(-90)),
        Vector3f(0, 0, toRadian(90)),
        Vector3f(0, 0, 0.1),
        Vector3f(0, 0, 0.1));
    Kinematics::Link link3 = Kinematics::Link(
        Kinematics::LinkType::LINK_TOWER,
        Vector3f(0, 0, toRadian(-90)),
        Vector3f(0, 0, toRadian(90)),
        Vector3f(0, 0, 0.1),
        Vector3f(0, 0, 0.1));

    std::vector<Kinematics::Link> links = {link1, link2, link3};
    Kinematics::KinematicConfiguration kinematicConfigration(links);

    Vector3f startVector(0.05, 0.0, 0.01);
    Vector3f endVector(0.09, 0.0, 0.01);

    servo::Servo servo1(log, i2c, 1, toRadian(-90), toRadian(90), 70, 500);
    servo::Servo servo2(log, i2c, 2, toRadian(-90), toRadian(90), 70, 500);
    servo::Servo servo3(log, i2c, 3, toRadian(-90), toRadian(90), 70, 500);

    bool start = false;
    while (1)
    {
        if (start)
        {
            log->writeInfoEntry(std::string("Setting new end position to :\n") + util::vector3fToString(startVector));
            kinematics.inverseKinematics(kinematicConfigration, startVector);
        }
        else
        {
            log->writeInfoEntry(std::string("Setting new end position to :\n") + util::vector3fToString(endVector));
            kinematics.inverseKinematics(kinematicConfigration, endVector);
        }
        start = !start;

        double towerAngle = kinematicConfigration[0].getAngles()[2];
        double theta1 = kinematicConfigration[1].getAngles()[1];
        double theta2 = kinematicConfigration[2].getAngles()[1];
        
        std::cout << 
				"Tower Angle: " << towerAngle << std::endl <<
				"Theta1: " << theta1 << std::endl <<
				"Theta2: " << theta2 << std::endl << std::endl;
        
        servo1.setAngle(towerAngle);
        servo2.setAngle(theta1);
        servo3.setAngle(theta2);

        sleep(2);
    }

    return 0;
}