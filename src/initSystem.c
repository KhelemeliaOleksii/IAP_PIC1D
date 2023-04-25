#include "../include/initSystem.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int initSystem (int isNeedContinue, char **msg) {
  strcpy(*msg, "");  
  strcat (*msg, __func__);    

  if (!isNeedContinue) {
    // to remove previous results
    if (system("rm *.dat") == 0) {
      strcat (*msg, ": Previous results have been removed!");    
    }
    strcat (*msg, "\n\t\tOK!");  
    return 0; 
  }

  //do something
  return -1;
}