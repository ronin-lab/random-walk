 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <time.h>

//inserisco le librerie specifiche
#include "R2D2.h"
//#include "C3P0.h"





//double myrand(void);	decidere se usare un LCG o se prendere il numero random da /dev/urandom

double AT-AT(); //un walker come gli AT-AT

//void istogramma();



int main() {

	srand(time(NULL));

	FILE *fp;

	fp = fopen("walk.dat", "w");


}


double myrand(void){



}

double AT-AT(par data, double *pos, double *var){


	int i;


	FILE *pf;

  	pf = fopen("walk_%dsteps_%dwalkers.dat", "w");

	

	for(i = 0; i < N; i++){


		c = random();

		
		if(c < 0.5){


			p = 1;


		}else{

	}

}
