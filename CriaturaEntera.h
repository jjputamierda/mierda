#ifndef CRIATURAE
#define CRIATURAE
#include "Criatura.h"
class CriaturaEntera : public Criatura {
   friend class AmbienteEntero;
   private:
      int valor;
	  
   public:
      CriaturaEntera();   
      CriaturaEntera(int);
	  CriaturaEntera & setValor(int);
	  int getValor();	  
      // Recibe: Un puntero a una criatura para cruzarla con la actual
      // Efectua: Retorna un vector terminado en 0 con los hijos
      Criatura ** cruzar( Criatura * ptr);
	  
      Criatura * inverso();	  
	  
      void mutar();
      
      ostream& imprimir(ostream&);
      
      Criatura * clonar();
     
	  int operator==(Criatura *);


};




#endif