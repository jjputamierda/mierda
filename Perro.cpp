#include<iostream>
#include"Perro.h"
Perro::Perro(){

}
void Perro::setPropietario(const char * name){
this->p = new Propietario(name);
}
Perro::~Perro(){
if(p!=0){
	delete this->p;
}
else{}
}