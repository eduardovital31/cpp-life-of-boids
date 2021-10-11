#pragma once

class Vec2 {
private:
    double m_x;
    double m_y;

public:
    Vec2();
    Vec2(float, float);
    Vec2(const Vec2& other);

public:
    float x() const; // return the x value
    float y() const; // return the y value
    Vec2 operator+(const Vec2 &other); // add vectors
    Vec2 operator-(const Vec2 &other) const; // substract vectors
    Vec2 operator*(const Vec2 &other); // multiply vectors term by term
    Vec2 operator*(const float &other); // scale the vector
    Vec2 operator/(const float &other); // scale the vector
    Vec2& operator=(const Vec2 &other); // assign vector
    float dot(Vec2 other); // return the scalar product
    float norm() const; // return the norm of the vector
    Vec2 normalize(); // return the current vector normalized
    float angle(); // return the angle between the current vector and `Vec2(1, 0)`
    float anglebt(Vec2 other); // return the angle between the current vector and an other vector
    void print(); // display the vector in shell
};
