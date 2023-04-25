#include "../include/initSuperParticles.h"
#include "../include/constants.h"
#include "../include/distributeParticles.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int initSuperParticles(const int number_SPs, const struct beam beam, 
      const enum velocity_distr_function velocity_df,   
      const enum coord_distr_function coord_df,
      struct super_particle *particles, char** msg)
{
  strcpy(*msg, "");  
  strcat (*msg, __func__);      

  double *velocities_SPs;
  velocities_SPs = (double *)malloc(number_SPs*sizeof(double));

  double *coords_SPs;
  coords_SPs = (double *)malloc(number_SPs*sizeof(double));
  // Length of plasma
  double length_beam = beam.end - beam.start;
  
  // Real particles (rp) all
  double rp_all = DENSITY_FIRST * length_beam;

  // Real particles per SuperParticle
  double rp_per_sp = (int)round(rp_all / number_SPs);
  // printf("REAL PER SUPER %f\n", rp_per_sp);  

  // Charge of SuperParticlse
  double charge_sp = rp_per_sp * beam.particle.charge;
  // printf("CHARGE %f\n", charge_sp);  

  // Mass of SuperParticle
  double mass_sp = rp_per_sp * beam.particle.mass;
  // printf("MASS %f\n", mass_sp);

  // Width of SuperParticle
  double width_sp = length_beam / number_SPs;
  // printf("WIDTH %f\n", width_sp);

  switch (velocity_df)
  {
    case uniform_v:
      initParticlesVelocity(number_SPs, VELOCITY_FIRST, 
          VELOCITY_FIRST, VELOCITY_FIRST, 0,
          distribute1DVelocityUniform, velocities_SPs, msg);
      break;
    case gauss_v:
      initParticlesVelocity(number_SPs, VELOCITY_FIRST, 
        VELOCITY_FIRST, VELOCITY_FIRST, 0,
        distribute1DVelocityUniform, velocities_SPs, msg);
      break;  
    default:
      initParticlesVelocity(number_SPs, VELOCITY_FIRST, 
          VELOCITY_FIRST, VELOCITY_FIRST, 0,
          distribute1DVelocityUniform, velocities_SPs, msg);
      break;
  }

  switch (coord_df)
  {
  case uniform_c:
    initParticlesCoord(number_SPs, 0, 
      beam.start, beam.end, 0, 
      distribute1DCoordUniform,
      coords_SPs, msg);
    break;
  case solid_bunch:
    initParticlesCoord(number_SPs, 0, 
      beam.start, beam.end, 0, 
      distribute1DCoordUniform,
      coords_SPs, msg);
    break;
  
  default:
    initParticlesCoord(number_SPs, 0, 
      beam.start, beam.end, 0, 
      distribute1DCoordUniform,
      coords_SPs, msg);
    break;
  }

  for (int i = 0; i < number_SPs; i++)
  {
    particles[i].charge = charge_sp;
    particles[i].mass = mass_sp;
    particles[i].coord = coords_SPs[i];
    particles[i].velocity = velocities_SPs[i];
    particles[i].width = width_sp;
  }

  free(velocities_SPs);
  free(coords_SPs);

  strcat (*msg, "\n\t\tOK!\tSuperParticles have been initialized.");  
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

