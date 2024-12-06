#include <iostream>
#include <clocale>
using namespace std;

void selection(string v[], int tam){
    int i,j,Min;
    string x;

    for (i=0;i<tam-1;i++){
        Min = i;
        for (j=i+1;j<tam;j++){
            if(v[j] < v[Min]){
                Min = j;
                cout << "true" << endl;
            }
        }
        // swap
        x = v[Min];
        v[Min] = v[i];
        v[i] = x;
    }
}

void mostrar(string v[], int tam){
    for (int i=0;i<tam;i++){
        cout << "Pos: " << i << " = " << v[i] << endl;
    }
}

int main(){

    setlocale(LC_ALL,"Portuguese");

    string entrada[] = {"G","A","B","R","I","E","L"}; //conjuntos ou enumeração
    mostrar(entrada,7);
    selection(entrada,7);
    mostrar(entrada,7);


    return 0;
}
