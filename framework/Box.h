#ifndef RAYTRACER_BOX_H
#define RAYTRACER_BOX_H

#include "shape.h"
#include <glm/vec3.hpp>

class Box : public Shape {
public:
    Box(glm::vec3 const& min, glm::vec3 const& max, std::string const& name, Color const& color);
    ~Box() override;

    float area() const override;
    float volume() const override;
    std::ostream& print(std::ostream& os) const override;

private:
    glm::vec3 min_;
    glm::vec3 max_;
};

#endif // RAYTRACER_BOX_H