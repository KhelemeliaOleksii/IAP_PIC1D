#ifndef INITSUPERPARTICLES_H
  #define INITSUPERPARTICLES_H

    int initParticlesCoord(int particle_number, double beam_position, 
          double min_coord, double max_coord, double coord_spread, 
          int distribute_function(int particle_number, double beam_position, 
            double min_coord, double max_coord, double coord_spread, 
            double* particles_coord, char**description),
          double *particle_velocities, char **df_description);

    int initParticlesVelocity(int particle_number, double beam_velocity, 
          double min_velocity, double max_velocity, double velocity_spread, 
          int distribute_function(int particle_number, double beam_velocity, 
            double min_velocity, double max_velocity, double velocity_spread, 
            double* particle_velocity, char**description),
          double *particle_velocities, char **df_description);

    int test (int size, int* src_array);
    
    int testString (int size, char **msg);
    
    int initSuperParticles();
#endif //INITSUPERPARTICLES_H