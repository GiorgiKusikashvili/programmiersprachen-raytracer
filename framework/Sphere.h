#include "shape.h"
#ifndef SPHERE_H
#define SPHERE_H
#include "shape.h"
#include <glm/vec3.hpp>
#include "Ray.h"
#include "HitPoint.h"

class Sphere : public Shape {
private:
    glm::vec3 center_;
    float radius_;
public:
    Sphere(glm::vec3 const& center, float radius, std::string const& name, Color const& color);
    ~Sphere() override;

    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;

    //Aufgabe 6.6
    HitPoint intersect(Ray const& ray) const;
};
#endif // SPHERE_H