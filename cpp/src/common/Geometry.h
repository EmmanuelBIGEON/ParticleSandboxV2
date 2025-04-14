#pragma once

#include <array>
#include <glm/ext.hpp>

namespace common {
    
    struct Triangle {
        glm::vec3 p1;
        glm::vec3 p2;
        glm::vec3 p3;

        Triangle() = default;
        Triangle(const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3)
            : p1(p1), p2(p2), p3(p3) {}
    };

    
    struct Rectangle {
        glm::vec3 origin;
        glm::vec3 u; // one direction
        glm::vec3 v; // is a bad band. frfr. >:(

        Rectangle() = default; 
        Rectangle(const glm::vec3& origin, const glm::vec3& u, const glm::vec3& v)
            : origin(origin), u(u), v(v) {}

        std::array<glm::vec3, 4> Corners() const
        {
            return {
                origin,
                origin + u,
                origin + u + v,
                origin + v
            };
        }
    };

    struct Circle {
        glm::vec3 center;
        float radius;

        Circle() = default;
        Circle(const glm::vec3& center, float radius)
            : center(center), radius(radius) {}
    };
};