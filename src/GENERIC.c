#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include "R2D2.h"

void syntax(int argc, char* argv[]){


	if(argc != A){


		fprintf(stderr, "ERROR! Syntax %s <tmax> <n passi>\n", argv[0]);


		exit(EXIT_FAILURE);


	}


}


void check_array(int *data_array){

if(data_array == NULL){


	fprintf(stderr, "Errore allocazione dinamica di !\n")

	exit(EXIT_FAILURE);


}

}
