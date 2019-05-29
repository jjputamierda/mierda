#ifndef _POBLACION_DE_CRIATURAS
#define _POBLACION_DE_CRIATURAS
#include "Criatura.h"
class Poblacion  {
   friend ostream& operator<<( ostream& salida, Poblacion * poblacionPtr ){
       if(poblacionPtr){
		   poblacionPtr->imprimir(salida);
	   }	   
	   return salida;
   }
   class Celda;
   private:
      Celda * primera;
	  Celda * ultima;


   class Celda {
      public:
         Criatura * elemento;
	     Celda * anterior;
	     Celda * siguiente;
	     Celda(Criatura *);
		 ~Celda();
   };
   
   public:
      
	  class Iterador {
		 friend class Poblacion; // Para solo la lista pueda acceder a los campos de la celda mediante el puntero actual
	     private:
		    Celda * actual;
	     public:
            Iterador();
            Iterador(Celda *);
            Iterador & operator++();
            Iterador operator++(int);
            int operator==(const Iterador &);
            int operator!=(const Iterador &);
	        Criatura * & operator*();
	  };
	  
	  Poblacion();
	  ~Poblacion();
	  Poblacion * clonar();
	  Iterador begin();
	  Iterador end();
	  void insertar(Iterador &,Criatura *);
	  ostream& imprimir( ostream&);
};
#endif