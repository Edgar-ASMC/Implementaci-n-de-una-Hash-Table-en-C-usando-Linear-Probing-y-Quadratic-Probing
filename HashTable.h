//
// Created by Edgar on 26/11/2024.
//
#ifndef TABLAHASH_H
#define TABLAHASH_H

#include <iostream>
#include <vector>
using namespace std;

enum MetodoColision {
    RESOLUCION_LINEAL,
    RESOLUCION_CUADRATICA
};

class TablaHash {
private:
    vector<int> tabla;
    int tamanioTabla;
    int numElementos;
    MetodoColision metodoColision;

    int funcionHash(int clave) const;
    int resolucionLineal(int clave, int intento) const;
    int resolucionCuadratica(int clave, int intento) const;
    void rehash();

public:
    TablaHash(int tamanio, MetodoColision metodo);
    void insertar(int clave);
    bool buscar(int clave) const;
    void eliminar(int clave);
    void mostrar() const;
};

#endif // TABLAHASH_H
