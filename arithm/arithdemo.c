#include <stdio.h>
#include "arith.h"

  //printf:stdio.h (header file)holds only decleration and not defination
  //every function have 
  //1.decleration
  //2.defination

int main(int argc, char const *argv[])
{
    printf("Addition= %d \n", add(65, 20));
    printf("Diff= %d \n", sub(65, 20));
    return 0;
    }