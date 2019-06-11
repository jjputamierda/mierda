#include "GeneticoMutativo.h"

GeneticoMutativo::GeneticoMutativo(){
	this->setNombre("GeneticoMutativo");
}

Poblacion *GeneticoMutativo::evolucionar(Poblacion *inicial){
	Poblacion *generacionActual = inicial;

	if (ambientePtr){
		generacionActual = inicial->clonar();
		int padre;
		int madre;

		Poblacion *generacionSiguiente;

		int cantidadGeneraciones = 0;
		int contador = 0;
		int poblacionPerfecta = 0;

		Criatura *criaturas[ambientePtr->getCantidadCriaturas()];
		double puntaje[ambientePtr->getCantidadCriaturas()];

		while (cantidadGeneraciones++ < 111 && !poblacionPerfecta){
			generacionSiguiente = new Poblacion();
			contador = 0;
			for (Poblacion::Iterador generacionActualItr = generacionActual->begin(); generacionActualItr != generacionActual->end(); ++generacionActualItr)
			{
				if (*generacionActualItr)
				{
					puntaje[contador] = ambientePtr->evaluar(*generacionActualItr);
					criaturas[contador++] = *generacionActualItr;
				}
			}

			double tempPuntaje;
			Criatura *tempCriatura;

			for (int l = 1; l < contador; ++l){
				tempPuntaje = puntaje[l];
				int j = l - 1;
				while ( (puntaje[j] > tempPuntaje) && (j >= 0) ){
					puntaje[j+1] = puntaje[j];
					j--;
					puntaje[j+1] = tempPuntaje;
				}
			}

			// REVISA SI EL MENOS APTO DE LA POBLACION ESTA PERFECTAMENTE ADAPTADO
			poblacionPerfecta = puntaje[contador] == 1;

			// 1. PASAR EL 10% DE LOS MAS APTOS DIRECTAMENTE A LA generacionSiguiente GENERACION
			int posVeinte = (int)(0.1 * contador);
			int cantidadSeleccionados = 0;
			Poblacion::Iterador fin = generacionSiguiente->end();
			for (int j = 0; j < posVeinte; ++j){
				generacionSiguiente->insertar(fin, criaturas[j]);
				cantidadSeleccionados++;
			}

			while (cantidadSeleccionados < ambientePtr->getCantidadCriaturas())
			{
			int padresOK = 0;
			int cortePadre;
			int corteMadre;
			int w = 0;
			Criatura **hijo = 0;
				while (!padresOK)
				{
					padre = (int)(((double)rand() / RAND_MAX) * contador);
					madre = (int)(((double)rand() / RAND_MAX) * contador);
					cortePadre = (int)(((double)rand() / RAND_MAX) * contador);
					corteMadre = (int)(((double)rand() / RAND_MAX) * contador);
					padresOK = padre != madre && padre <= cortePadre && madre <= corteMadre;
				}
				// 2. COMPLETO EL 90% RESTANTE CON LOS HIJOS DE DOS CRIATURAS (entre el mejor 50%) EN generacionSiguiente
				//    - PARA CALIFICAR LAS CRIATURAS SELECCIONADAS DEBEN TENER UN PUNTAJE MAYOR QUE SU PROBABILIDAD
				hijo = criaturas[padre]->cruzar(criaturas[madre]);
				// Agrega los hijos a la siguiente generacion
				while (hijo[w] && cantidadSeleccionados < ambientePtr->getCantidadCriaturas())
				{
					generacionSiguiente->insertar(fin, hijo[w]);
					delete hijo[w];
					cantidadSeleccionados++;
					++w;
				}
				delete[] hijo;
			}
			// DECIDIR SI HAY MUTACION Y SE LA APLICO ALEATORIAMETE A ALGUNA CRIATURA
			int corteMutuacion = PROBABILIDAD_MUTUACION;
			int probabilidad =  (int) (((double)rand() / RAND_MAX) * 70);//70% ya que en un algoritmo mutativo muchos deberían mutar
			cout << "Probabilidad de mutuacion: " << probabilidad << endl;
			if(probabilidad <= corteMutuacion){
				int criaturaAMutar = (int) (((double)rand() / RAND_MAX) * contador);
				criaturas[criaturaAMutar]->mutar();
				std::cout << "La criatura numero " << criaturaAMutar + 1 << " mutó!" << std::endl;
			}
			cout << "TESTING.. GENERACION ACTUAL" << endl;
			cout << generacionSiguiente << endl;
			delete generacionActual;
			generacionActual = generacionSiguiente;
			cout << "Termine generacion " << cantidadGeneraciones << endl;
		}
	return generacionActual;
 }
