#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <array>
#include "point.hpp"

typedef std::array<std::array<float, 4>, 4> matrix4;
typedef std::array<float, 4> matrix1;

class matrix {
private:
  matrix4 m;

public:
  matrix();

  matrix operator*(const matrix& mat) const;
  matrix& operator*=(const matrix& mat);

  ogl::point operator*(const ogl::point& poi) const;

  void set_identity();

  const matrix4& get() const;
  void set(const matrix4& mat);
};

class scale : public matrix {
public:
  scale(float sx, float sy, float sz);
};

class rotate_x : public matrix {
public:
  rotate_x(float angle);
};

class rotate_y : public matrix {
public:
  rotate_y(float angle);
};

class rotate_z : public matrix {
public:
  rotate_z(float angle);
};

class translation : public matrix {
public:
  translation(float tx, float ty, float tz);
};

#endif