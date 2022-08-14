#pragma once

// Standard includes
#include <vector>

// Projects includes
#include <link.hpp>

namespace Kinematics
{
    class KinematicConfiguration
    {
    public:
        KinematicConfiguration(std::vector<Link> links);

        Link &operator[](int idx);

    private:
        std::vector<Link> links;
    };
}