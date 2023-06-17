#ifndef DIAS_H
#define DIAS_H
#include "Viajes.h"
//Alejandro Ocampo Ramirez 402690729
//Mariadna Rodriguez Oviedo 402630747

class Dias {
private:
	//Creamos vector de conjuntos de viajes (31 grupos de 10 viajes)
	Viajes dias[31];
	float cobros[310];
	int viajes[310];
public:
	Dias() {
		for (int i = 0; i < 310; i++) {
			cobros[i] = 0.0;
			viajes[i] = 0;
		}
	}
	//Llama a la clase Viajes la cual llama a la Viaje para establecer un viaje en un dia
	void setDia(int pDia, float pKilometros, int pHoraDeLlegada, int pHoraDeSalida, string pLugarOrigen, string pLugarDestino) {
		if (getViajes(pDia) < 10) {
			dias[pDia - 1].setViajes(pKilometros, pHoraDeLlegada, pHoraDeSalida, pLugarOrigen, pLugarDestino);
			setViaje(pDia - 1);
		}
	}
	string toString(int pDia, int pViaje) {
		stringstream s;
		s << "Dia: " << pDia << endl;
		s << dias[pDia - 1].toString(pViaje - 1);
		return s.str();
	}
	//Funcion para pedir la cantidad de viajes registrados que tiene un dia
	int getViajes(int pDia) {
		return dias[pDia].getCantidad();
	}
	//Aumente la cantidad de viajes en un dia despues de establecer uno
	void setViaje(int pDia) {
		dias[pDia].setCantidad(getViajes(pDia) + 1);
	}
	//Calcula los promedios de datos y los devuelve en string
	string getPromedios() {
		stringstream s;
		float kilometrosProm = 0, costoProm = 0, cobroProm = 0, gasolinaProm = 0;
		int total = 0;
		for (int i = 0; i < 31; i++) {
			//Revisa todos los viajes registrados de todos los dias
			for (int k = 0; k < getViajes(i); k++) {
				total++;
				kilometrosProm += dias[i].getKilometros(k);
				costoProm += dias[i].getCosto(k);
				cobroProm += dias[i].getCobro(k);
				gasolinaProm += dias[i].getGasolina(k);
			}
		}
		kilometrosProm = kilometrosProm / total;
		costoProm = costoProm / total;
		cobroProm = cobroProm / total;
		gasolinaProm = gasolinaProm / total;

		s << "Kilometros promedio: " << kilometrosProm << endl;
		s << "Costo promedio: " << costoProm << endl;
		s << "Cobro promedio: " << cobroProm << endl;
		s << "Gasolina promedio: " << gasolinaProm << endl;
		return s.str();
	}
	//Devuelve la cantidad de viajes que hay por dia y el dia con más viajes y el que tiene menos viajes
	string viajesPorDia() {
		stringstream s;
		int masViajes, menosViajes, diaMas = 0, diaMenos = 0;
		masViajes = getViajes(0);
		menosViajes = getViajes(0);
		for (int k = 0; k < 31; k++) {
			if (getViajes(k) > masViajes && getViajes(k) > 0) {
				masViajes = getViajes(k);
				diaMas = k;
			}
			if (getViajes(k) < menosViajes && getViajes(k) > 0) {
				menosViajes = getViajes(k);
				diaMenos = k;
			}
		}
		s << "Dia con mas viajes: " << diaMas+1 << " (" << masViajes << ")" << endl;
		s << "Dia con menos viajes: " << diaMenos+1 << " (" << menosViajes << ")" << endl;

		for (int i = 0; i < 31; i++) {
			if (getViajes(i) > 0) {
				s << "Dia #" << i+1 << " Viajes: " << getViajes(i) << endl;
			}
		}
		return s.str();
	}
	string getDestino(int pDia, int pViaje) {
		return dias[pDia].getDestino(pViaje);
	}
	string getOrigen(int pDia, int pViaje) {
		return dias[pDia].getOrigen(pViaje);
	}
	//Devuelve todos los viajes en un destino dado
	string viajesPorDestino(string pDestino) {
		stringstream s;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getDestino(i, k) == pDestino) {
					s << toString(i + 1, k + 1) << endl;
				}
			}
		}
		return s.str();
	}
	//Cuenta la cantidad de viajes que tiene un mismo destino
	int viajesDestino(string pDestino) {
		int viajes = 0;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10;k++) {
				if (getDestino(i, k) == pDestino && getViajes(i) > 0) {
					viajes++;
				}
			}
		}
		return viajes;
	}
	float getGanancia(int pDia, int pViaje) {
		return dias[pDia].getGanancia(pViaje);
	}
	float getGanaciaDiaria(int pDia) {
		float ganancia = 0.0;
		for (int i = 0; i < 10; i++) {
			ganancia += getGanancia(pDia, i);
		}
		return ganancia;
	}
	//Muestra todos los viajes en un origen dado
	int viajesOrigen(string pOrigen) {
		int viajes = 0;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getOrigen(i, k) == pOrigen && getViajes(i) > 0) {
					viajes++;
				}
			}
		}
		return viajes;
	}
	//muestra el destino con mas viajes y el origen con mas viajes
	string lugarViajes() {
		string destino = "N/A", origen = "N/A";
		stringstream s;
		int masDestinos = 0, masOrigenes = 0;
		masDestinos = viajesDestino(getDestino(0, 0));
		masOrigenes = viajesDestino(getOrigen(0, 0));
		destino = getDestino(0, 0);
		origen = getOrigen(0, 0);
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (masDestinos < viajesDestino(getDestino(i, k)) && getViajes(i) > 0 && getDestino(i, k) != "N/A") {
					masDestinos = viajesDestino(getDestino(i, k));
					destino = getDestino(i, k);
				}
				if (masOrigenes < viajesDestino(getOrigen(i, k)) && getViajes(i) > 0 && getDestino(i, k) != "N/A") {
					masOrigenes = viajesDestino(getOrigen(i, k));
					origen = getOrigen(i, k);
				}
			}
		}
		s << "Destino con mas viajes: " << destino << " (" << masDestinos << ")" << endl;
		s << "Origen con mas viajes: " << origen << " (" << masOrigenes << ")" << endl;
		return s.str();
	}
	//Ordena los viajes de mayor cobro a menor
	void viajesOrdenadosPorCobro()
	{

		//En los siguientes bucles, asignamos los cobros de cada viaje a un vector, extrayendo correctamente el dia en que se hizo el viaje tambien

		for (int i = 0; i < 310; i++) {
			if (i > 9) {
				cobros[i] = dias[i / 10].getCobro(i % 10);
				viajes[i] = i;
			}
			else {
				cobros[i] = dias[0].getCobro(i);
				viajes[i] = i;
			}
		}
		
		//Aqui hacemos metodo burbuja para ordenar los viajes nuevamente del mayor al menor
		
		for (int i = 0; i < 310; i++) {
			for (int j = i + 1; j < 310; j++) {
				if (cobros[viajes[i]] < cobros[viajes[j]]) {
					int temporal = viajes[i];
					viajes[i] = viajes[j];
					viajes[j] = temporal;
				}
			}
		}
	}
	//Devuelve el string de los viajes ordenados segun su cobro
	string ordenToString() {
		viajesOrdenadosPorCobro();
		stringstream s;
		for (int x = 0; x < 310; x++) {
			int viajeOrden, diaOrden;
			if (viajes[x] > 9) {
				viajeOrden = viajes[x] % 10;
				diaOrden = viajes[x] / 10;
			}
			else {
				viajeOrden = viajes[x];
				diaOrden = 0;
			}
			if (cobros[viajes[x]] > 0) {
				s << toString(diaOrden + 1, viajeOrden + 1) << endl;
			}
		}
		return s.str();
	}

};

#endif
