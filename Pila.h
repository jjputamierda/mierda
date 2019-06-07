#ifndef _PILA
#define _PILA
template < class T >
class Pila {
	
	private:
	
	   class Celda {
	      public:
             Celda * siguiente;
             T elemento;		  
		     Celda(T elemento){
			    this->elemento = elemento;
			    siguiente = 0;
		     }
			 ~Celda(){
				 if(siguiente){
					 delete siguiente;
				 }
			 }
	   };
	
	   Celda * tope;
	
	public:
	     Pila(){
	     	tope = 0;
	     }
		  
	  
	   
       ~Pila(){
		  if(tope){
			  delete tope;
		  }
	   }
	   
	   int vacia(){
		   return !tope;
	   }
	   
	   T pop(){
	       T resp;
           if(tope){
			  resp = tope->elemento; 
		      Celda * victima = tope;
		      tope= tope->siguiente;
		      victima->siguiente=0;
		      delete victima;
		   }
		   return resp;
	   }
	   
	   T top(){
	      return (tope)?tope->elemento:0;		   
	   }
	   void push(T elemento){
		   Celda * nueva = new Celda(elemento);
		   nueva->siguiente = tope;
           tope = nueva;
	   }
};

#endif