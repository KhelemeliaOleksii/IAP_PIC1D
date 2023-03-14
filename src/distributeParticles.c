#include <math.h>
#include "../include/distributeParticles.h"
#include "../include/constants.h"

int distribute1DVelocityUniform(int particle_number, double beam_velocity, double** particle_velocity, char**description){
  
  *description = "Uniform velocity distribution function";

  for (int i = 0; i < particle_number; i++) {
      *particle_velocity[i] = beam_velocity;
  }
  return 0;
}

int distribute1DCoordUniform(int particle_number, double start, double end, double** particle_coord, char**description){
  double x_offset;

  *description = "Uniform coordinate distribution function";
  
  //--o----o-...-o----o--//
  //  |    | ... |    |  //
  /////////////////////////
  //no particles on borders
  x_offset = (end - start)/ 2.0 / particle_number;

  for (int i = 0; i < particle_number; i++) {
      *particle_coord[i] = x_offset + 2.0 * i * x_offset;
  }
  return 0;
}
