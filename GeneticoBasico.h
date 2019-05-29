#ifndef ALGORITMOGENETICOBASICO
#define ALGORITMOGENETICOBASICO
#include "Poblacion.h"
#include "Algoritmo.h"
#include<ctime>
#define PROBABILIDAD_MUTUACION 15
class GeneticoBasico: public Algoritmo {
	public:
	   GeneticoBasico();
       Poblacion * evolucionar( Poblacion * );
};

#endif