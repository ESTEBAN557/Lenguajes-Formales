#include <iostream> // Para entrada y salida
#include <string> // Para manejar cadenas de texto

using namespace std; // Se usa el espacio de nombres estándar para evitar escribir std:: antes de cada uso

// Definicion de los nombres de los estados tal cual aparecen en el diagrama
enum Estado { // Enumeración para representar los estados del autómata
    ESTADO_0137,
    ESTADO_247,
    ESTADO_7,
    ESTADO_8,
    ESTADO_58,
    ESTADO_68,
    ESTADO_RECHAZO // Estado de rechazo para cualquier transición no válida
};

bool perteneceAlLenguaje(string cadena) {
    // Inicia en el estado indicado por la flecha "inicio"
    Estado estadoActual = ESTADO_0137;

    for (int i = 0; i < cadena.length(); i++) { // Recorre cada símbolo de la cadena
        char simbolo = cadena[i]; // Obtiene el símbolo actual

        switch (estadoActual) { // Evalua el estado actual para determinar la transición
            case ESTADO_0137:
                if (simbolo == 'a') estadoActual = ESTADO_247;
                else if (simbolo == 'b') estadoActual = ESTADO_8;
                else estadoActual = ESTADO_RECHAZO;
                break;

            case ESTADO_247:
                if (simbolo == 'a') estadoActual = ESTADO_7;
                else if (simbolo == 'b') estadoActual = ESTADO_58;
                else estadoActual = ESTADO_RECHAZO;
                break;

            case ESTADO_7:
                if (simbolo == 'a') estadoActual = ESTADO_7;
                else if (simbolo == 'b') estadoActual = ESTADO_8;
                else estadoActual = ESTADO_RECHAZO;
                break;

            case ESTADO_58:
                if (simbolo == 'b') estadoActual = ESTADO_68;
                else estadoActual = ESTADO_RECHAZO;
                break;

            case ESTADO_68:
                if (simbolo == 'b') estadoActual = ESTADO_8;
                else estadoActual = ESTADO_RECHAZO;
                break;

            case ESTADO_8:
                if (simbolo == 'b') estadoActual = ESTADO_8;
                else estadoActual = ESTADO_RECHAZO;
                break;

            case ESTADO_RECHAZO:
                // Si cae en rechazo, se queda ahí
                break;
        }
    }

    // Verificamos si terminamos en un estado de aceptación (doble círculo) 
    if (estadoActual == ESTADO_247 ||
        estadoActual == ESTADO_8 ||
        estadoActual == ESTADO_68 ||
        estadoActual == ESTADO_58) {
    return true;
    }
    else {
    return false;
    }

}

int main() {
    string cadena;     
    cout << "--- Simulador de Automata Finito ---" << endl; 

    while (true) {

        cout << "\nIngrese la cadena a evaluar (alfabeto {a, b}) o 'salir': ";
        cin >> cadena;

        if (cadena == "salir") {
            cout << "Programa finalizado." << endl;
            break;
        }

        if (perteneceAlLenguaje(cadena)) {
            cout << "RESULTADO: La cadena SI es aceptada." << endl;
        } 
        else {
            cout << "RESULTADO: La cadena NO es aceptada." << endl;
        }
    }

    return 0;
}

