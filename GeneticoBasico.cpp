#include "GeneticoBasico.h"

GeneticoBasico::GeneticoBasico()
{
	this->setNombre("GeneticoBasico");
}

Poblacion *GeneticoBasico::evolucionar(Poblacion *inicial)
{
	Poblacion *generacionActual = inicial;

	if (ambientePtr)
	{
		generacionActual = inicial->clonar();
		int padre;
		int madre;

		Poblacion *generacionSiguiente;

		int cantidadGeneraciones = 0;
		int contador = 0;
		int poblacionPerfecta = 0;

		Criatura *criaturas[ambientePtr->getCantidadCriaturas()];
		double puntaje[ambientePtr->getCantidadCriaturas()];

		while (cantidadGeneraciones++ < 80 && !poblacionPerfecta)
		{
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
			// TO_DO: ORDENAR LAS CRIATURAS DESDE LA MAS APTA A LA MENOS APTA
			// HAGAN ALGO MAS EFICIENTE ... :)
			for (int l = 0; l < contador - 1; ++l)
			{
				for (int m = 0; m < contador - 1 - l; ++m)
				{
					if (puntaje[m] < puntaje[m + 1])
					{
						tempPuntaje = puntaje[m];
						tempCriatura = criaturas[m];
						puntaje[m] = puntaje[m + 1];
						criaturas[m] = criaturas[m + 1];
						puntaje[m + 1] = tempPuntaje;
						criaturas[m + 1] = tempCriatura;
					}
				}
			}

			// REVISA SI EL MENOS APTO DE LA POBLACION ESTA PERFECTAMENTE ADAPTADO
			poblacionPerfecta = puntaje[contador] == 1;

			// 1. PASAR EL 20% DE LOS MAS APTOS DIRECTAMENTE A LA generacionSiguiente GENERACION
			int posVeinte = (int)(0.2 * contador);
			int cantidadSeleccionados = 0;
			Poblacion::Iterador fin = generacionSiguiente->end();
			for (int j = 0; j < posVeinte; ++j)
			{
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
				// 2. COMPLETO EL 80% RESTANTE CON LOS HIJOS DE DOS CRIATURAS EN generacionSiguiente
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
			int probabilidad =  (int) (((double)rand() / RAND_MAX) * 100);
			cout << "Probabilidad de mutuacion: " << probabilidad << endl;
			if(probabilidad <= corteMutuacion){
				int criaturaAMutar = (int) (((double)rand() / RAND_MAX) * contador);
				criaturas[criaturaAMutar]->mutar();
				std::cout << "La criatura numero " << criaturaAMutar + 1 << " mutó!" << std::endl;
			}
			cout << "TESTING.. GENERACION ACTUAL" << endl;
			cout << generacionSiguiente << endl;
			// COMENTAR LUEGO DE VER COMO SE PORTA
			delete generacionActual;
			generacionActual = generacionSiguiente;
			cout << "Termine generacion " << cantidadGeneraciones << endl;
		}
	}
	return generacionActual;
}
