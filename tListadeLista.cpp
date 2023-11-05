#include<iostream>
#include<string>
#include"tLista.cpp"

using namespace std;

const int MAXSIZE = 1000000; 

typedef tLista tElemLista;
typedef int tElem;

class tListadeLista{
    private:
    int maxSize;
    int listSize;
    int curr;
    tElemLista *listArray;
    
    //Arreglo de listas

    
    public:
    //Terminadas
    tListadeLista();
    ~tListadeLista();
    void moveToStart();
    void moveToEnd();
    void prev();
    void next();
    int length();
    int currPos();

    //Por hacer
    void moveToPos(int pos);
    int append(tElemLista *item);
    int insert(tElemLista item);
    void clear();


    //Funciones que llama el deblock
    int get_ValueDeBlock(int pos);
    int insertDeBlock(int pos, tElem elem);
    int moveToPosSublist(int pos);

};

/*****
* tListadeLista tListadeLista
******
* Inicializa la estructura de tListadeLista con una lista basada en arreglos
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

tListadeLista::tListadeLista() {
    maxSize = MAXSIZE; // tamaño máximo de la lista
    listSize = 0;
    // lista vacía
    curr = 0;
    listArray = new tElemLista[maxSize];
}


/*****
* tListadeLista ~tListadeLista
******
* Limpia la memoria de la estructura de tListadeLista
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/
tListadeLista::~tListadeLista(){ 
    delete[] listArray; 
}

/*****
* void tListadeLista moveToStart 
******
* Posiciona el curr al inicio de la lista de lista
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/
void tListadeLista::moveToStart(){ curr = 0; }

/*****
* void tListadeLista moveToEnd
******
* posiciona el curr al ultimo dato valido de la lista
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tListadeLista::moveToEnd(){ curr = listSize; }

/*****
* void tListadeLista prev
******
* Avanza al elemento de la lista de listas anterior en donde esta posicionado el curr
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tListadeLista::prev(){ if (curr != 0) curr--; }

/*****
* void tListadeLista next
******
* avanza al siguiente elemento de la lista de listas
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tListadeLista::next(){ if (curr < listSize) curr++; }

/*****
* int tListadeLista currPos
******
* otorga el deato de la posicion del curr
******
* Input:
* nada
* .......
******
* Returns:
* retorna como un el valor de la posicion del curr en la lista
*****/

int tListadeLista::currPos(){ return curr; }

/*****
* int tlistadeLista length
******
* esta funcion otorga el dato de el largo de la lista de listas
******
* Input:
* nada
* .......
******
* Returns:
* retorna el largo de la lista de listas
*****/

int tListadeLista::length(){ return listSize; }

/*****
* void tListadeLista moveToPos
******
* mueve el curr a la posicio que indica la variable pos
******
* Input:
* int pos: Es el dato que indica en que posicion de la lista quiere mover el curr
* .......
******
* Returns:
* nada
*****/

void tListadeLista::moveToPos(int pos){
    if(pos > listSize || pos == curr){
        return;
    }
    moveToStart();
    while(curr != pos){
        next();
    }
}

/*****
* int tListadeLista insert
******
* inserta un elemento en la posicion actual de la lista de listas
******
* Input:
* tElemlista lista: Es una lista al cual se debe insertar 
* .......
******
* Returns:
* retorna en donde se posiciono la lista
*****/

int tListadeLista::insert(tElemLista item) { 
    int i=0;
    if (listSize >= maxSize) return -1;
    for (i = listSize; i > curr; i--) listArray[i] = listArray[i-1]; 
    listArray[i] = item;
    listSize++;
    return i; 
}

/*****
* void tListadeLista clear
******
* Borra todos los elementos de la lista, reinicializando la lista de listas
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

void tListadeLista::clear(){
    moveToStart();
    for(curr; curr<= listSize; next()){
        listArray[curr].clear();
    }
    tListadeLista();
}

/*****
* int tListadeLista insertDeBlock
******
* Es la funcion que llama deBlock para insertar un elemento en la lista de lista, lo que hace la funcion es recorrer cada
* sublista buscando si el elemento esta en las diferentes subslitas utilizando la posicion como referencia, cuando encuentra la
* la sublista obtiene la sublista y usa uno de los metodos de tLista para insertar el elemento
******
* Input:
* int pos: es la posicion al cual se quiere insertar el elemento en las sublistas
* tElem elem: es el elemento que se quiere insertar en una de las sublistas
* .......
******
* Returns:
* retorna un 1 si la insercion fue exitosa y retorna un -1 si fallo en la insercion
*****/

int tListadeLista::insertDeBlock(int pos, tElem elem){ 
    int count = 0, posicion=0;
    moveToStart(); 
    tLista *aux;
    int large=0;
    while(curr < listSize){
        aux = new tLista(listArray[curr]); 
        aux->moveToStart();
        large+=aux->length();
        if(large<pos){
            count=large;
            next();
        }else{
            posicion=pos-count;
            listArray[currPos()].insert(posicion, elem);
            delete aux;
            return 1;
            
        }
    }
    
    return -1;

    
    
}

/*****
* int tListadeLista get_ValueDeBlock
******
* Es la funcion que llama deBlock encontrar un elemento en la lista de lista, lo que hace la funcion es recorrer cada
* sublista buscando si el elemento esta en las diferentes subslitas utilizando la posicion como referencia, cuando encuentra la
* la sublista en donde se ubica el elemento a encontrar el valor, obtiene la sublista y usa uno de los metodos de tLista 
* para obtener el valor del elemento la posicion indicada
******
* Input:
* int pos: es la posicion al cual se quiere encontrar el elemento en las sublistas
* .......
******
* Returns:
* retorna el valor del elemento ubicado en la posicion si se encontro y si falla al encontrar el elemento retorna un -1 
*****/

int tListadeLista::get_ValueDeBlock(int pos){ 
    moveToStart(); 

    int count=0;
    int posicion=0;
    tLista *aux;
    int large=0;
    while(curr < listSize){
        aux= new tLista(listArray[curr]); 
        aux->moveToStart();
        large+=aux->length();
        if(large<pos){
            count=large;
            next();
        }else{
            posicion= pos-count;
            aux->moveToPos(posicion);
            tElem result = aux->getValue();
            delete aux;
            return result;
        }
    }
    return -1;



    
    
}

/*****
* int tListadeLista append
******
* inserta una lista al final del ultimo dato valido en la lista de listas
******
* Input:
* tElemLista* item: Es la direccion de memoria de la lista al cual se quiere insertar
* .......
******
* Returns:
* Retorna la posicion en la que se inserto el elemento 
*****/

int tListadeLista::append(tElemLista* item) {
    if (listSize >= maxSize) {
        
        return -1;
    }

    listArray[listSize] = *item; 
    listSize++;

    return listSize - 1;
}



/* int main(){
    tListadeLista l;
    tElemLista lista;
    lista.insert(0,1);
    lista.insert(0,2);
    lista.insert(0,3);

    lista.printList();
    lista.moveToStart();

    cout<<l.get_ValueDeBlock(1)<<endl;

    l.append(&lista);

    cout<<l.get_ValueDeBlock(1)<<endl;



    cout<<l.insertDeBlock(2,7)<<endl;
    cout<<l.get_ValueDeBlock(1)<<endl;


    return 0;
} */