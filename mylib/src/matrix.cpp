#include "matrix.hpp"
#include <cmath>

matrix::matrix() {
  set_identity();
}

void matrix::set_identity() {
  m = { {
    { 1.0f, 0.0f, 0.0f, 0.0f },
    { 0.0f, 1.0f, 0.0f, 0.0f },
    { 0.0f, 0.0f, 1.0f, 0.0f },
    { 0.0f, 0.0f, 0.0f, 1.0f }
  } };
}

matrix matrix::operator*(const matrix& mat) const {
  matrix result;
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      result.m[i][j] = 0.0f;
      for (int k = 0; k < 4; ++k) {
        result.m[i][j] += m[i][k] * mat.m[k][j];
      }
    }
  }
  return result;
}

matrix& matrix::operator*=(const matrix& mat) {
  *this = *this * mat;
  return *this;
}

ogl::point matrix::operator*(const ogl::point& poi) const {
  matrix1 point = {poi.x, poi.y, poi.z, 1};
  matrix1 result = {0, 0, 0, 0};

  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      result[i] += m[i][j] * point[j];
    }
  }

  return ogl::point(result[0], result[1], result[2]);
}


const matrix4& matrix::get() const {
  return m;
}

void matrix::set(const matrix4& mat) {
  m = mat;
}

scale::scale(float sx, float sy, float sz) {
  set_identity();
  matrix4 mat = get();
  mat[0][0] = sx;
  mat[1][1] = sy;
  mat[2][2] = sz;
  set(mat);
}

rotate_x::rotate_x(float angle) {
  set_identity();
  float c = std::cos(angle);
  float s = std::sin(angle);
  matrix4 mat = get();
  mat[1][1] = c;
  mat[1][2] = -s;
  mat[2][1] = s;
  mat[2][2] = c;
  set(mat);
}

rotate_y::rotate_y(float angle) {
  set_identity();
  float c = std::cos(angle);
  float s = std::sin(angle);
  matrix4 mat = get();
  mat[0][0] = c;
  mat[0][2] = s;
  mat[2][0] = -s;
  mat[2][2] = c;
  set(mat);
}

rotate_z::rotate_z(float angle) {
  set_identity();
  float c = std::cos(angle);
  float s = std::sin(angle);
  matrix4 mat = get();
  mat[0][0] = c;
  mat[0][1] = -s;
  mat[1][0] = s;
  mat[1][1] = c;
  set(mat);
}

translation::translation(float tx, float ty, float tz) {
  set_identity();
  matrix4 mat = get();
  mat[0][3] = tx;
  mat[1][3] = ty;
  mat[2][3] = tz;
  set(mat);
}