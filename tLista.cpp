#include<iostream>
#include<string>

using namespace std;

typedef int tElem;

struct tNodo{
    tElem info;
    tNodo* sig;
};

class tLista {
    private:
        tNodo* head;
        tNodo* tail;
        tNodo* curr;
        int listSize;
        int pos;

        tLista* sigL;
    public:
    //importantes
        tLista();
        ~tLista();
        void clear();
        int insert(int pos, tElem item);
        int length();
        tElem getValue();
        
    //posiblemente importantes
        void moveToStart();
        void moveToEnd();
        void moveToPos(int pos);
        void next();
        void prev();
        int currPos();

    //Extras
        int append(tElem item);
        tElem erase();
        void printList();

};

/*****
* tLista tLista
******
* Inicializa la estructura de tLista
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/


tLista:: tLista(){
    head=tail=curr= new tNodo;
    listSize=pos=0;
}


/*****
* tLista ~tLista
******
* Borra todos los elementos de la lista y elimina el head
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

tLista::~tLista(){
    clear();
    delete head;
}

/*****
* void tLista clear
******
* va pasando nodo por nodo eliminandolos, para luego asignar 0 a listSize y pos,
* aparte asigna NULL a head, tail y curr
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tLista::clear(){
    moveToStart();
    for(int i=0;i<listSize;i++){
        tNodo* aux = curr->sig;
        delete curr;
        curr = aux;
    }
    listSize=0; pos=0;
    head = NULL; tail = NULL; curr = NULL;
}

/*****
* int tLista insert
******
* Inserta un valor item en la posicion posh 
******
* Input:
* int posH : posicion en la que se desea insertar el elemento
  tElem item : elemento que se desea insertar en la lista
* .......
******
* Returns:
* int: la posicion en la que fue insertada el elemento
*****/


int tLista::insert(int posH, tElem item){
    moveToPos(posH);
    tNodo* aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->sig = aux;
    if(curr == tail){
        tail = curr->sig;
    }
    listSize++;
    return posH;
}

/*****
* int tLista append
******
* Agrega un elemento item al final de la lista
******
* Input:
* tElem item : elemento que se desea agregar al final de la lista
* .......
******
* Returns:
* int: el nuevo tamaño de la lista
*****/

int tLista::append(tElem item){
    if(listSize==0){
        insert(0, item);
    }
    else{
        tNodo* aux = new tNodo;
        tail->sig = new tNodo;
        tail->sig->info = item;
        tail = tail->sig;
        tail->sig = NULL;
        listSize++;
    }
    return listSize;
}

/*****
* int tLista length
******
* obtiene el tamaño de la lista
******
* Input:
* nada
* .......
******
* Returns:
* int: el tamaño de la lista
*****/

int tLista::length(){
    return listSize;
}

/*****
* tElem tLista getValue
******
* obtiene el valor que hay en la posicion actual de la lista
******
* Input:
* nada
* .......
******
* Returns:
* tElem: el valor que hay en la posicion actual
*****/

tElem tLista::getValue(){
    if (curr == NULL) return -1; // Cambié NULL a -1 para que sea compatible con el tipo tElemLista
    return curr->sig->info;
}

/*****
* void tLista moveToStart
******
* Mueve la posicion al inicio de la lista
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

//posiblemente importantes
void tLista::moveToStart(){
    curr = head;
    pos = 0;
}

/*****
* voidtLista moveToEnd
******
* Mueve la posicion al final de la lista
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tLista::moveToEnd(){
    curr = tail;
    pos = listSize;
}

/*****
* void tLista  moveToPos
******
* mueve el curr a la posicion posH
******
* Input:
* posH : posicion a la que se desea ir
* .......
******
* Returns:
* nada
*****/

void tLista::moveToPos(int posH){
    if (posH < 0 || posH > listSize) return;
    moveToStart();
    int posicion = 0;
    for (int i = 0; i < posH; i++) {
        next();
        posicion++;
    }
}

/*****
* void tLista next
******
* hace avanzar la posicion, ademas de hacer que curr apunte al siguiente nodo
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tLista::next(){
    if(curr == tail){
        return;
    }
    curr = curr->sig;
    pos++;
}

/*****
* void tLista prev
******
* Hace retroceder la posicion, ademas de hacer que curr apunte al nodo anterior
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tLista::prev(){
    tNodo* temp;
    if(curr == head){
        return;
    }
    temp = curr;
    moveToStart();
    while(curr->sig != temp){
        next();
    }
}

/*****
* int tLista currPos
******
* obtiene la posicion actual de la lista
******
* Input:
* nada
* .......
******
* Returns:
* int : posicion en la que se encuentra el curr
*****/

int tLista::currPos(){
    return pos;
}

/*****
* void tLista printList
******
* muestra por pantalla todos los elementos de la lista
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tLista::printList(){
    if(listSize==0){
        return;
    }else{
    tNodo* temp = head->sig;  // Empezar desde el primer nodo (después del nodo de cabeza)
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->sig;
    }
    cout << endl;
    }
}

