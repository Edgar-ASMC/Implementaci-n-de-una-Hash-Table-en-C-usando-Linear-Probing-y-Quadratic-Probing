//
// Created by Edgar on 26/11/2024.
//
#include "HashTable.h"

TablaHash::TablaHash(int tamanio, MetodoColision metodo)
    : tamanioTabla(tamanio), numElementos(0), metodoColision(metodo) {
    tabla.resize(tamanioTabla, -1);
}

int TablaHash::funcionHash(int clave) const {
    return clave % tamanioTabla;
}

int TablaHash::resolucionLineal(int clave, int intento) const {
    return (funcionHash(clave) + intento) % tamanioTabla;
}

int TablaHash::resolucionCuadratica(int clave, int intento) const {
    return (funcionHash(clave) + intento * intento) % tamanioTabla;
}

void TablaHash::rehash() {
    vector<int> tablaAntigua = tabla;
    tamanioTabla *= 2;
    tabla.resize(tamanioTabla, -1);
    numElementos = 0;

    for (int clave : tablaAntigua) {
        if (clave != -1 && clave != -2) {
            insertar(clave);
        }
    }
}

void TablaHash::insertar(int clave) {
    if ((double)numElementos / tamanioTabla >= 0.7) {
        rehash();
    }

    int intento = 0;
    int indice;
    do {
        indice = (metodoColision == RESOLUCION_LINEAL)
                    ? resolucionLineal(clave, intento)
                    : resolucionCuadratica(clave, intento);
        intento++;
    } while (tabla[indice] != -1 && tabla[indice] != -2);

    tabla[indice] = clave;
    numElementos++;
}

bool TablaHash::buscar(int clave) const {
    int intento = 0;
    int indice;
    do {
        indice = (metodoColision == RESOLUCION_LINEAL)
                    ? resolucionLineal(clave, intento)
                    : resolucionCuadratica(clave, intento);

        if (tabla[indice] == clave) {
            return true;
        }
        intento++;
    } while (tabla[indice] != -1 && intento < tamanioTabla);

    return false;
}

void TablaHash::eliminar(int clave) {
    int intento = 0;
    int indice;
    do {
        indice = (metodoColision == RESOLUCION_LINEAL)
                    ? resolucionLineal(clave, intento)
                    : resolucionCuadratica(clave, intento);

        if (tabla[indice] == clave) {
            tabla[indice] = -2;
            numElementos--;
            return;
        }
        intento++;
    } while (tabla[indice] != -1 && intento < tamanioTabla);
}

void TablaHash::mostrar() const {
    for (int i = 0; i < tamanioTabla; ++i) {
        cout << "Indice " << i << ": ";
        if (tabla[i] == -1) {
            cout << "Vacío";
        } else if (tabla[i] == -2) {
            cout << "Eliminado";
        } else {
            cout << tabla[i];
        }
        cout << "\n";
    }
}
