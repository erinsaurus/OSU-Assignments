/*********************************************
 ** Erin Alltop
 ** CS475 - Spring 2018
 ** Project 3
 ** False Sharing
 *********************************************/
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <omp.h>


#ifdef FIX1
struct s
{
    float value;
    int pad[NUM];
} Array[8];


int main(int argc, char * argv[]) 
{

    #ifndef _OPENMP
      fprintf(stderr, "OpenMP is not available\n");
      return 1;
    #endif

    omp_set_num_threads( NUMT );

    double time0 = omp_get_wtime();

    int someBigNumber = 1000000000;

    #pragma omp parallel for
    for(int i = 0; i < 8; i++)
    {
        float tmp = Array[i].value;
        for(int j = 0; j < someBigNumber; j++)
        {
           Array[i].value = Array[i].value + 2.;
        }
        Array[i].value = tmp;
    }

    double time1 = omp_get_wtime();
    double megaAdds = (((double)8. * someBigNumber)/(time1-time0)/1000000);

    printf("%f, ", megaAdds);
    return 0;
}
#endif

#ifdef FIX2
struct s
{
    float value;
} Array[8];


int main(int argc, char * argv[]) 
{

    #ifndef _OPENMP
      fprintf(stderr, "OpenMP is not available\n");
      return 1;
    #endif

    omp_set_num_threads( NUMT );

    double time0 = omp_get_wtime();

    int someBigNumber = 1000000000;

    #pragma omp parallel for
    for(int i = 0; i < 8; i++)
    {
        float tmp = Array[i].value;
        for(int j = 0; j < someBigNumber; j++)
        {
            tmp = tmp + 2.;
        }
        Array[i].value = tmp;
    }

    double time1 = omp_get_wtime();
    double megaAdds = (((double)8. * someBigNumber)/(time1-time0)/1000000);

    printf("%f, ", megaAdds);
    return 0;
}
#endif