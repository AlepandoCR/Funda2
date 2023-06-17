#include <iostream>
#include "Dias.h"
#include <stdlib.h>
//Alejandro Ocampo Ramirez 402690729
//Mariadna Rodriguez Oviedo 402630747
int main()
{
    Dias diaActual;
    float kilometros;
    int horaInicio, minsInicio, horaFin, minsFin, dia, menu = 0,viaje = 0;
    string Origen, Destino;
    //Bucle principal del programa
    while (menu != 9) {
        system("cls");
        cout << "1-Ingresar un viaje" << endl;
        cout << "2-Detalle viajes por dia" << endl;
        cout << "3-Promedios por viaje" << endl;
        cout << "4-Cantidad viajes por dia" << endl;
        cout << "5-Viajes por destino" << endl;
        cout << "6-Lugares con mas viajes realizados" << endl;
        cout << "7-Calcular ganancia diaria" << endl;
        cout << "8-Ordenar viajes" << endl;
        cout << "9-Salir" << endl;
        cin >> menu;
        system("cls");
        switch (menu) {
            //Establece un viaje segun el dia que escoja el usuario
        case 1:
            cout << "Ingrese el dia del viaje: ";
            cin >> dia;
            viaje = diaActual.getViajes(dia-1);
            if (dia > 31) {
                dia = 31;
            }
            system("cls");
            cout << "(Dia: " << dia << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese la cantidad de kilometros: ";
            cin >> kilometros;
            system("cls");
            cout << "(Dia: " << dia << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese la hora de inicio (sin minutos y en formato 24 horas): ";
            cin >> horaInicio;
            system("cls");
            cout << "(Dia: " << dia << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese los minutos de inicio: ";
            cin >> minsInicio;
            system("cls");
            cout << "(Dia: " << dia << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese la hora de fin (sin minutos y en formato 24 horas): ";
            cin >> horaFin;
            system("cls");
            cout << "(Dia: " << dia << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese los minutos de fin: ";
            cin >> minsFin;
            system("cls");
            cout << "(Dia: " << dia << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese el lugar de Origen: ";
            cin >> Origen;
            system("cls");
            cout << "(Dia: " << dia << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese el lugar de Destino: ";
            cin >> Destino;
            system("cls");
            diaActual.setDia(dia,kilometros,horaFin,horaInicio,Origen,Destino);
            break;
            //Muestra la informacion de un dia dado
        case 2:
            cout << "Escoja el dia: ";
            cin >> dia;
            for (int k = 0; k < diaActual.getViajes(dia-1); k++) {
                cout << diaActual.toString(dia,k+1) << endl;
            }
            system("pause");
            break;
            //Muestra los promedios
        case 3:
            cout << diaActual.getPromedios();
            system("pause");
            break;
            //muestra los viajes que hay por dia
        case 4:
            cout << diaActual.viajesPorDia();
            system("pause");
            break;
            //muestra los viajes que hay en un destino
        case 5:
            cout << "Ingrese el destino: ";
            cin >> Destino;
            system("cls");
            cout << diaActual.viajesPorDestino(Destino);
            system("pause");
            break;
            //muestra el destino con mas viajes y el origen con mas viajes
        case 6:
            cout<<diaActual.lugarViajes();
            system("pause");
            break;
            //Muestra la ganancia de un dia
        case 7:
            cout << "Ingrese el dia:" << endl;
            cin >> dia;
            cout<< "Ganancia: " << diaActual.getGanaciaDiaria(dia) << endl;
            system("pause");
            break;
            //Ordena los viajes de mayor cobro a menor
        case 8: 
            int elegir;
            cout << "1-Ordenar de dia mayor a menor" << endl << "2-Ordenar por monto (mayor a menor)" << endl;
            cin >> elegir;
            if (elegir == 1) {
                system("CLS");
                for (int i = 0; i < 31; i++) {
                    if (diaActual.getViajes(i) > 0) {
                        for (int k = 0; k < diaActual.getViajes(i); k++) {
                            cout << diaActual.toString(i + 1, k + 1) << endl;
                        }
                    }
                }
                system("pause");
            }
            else if (elegir == 2) {
                system("CLS");
                cout << diaActual.ordenToString();
                system("pause");
            }
            break;
        }
    }
    return 0;
}