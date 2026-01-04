#include <iostream>
#include <string>
using namespace std;

int contadorPalabras(string oracion) {
    int contador = 0;
    bool enPalabra = false;

    for (int i = 0; i < oracion.length(); i++) {
        if (oracion[i] != ' ' && !enPalabra) {
            contador++;
            enPalabra = true;
        }
        if (oracion[i] == ' ') {
            enPalabra = false;
        }
    }
    return contador;
}

int main() {
    string oracion;

    cout << "Escriba una oración:\n>>> ";
    getline(cin, oracion);

    cout << "Cantidad de palabras: " << contadorPalabras(oracion) << endl;
}