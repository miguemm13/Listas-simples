#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Nodo{
    string nombreArchivo;
    bool esPrioritario;
    Nodo *siguiente;    
};

void menu();
void insertarDocumento(Nodo *&, string, bool);
void mostrarDocumentos(Nodo *);
void procesarDocumento(Nodo *&);
bool colaLlena(Nodo *);

Nodo *colaDocumentos = nullptr; // Variable global para la cola de documentos

int main(){
    menu();
    return 0;
}

// Insertar un documento en la cola
void insertarDocumento(Nodo *&cola, string nombre, bool prioritario){
    Nodo *nuevoDocumento = new Nodo();
    nuevoDocumento->nombreArchivo = nombre;
    nuevoDocumento->esPrioritario = prioritario;
    nuevoDocumento->siguiente = nullptr;

    if (cola == nullptr){
        cola = nuevoDocumento;
    }
    else{
        Nodo *temp = cola;
        while (temp->siguiente != nullptr){
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoDocumento;
    }

    cout << "Documento '" << nombre << "' agregado a la cola correctamente." << endl;
}

// Mostrar todos los documentos en la cola
void mostrarDocumentos(Nodo *cola){
    if (cola == nullptr){
        cout << "La cola de documentos está vacía." << endl;
        return;
    }

    // Crear una lista temporal para ordenar los nodos
    Nodo *listaTemp = nullptr;
    while (cola != nullptr) {
        Nodo *nuevoNodo = new Nodo();
        nuevoNodo->nombreArchivo = cola->nombreArchivo;
        nuevoNodo->esPrioritario = cola->esPrioritario;
        nuevoNodo->siguiente = nullptr;

        // Insertar el nodo en la lista temporal de forma ordenada
        if (listaTemp == nullptr || (cola->esPrioritario && !listaTemp->esPrioritario)) {
            nuevoNodo->siguiente = listaTemp;
            listaTemp = nuevoNodo;
        } else {
            Nodo *aux = listaTemp;
            while (aux->siguiente != nullptr && (aux->siguiente->esPrioritario || !cola->esPrioritario)) {
                aux = aux->siguiente;
            }
            nuevoNodo->siguiente = aux->siguiente;
            aux->siguiente = nuevoNodo;
        }

        Nodo *temp = cola;
        cola = cola->siguiente;
        delete temp;
    }

    // Mostrar los documentos ordenados
    cout << "Documentos en la cola:" << endl;
    Nodo *temp = listaTemp;
    while (temp != nullptr) {
        cout << "Nombre: " << temp->nombreArchivo << " - Prioritario: " << (temp->esPrioritario ? "Sí" : "No") << endl;
        temp = temp->siguiente;
    }

    // Liberar la memoria de la lista temporal
    while (listaTemp != nullptr) {
        Nodo *aux = listaTemp;
        listaTemp = listaTemp->siguiente;
        delete aux;
    }
}


// Procesar el siguiente documento de la cola
void procesarDocumento(Nodo *&cola){
    if (cola == nullptr){
        cout << "La cola de documentos está vacía, no hay documentos para procesar." << endl;
        return;
    }

    Nodo *primerDocumento = cola;
    cola = cola->siguiente;
    cout << "Imprimiendo documento '" << primerDocumento->nombreArchivo << "'." << endl;
    delete primerDocumento;
}




// Verificar si la cola de documentos está llena (máximo 5 documentos)
bool colaLlena(Nodo *cola){
    int count = 0;
    Nodo *temp = cola;
    while (temp != nullptr){
        count++;
        temp = temp->siguiente;
    }
    return count >= 5;
}

void menu(){
    int opcion;
    string nombreDocumento;
    bool prioritario;

    do{
        cout << "\t.:MENU:.\n";
        cout << "1. Agregar documento a la cola\n";
        cout << "2. Mostrar documentos en la cola\n";
        cout << "3. Procesar siguiente documento\n";
        cout << "4. Salir\n";
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Ingrese el nombre del documento: ";
                cin >> nombreDocumento;
                cout << "¿Es prioritario? (1: Sí, 0: No): ";
                cin >> prioritario;
                if (colaLlena(colaDocumentos) && prioritario){
                    procesarDocumento(colaDocumentos);
                }
                if (!colaLlena(colaDocumentos)){
                    insertarDocumento(colaDocumentos, nombreDocumento, prioritario);
                }
                break;
            case 2:
                mostrarDocumentos(colaDocumentos);
                break;
            case 3:
                procesarDocumento(colaDocumentos);
                break;
        }
    } while (opcion != 4);
}
