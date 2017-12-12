#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


#define LEN 40
//later include library files
//#include "R2D2.h"
//#include "GENERIC.h"


//--------------------------------------------------function declarations---------------------------------------------------//

void check_array_int(int *);			//checks that array (type int) has been allocated

void check_array_double(double *);		//checks that array (type double) has been allocated

void clear_array_int(int *, int);		//clears array (type int)

void clear_array_double(double *, int);		//clears array (type double)

void *calloc(size_t n, size_t size);

double walker();				//random walk function

//void istogramma();				//creates histogram



//---------------------------------------------------------main-------------------------------------------------------------//

int main(int argc, char *argv) {		//input from terminal: number of steps (Nsteps); number of walkers (Nwalkers)



	//acquire variables from command line (syntax function checks for correct input)

	syntax(argc, argv);

	int Nsteps = atoi(argv[1]);

	int Nwalkers = atoi(argv[2]);



	//initialize seed for random number generation

	unsigned int seed;

	FILE *devran = fopen("/dev/urandom", "r");

	fread(&seed, sizeof(unsigned int), 1, devran);

	fclose(devran);

	srand(seed);







}





//------------------------------------------------------function body-------------------------------------------------------//


void check_array_int(int *array){


	if(array == NULL){


		fprintf(stderr, "Error! Dynamic memory allocation failed.\n");

		exit(EXIT_FAILURE);


	}


	return;


}

void check_array_double(double *array){


	if(array == NULL){


		fprintf(stderr, "Error! Dynamic memory allocation failed.\n");

		exit(EXIT_FAILURE);


	}


	return;


}


void clear_array_int(int *array, int N){


	int i;


	for(i=0; i<N; i++){


		array[i] = 0;


	}


	return;


}


void clear_array_double(double *array, int N){


	int i;


	for(i=0; i<N; i++){


		array[i] = 0;


	}


	return;


}


double walker(int Nsteps, int Nwalkers, double *pos, double *avg, double *var){


	int i, p;

  //file declarations to save data


	FILE *pf1, *pf2;

  char str1[LEN], str2[LEN];

  sprintf(str1, "walk_%dsteps_%dwalkers_avg.dat", Nsteps, Nwalkers);

  sprintf(str2, "walk_%dsteps_%dwalkers_pos.dat", Nsteps, Nwalkers);

  	pf1 = fopen(str1, "w");

    pf2 = fopen(str2, "w");

    fprintf(pf1, "#t\t <x>\t std_dev(x)\t <x^2>\t std_dev(x^2)\t\n ")



  //array declaration, allocation, check and clearing

	int *sums_pos, *sums_pos_2, *sums_pos_4, *avg, *avg_2, *avg_4, *var, *var_2, *std_dev, *std_dev_2;


	sums_pos = (int *)calloc(Nsteps, sizeof(int));

  check_array_int(sums_pos);

  clear_array_int(sums_pos);

	sums_pos_2 = (int *)calloc(Nsteps, sizeof(int));

  check_array_int(sums_pos_2);

  clear_array_int(sums_pos_2);

	sums_pos_4 = (int *)calloc(Nsteps, sizeof(int));

  check_array_int(sums_pos_4);

  clear_array_int(sums_pos_4);

	avg = (double *)calloc(Nsteps, sizeof(int));

  check_array_double(avg);

  clear_array_double(avg);

	avg_2 = (double *)calloc(Nsteps, sizeof(int));

  check_array_double(avg_2);

  clear_array_double(avg_2);

	avg_4 = (double *)calloc(Nsteps, sizeof(int));

  check_array_double(avg_4);

  clear_array_double(avg_4);

	var = (double *)calloc(Nsteps, sizeof(int));

  check_array_double(var);

  clear_array_double(var);

	var_2 = (double *)calloc(Nsteps, sizeof(int));

  check_array_double(var_2);

  clear_array_double(var_2);

	std_dev = (double *)calloc(Nsteps, sizeof(int));

  check_array_double(std_dev);

  clear_array_double(std_dev);

  std_dev_2 = (double *)calloc(Nsteps, sizeof(int));

  check_array_double(std_dev_2);

  clear_array_double(std_dev_2);



  //begin cycle; random number is generated from /dev/urandom and counter is incremented/decremented. Then the various quantities are calculated and saved on file

	for(i = 0; i < Nsteps; i++){


		c = random();


		if(c < 0.5){


			p++;


		}else{

			p--;

		}



		//non-averaged sums

		sums_pos[i] += p;

		sums_pos_2[i] += (p * p);

		sums_pos_4[i] += (p * p * p * p);


		//averages the sums

		avg[i] = (double) (sum_pos[i]) / (double) (Nwalkers);

		avg_2[i] = (double) (sum_pos_2[i]) / (double) (Nwalkers);

		avg_4[i] = (double) (sum_pos_4[i]) / (double) (Nwalkers);


    //variance

    var[i] = fabs(avg_2[i] - (avg[i] * avg[i]));

    var_2[i] = fabs(avg_4[i] - (avg_2[i] * avg_2[i]));


    //standard deviation

    std_dev[i] = sqrt(var[i] / (double) (Nwalkers));

    std_dev_2[i] = sqrt(var_2[i] / (double) (Nwalkers));


    //print on files

    fprintf(pf1 , "%d\t %lf\t %lf\t %lf\t %lf\t \n", i , avg[i], std_dev[i], avg_2[i], std_dev_2[i] );

    fprintf(pf2 , "%d\t %d\t %lf\t %d\t %lf\t \n", i , p, std_dev[i], (p*p), std_dev_2[i]);

  }

}
