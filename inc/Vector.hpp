#ifndef VECTOR_HPP_
#define VECTOR_HPP_

#pragma once

#include <iostream>
#include <vector>
#include <cmath>

struct Vector3{
    double x,y,z;

    void RotateX(float angle);
    void RotateY(float angle);
    void RotateZ(float angle);
    void Rotate(Vector3 angles);
};

struct Vector2{
    double x,y;
};

#endif