#include <iostream>
#include <string>
using namespace std;

void procesarChats(string chat[], int n, string horas[], string usuarios[], string mensajes[], int &contRoberto, int &contBelen) {
    for (int i = 0; i < n; i++) {

        string texto = chat[i];

        int pos1 = texto.find("//");
        int pos2 = texto.find("//", pos1 + 2);

        horas[i] = texto.substr(0, pos1);
        usuarios[i] = texto.substr(pos1 + 2, pos2 - (pos1 + 2));
        mensajes[i] = texto.substr(pos2 + 2);

        if (usuarios[i] == "Roberto") contRoberto++;
        else if (usuarios[i] == "Belen") contBelen++;
    }
}

int main() {
    system("chcp 65001 > nul");
    string chat[] = {
        "08:15//Roberto//Hola perdida, ¿como estas?",
        "08:17//Belen//Bien, gracias. ¿Y tu?",
        "08:20//Roberto//Aqui pensandote. ¿Quieres salir al cine hoy?",
        "08:21//Belen//Tu novia, ¿si te da permiso?",
        "08:22//Roberto//Cual novia?. Es una amiga nomas",
        "08:23//Roberto//mejor tu pide permiso a tu novio?"
    };

    int n = 6;

    string horas[n];
    string usuarios[n];
    string mensajes[n];

    int contRoberto = 0;
    int contBelen = 0;

    procesarChats(chat, n, horas, usuarios, mensajes, contRoberto, contBelen);

    cout << "\n=== MENSAJES PROCESADOS ===\n";
    for (int i = 0; i < n; i++) {
        cout << "Hora: " << horas[i] << endl;
        cout << "Usuario: " << usuarios[i] << endl;
        cout << "Mensaje: " << mensajes[i] << endl;
        cout << "--------------------------\n";
    }

    cout << "\nMensajes enviados por Roberto: " << contRoberto << endl;
    cout << "Mensajes enviados por Belen: " << contBelen << endl;

    return 0;
}