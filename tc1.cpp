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

void Arbol::Iterador::operator ++ () {
	//Si tiene hijos
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
			pila.pop()
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
