#pragma once

#include "defs.h"

class RGB;
class RGBA;

class RGBA {
public:
  ////////////////////////////////////////////////////////////
  RGBA() { }

  ////////////////////////////////////////////////////////////
  RGBA(uint40 _rgba) {
    memcpy(&rgba, &_rgba, sizeof(uint40));
  }

  ////////////////////////////////////////////////////////////
  RGBA(uint8 _r, uint8 _g, uint8 _b, uint8 _a) {
    r = _r;  g = _g; b = _b; a = _a;
  }
  
  ////////////////////////////////////////////////////////////
  union { 
    struct { uint8 r; uint8 g; uint8 b; uint8 a; };
    struct { uint40 rgba; };
  };

  RGB toRGB() {
    return RGB{r, g, b};
  }
};

class RGB {
public:
  ////////////////////////////////////////////////////////////
  RGB() { }

  ////////////////////////////////////////////////////////////
  RGB(uint32 _rgb) {
    memcpy(&rgb, &_rgb, sizeof(uint32));
  }

  ////////////////////////////////////////////////////////////
  RGB(uint8 _r, uint8 _g, uint8 _b) {
    r = _r;  g = _g; b = _b;
  }
  
  ////////////////////////////////////////////////////////////
  union { 
    struct { uint8 r; uint8 g; uint8 b;};
    struct { uint32 rgb; };
  };
};


template<size_t, class>
class Vec;

template<arithmetic T>
class Vec<2, T> {
  typedef Vec<2, T> __vec;
public:
  ////////////////////////////////////////////////////////////
  T x, y;

  ////////////////////////////////////////////////////////////
  Vec() { }

  ////////////////////////////////////////////////////////////
  Vec(T n): x(n), y(n) { }

  ////////////////////////////////////////////////////////////
  Vec(T x, T y): x(x), y(y) { }
  
  ////////////////////////////////////////////////////////////
  T operator[](size_t index) {
    if (!(index % 2)) { return x; } 
    else if (index % 2) { return y; }
  }

  ////////////////////////////////////////////////////////////
  __vec operator+=(const __vec& right) {
    x += right.x;
    y += right.y;
    return *this;
  }

  ////////////////////////////////////////////////////////////
  __vec operator-=(const __vec& right) {
    x -= right.x;
    y -= right.y;
    return *this;
  }

  ////////////////////////////////////////////////////////////
  __vec operator*=(const __vec& right) {
    x *= right.x;
    y *= right.y;
    return *this;
  }

  ////////////////////////////////////////////////////////////
  __vec operator/=(const __vec& right) {
    x /= right.x;
    y /= right.y;
    return *this;
  }
};

typedef Vec<2, float> Vec2;

////////////////////////////////////////////////////////////
template<arithmetic T>
inline Vec<2, T> operator+(const Vec<2, T>& left, const Vec<2, T>& right) {
  return Vec<2, T>(left.x+right.x, left.y+right.y);
}

////////////////////////////////////////////////////////////
template<arithmetic T>
inline Vec<2, T> operator-(const Vec<2, T>& left, const Vec<2, T>& right) {
  return Vec<2, T>(left.x-right.x, left.y-right.y);
}

////////////////////////////////////////////////////////////
template<arithmetic T>
inline Vec<2, T> operator/(const Vec<2, T>& left, const Vec<2, T>& right) {
  return Vec<2, T>(left.x/right.x, left.y/right.y);
}

////////////////////////////////////////////////////////////
template<arithmetic T>
inline Vec<2, T> operator*(const Vec<2, T>& left, const Vec<2, T>& right) {
  return Vec<2, T>(left.x*right.x, left.y*right.y);
}


template<arithmetic T>
class Vec<3, T> {
  typedef Vec<3, T> __vec;
public:
  ////////////////////////////////////////////////////////////
  T x, y, z;

  ////////////////////////////////////////////////////////////
  Vec() { }

  ////////////////////////////////////////////////////////////
  Vec(T n): x(n), y(n), z(n) { }

  ////////////////////////////////////////////////////////////
  Vec(T x, T y, T z): x(x), y(y), z(z) { }
  
  ////////////////////////////////////////////////////////////
  T operator[](size_t index) {
    if      (index % 3 == 0) { return x; } 
    else if (index % 3 == 1) { return y; }
    else if (index % 3 == 2) { return z; }
  }

  ////////////////////////////////////////////////////////////
  __vec operator+=(const __vec& right) {
    x += right.x;
    y += right.y;
    z += right.z;
    return *this;
  }

  ////////////////////////////////////////////////////////////
  __vec operator-=(const __vec& right) {
    x -= right.x;
    y -= right.y;
    z -= right.z;
    return *this;
  }

  ////////////////////////////////////////////////////////////
  __vec operator*=(const __vec& right) {
    x *= right.x;
    y *= right.y;
    z *= right.z;
    return *this;
  }

  ////////////////////////////////////////////////////////////
  __vec operator/=(const __vec& right) {
    x /= right.x;
    y /= right.y;
    z /= right.z;
    return *this;
  }
};

typedef Vec<3, float> Vec3;

////////////////////////////////////////////////////////////
template<arithmetic T>
inline Vec<3, T> operator+(const Vec<3, T>& left, const Vec<3, T>& right) {
  return Vec<3, T>(left.x+right.x, left.y+right.y, left.z+right.z);
}

////////////////////////////////////////////////////////////
template<arithmetic T>
inline Vec<3, T> operator-(const Vec<3, T>& left, const Vec<3, T>& right) {
  return Vec<3, T>(left.x-right.x, left.y-right.y, left.z-right.z);
}

////////////////////////////////////////////////////////////
template<arithmetic T>
inline Vec<3, T> operator/(const Vec<3, T>& left, const Vec<3, T>& right) {
  return Vec<3, T>(left.x/right.x, left.y/right.y, left.z/right.z);
}

////////////////////////////////////////////////////////////
template<arithmetic T>
inline Vec<3, T> operator*(const Vec<3, T>& left, const Vec<3, T>& right) {
  return Vec<3, T>(left.x*right.x, left.y*right.y, left.z*right.z);
}
