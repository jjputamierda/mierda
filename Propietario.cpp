#include "Propietario.h"
#include <iostream>

using namespace std;

Propietario::Propietario(){
this->name = "\0";
}
Propietario::Propietario(const char* name){
this->name = name;
}
Propietario::~Propietario(){
 
}
