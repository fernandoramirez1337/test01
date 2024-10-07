#ifndef PIZZA_HPP
#define PIZZA_HPP

#include "point.hpp"

namespace ogl {
class pizza {
public:
  ogl::point cero, uno, dos, tres, cuatro, cinco, seis, siete, ocho;
  unsigned int VBOs[1], VAOs[1], EBOs[1];
  pizza();
  ~pizza();

  void move(const ogl::vector&);

  void get_vertices(float*) const;
  void get_indices(unsigned int*, unsigned int = 0) const;
};
}

#endif