#ifndef PERRO
#define PERRO
#include"Propietario.h"


class Perro{
private:
    Propietario * p;
public:
    Perro();
    void setPropietario(const char * );
    ~Perro();

};

#endif 