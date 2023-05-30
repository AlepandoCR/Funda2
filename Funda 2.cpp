#include <iostream>
#include "Viajes.h"
#include <stdlib.h>

int main()
{
    Viajes viajeActual;
    float kilometros, gasolina;
    int horaInicio, minsInicio, horaFin, minsFin, dia, menu = 0,viaje = 0;
    string Origen, Destino;
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
        case 1:
            cout << "Ingrese el dia del viaje: ";
            cin >> dia;
            dia -= 1;
            viaje = viajeActual.getViajesEnDia(dia);
            system("cls");
            cout << "(Dia: " << dia + 1 << "  Viaje: " << viaje+1 << "/10)";
            cout << "Ingrese la cantidad de kilometros: ";
            cin >> kilometros;
            system("cls");
            cout << "(Dia: " << dia + 1 << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese la cantidad de Gasolina: ";
            cin >> gasolina;
            system("cls");
            cout << "(Dia: " << dia + 1 << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese la hora de inicio (sin minutos y en formato 24 horas): ";
            cin >> horaInicio;
            system("cls");
            cout << "(Dia: " << dia + 1 << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese los minutos de inicio: ";
            cin >> minsInicio;
            system("cls");
            cout << "(Dia: " << dia + 1 << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese la hora de fin (sin minutos y en formato 24 horas): ";
            cin >> horaFin;
            system("cls");
            cout << "(Dia: " << dia + 1 << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese los minutos de fin: ";
            cin >> minsFin;
            system("cls");
            cout << "(Dia: " << dia + 1 << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese el lugar de Origen: ";
            cin >> Origen;
            system("cls");
            cout << "(Dia: " << dia + 1 << "  Viaje: " << viaje + 1 << "/10)";
            cout << "Ingrese el lugar de Destino: ";
            cin >> Destino;
            system("cls");
            viajeActual.SetElementos(kilometros, gasolina, Origen, Destino, horaInicio, horaFin, minsFin, minsInicio, dia, viaje);
            cout << viajeActual.getDisponible(1, 1);
            break;
        case 2:
            cout << "Escoja el dia: ";
            cin >> dia;
            dia -= 1;
            for (int k = 0; k <= 10; k++) {
                if (viajeActual.getDisponible(dia, k) == true) {
                    cout << viajeActual.toString(dia, k)<<endl<<endl;
                }
            }
            system("pause");
            break;
        case 3:
            cout << viajeActual.promediosToString();
            system("pause");
            break;
        case 4:
            cout << viajeActual.cantidadDeViajesToString();
            system("pause");
            break;
        case 5:
            cout << "Ingrese el destino: ";
            cin >> Destino;
            system("CLS");
            cout << viajeActual.viajesDestino(Destino);
            system("pause");
            break;
        case 6:
            cout<<viajeActual.lugarViajes();
            system("pause");
            break;
        case 7:
            cout << "Ingrese el dia:" << endl;
            cin >> dia;
            cout<< "Ganancia: " << viajeActual.getGanancia(dia) << endl;
            system("pause");
            break;
        case 8: 
            int elegir;
            cout << "1-Ordenar de dia mayor a menor" << endl << "2-Ordenar por monto (mayor a menor)" << endl;
            cin >> elegir;
            if (elegir == 1) {
                system("CLS");
                for (int i = 0; i < 31; i++) {
                    for (int k = 0; k < 10; k++) {
                        if (viajeActual.getDisponible(i,k)) {
                            cout << viajeActual.toString(i, k);
                        }
                    }
                }
                system("pause");
            }
            else if (elegir == 2) {
                system("CLS");
                cout << viajeActual.viajesPorMonto();
                system("pause");
            }
            break;
        }
    }
    return 0;
}