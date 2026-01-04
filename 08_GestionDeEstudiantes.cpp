#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string carrera;
    double promedio;
};

void registrarEstudiante(vector<Estudiante> &estudiantes) {
    Estudiante nuevo;
    cout << "=== REGISTRAR NUEVO ESTUDIANTE ===";
    cout << "\nID: ";
    cin >> nuevo.id;
    if (nuevo.id > 1000 || nuevo.id <0) {
        cout << "\nERROR: El ID NO debe tener más de 3 dígitos" << endl;
        return;
    }
    cout << "NOMBRE: ";
    cin.ignore();
    getline(cin, nuevo.nombre);
    cout << "CARRERA: ";
    getline(cin, nuevo.carrera);
    cout << "PROMEDIO: ";
    cin >> nuevo.promedio;
    if (nuevo.promedio > 20 || nuevo.promedio < 0) {
        cout << "\nERROR: El promedio debe estar en un rango de 0-20" << endl;
        return;
    }

    estudiantes.push_back(nuevo);
}

void listarEstudiante(const vector<Estudiante> &estudiantes) {
    if (estudiantes.empty()) {
        cout << "\nNo hay estudiantes registrados..." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    for (int i=0; i<estudiantes.size(); i++) {
        cout << "\tESTUDIANTE "<< i+1;
        cout << "\nID: " << estudiantes[i].id
             << "\nNOMBRE: " << estudiantes[i].nombre
             << "\nCARRERA: " << estudiantes[i].carrera
             << "\nPROMEDIO: " << estudiantes[i].promedio 
             << "\n------------------------------" << endl;
    }
}

void buscarEstudiante(const vector<Estudiante> &estudiantes) {
    if (estudiantes.empty()) {
        cout << "\nNo hay estudiantes registrados..." << endl;
        return;
    }
    
    int buscar;

    cout << "Ingrese ID a buscar\n>>> ";
    cin >> buscar;

    cout << fixed << setprecision(2);

    for (int i=0; i<estudiantes.size(); i++) {
        if (buscar == estudiantes[i].id) {
            cout << "\tESTUDIANTE "<< i+1;
            cout << "\nID: " << estudiantes[i].id
                 << "\nNOMBRE: " << estudiantes[i].nombre
                 << "\nCARRERA: " << estudiantes[i].carrera
                 << "\nPROMEDIO: " << estudiantes[i].promedio << endl;
            return;
        }
    }
    cout << "\nEstudiante (" << buscar << ") no encontrado...";
}

void actualizarEstudiante(vector<Estudiante> &estudiantes) {
    if (estudiantes.empty()) {
        cout << "\nNo hay estudiantes registrados...\n";
        return;
    }

    int buscar;
    cout << "Ingrese ID a buscar\n>>> ";
    cin >> buscar;

    for (int i = 0; i < estudiantes.size(); i++) {
        if (buscar == estudiantes[i].id) {
            int opcion;
            cout << "\n¿Qué dato desea modificar?\n";
            cout << "1. Nombre\n";
            cout << "2. Carrera\n";
            cout << "3. Promedio\n>>> ";
            cin >> opcion;
            cin.ignore();

            if (opcion == 1) {
                cout << "Ingrese el nuevo nombre\n> ";
                getline(cin, estudiantes[i].nombre);
                cout << "Nombre actualizado con éxito!\n";
            }
            else if (opcion == 2) {
                cout << "Ingrese la nueva carrera\n> ";
                getline(cin, estudiantes[i].carrera);
                cout << "Carrera actualizada con éxito!\n";
            }
            else if (opcion == 3) {
                cout << "Ingrese el nuevo promedio\n> ";
                cin >> estudiantes[i].promedio;
                cout << "Promedio actualizado con éxito!\n";
            }
            else {
                cout << "Opción inválida.\n";
            }
            return;
        }
    }

    cout << "\nEstudiante (" << buscar << ") no encontrado...\n";
}

void eliminarEstudiante(vector<Estudiante> &estudiantes) {
    if (estudiantes.empty()) {
        cout << "\nNo hay estudiantes registrados...\n";
        return;
    }

    int buscar;
    cout << "Ingrese ID a eliminar\n>>> ";
    cin >> buscar;

    for (int i = 0; i < estudiantes.size(); i++) {

        if (buscar == estudiantes[i].id) {
            estudiantes.erase(estudiantes.begin() + i);
            cout << "Estudiante eliminado con éxito\n";
            return;
        }
    }

    cout << "\nEstudiante (" << buscar << ") no encontrado...\n";
}

vector<Estudiante> aprobados(const vector<Estudiante> &estudiantes) {
    vector<Estudiante> lista;
    for (int i=0; i<estudiantes.size(); i++) {
        if (estudiantes[i].promedio >= 14) lista.push_back(estudiantes[i]);
    }

    return lista;
}

int main() {
    system("chcp 65001 > nul");
    vector<Estudiante> estudiantes;
    int estudianteN = 0, opcion = 0;

    do {
        cout << "\n=== MENU ===";
        cout << "\n1. Registrar estudiante"
             << "\n2. Listar estudiantes"
             << "\n3. Buscar estudiante"
             << "\n4. Actualizar estudiante"
             << "\n5. Eliminar estudiante"
             << "\n6. Mostrar aprobados"
             << "\n7. SALIR\n>>> ";

        cin >> opcion;
        cout << endl;

        switch (opcion) {
        case 1: registrarEstudiante(estudiantes); break;
        case 2: listarEstudiante(estudiantes); break;
        case 3: buscarEstudiante(estudiantes); break;
        case 4: actualizarEstudiante(estudiantes); break;
        case 5: eliminarEstudiante(estudiantes); break;
        case 6: {
            vector<Estudiante> lista = aprobados(estudiantes);
            if (lista.empty()) {
            cout << "\nNo hay estudiantes aprobados\n";
            } else {
            cout << "\n=== ESTUDIANTES APROBADOS ===\n";
                for (int i = 0; i < lista.size(); i++) {
                    cout << "ID: " << lista[i].id << endl;
                    cout << "NOMBRE: " << lista[i].nombre << endl;
                    cout << "CARRERA: " << lista[i].carrera << endl;
                    cout << "PROMEDIO: " << lista[i].promedio << endl;
                    cout << "----------------------------\n";
                }
            }
            break;            
        }
        case 7: 
            cout << "Gracias por usar el sistema\nSALIENDO...";
            break;
        default:
            cout << "\nOpción Inválida" << endl;
            break;
        }
    } while (opcion != 7);
}