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
        unsigned int listSize;
        unsigned int pos;

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

tLista:: tLista(){
    head=tail=curr= new tNodo;
    listSize=pos=0;
}

tLista::~tLista(){
    clear();
}

void tLista::clear(){

    moveToStart(); // Moverse al principio de la lista
    while (curr->sig) {
        tNodo* temp = curr->sig;
        curr->sig = temp->sig; // Actualizar el puntero siguiente
        delete temp; // Liberar el nodo eliminado
        listSize--;
    }
    // Actualizar los punteros de la cabeza y la cola
    head = tail = curr;
    pos = 0;
}


int tLista::insert(int pos, tElem item){
    moveToPos(pos);
    tNodo* aux = curr->sig;
    curr->sig = new tNodo;
    curr->sig->info = item;
    curr->sig->sig = aux;
    if(curr == tail){
        tail = curr->sig;
    }
    listSize++;
    return pos;
}

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

tElem tLista::erase(){
    tElem valor = curr->sig->info;
    tNodo* direccion = curr->sig->sig;
    tNodo* aux = curr->sig;
    if (curr->sig == tail) tail = curr;
    delete aux;
    curr->sig = direccion;
    listSize--;
    return valor;
}

int tLista::length(){
    return listSize;
}

tElem tLista::getValue(){
    if (curr && curr->sig) { // Cambié NULL a -1 para que sea compatible con el tipo tElemLista
        return curr->sig->info;
    }
    return -1;
}

//posiblemente importantes
void tLista::moveToStart(){
    curr = head;
    pos = 0;
}

void tLista::moveToEnd(){
    curr = tail;
    pos = listSize;
}

void tLista::moveToPos(int posicion){
    if (posicion < 0 || posicion > listSize) return;
    moveToStart();
    int pos = 0;
    for (unsigned int i = 0; i < posicion; i++) {
        next();
        pos++;
    }
}

void tLista::next(){
    if(curr && curr->sig){
        curr=curr->sig;
        pos++;
    }
}

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

int tLista::currPos(){
    return pos;
}

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

/* int main(){

    return 0;
}
 */
