#include "Vector3D.h"



Vector3D::Vector3D () : x_(0), y_(0), z_(0) {
}

Vector3D::Vector3D (double x, double y, double z) : x_(x), y_(y), z_(z) {
}

Vector3D::~Vector3D () {
}



double Vector3D::getX () const {
    return x_;
}

double Vector3D::getY () const {
    return y_;
}

double Vector3D::getZ () const {
    return z_;
}



Vector3D Vector3D::operator+ (const Vector3D& secondVector) const {
    Vector3D result(x_ + secondVector.x_, y_ + secondVector.y_, z_ + secondVector.z_);
    return result;
}

Vector3D Vector3D::operator- (const Vector3D& secondVector) const {
    Vector3D result(x_ - secondVector.x_, y_ - secondVector.y_, z_ - secondVector.z_);
    return result;
}

Vector3D Vector3D::operator- () const {
    Vector3D result(-x_, -y_, -z_);
    return result;
}

#include<iostream>
using namespace std;
Vector3D Vector3D:: operator* (double number) const {
    Vector3D result(x_ * number, y_ * number, z_ * number);
    return result;
}



Vector3D operator* (double number, const Vector3D& vector) {
    Vector3D result(number * vector.x_, number* vector.y_, number * vector.z_);
    return result;
}

std::istream& operator>> (std::istream& iStream, Vector3D& vector) {
    char sign; // variable containing symbols like ) or ( or ,
    iStream >> sign >> vector.x_ >> sign >> vector.y_ >> sign >> vector.z_ >> sign ;
    return iStream;
}

std::ostream& operator<< (std::ostream& oStream, const Vector3D& vector) {
    oStream << '(' << vector.x_ << ',' << vector.y_ << ',' << vector.z_ << ')' ;
    return oStream;
}
