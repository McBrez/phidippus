#include <kinematics.hpp>
#include <Servo.hpp>
#include <PCA9685.hpp>
#include <memory>
#include <unistd.h>

double toRadian(double degree)
{
    return M_PI / 180.0 * degree;
}

int main()
{
    std::shared_ptr<PCA9685> i2c(new PCA9685(PCA9685::setupDevice(0x40)));
    i2c->setPWMFreq(100);

    Kinematics::Kinematics kinematics;

    Kinematics::Link link1 = Kinematics::Link(
        Kinematics::LinkType::LINK_TOWER,
        Vector3f(0, 0, toRadian(-90)),
        Vector3f(0, 0, toRadian(90)),
        Vector3f(0, 0, 0.050),
        Vector3f(0, 0, 0.050));
    Kinematics::Link link2 = Kinematics::Link(
        Kinematics::LinkType::LINK_TOWER,
        Vector3f(0, 0, toRadian(-90)),
        Vector3f(0, 0, toRadian(90)),
        Vector3f(0, 0, 0.050),
        Vector3f(0, 0, 0.050));
    Kinematics::Link link3 = Kinematics::Link(
        Kinematics::LinkType::LINK_TOWER,
        Vector3f(0, 0, toRadian(-90)),
        Vector3f(0, 0, toRadian(90)),
        Vector3f(0, 0, 0.050),
        Vector3f(0, 0, 0.050));

    std::vector<Kinematics::Link> links = {link1, link2, link3};
    Kinematics::KinematicConfiguration kinematicConfigration(links);

    Vector3f startVector(0.03, 0, 0.0);
    Vector3f endVector(0.03, 0.1, 0.0);

    servo::Servo servo1(i2c, 1, toRadian(-90), toRadian(90), 70, 500);
    servo::Servo servo1(i2c, 2, toRadian(-90), toRadian(90), 70, 500);
    servo::Servo servo1(i2c, 3, toRadian(-90), toRadian(90), 70, 500);

    bool start = false;
    while (1)
    {
        if (start)
        {
            kinematics.inverseKinematics(kinematicConfigration, startVector);
        }
        else
        {
            kinematics.inverseKinematics(kinematicConfigration, endVector);
        }
        start = !start;

        servo1.setAngle(kinematicConfigration[0].getAngles()[2]);
        servo1.setAngle(kinematicConfigration[1].getAngles()[2]);
        servo1.setAngle(kinematicConfigration[2].getAngles()[2]);

        sleep(2);
    }

    return 0;
}