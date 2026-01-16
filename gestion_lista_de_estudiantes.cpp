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

int main() {
    
    
    
    return 0;
}