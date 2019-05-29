#include "CriaturaEntera.h"
#include<ctime>
#include<climits>


CriaturaEntera::CriaturaEntera(){
	this->valor = 0;
}
CriaturaEntera::CriaturaEntera(int valor){
	this->valor = valor;
}

CriaturaEntera & CriaturaEntera::setValor(int valor){
	this->valor = valor;
	return *this;
}
	 
int CriaturaEntera::getValor(){
	return valor;
}	 
ostream& CriaturaEntera::imprimir(ostream& salida){
   salida << valor;
   return salida;   
}

Criatura * CriaturaEntera::clonar(){
	CriaturaEntera * nuevaPtr = new CriaturaEntera(valor);
	return nuevaPtr;
}

int CriaturaEntera::operator==(Criatura * criaturaPtr){
	
	CriaturaEntera * criaturaEnteraPtr = dynamic_cast< CriaturaEntera * >( criaturaPtr );
	
	return criaturaEnteraPtr && criaturaEnteraPtr->valor == this->valor;
}

Criatura ** CriaturaEntera::cruzar( Criatura * ptr){
	Criatura * * hijo = 0;
	if(ptr){
  	   CriaturaEntera * enteraPtr = dynamic_cast< CriaturaEntera *>(ptr);	
       hijo = new Criatura * [2]; // Solo tiene un hijo promedio
	   hijo[0] = new CriaturaEntera( (this->valor + enteraPtr->valor )/2 );
       hijo[1]=0; // El ultimo puntero es nulo
	}
	return hijo;
}
	  
Criatura * CriaturaEntera::inverso(){
	return new CriaturaEntera((valor>0)? (INT_MAX - valor) : (INT_MAX + valor));	
}	  
	  
void CriaturaEntera::mutar(){
	int mutacion = (int)(rand()*INT_MAX);
	if(rand()>0.5){
       valor+= mutacion;
	}
	else {
       valor-= mutacion;		
	}
}

