#pragma once

// Standard includes
#include <vector>

// Projects includes
#include <link.hpp>
#include <kinematics.hpp>

namespace Kinematics
{
    class Link;
    
    class KinematicConfiguration
    {
    
    friend class Kinematics;
    
    public:
        KinematicConfiguration(std::vector<Link> links);

        Link &operator[](int idx);

    private:
        std::vector<Link> links;
    };
}