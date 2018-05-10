#ifndef VECTOR3D_VECTOR3D_H_

#define VECTOR3D_VECTOR3D_H_

#include <ostream>
#include <istream>

class Vector3D {
public:
    // constructors and destructors for the class
    Vector3D();
    Vector3D(double x, double y, double z);
    ~Vector3D();

    // getters for the member variables
    double getX() const;
    double getY() const;
    double getZ() const;

    // member operators for the class
    Vector3D operator+(const Vector3D& secondVector) const;
    Vector3D operator-(const Vector3D& secondVector) const;
    Vector3D operator-() const;
    Vector3D operator*(double number) const;

    // friend operators
    friend Vector3D operator*(double number, const Vector3D& vector);
    friend std::istream& operator>>(std::istream& iStream, Vector3D& vector);
    friend std::ostream& operator<<(std::ostream& oStream, const Vector3D& vector);

private:
    double x_;
    double y_;
    double z_;
};


#endif
