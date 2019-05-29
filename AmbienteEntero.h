#ifndef AMBIENTE_ENTERO
#define AMBIENTE_ENTERO
#include "CriaturaEntera.h"
#include "Poblacion.h"
#include "Ambiente.h"
class AmbienteEntero : public Ambiente {
	public:
	  AmbienteEntero();
      double evaluar(Criatura *);
      Poblacion * crearPoblacionInicial();	  	  
};

#endif