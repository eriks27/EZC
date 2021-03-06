#include <time.h>
#include <ctype.h>

#include "arraySum.h"

int main(int argc, char *argv[])
{

  /* Piefiksējam izpildes laiku */
  clock_t start, end;
  double gpu_time_used;  

      
  /* starts pirms datu inicializācijas */        
  start = clock();

  char * pEnd;
  if (argv[1])
  {
    int size_array = strtol(argv[1], &pEnd,10);
    if ( size_array <= 0)
      {
        printf("== No integer type or integer is negative ==\n");
        return 0;
      }
    else
      mainCL(size_array);
   }
   else 
    {
      printf("== No argument value ==\n");
      return 0;
    }
  
  /* pievifiksējam prgrammas izpildes beigu laiku */
  end = clock();
  
  gpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("== Total execution time ==\n");
  printf("%.2f sec.\n", gpu_time_used); 
   
}
