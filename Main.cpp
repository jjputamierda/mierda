#include "Arbol.h"
#include<ctime>

template< class T >
void demo(T inicial){
   Arbol<T> arbol;
   T aleatorio = inicial;
   cout << endl<< "DEMO" << endl;
   for(int i=0; i<10; ++i){
      aleatorio = (T)(((double)rand()/RAND_MAX)* 101);
	  cout << "Generado: "<< aleatorio <<endl;
      arbol.insertar(aleatorio);
   }
   cout << "Ordenados sin duplicados"<<endl;
   cout << arbol;   	
}

int main(){   
   srand(time(0));
   demo(0);
   demo(0.0);
   return 0;
}