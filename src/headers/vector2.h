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
};

/// Changes current values
inline void vector2::normalize() {
  float inv_len = 1.0f / std::sqrt(x * x + y * y);
  x = x * inv_len;
  y = y * inv_len;
}

inline void vector2::print() {
  std::cout << "{" << x << ", " << y << "}" << std::endl;
}
