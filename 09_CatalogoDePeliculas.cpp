#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

struct Pelicula {
    int id;
    string titulo;
    string director;
    bool enCartelera;
};

void registrarPelicula(vector<Pelicula> &peliculas) {
    Pelicula nueva;

    cout << "\n=== REGISTRAR NUEVA PELICULA ===\n";

    cout << "ID: ";
    cin >> nueva.id;
    if (nueva.id < 0 || nueva.id > 999) {
        cout << "ERROR: El ID debe tener como máximo 3 dígitos.\n";
        return;
    }

    cin.ignore();
    cout << "TITULO: ";
    getline(cin, nueva.titulo);

    cout << "DIRECTOR: ";
    getline(cin, nueva.director);

    int estado;
    cout << "Seleccione una opcion:\n";
    cout << "1. En cartelera\n";
    cout << "0. Fuera de cartelera\n>>> ";
    cin >> estado;

    nueva.enCartelera = (estado == 1);

    peliculas.push_back(nueva);

    cout << "Película registrada con éxito.\n";
}

void listarPeliculas(const vector<Pelicula> &peliculas) {
    if (peliculas.empty()) {
        cout << "\nNo hay peliculas registradas...\n";
        return;
    }

    cout << "\n# | ID   | TITULO                 | DIRECTOR              | ESTADO\n";

    for (int i = 0; i < peliculas.size(); i++) {
        cout << i + 1 << " | "
             << setw(4) << peliculas[i].id << " | "
             << setw(22) << peliculas[i].titulo << " | "
             << setw(21) << peliculas[i].director << " | ";

        if (peliculas[i].enCartelera) cout << "En cartelera\n";
        else cout << "Fuera de cartelera\n";
    }
}

void buscarPelicula(const vector<Pelicula> &peliculas) {
    if (peliculas.empty()) {
        cout << "\nNo hay peliculas registradas...\n";
        return;
    }

    int idBuscar;
    cout << "ID: ";
    cin >> idBuscar;
     cout << "\n# | ID   | TITULO                 | DIRECTOR              | ESTADO\n";

    for (int i = 0; i < peliculas.size(); i++) {
        if (idBuscar == peliculas[i].id) {
            cout << i + 1 << " | "
                 << setw(4) << peliculas[i].id << " | "
                 << setw(22) << peliculas[i].titulo << " | "
                 << setw(23) << peliculas[i].director << " | ";

            if (peliculas[i].enCartelera) cout << "En cartelera\n";
            else cout << "Fuera de cartelera\n";   
            return;
        }
    }
    cout << "\n? | " << idBuscar << " | ---------------------- | --------------------- | ------\n> No encontrado\n";
}

void cambiarEstado(vector<Pelicula> &peliculas) {
    if (peliculas.empty()) {
        cout << "\nNo hay peliculas registradas...\n";
        return;
    }

    int idCambiar;
    cout << "ID: ";
    cin >> idCambiar;

    for (int i = 0; i < peliculas.size(); i++) {
        if (idCambiar == peliculas[i].id) {
            peliculas[i].enCartelera = !peliculas[i].enCartelera;
            cout << "\nEstado actualizado con éxito\n";
            return;
        }
    }
    cout << "\nID (" << idCambiar << ") no encontrado\n";
}

void eliminarPelicula(vector<Pelicula> &peliculas) {
    if (peliculas.empty()) {
        cout << "\nNo hay peliculas registradas...\n";
        return;
    }

    int idEliminar;
    cout << "ID: ";
    cin >> idEliminar;

    for (int i = 0; i < peliculas.size(); i++) {
        if (idEliminar == peliculas[i].id) {
            string eliminado = peliculas[i].titulo;
            peliculas.erase(peliculas.begin() + i);
            cout << eliminado << " eliminada con éxito\n";
            return;
        }
    }
    cout << "\nID (" << idEliminar << ") no encontrado\n";
}

vector<Pelicula> filtrar(const vector<Pelicula> &peliculas, bool estado) {
    vector<Pelicula> filtro;
    for (int i=0; i< peliculas.size(); i++) {
        if (peliculas[i].enCartelera == estado) filtro.push_back(peliculas[i]);
    }
    return filtro;
}

int main() {
    system("chcp 65001 > nul");
    vector<Pelicula> peliculas;
    int opcion;
    
    while (opcion != 7) {
        cout << "\n\tMENU";
        cout << "\n1. Registrar Película"
             << "\n2. Listar Películas"
             << "\n3. Buscar Película"
             << "\n4. Cambiar estado"
             << "\n5. Eliminar Película"
             << "\n6. Filtrar Películas"
             << "\n7. SALIR\n>>> ";
        cin >> opcion;

        switch (opcion) {
        case 1: registrarPelicula(peliculas); break;
        case 2: listarPeliculas(peliculas); break;
        case 3: buscarPelicula(peliculas); break;
        case 4: cambiarEstado(peliculas); break;
        case 5: eliminarPelicula(peliculas); break;
        case 6: {
            int opcion;
            cout << "\nFiltrar por estado:\n";
            cout << "1. En cartelera\n";
            cout << "0. Fuera de cartelera\n>>> ";
            cin >> opcion;

            bool estado = (opcion == 1);

            vector<Pelicula> lista = filtrar(peliculas, estado);

            if (lista.empty()) {
                cout << "\nNo hay peliculas con ese estado\n";
            } else {
                cout << "\n=== PELICULAS FILTRADAS ===\n";
                for (int i = 0; i < lista.size(); i++) {
                    cout << i + 1 << " | "
                        << setw(4) << peliculas[i].id << " | "
                        << setw(20) << peliculas[i].titulo << " | "
                        << setw(20) << peliculas[i].director << " | ";

                    if (peliculas[i].enCartelera) cout << "En cartelera\n";
                    else cout << "Fuera de cartelera\n";
                }
            }
            break;
        }
        case 7:
            cout << "\nGracias por usar el sistema\nSALIENDO...";
            break;
        default:
            cout << "\nOpción Inválida" << endl;
            break;
        }
    }    
}