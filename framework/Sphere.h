//
// Created by giorg on 6/28/2026.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "shape.h"
#include <glm/vec3.hpp>
#include <cmath>

class Sphere : public Shape {

private:
    glm::vec3 center_;
    float radius_;

public:
    Sphere(glm::vec3 const& center, float radius)
    : center_{center}, radius_{radius} {
        /*
    Das ist gleich wie:
    center_ = center;
    radius_ = radius;
        */
    }

    float area() const override {
        return 4.0f * M_PI * radius_ * radius_;
    }

    float volume() const override {
        return (4.0f/3.0f) * M_PI * radius_ * radius_*radius_;
    }


};

#endif //RAYTRACER_SPHERE_H
