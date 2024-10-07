#ifndef ESTRELLA_HPP
#define ESTRELLA_HPP

#include "triangle.hpp"
#include "point.hpp"

namespace ogl {
class estrella {
public:
  ogl::point cero, uno, dos, tres, cuatro, cinco, seis, siete, ocho, nueve;
  unsigned int VBOs[1], VAOs[1], EBOs[1];
  estrella();
  ~estrella();

  void move(const ogl::vector&);

  void get_vertices(float*) const;
  void get_indices(unsigned int*, unsigned int = 0) const;
};
}

#endif