#define GLM_ENABLE_EXPERIMENTAL
#include "Sphere.h"
#include "glm/vec3.hpp"
#include <cmath>

#include <glm/gtx/intersect.hpp> // Wichtig für die Schnittberechnung
#include <glm/glm.hpp>            // Für glm::normalize

    glm::vec3 center_;
    float radius_;

    //Aufgabe 6.4 und 6.5: Der Konstruktor reicht Name und Farbe an die Basisklasse weiter!
   Sphere:: Sphere(glm::vec3 const& center, float radius,std::string const& name, Color const& color)
    : center_{center}, radius_{radius}, Shape{name, color} {
        /*
    Das ist gleich wie:
    center_ = center;
    radius_ = radius;
        */
    }

    float Sphere::area() const  {
        return 4.0f * M_PI * radius_ * radius_;
    }

    float Sphere::volume() const {
        return (4.0f/3.0f) * M_PI * radius_ * radius_*radius_;
    }
    std::ostream& Sphere::print(std::ostream& os) const  {
        Shape::print(os); //  Aufruf der Basisklasse für Name & Farbe. Also das ist die Methode von Basisklasse shape. Wenn wir Sphere::print aufrufen wird auch Shape::print aufgerufen
        os << ", Typ: Kugel, Zentrum: (" << center_.x << "," << center_.y << "," << center_.z << "), Radius: " << radius_;
        return os;
    }
HitPoint Sphere::intersect(Ray const& ray) const {
       HitPoint hit;

       // 1. Strahlrichtung normalisieren zur Sicherheit
       glm::vec3 norm_dir = glm::normalize(ray.direction);

       float scalar_distance = 0.0f;

       // 2. GLM Schnittfunktion aufrufen (erwartet quadrierten Radius)
       hit.intersected = glm::intersectRaySphere(
           ray.origin, norm_dir,
           center_,
           radius_ * radius_, // Quadrierter Radius!
           scalar_distance
       );

       // 3. Wenn getroffen, befüllen wir das HitPoint-DTO
       if (hit.intersected) {
           hit.distance = scalar_distance; // [cite: 96]
           hit.name = name_;               // Aus der Basisklasse Shape
           hit.color = color_;             // Aus der Basisklasse Shape
           hit.point = ray.point_at_parameter(scalar_distance); // p(t) = o + t * d
           hit.direction = norm_dir;
       }

       return hit;
   }


