#ifndef ALGORITMOCRUEL
#define ALGORITMOCRUEL
#include "Poblacion.h"
#include "Algoritmo.h"
#include<ctime>
#define PROBABILIDAD_MUTUACION 2
class AlgoritmoCruel: public Algoritmo {
	public:
	   AlgoritmoCruel();
       Poblacion * evolucionar( Poblacion * );
};

#endif
