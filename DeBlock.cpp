#include<iostream>
#include<string>

#include"tListadeLista.cpp"

using namespace std;

typedef int tElem;
typedef tLista tElemLista;

class DeBlock{ 
private: 
    int cant_elems; 
    tListadeLista l;
    
public: 
    
    DeBlock(tElem* elems, int n, int b);
    ~DeBlock(); 
    int insert(int pos, tElem elem);
    tElem erase(int pos); 
    tElem get_value(int pos);
    int length(); 
    void clear(); 
};

/*****
* DeBlock DeBlock
******
* Inicializa la estructura de DeBlock (Constructor)
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

DeBlock::DeBlock(tElem* elems, int n, int b){
    
    tElem elem_array;
    cant_elems=n;

    tElemLista* lista = new tElemLista;
    for(int i=0; i<n; i++){
        elem_array=elems[i];
        
        if(i%b == 0 && i!=0){
            l.append(lista);
            lista->clear();
            tLista* lista = new tLista; 
        }
        lista->append(elem_array);
    }
    
}

/*****
* DeBlock ~Deblock
******
* Limpia la memoria utilizada por la estructura de DeBlock
******
* Input:
* nada
* .......
******
* Returns:
* nada
*****/

DeBlock::~DeBlock(){
    l.clear();
    cant_elems=0;
}

/*****
* int Deblock insert
******
* Es una función que verifica si la posicion es valida para ejecutar el metodo del TDA de ListadeLista insertDeBlock y si 
* es valida entonces aumenta la variable de los elementos que hay
******
* Input:
* int pos: Es la posicion al cual se quiere insertar el elemento
* tElem elem: Es el elemento que se quiere insertar
* .......
******
* Returns:
* 1 si la posicion es valida, retorna 0 si la posicion es invalida
*****/
int DeBlock::insert(int pos, tElem elem){
    if(cant_elems<=pos){
        cant_elems++;
        return l.insertDeBlock(pos, elem);;
    }else{
        return 0;
    }

}

/*****
* tElem DeBlock get_Value
******
* Llama a un metodo del TDA de tListadeLista que se encarga de insertar el elemento en la posicion deseada
******
* Input:
* int pos: es la posicion del cual se quiere obtener el valor
* .......
******
* Returns:
* Retorna un elemento de tipo tElem
*****/

tElem DeBlock::get_value(int pos){
    return l.get_ValueDeBlock(pos);
}

/*****
* int DeBlock length
******
* Se encarga de dar el dato de cuantos elementos totales hay en el DeBlock
******
* Input:
* nada
* .......
******
* Returns:
* un int con la cantidad de elementos que hay en el DeBlock
*****/

int DeBlock::length(){
    return cant_elems;
}

/* int main(){
    return 0;
} */
