#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>
#include "color.hpp"

class Shape {
public:
    Shape(std::string const& name, Color const& color);
    virtual ~Shape();

    virtual float area() const = 0;
    virtual float volume() const = 0;

    virtual std::ostream& print(std::ostream& os) const;

protected:
    std::string name_;
    Color color_;
};

// Nur die Deklaration des Operators
std::ostream& operator<<(std::ostream& os, Shape const& s);

#endif // SHAPE_H