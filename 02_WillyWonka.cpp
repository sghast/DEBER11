#include <iostream>
#include <iomanip>
using namespace std;

void nivelesDeDulzura(double tableta[][6]) {
    int valor;
    for (int i=0; i<4; i++) {
        for (int j=0; j<6; j++) {
            do {
                cout << "Celda [" << i+1 << "][" << j+1 << "]: ";
                cin >> valor;

                if (valor < 1 || valor > 9) {
                    cout << "FUERA DE RANGO! (1-9)\n";
                }
            } while (valor < 1 || valor > 9);

            tableta[i][j] = valor;
        }
    }
}


double promedioDulzura(double tableta[][6]) {
    double suma=0;
    for (int i=0; i<4; i++) {
        for (int j=0; j<6; j++) {
            suma += tableta[i][j];
        }
    }
    return suma/24;
}

int main() {
    double tableta[4][6];

    cout << "=== NIVELES DE DULZURA ===\n";
    nivelesDeDulzura(tableta);
    
    cout << fixed << setprecision(2);
    cout << "\nPROMEDIO: " << promedioDulzura(tableta);

}