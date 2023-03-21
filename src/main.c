#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/types.h"
#include "../include/constants.h"
#include "../include/initLayout.h"
#include "../include/initSystem.h"
#include "../include/initSuperParticles.h"

int main () {
    printf("hello\n");

    // array to a description of a procedure work;
    char procedure_description[200];
    char *ptr_procedure_description = procedure_description;

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

    //to initialize borders of the physical system
    enum boundary_types boundary_type = absorb;
    struct boundary boundaries[2];

    if (initLayout(BORDER_XMIN, boundary_type, BORDER_XMAX, boundary_type, boundaries, &ptr_procedure_description) < 0) {
        printf("ERROR! Exit with failure!\n\t%s\n", ptr_procedure_description );
        exit(1);
    } else {
        printf("%s\n", ptr_procedure_description);
        // int i=0;
        // for (i = 0; i < 2; i++){
        //     printf("Bou %i = %e, type %d\n", i, boundaries[i].value, boundaries[i].type);
        // }
    };
    
    //  // array to particles coord
    // double particles_coord[(int)SUPERPRTCLS];
    // // array to particles velocity
    // double particles_velocity[(int)SUPERPRTCLS];

    // initSuperParticles(SUPERPRTCLS, MESHCELLS, MESHCELL_LENGTH, particles_coord, particles_velocity);

    // // to initialize LAYOUT of experiment
    //initLayout();

    // to initialize PARTICLE initial condition 
    // - positions
    // - velocities
    //initParticles();

    // to initialize ELECTRO-MAGNETICS FIELDS
    // - eletric fieds E
    // - magnetic fields B
    //initFields();

    // to carry out PERFORMING
    // use initial condition to start calculatiion
    // perform();

    return 0;
}