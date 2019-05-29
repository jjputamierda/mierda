#include "Poblacion.h"

Poblacion::Celda::Celda(Criatura * elemento){
   anterior = 0;
   siguiente = 0;
   if(elemento){
      this->elemento = elemento->clonar();   
   }
   else {
	  this->elemento=elemento; 
   }
}
Poblacion::Celda::~Celda(){ 
  if(siguiente){
	  delete siguiente;
  }
  if(elemento){
	delete elemento;
  }
}

Poblacion::Iterador::Iterador(){
	actual = 0;
}

Poblacion::Iterador::Iterador(Celda * actual){
	this->actual = actual;
}

Poblacion::Iterador & Poblacion::Iterador::operator++(){
	if(actual){
		actual = actual->siguiente;
	}
    return *this;
}

Poblacion::Iterador Poblacion::Iterador::operator++(int noSeUsa){
	Iterador viejo(actual);
    ++(*this);
	return viejo;
}

int Poblacion::Iterador::operator==(const Poblacion::Iterador & otro){
	return this->actual == otro.actual;
}


int Poblacion::Iterador::operator!=(const Poblacion::Iterador & otro){
	return this->actual != otro.actual;	
}
Criatura * & Poblacion::Iterador::operator*(){
	return actual->elemento;
}

Poblacion * Poblacion::clonar(){
	Poblacion * nuevaPtr = new Poblacion();	   
	Poblacion::Iterador fin = nuevaPtr->end();
    for( Poblacion::Iterador i = this->begin(); i != this->end(); ++i){
         nuevaPtr->insertar(fin,*i);
	}
	return nuevaPtr;
}


Poblacion::Poblacion(){
	primera = 0;
	ultima = 0;
}

Poblacion::~Poblacion(){
   if(primera){
      delete primera;	   
   }
}

Poblacion::Iterador Poblacion::begin(){
	Iterador iterador(primera);
	return iterador;
}
Poblacion::Iterador Poblacion::end(){
	Iterador iterador;
	return iterador;
}

void Poblacion::insertar(Poblacion::Iterador & iterador, Criatura * valor){
	Celda * nueva = new Celda( valor );
	if(iterador==begin()){
	    if(!primera){
			primera = nueva;
			ultima = nueva;
		}
        else {
			nueva->siguiente = primera;
			primera->anterior = nueva;
			primera = nueva;
		}		
	}
	else {
		if(iterador==end()){
			nueva->anterior=ultima;
			ultima->siguiente = nueva;
			ultima = nueva;
		}
		else {
			nueva->anterior = iterador.actual->anterior;
			nueva->siguiente = iterador.actual;
			nueva->anterior->siguiente = nueva;
			nueva->siguiente->anterior = nueva;
			// iterador.actual->anterior = nueva;			
		}	
	}
}

ostream& Poblacion::imprimir( ostream& salida ){
   Poblacion::Iterador inicioIterator = begin();
   Poblacion::Iterador finalIterator = end();
   
   for(Poblacion::Iterador it = inicioIterator; it!= finalIterator; ++it){
      salida << *it;
      salida << " ";
   } 
   
   return salida;
}


















