#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "../include/types.h"
#include "../include/constants.h"
#include "../include/initSystem.h"
#include "../include/initLayout.h"
#include "../include/initMesh.h"
#include "../include/initRealParticle.h"
#include "../include/initBeam.h"
#include "../include/initSuperParticles.h"

int main () {
    printf("hello\n");

    // array to a description of a procedure work;
    char procedure_description[200];
    char *ptr_procedure_description = procedure_description;
    
    ///////////////////////////////////////////////
    // to initialize SYSTEM
        // will need to be coding 
        // - remove/replace/save/rename log-file and files with previous results
        // - create new directories and files to save task parameters and results
        // - create log-file 
    if (initSystem(0, &ptr_procedure_description) < 0) {
        printf("Exit with failure!\n %s\n", ptr_procedure_description );
        exit(1);
    } else {
        printf("%s\n", ptr_procedure_description);
    };

    ///////////////////////////////////////////////
    //to initialize borders of the physical system
    enum boundary_types boundary_type = absorb;
    struct boundary boundaries[2];

    if (initLayout(BORDER_XMIN, boundary_type, BORDER_XMAX, boundary_type, boundaries, &ptr_procedure_description) < 0) {
        printf("ERROR! Exit with failure!\n\t%s\n", ptr_procedure_description );
        exit(1);
    } else {
        printf("%s\n", ptr_procedure_description);
    };
    
    
    ///////////////////////////////////////////////
    //to initialize nodes of the mesh
    // will need to be coding 
    // - error handler
    // - check errors  
    int number_nodes;
    countNodes(MESHCELL_LENGTH, boundaries, &number_nodes);

    struct mesh_node *nodes;
    nodes = (struct mesh_node*)malloc((number_nodes)*sizeof(struct mesh_node));
    if (initMesh(number_nodes, MESHCELL_LENGTH, nodes, &ptr_procedure_description) < 0) {
        printf("ERROR! Exit with failure!\n\t%s\n", ptr_procedure_description );
        exit(1);
    } else {
        printf("%s\n", ptr_procedure_description);
    };

    //////////////////////////////////////////////////
    // to initialize real particle type
    struct particle_type particle_1;

    // The first type of particle
    if (initRealParticle(-1, ELEM_CHARGE, 1, ELECTRON_MASS, &particle_1, &ptr_procedure_description) < 0) {
        printf("ERROR! Exit with failure!\n\t%s\n", ptr_procedure_description );
        exit(1);
    } else {
        printf("%s\n", ptr_procedure_description);
    };


    ///////////////////////////////////////////////
    //to initialize beam parameter
    struct beam beam_1;

    initBeam(particle_1, VELOCITY_FIRST, uniform_v, 0, boundaries, 0.5, uniform_c, 0, 0.1, 0.1, &beam_1, &ptr_procedure_description);
    // printf("particle charge %f,\n\t mass %f\n", beam_1.particle.charge, beam_1.particle.mass);
    // printf("beam velocity %f,\n", beam_1.velocity);
    // printf("beam velocity distribution function %d,\n", beam_1.velocity_df);
    // printf("beam velocity spread %f,\n", beam_1.velocity_spread);
    // printf("beam position %f,\n", beam_1.position_center);
    // printf("beam coord ditributon function %d,\n", beam_1.coord_df);
    // printf("beam position spread %f,\n", beam_1.position_spread);
    // printf("beam offset start %f,\n", beam_1.offset_start);
    // printf("beam offset end %f,\n", beam_1.offset_end);

    printf("%s\n", ptr_procedure_description);

    //////////////////////////////////////////////////
    // to initialize SUPER PARTICLES initial condition 
    // - positions
    // - velocities
    struct super_particle super_particles[(int)SUPERPRTCLS];

    enum velocity_distr_function velocity_df = uniform_v;
  
    enum coord_distr_function coord_df = uniform_c;

    initSuperParticles((int)SUPERPRTCLS, beam_1,velocity_df, coord_df, &super_particles, &ptr_procedure_description);

    // to initialize ELECTRO-MAGNETICS FIELDS
    // - eletric fieds E
    // - magnetic fields B
    //initFields();

    // to carry out PERFORMING
    // use initial condition to start calculatiion
    // perform();
    free(nodes);
    return 0;
}