//
// Created by giorg on 6/29/2026.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H
#include <glm/vec3.hpp>

struct Ray {
    glm::vec3 origin{0.0f, 0.0f, 0.0f};
    glm::vec3 direction{0.0f, 0.0f, 1.0f}; // Muss normalisiert sein

    // Berechnet den Punkt auf dem Strahl bei Distanz t
    //origin ist der Anfangspunkt(o), t ist distanz, direction ist die Richtung des Strahls (d). p(t) ist die Punkt wo der Straht endet (Endpunkt)
    glm::vec3 point_at_parameter(float t) const {
        return origin + t * direction; // p(t) = o + t * d
    }
};

#endif //RAYTRACER_RAY_H
