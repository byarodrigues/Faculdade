#ifndef STRUCTSBIBLI_H_INCLUDED
#define STRUCTSBIBLI_H_INCLUDED
#include <iostream>
using namespace std;  //biblioteca criada apenas para a criação das structs basicas do programa que esta sendo utilixada em todos os codigos;
struct TVacas{
    string codigo;
    string raca;
    string litrosP[7];
};
struct TCelula{
    TVacas vaca;
    TCelula *proximo;
};


#endif // STRUCTSBIBLI_H_INCLUDED
