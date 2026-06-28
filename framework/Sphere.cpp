//
// Created by giorg on 6/28/2026.
//

#ifndef RAYTRACER_SPHERE_H
#define RAYTRACER_SPHERE_H

#include "Shape.cpp"
#include "glm/vec3.hpp"
#include <cmath>

    glm::vec3 center_;
    float radius_;

    //Aufgabe 6.3: Der Konstruktor reicht Name und Farbe an die Basisklasse weiter!
   Sphere:: Sphere(glm::vec3 const& center, float radius,std::string const& name, Color const& color)
    : center_{center}, radius_{radius}, Shape{name, color} {
        /*
    Das ist gleich wie:
    center_ = center;
    radius_ = radius;
        */
    }

    float Sphere::area() const override {
        return 4.0f * M_PI * radius_ * radius_;
    }

    float Sphere::volume() const override {
        return (4.0f/3.0f) * M_PI * radius_ * radius_*radius_;
    }
    std::ostream& Sphere::print(std::ostream& os) const override {
        Shape::print(os); //  Aufruf der Basisklasse für Name & Farbe
        os << ", Typ: Kugel, Zentrum: (" << center_.x << "," << center_.y << "," << center_.z << "), Radius: " << radius_;
        return os;
    }


#endif //RAYTRACER_SPHERE_H
