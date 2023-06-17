#ifndef VIAJES_H
#define VIAJES_H
#include "Viaje.h"
//Alejandro Ocampo Ramirez 402690729
//Mariadna Rodriguez Oviedo 402630747
class Viajes {
private:
	//se crea una coleccion de viajes
	Viaje viajes[10];
	int cantidad;
public:
	Viajes(){
		cantidad = 0;
	}
	//Llama a la funcion Viaje para establecer un viaje
	void setViajes( float pKilometros, int pHoraDeLlegada, int pHoraDeSalida, string pLugarOrigen, string pLugarDestino) {
		if (cantidad < 10) {
			viajes[cantidad].setViaje(pKilometros, pHoraDeLlegada, pHoraDeSalida, pLugarOrigen, pLugarDestino);
		}
	}
	string toString(int pViaje) {
		stringstream s;
		s << "Viaje: " << pViaje+1 << endl;
		s << viajes[pViaje].toString();
		return s.str();
	}
	int getCantidad() {
		return cantidad;
	}
	float getKilometros(int pViaje) {
		return viajes[pViaje].getKilometros();
	}
	float getCosto(int pViaje) {
		return viajes[pViaje].getCosto();
	}
	float getCobro(int pViaje) {
		return viajes[pViaje].getCobro();
	}
	float getGasolina(int pViaje) {
		return viajes[pViaje].getGasolina();
	}
	string getDestino(int pViaje) {
		return viajes[pViaje].getLugarDestino();

	}
	string getOrigen(int pViaje) {
		return viajes[pViaje].getLugarOrigen();
	}
	float getGanancia(int pViaje) {
		return viajes[pViaje].ganancia();
	}
	void setCantidad(int pCantidad) {
		cantidad = pCantidad;
	}
};

#endif
