#include <math.h>
#include "../include/distributeParticles.h"
#include "../include/constants.h"



// int distribute1DVelocityUniform(char**description){

int distribute1DVelocityUniform(int particle_number, double beam_velocity, 
        double min_velocity, double max_velocity, double spread, 
        double* particle_velocity, char **msg){
  strcat (*msg, "\n\tUniform velocity distribution function with spread");    

  for (int i = 0; i < particle_number; i++) {
      particle_velocity[i] = beam_velocity;
  }
  return 0;
}

int distribute1DCoordUniform(int particle_number, double beam_position, 
        double min_coord, double max_coord, double spread, 
        double* particles_coord, char**msg){

  strcat (*msg, "\n\tUniform 1D coordinate distribution function");    
  
  double x_offset;
    
  //--o----o-...-o----o--//
  //  |    | ... |    |  //
  /////////////////////////
  //no particles on borders
  x_offset = (max_coord - min_coord)/ 2.0 / particle_number;

  for (int i = 0; i < particle_number; i++) {
      particles_coord[i] = x_offset + 2.0 * i * x_offset;
  }

  return 0;
}
