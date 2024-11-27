#include "HashTable.h"

int main() {
    cout << "Tabla Hash con Resolucion Lineal:\n";
    TablaHash tablaLineal(6, RESOLUCION_LINEAL);

    tablaLineal.insertar(1);
    tablaLineal.insertar(10);
    tablaLineal.insertar(2);
    tablaLineal.insertar(8);

    tablaLineal.mostrar();
    cout << "Buscar 8: " << (tablaLineal.buscar(8) ? "Encontrado" : "No encontrado") << "\n";
    tablaLineal.eliminar(8);
    cout << "Despues de eliminar 8:\n";
    tablaLineal.mostrar();

    cout << "\nTabla Hash con Resolucion Cuadratica:\n";
    TablaHash tablaCuadratica(6, RESOLUCION_CUADRATICA);

    tablaLineal.insertar(1);
    tablaLineal.insertar(10);
    tablaLineal.insertar(2);
    tablaLineal.insertar(8);

    tablaCuadratica.mostrar();
    cout << "Buscar 8: " << (tablaCuadratica.buscar(8) ? "Encontrado" : "No encontrado") << "\n";
    tablaCuadratica.eliminar(8);
    cout << "Despues de eliminar 8:\n";
    tablaCuadratica.mostrar();

    return 0;
}
