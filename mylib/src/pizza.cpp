#include "pizza.hpp"

#include <cstring> 

ogl::pizza::pizza() : 
cero( 0.00f, 0.50f, 0.0f),
uno( 0.37f, 0.37f, 0.0f),
dos( 0.50f, 0.00f, 0.0f),
tres( 0.37f,-0.37f, 0.0f),
cuatro( 0.00f,-0.50f, 0.0f),
cinco(-0.37f,-0.37f, 0.0f),
seis(-0.50f, 0.00f, 0.0f),
siete(-0.37f, 0.37f, 0.0f),
ocho( 0.00f, 0.00f, 0.0f) {}

ogl::pizza::~pizza() { }

void ogl::pizza::move(const ogl::vector& v) {
  cero += v;
  uno += v;
  dos += v;
  tres += v;
  cuatro += v;
  cinco += v;
  seis += v;
  siete += v;
  ocho += v;
}

void ogl::pizza::get_vertices(float* vertices) const {
  vertices[0] = cero.x;  vertices[1] = cero.y;  vertices[2] = cero.z;
  vertices[3] = uno.x;  vertices[4] = uno.y;  vertices[5] = uno.z;
  vertices[6] = dos.x;  vertices[7] = dos.y;  vertices[8] = dos.z;
  vertices[9] = tres.x;  vertices[10] = tres.y;  vertices[11] = tres.z;
  vertices[12] = cuatro.x;  vertices[13] = cuatro.y;  vertices[14] = cuatro.z;
  vertices[15] = cinco.x;  vertices[16] = cinco.y;  vertices[17] = cinco.z;
  vertices[18] = seis.x;  vertices[19] = seis.y;  vertices[20] = seis.z;
  vertices[21] = siete.x;  vertices[22] = siete.y;  vertices[23] = siete.z;
  vertices[24] = ocho.x;  vertices[25] = ocho.y;  vertices[26] = ocho.z;
}

void ogl::pizza::get_indices(unsigned int* indices, unsigned int base) const {
  indices[0] = 0;  indices[1] = 1;
  indices[2] = 1;  indices[3] = 2;
  indices[4] = 2;  indices[5] = 3;
  indices[6] = 3;  indices[7] = 4;
  indices[8] = 4;  indices[9] = 5;
  indices[10] = 5;  indices[11] = 6;
  indices[12] = 6;  indices[13] = 7;
  indices[14] = 7;  indices[15] = 0;
  indices[16] = 0;  indices[17] = 8;
  indices[18] = 1;  indices[19] = 8;
  indices[20] = 2;  indices[21] = 8;
  indices[22] = 3;  indices[23] = 8;
  indices[24] = 4;  indices[25] = 8;
  indices[26] = 5;  indices[27] = 8;
  indices[28] = 6;  indices[29] = 8;
  indices[30] = 7;  indices[31] = 8;

}

