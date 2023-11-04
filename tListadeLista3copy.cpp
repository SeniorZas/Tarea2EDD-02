#include<iostream>
#include<string>
#include"tLista.cpp"

using namespace std;

const int MAXSIZE = 100000; 

typedef tLista tElemLista;

class tListadeLista{
    private:
    int maxSize;
    int listSize;
    int curr;
    tElemLista * listArray;
    
    //Pequeño truquito falta inicializarlo
    tElem *elemArray;
    
    //Arreglo de listas

    
    public:
    //Terminadas
    tListadeLista();
    ~tListadeLista();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();

    //Por hacer
    int length();
    void currPos();
    void moveToPos();
    int append(); //Modificar insertar listas

    int getValue();
    int insert();



    void clear();
    int insert(int posicion, tElem elem);

};

tListadeLista::tListadeLista() {
    maxSize = MAXSIZE; // tamaño máximo de la lista
    listSize = 0;
    // lista vacía
    curr = 0;
    listArray = new tElemLista[maxSize];
}

tListadeLista::~tListadeLista() { delete[] listArray; }

void tListadeLista::moveToStart() { curr = 0; }

void tListadeLista::moveToEnd() { curr = listSize; }

void tListadeLista::prev() { if (curr != 0) curr--; }

void tListadeLista::next() { if (curr < listSize) curr++; }

//PPT

int tListadeLista::insert(tElemLista item) {
    int i=0;
    if (listSize >= maxSize) return -1; //lista llena, no se inserta
    for (i = listSize; i > curr; i--) listArray[i] = listArray[i-1];
    
    listArray[i] = item;
    listSize++;
    return i; // retorna posición de inserción
}


//Modifiquen esto para que inserte listas
int tListadeLista::append(tElemLista item) {
    if (listSize >= maxSize) return 0;
    //lista llena, no se inserta
    listArray[listSize++] = item;
    return 1;
    // inserción exitosa
}







int main(){
    tListadeLista l;
    tLista lista;
    lista.append(1);
    lista.append(2);
    lista.append(3);

    lista.printList();
    lista.moveToStart();

    l.appendList(lista);


    cout<<l.insert(0,1)<<endl;

    //l.elemsXlista(3);

    //l.insert(2,10);
    //l.printLists();



    return 0;
}