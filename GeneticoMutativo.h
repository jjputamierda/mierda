#ifndef ALGORITMOMUTATIVO
#define ALGORITMOMUTATIVO
#include "Poblacion.h"
#include "Algoritmo.h"
#include<ctime>
#define PROBABILIDAD_MUTUACION 50
class AlgoritmoMutativo: public Algoritmo {
	public:
	  AlgoritmoMutativo();
    Poblacion * evolucionar( Poblacion * );
};

#endif
