#ifndef MOTO_H
#define MOTO_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const int dias = 31, nViajes = 10;
class Viajes
{
private:
	int diasRegistrados,nViajesRegistrados;
	float Kilometros[dias][nViajes];
	float Gasolina[dias][nViajes];
	float montoCobrado[dias][nViajes];
	float Costos[dias][nViajes];
	string lugarOrigen[dias][nViajes];
	string lugarDestino[dias][nViajes];
	int horaInicio[dias][nViajes];
	int horaFin[dias][nViajes];
	int minInicio[dias][nViajes];
	int minFin[dias][nViajes];
	bool disponible[dias][nViajes];
public:
	Viajes() {
		for (int i = 0; i < dias; i++) {
			for (int k = 0; k < nViajes; k++) {
				Kilometros[i][k] = 0.0;
				Gasolina[i][k] = 0.0;
				montoCobrado[i][k] = 0.0;
				Costos[i][k] = 0.0;
				lugarOrigen[i][k] = "N/A";
				lugarDestino[i][k] = "N/A";
				horaInicio[i][k] = 0;
				horaFin[i][k] = 0;
				minInicio[i][k] = 0;
				minFin[i][k] = 0;
				disponible[i][k] = false;
			}
		}
		diasRegistrados = 0;
		nViajesRegistrados = 0;
	}
	void SetElementos(float pKilometros, float pGasolina, string pOrigen, string pDestino, int pInicio, int pFin, int pMinFin, int pMinInicio, int pDia, int pViaje) {
		bool viajesAnterior = false;
		if (!disponible[pDia-1][pViaje]) {
			viajesAnterior = true;
		}
		Kilometros[pDia][pViaje] = pKilometros;
		Gasolina[pDia][pViaje] = pGasolina;
		lugarOrigen[pDia][pViaje] = pOrigen;
		lugarDestino[pDia][pViaje] = pDestino;
		horaInicio[pDia][pViaje] = pInicio;
		horaFin[pDia][pViaje] = pFin;
		minInicio[pDia][pViaje] = pMinInicio;
		minFin[pDia][pViaje] = pMinFin;
		disponible[pDia][pViaje] = true;
		if (viajesAnterior) {
			disponible[pDia - 1][pViaje] = false;
		}
	}
	void setKilometros(int pDia, int pViaje, float pKilometros) {
		Kilometros[pDia][pViaje] = pKilometros;
	}
	void setGasolina(int pDia, int pViaje, float pGasolina) {
		Gasolina[pDia][pViaje] = pGasolina;
	}
	void setMontoCobrado(int pDia, int pViaje, float pMontoCobrado) {
		montoCobrado[pDia][pViaje] = pMontoCobrado;
	}
	void setCostos(int pDia, int pViaje, float pCosto) {
		Costos[pDia][pViaje] = pCosto;
	}
	void setLugarOrigen(int pDia, int pViaje, string pLugarOrigen) {
		lugarOrigen[pDia][pViaje] = pLugarOrigen;
	}
	void setLugarDestino(int pDia, int pViaje, string pLugarDestino) {
		lugarDestino[pDia][pViaje] = pLugarDestino;
	}
	void setHoraInicio(int pDia, int pViaje, int valor) {
		horaInicio[pDia][pViaje] = valor;
	}
	void setHoraFin(int pDia, int pViaje, int valor) {
		horaFin[pDia][pViaje] = valor;
	}
	void setMinInicio(int pDia, int pViaje, int valor) {
		minInicio[pDia][pViaje] = valor;
	}
	void setMinFin(int pDia, int pViaje, int valor) {
		minFin[pDia][pViaje] = valor;
	}
	float getKilometros(int pDia, int pViaje) {
		return Kilometros[pDia][pViaje];
	}
	int getHoraInicio(int pDia, int pViaje) {
		return horaInicio[pDia][pViaje];
	}
	float getGasolina(int pDia, int pViaje) {
		return Gasolina[pDia][pViaje];
	}
	string getDestino(int pDia, int pViaje) {
		return lugarDestino[pDia][pViaje];
	}
	string getOrigen(int pDia, int pViaje) {
		return lugarOrigen[pDia][pViaje];
	}
	float getCobro(int pDia, int pViaje) {
		if (getHoraInicio(pDia, pViaje) < 6 && getHoraInicio(pDia,pViaje) > 22) {
			montoCobrado[pDia][pViaje] = (getKilometros(pDia, pViaje) * 500) + ((getKilometros(pDia, pViaje) * 500)* 0.25);
		}
		else {
			montoCobrado[pDia][pViaje] = (getKilometros(pDia, pViaje) * 500);
		}
		if (montoCobrado[pDia][pViaje] < 1000) {
			montoCobrado[pDia][pViaje] = 1000;
		}
		return montoCobrado[pDia][pViaje];
	}
	float getCosto(int pDia, int pViaje) {
		float costo = 0;
		costo += (getKilometros(pDia, pViaje) * 150) + (getGasolina(pDia, pViaje) * 850);
		return costo;
	}
	bool getDisponible(int pDia, int pViaje) {
		return disponible[pDia][pViaje];
	}
	float promedioKilometros() {
		float promedioKm = 0, km = 0, total = 0;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getDisponible(i,k) == true) {
					km += getKilometros(i, k);
					total++;
				}
			}
		}
		promedioKm = km / total;
		return promedioKm;
	}
	float promedioCobro() {
		float promedioCobr = 0, cobros = 0, total = 0;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getDisponible(i, k) == true) {
					cobros += getCobro(i, k);
					total++;
				}
			}
		}
		promedioCobr = cobros / total;
		return promedioCobr;
	}
	float promedioCosto() {
		float promedioCost = 0, costos = 0, total = 0;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getDisponible(i, k) == true) {
					costos += getCosto(i, k);
					total++;
				}
			}
		}
		promedioCost = costos / total;
		return promedioCost;
	}
	float promedioGasolina() {
		float promedioGaso = 0, gasolinaTotal = 0, total = 0;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getDisponible(i, k) == true) {
					gasolinaTotal += getGasolina(i, k);
					total++;
				}
			}
		}
		promedioGaso = gasolinaTotal / total;
		return promedioGaso;
	}
	int getViajesEnDia(int pDia) {
		int cantidad = 0;
		for (int i = 0; i < 10; i++) {
			if (getDisponible(pDia, i)) {
				cantidad++;
			}
		}
		return cantidad;
	}
	int masViajes() {
		int max, aux = 0;
		max = getViajesEnDia(0);
		for (int i = 0; i < 31; i++) {
			if (max < getViajesEnDia(i)) {
				max = getViajesEnDia(i);
				aux = i;
			}
		}
		return aux + 1;
	}
	int menosViajes() {
		int min, aux = 0;
		min = getViajesEnDia(0);
		for (int i = 0; i < 31; i++) {
			if (min > getViajesEnDia(i)) {
				min = getViajesEnDia(i);
				aux = i;
			}
		}
		return aux;
	}
	int getViajesDestino(string pDestino) {
		int destinos = 0;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getDestino(i, k) == pDestino && getDisponible(i, k)) {
					destinos++;
				}
			}
		}
		return destinos;
	}
	int getViajesOrigen(string pOrigen) {
		int origenes = 0;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getOrigen(i, k) == pOrigen && getDisponible(i, k)) {
					origenes++;
				}
			}
		}
		return origenes;
	}
	float gananciaViaje(int pDia, int pViaje) {
		int ganancia = 0;
		ganancia = getCobro(pDia, pViaje) - getCosto(pDia, pViaje);
		return ganancia;
	}
	float getGanancia(int pDia) {
		float ganancia = 0;
		for (int i = 0; i < 10; i++) {
			if (getDisponible(pDia - 1, i)) {
				ganancia += gananciaViaje(pDia - 1, i);
			}
		}
		return ganancia;
	}

	string viajesPorMonto() {
		stringstream s;
		int aux[31][10], ordenDias[31][10], temp = 0;

		for (int j = 0; j < 31; j++) {
			for (int p = 0; p < 10; p++) {
				aux[j][p] = getCobro(j, p);
				ordenDias[j][p] = p;
			}
		}

		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 10; j++) {
				for (int k = j + 1; k < 10; k++) {
					if (aux[i][j] < aux[i][k]) {
						// Intercambiar los valores de aux[i][j] y aux[i][k]
						int temp = aux[i][j];
						aux[i][j] = aux[i][k];
						aux[i][k] = temp;

						// Intercambiar los valores de ordenDias[i][j] y ordenDias[i][k]
						temp = ordenDias[i][j];
						ordenDias[i][j] = ordenDias[i][k];
						ordenDias[i][k] = temp;
					}
				}
			}
		}

		for (int monto = 0; monto < 10; monto++) {
			for (int dia = 0; dia < 31; dia++) {
				if (getDisponible(dia, ordenDias[dia][monto])) {
					s << toString(dia, ordenDias[dia][monto]);
				}
			}
		}

		return s.str();
	}
	string lugarViajes() {
		string destino = "N/A", origen = "N/A";
		stringstream s;
		int masDestinos = 0, masOrigenes = 0;
		masDestinos = getViajesDestino(getDestino(0,0));
		masOrigenes = getViajesOrigen(getOrigen(0,0));
		destino = getDestino(0, 0);
		origen = getOrigen(0,0);
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (masDestinos < getViajesDestino(getDestino(i,k)) && getDisponible(i, k)) {
					masDestinos = getViajesDestino(getDestino(i, k));
					destino = getDestino(i, k);
				}
				if (masOrigenes < getViajesOrigen(getOrigen(i,k)) && getDisponible(i, k)) {
					masOrigenes = getViajesOrigen(getOrigen(i, k));
					origen = getOrigen(i, k);
				}
			}
		}
		s << "Destino con mas viajes: " << destino << " (" << masDestinos << ")" << endl;
		s << "Origen con mas viajes: " << origen << " (" << masOrigenes << ")" << endl;
		return s.str();
	}
	string viajesDestino(string pDestino) {
		stringstream s;
		for (int i = 0; i < 31; i++) {
			for (int k = 0; k < 10; k++) {
				if (getDestino(i,k) == pDestino) {
					s << toString(i,k) << endl;
				}
			}
		}
		return s.str();
	}
	string cantidadDeViajesToString() {
		stringstream s,ss,sss;
		ss << "Dia con mas viajes: " << masViajes() << endl << "Dia con menos viajes: " << menosViajes() << endl << endl;
		for (int i = 0; i < 31; i++) {
			if (getViajesEnDia(i) != 0) {
				s << "Dia #" << i + 1 << ": " << getViajesEnDia(i) << " Viajes" << endl;
			}
		}
		sss << ss.str() << s.str();
		return sss.str();
	}
	string promediosToString() {
		stringstream s;
		s <<"Kilometros promedio: " << promedioKilometros() << endl << "Costo promedio: " << promedioCosto() << endl << "Cobro promedio: " << promedioCobro() << endl << "Gasolina usada promedio: " << promedioGasolina() << endl;
		return s.str();
	}
	//Devuelve la hora con formato hora y minutos
	string getSHoraInicio(int pDia, int pViaje) {
		stringstream s;
		if (minInicio[pDia][pViaje] < 10) {
			s << horaInicio[pDia][pViaje] << ":0" << minInicio[pDia][pViaje];
		}
		else {
			s << horaInicio[pDia][pViaje] << ":" << minInicio[pDia][pViaje];
		}
		return s.str();
	}
	string getSHoraFin(int pDia, int pViaje) {
		stringstream s;
		if (minFin[pDia][pViaje] < 10) {
			s << horaFin[pDia][pViaje] << ":0" << minFin[pDia][pViaje];
		}
		else {
			s << horaFin[pDia][pViaje] << ":" << minFin[pDia][pViaje];
		}
		return s.str();
	}
	string toString(int pDia, int pViaje) {
		stringstream s;
		if (getHoraInicio(pDia, pViaje) < 6 && getHoraInicio(pDia, pViaje) > 22) {
			s << "Dia: " << pDia + 1 << endl << "Viaje: " << pViaje + 1 << endl << "Kilometros: " << Kilometros[pDia][pViaje] << endl << "Gasolina: " << Gasolina[pDia][pViaje] << endl << "Lugar de Origen: " << lugarOrigen[pDia][pViaje] << endl << "Lugar de Destino: " << lugarDestino[pDia][pViaje] << endl << "Hora Inicio: " << getSHoraInicio(pDia, pViaje) << endl << "Hora final del viaje: " << getSHoraFin(pDia, pViaje) << endl << "Monto Cobrado: " << getCobro(pDia, pViaje) << " (" << getKilometros(pDia, pViaje) << "* 500) + ((" << getKilometros(pDia, pViaje) << "* 500) * 0.25)" << endl << "Costo: " << getCosto(pDia, pViaje) << " (" << getKilometros(pDia, pViaje) << "* 150) + (" << getGasolina(pDia, pViaje) << "* 850)" << endl;
		}
		else {
			s << "Dia: " << pDia + 1 << endl << "Viaje: " << pViaje + 1 << endl << "Kilometros: " << Kilometros[pDia][pViaje] << endl << "Gasolina: " << Gasolina[pDia][pViaje] << endl << "Lugar de Origen: " << lugarOrigen[pDia][pViaje] << endl << "Lugar de Destino: " << lugarDestino[pDia][pViaje] << endl << "Hora Inicio: " << getSHoraInicio(pDia, pViaje) << endl << "Hora final del viaje: " << getSHoraFin(pDia, pViaje) << endl << "Monto Cobrado: " << getCobro(pDia, pViaje) << "  (" << getKilometros(pDia, pViaje) << "* 500)" << endl << "Costo: " << getCosto(pDia, pViaje) << " (" << getKilometros(pDia, pViaje) << "* 150) + (" << getGasolina(pDia, pViaje) << "* 850)" << endl;
		}
		return s.str();
	}
};
#endif
