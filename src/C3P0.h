//file header per le funzioni di "base" non inerenti al random walk
#ifndef R2D2_H_
#define R2D2_H_

#define PARS 3
#define a 16807ULL
#define m (0x7FFFFFFF)


//-------------------------------------------------------typedef------------------------------------------------------------//


typedef struct{


	int walkers, origin;


}par;



//-----------------------------------------------prototipi delle funzioni---------------------------------------------------//


void syntax(int, char**);

void empty(double *, int);	//azzera gli array



#endif

/*END R2D2.h*/
