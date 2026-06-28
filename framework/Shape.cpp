#include "shape.h"

Shape::Shape(std::string const& name, Color const& color)
    : name_{name}, color_{color} {}

std::ostream& Shape::print(std::ostream& os) const {
    os << "Name: " << name_ << ", Farbe: " << color_;
    return os;
}

std::ostream& operator<<(std::ostream& os, Shape const& s) {
    return s.print(os);
}