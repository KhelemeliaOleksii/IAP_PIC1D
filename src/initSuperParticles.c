#include "../include/initSuperParticles.h"
#include "../include/constants.h"
#include "../include/distributeParticles.h"
#include <stdio.h>
#include <math.h>

int initSuperParticles(int number_SPs, struct beam beam, double *super_particles, char** msg)
{
  strcpy(*msg, "");  
  strcat (*msg, __func__);    

  // Length of plasma
  double length_beam = beam.end - beam.start;
  
  // Real particles (rp) all
  double rp_all = DENSITY_FIRST * length_beam;

  // Real particles per SuperParticle
  double rp_per_sp = (int)round(rp_all / number_SPs);

  // Charge of SuperParticlse
  double charge_sp = rp_per_sp * beam.particle.charge;

  // Mass of SuperParticle
  double mass_sp = rp_per_sp * beam.particle.mass;
  
  initParticlesVelocity(number_SPs, VELOCITY_FIRST, 
      VELOCITY_FIRST, VELOCITY_FIRST, 0,
      distribute1DVelocityUniform, velocities_SPs, &msg);
  for (int i = 0; i < number_SPs; i++)
  {
    printf("V[%d] = %f\t", i, velocities_SPs[i]);
    if (i%3 == 0) {
      printf("\n");
    }
  }
  
  printf("%s", msg);

  initParticlesCoord(number_SPs, 0, 
          plasma_borders[0], plasma_borders[1], 0, 
          distribute1DCoordUniform,
          coords_SPs, &msg);

  for (int i = 0; i < number_SPs; i++)
  {
    printf("x[%d] = %f\t", i, coords_SPs[i]);
    if (i%3 == 0) {
      printf("\n");
    }
  }
  
  printf("%s", msg);

  return 0;
}

int initParticlesVelocity(int particle_number, double beam_velocity, 
          double min_velocity, double max_velocity, double velocity_spread, 
          int distribute_function(int particle_number, double beam_velocity, 
            double min_velocity, double max_velocity, double velocity_spread, 
            double* particles_velocity, char**description),
          double *particles_velocity, char **df_description){
            
  distribute_function(particle_number, beam_velocity, 
    beam_velocity, beam_velocity, velocity_spread, 
    particles_velocity, df_description);

  return 0;
}
    
int initParticlesCoord(int particle_number, double beam_position, 
          double min_coord, double max_coord, double coord_spread, 
          int distribute_function(int particle_number, double beam_position, 
            double min_coord, double max_coord, double coord_spread, 
            double* particles_coord, char**description),
          double *particles_coord, char **df_description){

  distribute_function(particle_number, beam_position, 
            min_coord, max_coord, coord_spread, 
            particles_coord, df_description);

  return 0;
}

int test (int size, int *src_array) {
  int i;
  for (i=0; i< size; i++) {
    src_array[i] = i;
  }
  return 0;
}

int testString (int size, char **msg) {
  *msg = "Test is OK!";
  return 0;
}

