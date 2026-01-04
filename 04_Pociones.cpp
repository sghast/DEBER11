#include <iostream>
#include <vector>
using namespace std;

struct PocionMagica {
    string nombre;
    vector<string> ingredientes;
    int tiempoPreparacion;
    string efecto;
};

void cargarPociones(vector<PocionMagica> &pociones);
bool contieneIngrediente(const PocionMagica &pocion, string ingrediente);
void buscarPorIngrediente(const vector<PocionMagica> &pociones, string ingrediente);

int main() {
    system("chcp 65001 > nul");
    vector<PocionMagica> pociones;

    cargarPociones(pociones);

    string ingredienteBuscado;
    cout << "Ingrese el nombre de un ingrediente: ";
    getline(cin, ingredienteBuscado);

    buscarPorIngrediente(pociones, ingredienteBuscado);

    return 0;
}

void cargarPociones(vector<PocionMagica> &pociones) {

    PocionMagica p1;
    p1.nombre = "Elixir de Fuerza";
    p1.ingredientes = {"Raíz de mandrágora", "Polvo de ogro", "Agua lunar"};
    p1.tiempoPreparacion = 30;
    p1.efecto = "Aumenta la fuerza física";

    PocionMagica p2;
    p2.nombre = "Poción de Invisibilidad";
    p2.ingredientes = {"Hojas de sombra", "Raíz de mandrágora", "Esencia espectral"};
    p2.tiempoPreparacion = 45;
    p2.efecto = "Vuelve invisible al usuario";

    PocionMagica p3;
    p3.nombre = "Brebaje de Sabiduría";
    p3.ingredientes = {"Flor de loto", "Tinta arcana", "Agua lunar"};
    p3.tiempoPreparacion = 25;
    p3.efecto = "Incrementa la inteligencia";

    pociones.push_back(p1);
    pociones.push_back(p2);
    pociones.push_back(p3);
}

bool contieneIngrediente(const PocionMagica &pocion, string ingrediente) {
    for (string ing : pocion.ingredientes) {
        if (ing == ingrediente) {
            return true;
        }
    }
    return false;
}

void buscarPorIngrediente(const vector<PocionMagica> &pociones, string ingrediente) {

    bool encontrado = false;

    cout << "\nPociones que contienen \"" << ingrediente << "\":\n";

    for (const PocionMagica &p : pociones) {
        if (contieneIngrediente(p, ingrediente)) {
            cout << "- " << p.nombre << " (" << p.efecto << ")\n";
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron pociones con ese ingrediente.\n";
    }
}