#include <iostream>
using namespace std;

void inicializarTablero(char tablero[][6], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 6; j++) {
            tablero[i][j] = '~';
        }
    }
}

void colocarBarco(char tablero[][6], int fila, int columnaInicio) {
    for (int j = columnaInicio; j < columnaInicio + 3; j++) {
        tablero[fila][j] = 'B';
    }
}

void mostrarTablero(char tablero[][6], int filas) {
    cout << "\nTABLERO\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < 6; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

bool disparar(char tablero[][6], int fila, int columna) {
    if (tablero[fila][columna] == 'B') {
        return true;
    }
    return false;
}

int main() {
    const int FILAS = 6;
    const int COLUMNAS = 6;

    char tablero[FILAS][COLUMNAS];

    inicializarTablero(tablero, FILAS);

    colocarBarco(tablero, 2, 1);

    mostrarTablero(tablero, FILAS);

    int fila, columna;
    cout << "\nIngrese fila (1-6): ";
    cin >> fila;
    cout << "Ingrese columna (1-6): ";
    cin >> columna;

    fila--; columna--;

    if (disparar(tablero, fila, columna)) {
        cout << "Impacto! Tocaste el barco.\n";
    } else {
        cout << "Fallaste el disparo!\n";
    }
}

