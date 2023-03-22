#ifndef TYPE_H 
  #define TYPE_H

  enum boundary_types{mirror = 0, absorb = 1, period = 2};

  struct boundary
  {
    double value;
    enum boundary_types type;
  };
  
  struct mesh_node {
    double coord;
    double charge;
    double field_E;
    double field_B;
  };
  
  struct particle_type {
    double mass;
    double charge;
  }; 
  
  enum velocity_distr_function{uniform_v = 0, gauss_v =1};
  
  enum coord_distr_function{uniform_c = 0, solid_bunch = 1, gauss_bunch =2};

 

  struct beam {
    struct particle_type  particle;
    double velocity;
    enum velocity_distr_function velocity_df;
    double velocity_spread;
    double position_center;
    enum coord_distr_function coord_df;
    double position_spread;
    double start;
    double end;
  };

  struct super_particle {
    double mass;
    double charge;
    double velocity;
    double coord;
    double width;
  };

#endif //TYPE_H