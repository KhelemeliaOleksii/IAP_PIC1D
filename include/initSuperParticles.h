#ifndef INITSUPERPARTICLES_H
  #define INITSUPERPARTICLES_H
    int initParticlesPosition(int particle_number, double **borders, int distribute_function(int, double, double, double**, char**), double **particle_position, char **function_description);

    int initParticlesVelocity(int particle_number, double beam_velocity, int distribute_function(int, double, double**, char**), double **particle_velocity, char **function_description);

    int initSuperParticles();
#endif //INITSUPERPARTICLES_H