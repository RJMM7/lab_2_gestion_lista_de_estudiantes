#include <iostream>
using namespace std;

class Estudiante {
// Atributos
private:
    string nombre;
    float notaFinal;

// Constructor
public:
    Estudiante(string nombreEstudiante, float notaEstudiante) {
        nombre = nombreEstudiante;
        notaFinal = notaEstudiante;
    }

    // Metodo
    void imprimir() {
        cout << "Nombre: " << nombre << " Nota final: " << notaFinal << endl;
    }

    float obtenerNotaFinal() {
        return notaFinal;
    }
};


class Nodo{ 

    public:
    Estudiante estudiante;
    Nodo* siguiente;

    Nodo(Estudiante e) : estudiante(e) { 
        siguiente = nullptr;
    }
};


class ListaEnlazada { 
    private: Nodo* head;

    float sumarNotasRecursivo(Nodo* nodo) { 
        if(nodo==nullptr)
        return 0;
        return nodo ->estudiante.obtenerNotaFinal() + sumarNotasRecursivo(nodo->siguiente);
    }

    int contarNodosRecursivo(Nodo* nodo) { 
        if(nodo==nullptr)
        return 0;
        return 1 + contarNodosRecursivo(nodo->siguiente);
    }
    public: 
    ListaEnlazada(){ 
        head = nullptr;
    }

    void agregarEstudiante(string nombre, float nota) { 
        Estudiante nuevo(nombre, nota);
        Nodo* nuevoNodo = new Nodo(nuevo);

        if(head == nullptr) {
            head = nuevoNodo;
        } else { 
            Nodo* actual = head;
            while(actual->siguiente != nullptr) { 
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }


    void imprimirLista() {

        Nodo* actual = head;
        while(actual!=nullptr) {
            actual->estudiante.imprimir();
            actual = actual ->siguiente;
        }
    }

     float calcularPromedioRecursivo() {
        int total = contarNodosRecursivo(head);
        if (total == 0) return 0;

        float suma = sumarNotasRecursivo(head);
        return suma / total;
    }

};

int main() {
    
    ListaEnlazada lista;

    lista.agregarEstudiante("Daniel", 8);
    lista.agregarEstudiante("Medrano", 7.5);
    lista.agregarEstudiante("Calles", 5.4);

    cout<<" Lista de estudiantes\n";
    lista.imprimirLista();

    float promedio = lista.calcularPromedioRecursivo();
    cout<< " El promedio de notas es: " << promedio << " \n";
    
    return 0;
}