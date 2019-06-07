#ifndef EL_ARBOL
#define EL_ARBOL
#define HIJOS 2
#define IZQ 0
#define DER 1
#include<iostream>
#include "Pila.h"
using namespace std;
template< class T >
class Arbol {
    class Nodo;
    friend ostream& operator<<(ostream & salida, Arbol& arbol){
      if(arbol.raiz){
	     arbol.raiz->imprimir(salida);
	  }
	  return salida;
    }
   
private:
       Nodo * raiz;

    class Nodo {
      private:
	     T valor;
         Nodo * hijo[HIJOS];		 
      public:
	     Nodo(T valor){
		    this->valor = valor;
		    hijo[IZQ]=0;
			hijo[DER]=0;
		 }
		 ~Nodo(){
		    if(hijo[IZQ]){
			   delete hijo[IZQ];			   
			}
			if(hijo[DER]){
			   delete hijo[DER];			   
			}
		 }
		 void insertar(T valor){
		    if(this->valor!=valor){
			   int lado = (valor < this->valor)? IZQ : DER;
			   if(hijo[lado]){
			      hijo[lado]->insertar(valor);
			   }
			   else {
			      hijo[lado] = new Nodo(valor);
			   }
			}
		 }
		 ostream& imprimir(ostream& salida){
		    if(hijo[IZQ]){
			   hijo[IZQ]->imprimir(salida);
			}
			salida << valor << " ";
			if(hijo[DER]){
			   hijo[DER]->imprimir(salida);			
			}
		 }
    };
   
    
	   
	public:
	   class Iterador{
	   //Arbol<T>::Iterador
	   friend class Pila<Arbol<T>::Nodo*>; //Para solo la lista pueda acceder a los campos de la celda mediante el puntero actual
	   friend class Arbol<T>::Nodo;  
	     private:
		    Nodo * actual;
		    Pila<Arbol<T>::Nodo*>pila;
	     public:
            Iterador(){
            	this->actual = 0;
            	this->pila = new Pila<Arbol<T>::Nodo*>();
            }

            Iterador(Nodo *r){
                  this->pila = new Pila<Arbol<T>::Nodo*>();
                  this->actual = r;
            }
            Iterador & operator++(){
                if (actual->hijos[IZQ] || actual->hijos[DER]) {
		//Si tiene que ir a la izquierda
		if (!pila.vacia() && pila.tope()->elemento == actual->elemento) {
			//Mete el izquierdo
			pila.push(actual->hijos[IZQ]);
			//Mueve el actual al izquierdo
			actual = actual->hijos[IZQ];
		}
		//Si tiene que ir a la derecha
		if (!pila.vacia() && pila.tope()->elemento == actual->hijos[IZQ]->elemento) {
			//Saca el izquierdo
			pila.pop();
			//Mete el derecho
			pila.pop(actual->hijos[DER]);
			//Cambia actual a derecho
			actual = actual->hijos[DER];
		}
		//Si tiene que subir a partir de una hoja intermedia
		if(actual->hijos[DER]->elemento == pila.top()->elemento) {
			//Saca al derecho
			pila.pop();
			//Se saca a si mismo de manera temporal
			Nodo* tmp = pila.pop();
			//Manda el actual hacia arriba
			actual = pila.top();
			//Se vuelve a meter
			pila.push(tmp);
		}
	} else {
		Nodo* tem = pila.pop();
		//Manda el actual hacia arriba
		actual = pila.top();
		//Se vuelve a meter
		pila.push(tem);
	}
	return this;
            }
            //Corregir detalle
            Iterador operator++(int){
                if (actual->hijos[IZQ] || actual->hijos[DER]) {
		//Si tiene que ir a la izquierda
		if (!pila.vacia() && pila.tope()->elemento == actual->elemento) {
			//Mete el izquierdo
			pila.push(actual->hijos[IZQ]);
			//Mueve el actual al izquierdo
			actual = actual->hijos[IZQ];
		}
		//Si tiene que ir a la derecha
		if (!pila.vacia() && pila.tope()->elemento == actual->hijos[IZQ]->elemento) {
			//Saca el izquierdo
			pila.pop();
			//Mete el derecho
			pila.pop(actual->hijos[DER]);
			//Cambia actual a derecho
			actual = actual->hijos[DER];
		}
		//Si tiene que subir a partir de una hoja intermedia
		if(actual->hijos[DER]->elemento == pila.top()->elemento) {
			//Saca al derecho
			pila.pop();
			//Se saca a si mismo de manera temporal
			Nodo* tmp = pila.pop();
			//Manda el actual hacia arriba
			actual = pila.top();
			//Se vuelve a meter
			pila.push(tmp);
		}
	} else {
		Nodo* tem = pila.pop();
		//Manda el actual hacia arriba
		actual = pila.top();
		//Se vuelve a meter
		pila.push(tem);
	}
	return this;
            }
            int operator==(const Iterador & otro){
                 return(this->actual->valor == otro.actual.valor);
            }
            
            int operator!=(const Iterador & otro){
            	return(this->actual->valor != otro.actual.valor);
            }
	        
	        Iterador operator=(Iterador& orig) {
            pila = orig.pila();
            actual = orig.actual;
            return this;
            }
	        ~Iterador(){
	        	if(pila){
	        		delete pila;
	        	}

	        }
	  };
	   Arbol(){
		   raiz=0;
	   }
	   ~Arbol(){
		   if(raiz){
			   delete raiz;
		   }
	   }	   
	   void insertar(T valor){
		   if(raiz){
			   raiz->insertar(valor);
		   }
		   else {
			   raiz = new Nodo(valor);
		   }
	   }

      
    
           Iterador begin(){

	        Iterador it = new Iterador (raiz);
	        it -> pila.push(raiz->valor);
	        while(it->hijo[IZQ]){
	        	it->actual=it->hizo[IZQ];
	        	it-> pila.push(it->actual->valor); 
	        }
	        return it;
	   }
         Iterador end(){

	        Iterador it = new Iterador (raiz);
	        it -> pila.push(raiz->valor);
	        while(it->hijo[DER]){
	        	it->actual=it->hizo[DER];
	        	it-> pila.push(it->actual->valor); 
	        }
	        return it;
	   }

};


#endif
