//Calcular el mayor y menor elemento de la lista

#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *siguiente;	
};

void menu();
void insertarLista(Nodo *&,int);
void mostrarLista(Nodo *);
void borrarNodo(Nodo *&,int);
void insertarAlFinal(Nodo *&, int);
void calcularMayorMenor(Nodo *);
void sumaPromedio(Nodo *);

Nodo *lista = NULL;      //Variables

int main(){
	int dato;
	char opcion;
	
	menu();
	
	return 0;
}

//Insertar elemento en la lista
void insertarLista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	Nodo *aux;
	
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = NULL;
	
	if(lista == NULL){//Si la lista esta vacia
		lista = nuevo_nodo;//agregamos el primer nodo
	}
	else{
		aux = lista;
		while(aux->siguiente != NULL){//recorremos la lista hasta llegar al final
			aux = aux->siguiente;
		}
		aux->siguiente = nuevo_nodo;//agregamos el nuevo nodo al final de la lista
	}
	cout<<"\tElemento "<<n<<" agregado a lista correctamente\n";
}

//Mostrar todos los elementos de la lista
void mostrarLista(Nodo *lista){	
	Nodo *actual = new Nodo();
	
	actual = lista;
	while(actual != NULL){ //mientras no sea final de la lista
		cout<<actual->dato<<" -> "; //mostramos el dato
		actual = actual->siguiente; //avanzamos a la siguiente posicion de la lista
	}
}

//Borrar Nodo
void borrarNodo(Nodo *&lista, int n){
	//preguntar si la lista no esta vacia 
	if(lista != NULL){
		Nodo *aux_borrar;
		Nodo *anterior = NULL; 

		aux_borrar = lista;

		//recorrer la lista 
		while((aux_borrar != NULL) && (aux_borrar->dato != n)){
			anterior = aux_borrar;
			aux_borrar = aux_borrar->siguiente;
		}
		//el elemento no ha sido encontrado 
		if(aux_borrar == NULL){
			cout<<"El elemento no ha sido encontrado";
		}
		//el primer elemento es que vamos a borrar 
		else if(anterior == NULL){
			lista = lista->siguiente;
			delete aux_borrar;
		}
		//El elemento esta en la lista pero no es el primer nodo
		else{
			anterior->siguiente = aux_borrar->siguiente;
			delete aux_borrar;
			cout<<"elemento borrado";
		}
	}
}

// Insertar elemento al final de la lista
void insertarAlFinal(Nodo *&lista, int n) {
    insertarLista(lista, n);
}



//Calcular el mayor y el menor elemento de la lista
void calcularMayorMenor(Nodo *lista){
	int mayor=0,menor=999999;

	while (lista != NULL){  //recorrer la lista 
		if((lista->dato) > mayor){
			mayor = lista->dato;
		}
		if((lista->dato) < menor){
			menor = lista->dato;
		}
		lista = lista->siguiente; 
	}

	cout<<"\nEl mayor elemento es: "<<mayor<<endl;
	cout<<"\nEl menor elemento es: "<<menor<<endl;
}

void sumaPromedio(Nodo *lista){
	int suma, promedio = 0,contador = 0;

	while (lista != NULL){  //recorrer la lista 
		suma = suma + lista->dato;
		contador ++;
		promedio = suma / contador;

		lista = lista->siguiente;
	}
	cout<<"\nLa suma es: "<<suma<<endl;
	cout<<"\nEl promedio es: "<<promedio<<endl;
}


void menu(){
    int opcion,dato;

    do{
        cout<<"\t.:MENU:.\n";
        cout<<"1. Insertar elemento al principio de la lista\n";
        cout<<"2. Insertar elemento al final de la lista\n";
        cout<<"3. Mostrar elementos de la lista\n";
		cout<<"4. Eliminar elemento de la lista\n";
		cout<<"5. Calcular mayor y menor elemento de la lista\n";
		cout<<"6. calcular suma y promedio\n";
        cout<<"7. Salir\n";
        cout<<"Opcion: ";cin>>opcion;

        switch (opcion){
        case 1: cout<<"Digite un numero para agregarlo al principio de la lista: ";
		        cin>>dato;
		        insertarLista(lista,dato);
                cout<<"\n";
                break;
        case 2: cout<<"Digite un numero para agregarlo al final de la lista: ";
		        cin>>dato;
		        insertarAlFinal(lista,dato);
                cout<<"\n";
                break;
        case 3: cout<<"\nElementos de la lista: \n";
	            mostrarLista(lista); //mostramos la lista
                cout<<"\n";
                break;
		case 4: cout<<"\nDigite el elemento que desea eliminar: ";
				cin>>dato;
				borrarNodo(lista,dato);
				cout<<"\n";
				break;
		case 5: calcularMayorMenor(lista);
				cout<<"\n";
				break;
		case 6: sumaPromedio(lista);
				cout<<"\n";
				break;
        } 

    }while(opcion != 7 );

}