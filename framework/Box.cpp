//
// Created by giorg on 6/28/2026.
//



#include "Box.h"
#include "glm/vec3.hpp"
#include "cmath"


  Box::Box(glm::vec3 const& min, glm::vec3 const& max,std::string const& name, Color const& color):max_{max}, min_{min},Shape{name, color} {
      std::cout << "[Konstruktor] Sphere '" << name_ << "' wurde erstellt.\n";
  }
Box::~Box() {
      std::cout << "[Destruktor] Sphere '" << name_ << "' wurde gelöscht.\n";
  }
    float Box::area() const  {
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
    float Box::volume() const  {
        float a = std::abs(max_.x - min_.x);
        float b = std::abs(max_.y - min_.y);
        float c = std::abs(max_.z - min_.z);

        return a*b*c;
    }
    std::ostream& Box:: print(std::ostream& os) const  {
        Shape::print(os); // Aufruf der Basisklasse für Name & Farbe
        os << ", Typ: Box, Min: (" << min_.x << "," << min_.y << "," << min_.z
           << "), Max: (" << max_.x << "," << max_.y << "," << max_.z << ")";
        return os;
    }


    glm::vec3  min_;
    glm::vec3  max_;
    //float radius_;





