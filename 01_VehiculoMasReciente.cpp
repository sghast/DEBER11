#include <iostream>
using namespace std;

struct Vehiculo {
    string marca;
    string modelo;
    int anio;
};

void ingresarDatos(Vehiculo vehiculos[], int &pos) {
    if (pos >= 5) {
        cout << "\nAlmacenamiento lleno\n";
        return;
    }

    cout << "\nDATOS DEL VEHICULO";
    cout << "\nIngrese la marca: ";
    cin >> vehiculos[pos].marca;

    cin.ignore(); 
    cout << "Ingrese el modelo: ";
    getline(cin, vehiculos[pos].modelo);

    cout << "Ingrese el año: ";
    cin >> vehiculos[pos].anio;

    pos++;
}

void mostrarDatosReciente(Vehiculo vehiculo) {
    cout << "\nDATOS DEL VEHICULO MÁS RECIENTE";
    cout << "\nMARCA: " << vehiculo.marca
         << "\nMODELO: " << vehiculo.modelo
         << "\nAÑO: " << vehiculo.anio << endl;
}

int main() {
    system("chcp 65001 > nul");

    Vehiculo vehiculos[5];
    int pos = 0;
    int opcion;

    do {
        cout << "\n=== MENÚ ====";
        cout << "\n1. Ingresar vehículo"
             << "\n2. Mostrar datos del vehículo más reciente"
             << "\n3. SALIR"
             << "\n>>> ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                ingresarDatos(vehiculos, pos);
                break;

            case 2:
                if (pos == 0) {
                    cout << "\nNo hay vehículos registrados\n";
                } else {
                    mostrarDatosReciente(vehiculos[pos - 1]);
                }
                break;

            case 3:
                cout << "\nGracias por usar el sistema\nSALIENDO...\n";
                break;

            default:
                cout << "\nOpción inválida!\n";
        }

    } while (opcion != 3);
}