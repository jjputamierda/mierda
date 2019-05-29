#ifndef ALGORITMO
#define ALGORITMO
#include "Poblacion.h"
#include "Ambiente.h"
#include<cstring>
class Algoritmo {

   protected:
      char nombre[100];
      Ambiente * ambientePtr;	  
	  
	public:  
	
	  virtual Poblacion * evolucionar( Poblacion * )=0;
	  
	  void asignar( Ambiente * ptr){
		  ambientePtr = ptr;
	  }
	  
	  // Pregunta al algoritmo si corresponde a un tipo de criatura
	  int esUsted(const char * nombre){
		  return !strcmp(this->nombre,nombre);  
	  }
	  
	  void setNombre(const char * nombre){
		  strncpy(this->nombre,nombre,99);
		  this->nombre[99]='\0';
	  }
	  
	  char * getNombre(){
		  return nombre;
	  }
      // Destructor virtual con implementación vacia

      virtual ~Algoritmo(){};


	  
};




#endif