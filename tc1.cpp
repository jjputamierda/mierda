Arbol::Iterador::Iterador() {
  Pila pila();
  actual = nullptr;
}

Arbol::Iterador::Iterador(Nodo* r) {
  Pila pila();
  actual = r;
}

Arbol::Iterador::operator = (Iterador& orig) {
  pila = orig.pila();
  actual = orig.actual;
}

Iterador Arbol::begin() {
  Iterador it(raiz);
  it.pila.push(it.actual);
  while(actual->hijo[IZQ]) {
    it.actual = it.actual->hijo[IZQ];
    it.pila.push(it.actual);
  }
}

Iterador Arbol::end() {
  Iterador it(raiz);
  it.pila.push(it.actual);
  while(actual->hijo[DER]) {
    it.actual = it.actual->hijo[DER];
    it.pila.push(it.actual);
  }
}

Arbol::Iterador::operator++ () {
  //Si tiene que procesar
  if((!actual->hijo[IZQ] && !actual->hijo[DER]) || pila.top()->elemento > actual->elemento) {
    //Sube
    Nodo* tmp = pila.pop();
    actual = pila.top();
    pila.push(tmp);

  } else {
    //Si tiene que moverse a la izquierda
    if (actual->hijo[IZQ] && pila.top()->elemento > actual->hijo[IZQ]->elemento){
      actual = actual->hijo[IZQ];
      pila.push(actual);
    }
    //Si tiene que moverse a la derecha
    if (actual->hijo[DER] && actual->hijo[DER] > pila.top){
      actual = actual->hijo[DER];
    }
  }
}
