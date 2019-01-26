#include "simd.p5.h"

float Randf(float low, float high) 
{
  float r = (float)rand();
  return (low + r * (high - low) / (float)RAND_MAX);
}

void Mul(float *A, float *B, float *C, int length) {
    for (int i = 0; i < length; i++) {
        C[i] = A[i] * B[i];
    }
}

float MulSum(float *A, float *B, int length) {
    float sum = 0.0;
    for (int i = 0; i < length; i++) {
        sum += A[i] * B[i];
    }
    return sum;
}


int main()
{

	#ifndef _OPENMP
		fprintf(stderr, "OpenMP is not available\n");
	     return 1;
	#endif

	 float maxPerformance = 0.0,
	 		averagePerformance = 0.0,
	 		currentPerformance = 0.0,
	 		sumPerformance = 0.0;

	// Setup arrays
	  float *A = new float[LEN],
	  		*B = new float[LEN],
	  		*C = new float[LEN];

	  for(int i = 0; i < LEN; i++)
	  {
	  	A[i] = Randf(0.1f, 1.f);
	  	B[i] = Randf(0.1f, 1.f);
	  }   

	  float result0, result1;

	  for(int i = 0; i < 100; i++)
	  {
		  double time0 = omp_get_wtime();

		#ifdef SSE_ARRAY_MULT
		     //printf("SSE_ARRAY_MULT, ");
		     SimdMul(A, B, C, LEN);
		#endif

		#ifdef ARRAY_MULT
		     //printf("ARRAY_MULT, ");
		     Mul(A, B, C, LEN);
		#endif

		#ifdef SSE_MULT_RED
		     //printf("SSE_MULT_RED, ");
		     result0 = SimdMulSum(A, B, LEN);
		#endif

		#ifdef MULT_RED
		     //printf("MULT_RED, ");
		     result1 = MulSum(A, B, LEN);
		#endif

		 double time1 = omp_get_wtime();
		 currentPerformance = (double)LEN/(time1 - time0)/1000000;

		 if(maxPerformance < currentPerformance)
		 {
		 	maxPerformance = currentPerformance;
		 }
		 sumPerformance += currentPerformance;

		}
	
	averagePerformance = sumPerformance / 100;

	//printf("%8.2f, %8.2f\n", maxPerformance, averagePerformance);
	printf("\t\t%8.2f,\t", maxPerformance);

}