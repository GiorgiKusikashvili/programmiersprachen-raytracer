//
// Created by giorg on 6/28/2026.
//

#ifndef RAYTRACER_BOX_H
#define RAYTRACER_BOX_H
#include "shape.h"
#include "glm/vec3.hpp"
#include "cmath"

class Box: public Shape {
    public:
    Box(glm::vec3 const& min, glm::vec3 const& max):max_{max}, min_{min} {}

    float area() const override {
        /* MAX   MIN
         * (x) - (x) =a   -->Breite
         * (y) - (y) =b   -->Länge
         * (z) - (z) =c   -->Tiefe
         */
        float a = std::abs(max_.x - min_.x);
        float b = std::abs(max_.y - min_.y);
        float c = std::abs(max_.z - min_.z);
        return 2.0f * ((a * b) + (a * c) + (b * c));//Formel für area
    }
    float volume() const override {
        float a = std::abs(max_.x - min_.x);
        float b = std::abs(max_.y - min_.y);
        float c = std::abs(max_.z - min_.z);

        return a*b*c;
    }

    private:
    glm::vec3 const& min_;
    glm::vec3 const& max_;
    //float radius_;
};



#endif //RAYTRACER_BOX_H
