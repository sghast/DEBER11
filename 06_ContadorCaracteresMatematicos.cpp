#include <iostream>
#include <string>
#include <vector>
using namespace std;

void separarComponentes(const string &expresion) {

    vector<char> numeros;
    vector<char> operadores;
    vector<char> otros;

    for (int i = 0; i < expresion.length(); i++) {
        char c = expresion[i];
        bool existe = false;

        if (c >= '0' && c <= '9') {
            for (char n : numeros) {
                if (n == c) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                numeros.push_back(c);
            }
        }

        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            for (char op : operadores) {
                if (op == c) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                operadores.push_back(c);
            }
        }

        else if (c != ' ') {
            for (char o : otros) {
                if (o == c) {
                    existe = true;
                    break;
                }
            }
            if (!existe) {
                otros.push_back(c);
            }
        }
    }

    cout << "\nNumeros: ";
    for (char n : numeros) {
        cout << n << " ";
    }

    cout << "\nOperadores: ";
    for (char op : operadores) {
        cout << op << " ";
    }

    cout << "\nOtros: ";
    for (char o : otros) {
        cout << o << " ";
    }

    cout << endl;
}

int main() {
    string expresion;

    cout << "Ingrese la expresion matematica:\n>>> ";
    getline(cin, expresion);

    separarComponentes(expresion);

    return 0;
}
