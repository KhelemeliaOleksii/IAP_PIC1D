#include <stdio.h>

#include "runModel.h"
#include "initSystem.h"
#include "initSuperParticles.h"
int main () {
    printf("hello\n");

    initSystem(0);

    initSuperParticles();
    return 0;
}