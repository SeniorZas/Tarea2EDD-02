#include<iostream>
#include<fstream>
#include<string>

#include"DeBlock.cpp"

using namespace std;

typedef int tElem;


/*****
*
Void input
******
*
Abre el archivo de pruebas.txt y lee los datos, ejecuta las instrucciones y 
las muestra por pantalla 
******
*
Input:
*
Ninguno
*
.......
******
*
Returns:
*
Ninguno
*****/
void input(){
    int n_iniciales, tam_bloques;
    int secuencia[1000];

    ifstream file("pruebas.txt");
    string linea;

    if(!file.is_open()){
        cout<<"Error al abrir el archivo"<<endl;
    }
    
    file>>n_iniciales>>tam_bloques;

    for (int i = 0; i < n_iniciales; i++) {
        file>>secuencia[i];
    }


    
    tElem* elems = new tElem[n_iniciales]; //arreglo que contendra todos los numeros que nos dan en el txt
    
    
    for(int i=0;i<=n_iniciales;i++){
        elems[i] = int(secuencia[2*i]);
    }
    DeBlock deblock = DeBlock(elems, n_iniciales, tam_bloques);

    int numero_operaciones;
    file >> numero_operaciones;
    file.ignore();


    string operacion;
    int aux;
    int aux2;
    for(int i=0;i<numero_operaciones;i++){
        getline(file, linea);
        operacion = linea.substr(0, linea.find(" "));
        if(operacion == "I"){
            aux = stoi(linea.substr(linea.find(" ")+1)); // elemento
            aux2 = stoi(linea.substr(linea.find(" ")+3)); //pos
            cout<<deblock.insert(aux2, aux)<<endl;
        }
        if(operacion == "G"){
            aux = stoi(linea.substr(linea.find(" ")+1));
            cout<<deblock.get_value(aux)<<endl;
        }
        if(operacion == "L"){
            cout<<deblock.length()<<endl;
        }

    }

    file.close();
}

int main(){
    input();
    return 0;
}
