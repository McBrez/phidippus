// Project includes
#include <kinematic_configuration.hpp>

namespace Kinematics
{
    KinematicConfiguration::KinematicConfiguration(std::vector<Link> links) : links(links) {}

    Link &KinematicConfiguration::operator[](int idx)
    {
        return this->links[idx];
    }
}