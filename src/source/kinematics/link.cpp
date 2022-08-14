#include <link.hpp>

namespace Kinematics
{
    Link::Link(
        LinkType linkType,
        Vector3f linkAnglesMin,
        Vector3f linkAnglesMax,
        Vector3f linkTransMin,
        Vector3f linkTransMax) : linkType(linkType),
                                 linkAnglesMin(linkAnglesMin),
                                 linkAnglesMax(linkAnglesMax),
                                 linkTransMin(linkTransMin),
                                 linkTransMax(linkTransMax),
                                 currTrans(linkTransMax)
    {
    }

    Vector3f Link::getAngles() const { return this->currAngles; }

    Vector3f Link::getTrans() const { return this->currTrans; }

} // namespace Kinematics
