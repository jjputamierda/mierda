#ifndef AMBIENTE
#define AMBIENTE
#include "Criatura.h"
#include "Poblacion.h"
#include<cstring>
class Ambiente {

   protected:
      char nombre[100];
	  int cantidadCriaturas;
	  
	public:  
	  // Pregunta a un ambiente si corresponde a un tipo de criatura
	  int esUsted(const char * nombre){
		  return !strcmp(this->nombre,nombre);
		  
	  }
	  void setNombre(const char * nombre){
		  strncpy(this->nombre,nombre,99);
		  this->nombre[99]='\0';
	  }
	  
	  void setCantidadCriaturas(int cantidadCriaturas){
		  this->cantidadCriaturas=cantidadCriaturas;
	  }	  
	  
	  int getCantidadCriaturas(){
		  return cantidadCriaturas;
	  }
	  
	  char * getNombre(){
		  return nombre;
	  }
      // Destructor virtual con implementación vacia

      virtual ~Ambiente(){};

	  // Efectua: Evalua una criatura en el ambiente y retorna su valor de ajuste al ambiente
	  // 0 PEOR y 1 es el MEJOR TEÓRICO	  
      virtual double evaluar(Criatura *)=0;
	  
	  // Construye una poblacin de Criaturas del tamaño que recibe como parametro
	  // DEBE ASIGNAR SU CANTIDAD DE CRIATURAS
      virtual Poblacion * crearPoblacionInicial()=0;	  
	  
};




#endif