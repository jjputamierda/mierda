#ifndef ALGORITMOGENETICOSUERTUDO
#define ALGORITMOGENETICOSUERTUDO
#include "Poblacion.h"
#include "Algoritmo.h"
#include<ctime>
#define PROBABILIDAD_M 10
class GeneticoSuertudo: public Algoritmo {
	public:
	   void quicksort(double * &,Criatura * & ,int ,int);
       void swap(double * & , Criatura * & ,int , int );
	   GeneticoSuertudo();
       Poblacion * evolucionar( Poblacion * );
};

#endif