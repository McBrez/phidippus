#pragma once

// Eigen includes
#include <Dense>

// Project includes
#include <kinematics.hpp>

using Eigen::Vector3f;

namespace Kinematics
{
    /**
     * @brief Identifies the different link types.
     */
    enum LinkType
    {
        /// A link that only rotates in its z-axis.
        LINK_TOWER,

        /// A link that only rotates in either of its y- or x-axis.
        LINK_ELBOW
    };

    /**
     * @brief Class that describes a kinematic link and holds its current
     * state.
     */
    class Link
    {
        /// Has to have private access, to write the target angles.
        friend class Kinematics;

    public:
        /**
         * @brief Construct a new Link object
         *
         * @param linkAnglesMin: Vector containing the minimum angles of the
         * link.
         * @param linkAnglesMax: Vector containing the maximum angle of the
         * link.
         * @param linkTransMin: Vector containing the minimum translation of the
         * link.
         * @param linkTransMax: Vector containing the maximum translation of the
         * link.
         */
        Link(
            LinkType linkType,
            Vector3f linkAnglesMin,
            Vector3f linkAnglesMax,
            Vector3f linkTransMin,
            Vector3f linkTransMax);

        Vector3f getAngles() const;

        Vector3f getTrans() const;

    private:
        LinkType linkType;

        /// Vector containing the minimum angles of the link.
        Vector3f linkAnglesMin;
        Vector3f linkAnglesMax;
        Vector3f linkTransMin;
        Vector3f linkTransMax;

        /// The current angles of the link.
        Vector3f currAngles;
        /// The current translation of the link.
        Vector3f currTrans;

        // The target angle, in case of
        Vector3f targetAngles;

        Vector3f targetTrans;
    };
}