#include <math.h>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

int		NowYear;		// 2017 - 2022
int		NowMonth;		// 0 - 11

float	NowPrecip;		// inches of rain per month
float	NowTemp;		// temperature this month
float	NowHeight;		// grain height in inches
int		NowNumDeer;		// number of deer in the current population
float	ExcessGrowth = 0.0;   // extra growth due to fertilizer

const float GRAIN_GROWS_PER_MONTH =		8.0;
const float ONE_DEER_EATS_PER_MONTH =	0.5;

const float AVG_PRECIP_PER_MONTH =		6.0;	// average
const float AMP_PRECIP_PER_MONTH =		6.0;	// plus or minus
const float RANDOM_PRECIP =				2.0;	// plus or minus noise

const float AVG_TEMP =					50.0;	// average
const float AMP_TEMP =					20.0;	// plus or minus
const float RANDOM_TEMP =				10.0;	// plus or minus noise

const float MIDTEMP =					40.0;
const float MIDPRECIP =					10.0;

const float SCAM_MINTEMP = 	  		   	50.0;
const float SCAM_MAXPRECIP = 			 8.0;


void GrainDeer();
void Grain();
void Watcher();
void FertilizerScam();


unsigned int seed = time(NULL);  // a thread-private variable
//float x = Ranf( &seed;, -1.f, 1.f );

float SQR( float x )
{
        return x*x;
}

float Ranf( unsigned int *seedp,  float low, float high )
{
        float r = (float) rand_r( seedp );              // 0 - RAND_MAX

        return(   low  +  r * ( high - low ) / (float)RAND_MAX   );
}

int main()
{

	// starting date and time:
	NowMonth =    0;
	NowYear  = 2017;

	// starting state (feel free to change this if you want):
	NowNumDeer = 1;
	NowHeight =  1.;
	ExcessGrowth = 0.;

	  printf("Date\tPrecip\tTemp\tHeight\tDeer\tExcess Growth\n");

	omp_set_num_threads( 4 );	// same as # of sections
	#pragma omp parallel sections
	{
		#pragma omp section
		{
			GrainDeer( );
		}

		#pragma omp section
		{
			Grain( );
		}

		#pragma omp section
		{
			Watcher( );
		}

		#pragma omp section
		{
			FertilizerScam( );	// your own
		}
	}       // implied barrier -- all functions must return in order
	// to allow any of them to get past here
}


void GrainDeer()
{
	while( NowYear < 2023 )
	{
	// compute a temporary next-value for this quantity
	// based on the current state of the simulation:
	float height = NowHeight;
	int deer = NowNumDeer;

	if(deer > height)
		deer--;
	else if (deer < height)
		deer++;

	// DoneComputing barrier:
	#pragma omp barrier
	NowNumDeer = deer;

	// DoneAssigning barrier:
	#pragma omp barrier
	

	// DonePrinting barrier:
	#pragma omp barrier
	
	}
}

void Grain()
{
	while( NowYear < 2023 )
	{
	// compute a temporary next-value for this quantity
	// based on the current state of the simulation:
	float height = NowHeight;

	float tempFactor = exp(   -SQR(  ( NowTemp - MIDTEMP ) / 10.  )   );
	float precipFactor = exp(   -SQR(  ( NowPrecip - MIDPRECIP ) / 10.  )   );

	 height += tempFactor * precipFactor * GRAIN_GROWS_PER_MONTH;
	 height -= (float)NowNumDeer * ONE_DEER_EATS_PER_MONTH;
	 if(height < 0)
	 	height = 0;

	 height += ExcessGrowth;

	// DoneComputing barrier:
	#pragma omp barrier
	NowHeight = height;

	// DoneAssigning barrier:
	#pragma omp barrier
	

	// DonePrinting barrier:
	#pragma omp barrier
	
	}
}

void Watcher()
{
	while( NowYear < 2023 )
	{
	// compute a temporary next-value for this quantity
	// based on the current state of the simulation:
	

	// DoneComputing barrier:
	#pragma omp barrier
	

	// DoneAssigning barrier:
	#pragma omp barrier

	float celsius = 5 * (NowTemp - 32) / 9;
	float tempCM = NowPrecip * 2.54;
	float tempEG = ExcessGrowth * 2.54;

	printf("%d-%d\t%6.2f\t%6.2f\t%6.2f\t%d\t%6.2f\n", NowMonth+1, NowYear, tempCM, celsius, NowHeight, NowNumDeer, tempEG);

	if(NowMonth == 11)
	{
		NowMonth = 0;
		NowYear++;
	}
	else NowMonth++;

	float ang = (  30.*(float)NowMonth + 15.  ) * ( M_PI / 180. );

	float temp = AVG_TEMP - AMP_TEMP * cos( ang );
	NowTemp = temp + Ranf( &seed, -RANDOM_TEMP, RANDOM_TEMP );

	float precip = AVG_PRECIP_PER_MONTH + AMP_PRECIP_PER_MONTH * sin( ang );
	NowPrecip = precip + Ranf( &seed,  -RANDOM_PRECIP, RANDOM_PRECIP );

	if( NowPrecip < 0. )
	NowPrecip = 0.;

	// DonePrinting barrier:
	#pragma omp barrier
	
	}
}

// Every once in a while the CEO of a local fertlizer company
// dumps a sizable amount of fertilizer in the graindeer fields
// out of the goodness of his heart and not due to an embezzlement scheme
// He only comes if it isn't likely to rain. He does not own an umbrella. Too expensive.
void FertilizerScam()
{
	while( NowYear < 2023 )
	{
	// compute a temporary next-value for this quantity
	// based on the current state of the simulation:
	float scam = ExcessGrowth;

	if(NowPrecip <= SCAM_MAXPRECIP && NowTemp >= SCAM_MINTEMP)
	{
		scam = NowHeight * 0.10; // max dumping 
	}
	else if(NowPrecip > SCAM_MAXPRECIP && NowTemp >= SCAM_MINTEMP)
	{
		scam = NowHeight * 0.05; // rainy, but at least it isn't too cold
	}
	else if(NowPrecip <= SCAM_MAXPRECIP && NowTemp <= SCAM_MINTEMP)
	{
		scam = NowHeight * 0.01; // freezing, but at least it isn't too rainy
	}
	else
		scam = 0.0; // not today!

	// DoneComputing barrier:
	#pragma omp barrier
	ExcessGrowth = scam;

	// DoneAssigning barrier:
	#pragma omp barrier
	

	// DonePrinting barrier:
	#pragma omp barrier
	
	}
}



