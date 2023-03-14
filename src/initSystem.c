#include "../include/initSystem.h"
#include "../include/initSystem.h"
#include <stdlib.h>
#include <stdio.h>
int initSystem (int needContinue) {
  if (!needContinue) {
    // to remove previous results
    system("rm *.dat");
    fprintf(stdout, "Previous results have been removed!\n"); fflush(stdout);
    return 0;
  }
  //do something
  return 0;
}