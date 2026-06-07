#pragma once
#include <cmath>
#include <iostream>

// Vector2 class
class vector2 {
public:
  float x, y;

  vector2() : x(0), y(0) {}
  vector2(float x, float y) : x(x), y(y) {}

  void normalize();
  void print();
  static const float getDistanceSquare(const vector2 &v1, const vector2 &v2);
  static const vector2 getDirection(const vector2 &v1, const vector2 &v2);

  void operator+=(const vector2 &vc) {
    x += vc.x;
    y += vc.y;
  }

  vector2 operator*(const float &f) const { return {x * f, y * f}; }
  vector2 operator-(const vector2 &v) const { return {x - v.x, y - v.y}; }
};

/// Changes current values
inline void vector2::normalize() {
  if (x == 0 && y == 0)
    return;
  float inv_len = 1.0f / std::sqrt(x * x + y * y);
  x = x * inv_len;
  y = y * inv_len;
}

inline void vector2::print() {
  std::cout << "{" << x << ", " << y << "}" << std::endl;
}

inline const float vector2::getDistanceSquare(const vector2 &v1,
                                              const vector2 &v2) {
  return std::abs((v1.x - v2.x) * (v1.x - v2.x) +
                  ((v1.y - v2.y) * (v1.y - v2.y)));
}
inline const vector2 vector2::getDirection(const vector2 &v1,
                                           const vector2 &v2) {
  vector2 answ = v1 - v2;
  answ.normalize();
  return answ;
}
