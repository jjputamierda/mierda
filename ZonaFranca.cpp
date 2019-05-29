#include "ZonaFranca.h"


ZonaFranca::ZonaFranca(){
	ambienteCounter = 0;
	algoritmoCounter = 0;
	ambiente[ambienteCounter++] = new AmbienteEntero();
  //  ambiente[ambienteCounter++] = new AmbienteMochila();
	// ambiente[ambienteCounter++] = new OTRO_AMBIENTE_MAS();
    // Y PUEDEN AGREGAR LINEAS MAS LINEA SIMILARES
    
	algoritmo[algoritmoCounter++] = new GeneticoBasico();
    //algoritmo[algoritmoCounter++] = new SuperGenetico();
    // 	algoritmo[algoritmoCounter++] = new Y_SOLO_ESTO_OTRO_PUEDEN_TOCAR();
    // O AGREGAR LINEAS SIMILARES
}

ZonaFranca::~ZonaFranca(){
  for(int i=0; i< ambienteCounter; ++i){
     delete ambiente[i];
  }
  for(int j=0; j< algoritmoCounter; ++j){
     delete algoritmo[j];
  }	  
}

Ambiente * ZonaFranca::nuevoAmbiente(string nombre, int cantidadCriaturas){
   Ambiente * seleccionado = 0;
   for(int i=0; !seleccionado && i < ambienteCounter; ++i){
	    if(ambiente[i] && ambiente[i]->esUsted(nombre)){
			seleccionado = ambiente[i];
			seleccionado->setCantidadCriaturas(cantidadCriaturas);
		}   
   }
   return seleccionado;
}
	  
Algoritmo * ZonaFranca::nuevoAlgoritmo(string nombre){
   Algoritmo * seleccionado = 0;
   for(int i=0; !seleccionado && i < algoritmoCounter; ++i){
	    if(algoritmo[i] && algoritmo[i]->esUsted(nombre)){
			seleccionado = algoritmo[i];	
		}   
   }
   return seleccionado;
}
