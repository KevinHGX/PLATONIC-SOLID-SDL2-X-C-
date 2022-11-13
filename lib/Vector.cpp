#include "../inc/Vector.hpp"

void Vector3::RotateX(float angle)
{
    double newY = y * cos(angle) - z * sin(angle);
    double newZ = y * sin(angle) + z * cos(angle);

    y = newY;
    z = newZ;
}
void Vector3::RotateY(float angle)
{
    double newX = x * cos(angle) - z * sin(angle);
    double newZ = x * sin(angle) + z * cos(angle);

    x = newX;
    z = newZ;
}
void Vector3::RotateZ(float angle)
{
    double newX = x * cos(angle) - y * sin(angle);
    double newY = x * sin(angle) + y * cos(angle);

    x = newX;
    y = newY;
}

void Vector3::Rotate(Vector3 angles)
{
    if (angles.x != 0)
        RotateX(angles.x);
    if (angles.y != 0)
        RotateY(angles.y);
    if (angles.z != 0)
        RotateZ(angles.z);
}