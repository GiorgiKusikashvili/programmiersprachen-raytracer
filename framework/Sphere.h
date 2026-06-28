#include "shape.h"
#ifndef SPHERE_H
#define SPHERE_H
#include "shape.h"
#include <glm/vec3.hpp>

class Sphere : public Shape {
private:
    glm::vec3 center_;
    float radius_;
public:
    Sphere(glm::vec3 const& center, float radius, std::string const& name, Color const& color);

    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;
};
#endif // SPHERE_H