#ifndef RAYTRACER_HITPOINT_H
#define RAYTRACER_HITPOINT_H
#include <glm/vec3.hpp>
#include <string>
#include "color.hpp"

struct HitPoint {
    bool intersected = false;        // 1. Ob ein Schnitt erfolgt ist also "bool hit=false"
    float distance = 0.0f;           // 2. Distanz des Schnitts (Parameter t)
    std::string name = "";           // 3. Name des geschnittenen Objekts
    Color color{0.0f, 0.0f, 0.0f};   // 4. Farbe des geschnittenen Objekts
    glm::vec3 point{0.0f, 0.0f, 0.0f}; // 5. 3D-Schnittpunkt
    glm::vec3 direction{0.0f, 0.0f, 0.0f}; // 6. Richtung des Strahls
};
#endif //RAYTRACER_HITPOINT_H
