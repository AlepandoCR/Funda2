#ifndef VIAJE_H
#define VIAJE_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;
//Alejandro Ocampo Ramirez 402690729
//Mariadna Rodriguez Oviedo 402630747
/*
* Esta clase se encarga de registrar la información de un viaje individual
* Posteriormente sera llamada por una coleccion para hacer un conjunto de viajes
*/
class Viaje {
private:
    float gasolina;
    float kilometros;
    int horaDeLlegada;
    int horaDeSalida;
    float costo;
    float cobro;
    string lugarOrigen;
    string lugarDestino;

public:
    Viaje() {
        gasolina = 0.0;
        kilometros = 0.0;
        horaDeLlegada = 0;
        horaDeSalida = 0;
        costo = 0.0;
        cobro = 0.0;
        lugarDestino = "N/A";
        lugarOrigen = "N/A";
    }

    void setGasolina(float pGasolina) {
        gasolina = pGasolina;
    }

    void setKilometros(float pKilometros) {
        kilometros = pKilometros;
    }

    void setHoraDeLlegada(int pHoraDeLlegada) {
        horaDeLlegada = pHoraDeLlegada;
    }

    void setHoraDeSalida(int pHoraDeSalida) {
        horaDeSalida = pHoraDeSalida;
    }

    void setCosto(float pCosto) {
        costo = pCosto;
    }

    void setCobro(float pCobro) {
        cobro = pCobro;
    }

    void setLugarOrigen(string pLugarOrigen) {
        lugarOrigen = pLugarOrigen;
    }

    void setLugarDestino(string pLugarDestino) {
        lugarDestino = pLugarDestino;
    }

    float getGasolina() {
        return gasolina;
    }

    float getKilometros() {
        return kilometros;
    }

    int getHoraDeLlegada() {
        return horaDeLlegada;
    }

    int getHoraDeSalida() {
        return horaDeSalida;
    }

    float getCosto() {
        return costo;
    }

    float getCobro() {
        return cobro;
    }

    string getLugarOrigen() {
        return lugarOrigen;
    }

    string getLugarDestino() {
        return lugarDestino;
    }
    //Con esta funcion se establecen los datos dados por el usuario a cada variable del viaje
    void setViaje(float pKilometros, int pHoraDeLlegada, int pHoraDeSalida, string pLugarOrigen, string pLugarDestino) {
        kilometros = pKilometros;
        horaDeLlegada = pHoraDeLlegada;
        horaDeSalida = pHoraDeSalida;
        lugarOrigen = pLugarOrigen;
        lugarDestino = pLugarDestino;
        gasolina = kilometros/5 ;
        costo = (150 * kilometros) + (850 * gasolina);
        cobro = (500 * kilometros);
        if (horaDeSalida > 21 || horaDeSalida < 7) {
            cobro += cobro * 0.25;
        }
        if (cobro < 1000) {
            cobro = 1000;
        }
    }

    float ganancia() {
        return cobro - costo;
    }
    //Muestra toda la informacion necesaria de un viaje
    string toString() {
        stringstream ss;
        ss << "Gasolina: " << gasolina << endl;
        ss << "Kilometros: " << kilometros << endl;
        ss << "Hora de llegada: " << horaDeLlegada << endl;
        ss << "Hora de salida: " << horaDeSalida << endl;
        ss << "Costo: " << costo << endl;
        if (horaDeSalida > 21 || horaDeSalida < 7) {
            ss << "Cobro: " << cobro << " (500 * " << kilometros << ")" << " + 25%" << endl;
        }
        else {
            ss << "Cobro: " << cobro << " (500 * " << kilometros << ")" << endl;
        }
        ss << "Lugar de origen: " << lugarOrigen << endl;
        ss << "Lugar de destino: " << lugarDestino << endl;
        return ss.str();
    }
};
#endif
