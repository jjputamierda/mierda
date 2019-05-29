#include "ZonaFranca.h" // Le pido instancias de Ambiente y de Algoritmo..
#include "Poblacion.h" // Poblacion de criaturas 
#include <ctime>

#define _MAX_CRIATURAS 100;
int main(int argn, char ** argv){
   char * nombreAlgoritmo = argv[1];
   char * nombreCriatura = argv[2];
   char * cantidadCriaturasString = argv[3];
   int cantidadCriaturas=0;
   
   cantidadCriaturas = atoi(cantidadCriaturasString);

   
   ZonaFranca territorio;
   srand(time(0));

   Ambiente * ambientePtr = territorio.nuevoAmbiente(nombreCriatura,cantidadCriaturas);
   Algoritmo * algoritmoPtr = territorio.nuevoAlgoritmo(nombreAlgoritmo);
   if(!ambientePtr || !algoritmoPtr){
	   cerr << "Debe proporcionar un nombre de criatura y algoritmos validos"<< endl;
	   if(ambientePtr){
		   delete ambientePtr;
	   }
	   if(algoritmoPtr){
		   delete ambientePtr;
	   }
   }
   else {
      
      cout << "Algoritmo: "<<nombreAlgoritmo << " Criatura: " << nombreCriatura<<endl; 
	   
      algoritmoPtr->asignar(ambientePtr);
      Poblacion * poblacionInicialPtr = ambientePtr->crearPoblacionInicial();

      // Algoritmo no puede modificar la poblacion inicial
      cout << "POBLACION INICIAL "<<endl;
      cout << poblacionInicialPtr;
      cout << endl;
 
      cout << "Cantidad de criaturas: " << cantidadCriaturas << endl;
      Poblacion * poblacionFinalPtr =  algoritmoPtr->evolucionar(poblacionInicialPtr);   


 // Algoritmo no puede modificar la poblacion inicial
      cout << "POBLACION FINAL "<<endl;
      cout << poblacionFinalPtr;
      cout << endl;
	  
	  if(poblacionInicialPtr){
         delete poblacionInicialPtr;	  
	  }
	  if(poblacionFinalPtr){
         delete poblacionFinalPtr;
	  }
   }
   return 0;
}