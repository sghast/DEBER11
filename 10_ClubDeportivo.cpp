#include <iostream> 
#include <vector>
using namespace std;

struct Jugador {
    int id;
    string nombre;
    string posicion;
    int edad;
};

struct Equipo {
    int id;
    string nombre;
    string entrenador;
    vector<Jugador> jugadores;
};

void registrarEquipo(vector<Equipo> &equipos) {
    Equipo nuevoE;
    cout << "COMPLETE LA INFORMACION DEL NUEVO EQUIPO\n";
    cout << "ID: ";
    cin >> nuevoE.id;
    if (nuevoE.id < 0 || nuevoE.id > 999) {
        cout << "ERROR: El ID debe tener máximo 3 dígitos" << endl;
        return;
    }
    cin.ignore();
    cout << "NOMBRE: ";
    getline(cin, nuevoE.nombre);
    cout << "ENTRENADOR: ";
    getline(cin, nuevoE.entrenador);
    
    nuevoE.jugadores.clear();

    equipos.push_back(nuevoE);
    cout << nuevoE.nombre << " registrado con éxito!" << endl;
}

int indiceEquipo(const vector<Equipo> &equipos, int numEquipo) {
    for (int i=0; i<equipos.size(); i++) {
        if (numEquipo == equipos[i].id) return i;
    }
    return -1;
}

void agregarJugador(vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "No hay equipos para agregar jugadores...\n";
        return;
    }

    int numEquipo;
    cout << "ID del equipo: ";
    cin >> numEquipo;

    int indice = indiceEquipo(equipos, numEquipo);

    if (indice == -1) {
        cout << "Equipo (" << numEquipo << ") no existe...\n";
        return;
    }

    Jugador nuevoJ;
    cout << "COMPLETE LA INFORMACIÓN DEL NUEVO JUGADOR\n";
    cout << "ID: ";
    cin >> nuevoJ.id;
    if (nuevoJ.id < 0 || nuevoJ.id > 999) {
        cout << "ERROR: El ID debe tener máximo 3 dígitos\n";
        return;
    }

    cin.ignore();
    cout << "NOMBRE: ";
    getline(cin, nuevoJ.nombre);

    cout << "POSICION: ";
    getline(cin, nuevoJ.posicion);

    cout << "EDAD: ";
    cin >> nuevoJ.edad;

    equipos[indice].jugadores.push_back(nuevoJ);

    cout << nuevoJ.nombre << " agregado a la plantilla.\n";
}

void listarEquipos(const vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "No hay equipos registrados...\n";
        return;
    }

    for (int i=0; i<equipos.size(); i++) {
        cout << equipos[i].nombre << " (ID: " << equipos[i].id 
             << ") - Entrenador: " << equipos[i].entrenador << endl;
        if (equipos[i].jugadores.empty()) {
            cout << "Sin jugadores\n";
        } else {
            cout << "\tJUGADORES\n";
            for (int j=0; j<equipos[i].jugadores.size(); j++) {
            cout << "\t" << j+1 << ". (ID: " << equipos[i].jugadores[j].id << ") "
                 << equipos[i].jugadores[j].nombre << " / "
                 << equipos[i].jugadores[j].edad << " años / "
                 << equipos[i].jugadores[j].posicion << endl;
            }
        }
        cout << "-----------------------------------------------------\n";
    }
}

void buscarEquipo(const vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "No hay equipos registrados...\n";
        return;
    }

    int idBuscar;
    cout << "ID del equipo: ";
    cin >> idBuscar;

    for (int i=0; i<equipos.size(); i++) {
        if (idBuscar == equipos[i].id) {
            cout << endl;
            cout << equipos[i].nombre << " (ID: " << equipos[i].id 
                << ") - Entrenador: " << equipos[i].entrenador << endl;
            if (equipos[i].jugadores.empty()) {
                cout << "Sin jugadores\n";
            } else {
                cout << "\tJUGADORES\n";
                for (int j=0; j<equipos[i].jugadores.size(); j++) {
                cout << "\t" << j+1 << ". (ID: " << equipos[i].jugadores[j].id << ") "
                     << equipos[i].jugadores[j].nombre << " / "
                     << equipos[i].jugadores[j].edad << " años / "
                     << equipos[i].jugadores[j].posicion << endl;
                }
            }
            return;
        }
    }
    cout << "Equipo (" << idBuscar << ") no encontrado..." << endl;
}

void eliminarJugador(vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "No hay equipos registrados...\n";
        return;
    }

    int idEliminar;
    cout << "ID del jugador: ";
    cin >> idEliminar;

    for (int i=0; i<equipos.size(); i++) {
        for (int j=0; j<equipos[i].jugadores.size(); j++) {
            if (idEliminar == equipos[i].jugadores[j].id) {
                string eliminado = equipos[i].jugadores[j].nombre;
                equipos[i].jugadores.erase(equipos[i].jugadores.begin() + j);
                cout << eliminado << " eliminado de " 
                     << equipos[i].nombre << " con éxito!";
                return;
            }
        }
    }
    cout << "Jugador (" << idEliminar << ") no encontrado..." << endl;
}

vector<Equipo> filtrar(const vector<Equipo> &equipos, const string &nEntrenador) {
    vector<Equipo> filtroEntrenadores;
    for (int i=0; i<equipos.size(); i++) {
        if (nEntrenador == equipos[i].entrenador) filtroEntrenadores.push_back(equipos[i]);
    }
    return filtroEntrenadores;
}

void eliminarEquipo(vector<Equipo> &equipos) {
    if (equipos.empty()) {
        cout << "No hay equipos registrados...\n";
        return;
    }

    int idEquipoEliminar;
    cout << "ID del equipo: ";
    cin >> idEquipoEliminar;

    for (int i=0; i<equipos.size(); i++) {
        if (idEquipoEliminar == equipos[i].id) {
            string equipoEliminado = equipos[i].nombre;
            equipos.erase(equipos.begin() + i);
            cout << equipoEliminado << " eliminado con éxito!\n";
            return;
        }
    }
    cout << "Equipo (" << idEquipoEliminar << ") no encontrado..." << endl;
}

int main() {
    system("chcp 65001 > nul");
    vector<Equipo> equipos;
    int opcion;

    do {
        cout << "\n\t=== MENU ===";
        cout << "\n1. Registrar equipo"
             << "\n2. Agregar jugador a equipo"
             << "\n3. Listar equipos con sus jugadores"
             << "\n4. Buscar equipo"
             << "\n5. Eliminar jugador de un equipo"
             << "\n6. Filtrar equipos por entrenador"
             << "\n7. Eliminar equipo completo"
             << "\n8. SALIR\n>>> ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: registrarEquipo(equipos); break;
        case 2: agregarJugador(equipos); break;
        case 3: listarEquipos(equipos); break;
        case 4: buscarEquipo(equipos); break;
        case 5: eliminarJugador(equipos); break;
        case 6: {
            string filEntrenador;
            cout << "\nIngrese el nombre del entrenador\n";
            getline(cin, filEntrenador);

            vector<Equipo> eqEntrenador = filtrar(equipos, filEntrenador);

            if (!eqEntrenador.empty()) {
                cout << "EQUIPOS A CARGO DE " << filEntrenador << endl;
                for (int i=0; i<eqEntrenador.size(); i++) {
                    cout << i+1 << ". " << eqEntrenador[i].nombre
                         << " (ID: " << eqEntrenador[i].id << ")"
                         << " - Jugadores: " << eqEntrenador[i].jugadores.size() << endl;
                }
            } else {
                cout << filEntrenador << " no es entrenador de ningún equipo\n";
            }
        }
        break;
        case 7: eliminarEquipo(equipos); break;
        case 8:
            cout << "Gracias por usar el sistema\nSALIENDO...";
            break;
        default:
            cout << "Opción Inválida\n";
            break;
        }
    } while (opcion != 8);
}