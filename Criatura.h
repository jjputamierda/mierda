#ifndef CRIATURA
#define CRIATURA
#include<iostream>
using namespace std;
class Criatura {
   friend ostream& operator<<(ostream& salida,Criatura * ptr){
	   if(ptr){
		  ptr->imprimir(salida); 
	   }
	   return salida;
   }
   public:
      // Destructor virtual con implementación vacia
      virtual ~Criatura(){};
	  
      // Recibe: Un puntero a una criatura para cruzarla con la actual
      // Efectua: Retorna un vector terminado en 0 con los hijos
      virtual Criatura ** cruzar( Criatura * )=0;
	  
      // Efecto: Aplica una mutación a la criatura
	  virtual void mutar()=0;
      
	  virtual ostream& imprimir(ostream&)=0;
      
      virtual Criatura * clonar()=0;

      virtual Criatura * inverso()=0;
	  
      virtual int operator==( Criatura *)=0;
};




#endif