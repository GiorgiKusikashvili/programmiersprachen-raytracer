//
// Created by giorg on 6/28/2026.
//

#ifndef RAYTRACER_SHAPE_H
#define RAYTRACER_SHAPE_H


class Shape {//Rein Virtuelle Klasse (Weil sie hat nur rein virtuelle Methoden)
    public:
   //Destruktor
    virtual ~Shape() = default;

    // Rein virtuelle Methoden
    virtual float area() const = 0;
    virtual float volume() const = 0;
};
#endif //RAYTRACER_SHAPE_H