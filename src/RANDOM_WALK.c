 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <time.h>

//inserisco le librerie specifiche
//#include "R2D2.h"
//#include "GENERIC.h"



void *calloc(size_t n, size_t size);

//double myrand(void);	decidere se usare un LCG o se prendere il numero random da /dev/urandom

double walker(); //

//void istogramma();



int main(int argc, char *argv) {

	unsigned int seed;

	FILE *fp;

	fp = fopen("walk.dat", "w");



	//init seed

  	FILE *devran = fopen("/dev/urandom", "r");

	fread(&seed, sizeof(unsigned int), 1, devran);

	fclose(devran);


	srand(seed);



	int *pos, *avg, *var;	//dichiarazione array per posizione, media e varianza


	//allocazione dinamica array

	pos = (int *)calloc(Nsteps+1, sizeof(int));

	avg = (int *)calloc(Nsteps+1, sizeof(int));

	var = (int *)calloc(Nsteps+1, sizeof(int));


	//controllo allocazione -> scrivere poi funzione che prende in input il nome dell'array e fa il check

	if(pos == NULL){


		fprintf(stderr, "Errore allocazione dinamica di pos!\n")

		exit(EXIT_FAILURE);


	}else if(avg == NULL){


		fprintf(stderr, "Errore allocazione dinamica di avg!\n")

		exit(EXIT_FAILURE);


	}else if(var == NULL){


		fprintf(stderr, "Errore allocazione dinamica di var!\n")

		exit(EXIT_FAILURE);


	}








}


/*double myrand(void){



}*/

double walker(par data, double *pos, double *avg, double *var){


	int i;


	FILE *pf;

  	pf = fopen("walk_%dsteps_%dwalkers.dat", "w");



	for(i = 0; i < N; i++){


		c = random();


		if(c < 0.5){


			p++;


		}else{

			p--;

		}



		pos[i] += p;



}
