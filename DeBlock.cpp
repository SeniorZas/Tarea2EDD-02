#include<iostream>
#include<string>

#include"tListadeLista2.cpp"

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

DeBlock::DeBlock(tElem* elems, int n, int b){
    
    tElem elem_array;
    cant_elems=n;
    l.elemsXlista(b);

    tElemLista* lista = new tElemLista;
    for(int i=0; i<n; i++){
        elem_array=elems[i];
        
        if(i%b == 0 && i!=0){
            l.appendList(lista);
            lista->clear();
            tLista* lista = new tLista; 
        }
        lista->append(elem_array);
    }
    
}

DeBlock::~DeBlock(){
    l.clear();
    cant_elems=0;
}

int DeBlock::insert(int pos, tElem elem){
    if(cant_elems<=pos){
        cant_elems++;
        return l.insert(pos, elem);;
    }else{
        return 0;
    }

}

tElem DeBlock::get_value(int pos){
    return l.get_value(pos);
}

int DeBlock::length(){
    return cant_elems;
}

/* int main(){
    return 0;
} */
