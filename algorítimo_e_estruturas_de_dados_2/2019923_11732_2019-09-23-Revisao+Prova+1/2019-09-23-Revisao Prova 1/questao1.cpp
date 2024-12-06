#include <iostream>
#include <clocale>
using namespace std;

// SESS�O DE DECLARA��ES

const int maxTam1 = 5;
const int maxTam2 = 10;

// ESTRUTURAS

struct TItem{
    int chave;
    //... outros
};

struct TLista_A{
    TItem vetItens[maxTam1]; //suporte para os itens
    int primeiro;   // controle
    int ultimo;     // controle
};

struct TLista_A_Dobro{
    TItem vetItens[maxTam2]; //suporte para os itens
    int primeiro;   // controle
    int ultimo;     // controle
};

// OPERA��ES B�SICAS
void criarListaVazia(TLista_A &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}

bool estaVazia(TLista_A l){
    return l.primeiro == l.ultimo;
}

bool estaCheia(TLista_A l){
    return l.ultimo >= maxTam1;
}

// MANTENDO O INSERIR PADR�O
void inserirPadrao(TLista_A &l, TItem x){
    if(estaCheia(l)){ // testa pra ver se cabe
        cout << "A lista est� cheia. N�o posso inserir." << endl;
    }
    else{
        l.vetItens[l.ultimo] = x;   //orienta ou controla a posi��o em que
        l.ultimo++;                 // o item ser� alocado
    }
}

/// letra a) da quest�o 1
// MODIFICANDO PARA UMA INSER��O ORDENADA CRESCENTE:

// CRIAR OPERA��O PARA ACHAR ONDE SER� INSERIDO O NOVO ITEM
int achaPosicao(TLista_A l, int novo){
    //cout << "=== PROCURANDO POSI��O ===" << endl;
    int pegaPos = -1;
    for(int i=l.primeiro;i<l.ultimo && pegaPos == -1;i++){ // a condi��o testa o limite em fun��o do campo �ltimo
        if (novo < l.vetItens[i].chave){                   // e tamb�m se o valor de pegaPos foi alterado!
            //cout << "menor" << endl;                       // assim, haver� uma interrup��o do FOR
            //return i-1;                                  // DESAFIO: transforme em um WHILE!!!
            if(i == 0){ // quando for na cabe�a
                pegaPos = 0;
            }
            else{
                pegaPos = i;
            }
        }
    }
    //return l.ultimo-1; //pq j� incrementamos na inser��o
    if (pegaPos != -1){
        return pegaPos;
    }
    else{
        return l.ultimo;
    }
}

void inserirOrdenado(TLista_A &l, TItem x){
    if(estaCheia(l)){ // testa pra ver se cabe
        cout << "A lista est� cheia. N�o posso inserir." << endl;
    }
    else{
        int posicao = achaPosicao(l,x.chave);
        cout << "Posi��o retornada: " << posicao << endl;

        cout << "Inserindo o " << x.chave << ": "; // vai juntar com o cout do lugar
        // VAZIA ou na ULTIMA
        if (estaVazia(l) || posicao == l.ultimo){
            l.vetItens[l.ultimo] = x;
            l.ultimo++;
            cout << "na cabe�a ou na cauda" << endl; // DESAFIO: separe a mensagem para cabe�a OU cauda
        }
        else{ // NO MEIO
            // REALOCANDO
            int auxUlt = l.ultimo;
            //1. abrir espa�o para ele
            for(int i=posicao;i<l.ultimo;i++){
                l.vetItens[auxUlt] = l.vetItens[auxUlt-1];
                auxUlt--;
            }
            l.vetItens[posicao] = x;
            l.ultimo++;
            if (posicao == 0){
                cout << "na cabe�a" << endl;
            }
            else{
                cout << "no meio" << endl;
            }

        }
    }
}

void mostrar(TLista_A l){
    cout << "=== MOSTRANDO ITENS DA LISTA ===" << endl;
    if (estaVazia(l)){
        cout << "Lista vazia. Nenhum item para mostrar. " << endl;
    }
    else{
        for(int i=l.primeiro;i<l.ultimo;i++){
            cout << "Pos " << i << ": " << l.vetItens[i].chave << endl;
        }
    }
}

void retirarPos(TLista_A &l, int p){
    int aux;

    if((estaVazia(l)) || (p>=l.ultimo) || (p<l.primeiro)){
        cout << "N�o posso retirar! Lista vazia ou posi��o fora do limite" << endl;
    }
    else{
       l.ultimo--;
       for(aux=p;aux<l.ultimo;aux++){
            l.vetItens[aux] = l.vetItens[aux+1];
       }
       cout << "O elemento foi retirado com sucesso!" << endl;
    }
}

/// letra b) da quest�o 1
int buscarChave(TLista_A l, int c){
    bool achou = false;
    int pegaPos;

    if (estaVazia(l)){
        return -1;
    }
    else{
        for(int i=l.primeiro;i<l.ultimo && achou == false;i++){
            if(l.vetItens[i].chave == c){
                achou = true;
                pegaPos = i;
                // break; N�O USAR! Modifique a condi��o acrescentando o teste novo do achou
            }
        }
        if(achou == true){
            return pegaPos;
        }
        else{
            return -1;
        }
    }
}

void retirarPorChave(TLista_A &l,int c){
    if (estaVazia(l)){
        cout << "Lista Vazia! Nenhum elemento para retirar." << endl;
    }
    else{
        retirarPos(l, buscarChave(l,c));
    }
}

/// letra e) da quest�o 1
void copiarLista(TLista_A lOrigem, TLista_A &lDestino){ // observe a refer�ncia s� na segunda!!!
    // lDestino = lOrigem; N�OOOO FA�AM ISSO! SEN�O SER� O MESMO VETOR, POIS O VETOR � UM PONTEIRO
    if (estaVazia(lOrigem)){
        cout << "Lista de Origem Vazia. Nenhum item para copiar!" << endl;
    }
    else{
        for (int i=lOrigem.primeiro;i<lOrigem.ultimo;i++){
            inserirPadrao(lDestino,lOrigem.vetItens[i]);
        }
        cout << "Lista copiada com sucesso!" << endl;
    }
}

// CADASTRAR ITENS NA LISTA DE 5 ELEMENTOS
void cadastrarItens(TLista_A &l){
    cout << "=== CADASTRANDO OS ITENS INICIAIS === " << endl;

    TItem iAux;
    char resp = 'S';
    while (resp != 'N'){
        cout << "Informe o valor do item: ";
        cin >> iAux.chave; // se tivesse outros campos, pegaria agora tamb�m
        inserirOrdenado(l,iAux);

        cout << "\n      Deseja inserir outro item(S/N)?  ";
        cin >> resp;
    }
}


// LISTA DOBRADA
// OPERA��ES B�SICAS
void criarListaVaziaD(TLista_A_Dobro &l){
    l.primeiro = 0;
    l.ultimo = l.primeiro;
}

bool estaVaziaD(TLista_A_Dobro l){
    return l.primeiro == l.ultimo;
}

bool estaCheiaD(TLista_A_Dobro l){
    return l.ultimo >= maxTam2;
}

void inserirD(TLista_A_Dobro &l, TItem x){
    if(estaCheiaD(l)){ // testa pra ver se cabe
        cout << "A lista est� cheia. N�o posso inserir." << endl;
    }
    else{
        l.vetItens[l.ultimo] = x;   //orienta ou controla a posi��o em que
        l.ultimo++;                 // o item ser� alocado
    }
}

void mostrarD(TLista_A_Dobro l){

    cout << "=== MOSTRANDO ITENS DA LISTA DOBRADA ===" << endl;
    if (estaVaziaD(l)){
        cout << "Lista vazia. Nenhum item para mostrar. " << endl;
    }
    else{
        for(int i=l.primeiro;i<l.ultimo;i++){
            cout << "Pos " << i << ": " << l.vetItens[i].chave << endl;
        }
    }
}

void retirarPosD(TLista_A_Dobro &l, int p){
    int aux;

    if((estaVaziaD(l)) || (p>=l.ultimo) || (p<l.primeiro)){
        cout << "N�o posso retirar! Lista vazia ou posi��o fora do limite" << endl;
    }
    else{
       l.ultimo--;
       for(aux=p;aux<l.ultimo;aux++){
            l.vetItens[aux] = l.vetItens[aux+1];
       }
    }
}

int buscarChaveD(TLista_A_Dobro l, int c){
    bool achou = false;
    int pegaPos;

    if (estaVaziaD(l)){
        return -1;
    }
    else{
        for(int i=l.primeiro;i<l.ultimo;i++){
            if(l.vetItens[i].chave == c){
                achou = true;
                pegaPos = i;
                break;
            }
        }
        if(achou == true){
            return pegaPos;
        }
        else{
            return -1;
        }
    }
}

void retirarChaveD(TLista_A_Dobro &l,int c){
    // big procedimento que localiza e retira
    // ou vou apenas localizar e pegar a posi��o,
    // chamando o retirarPos em seguida???

    // DESAFIO: junte a FUN��O buscarChave com o PROCED retirarPos
    // e construa este retirarChave
}



/// letra f) da quest�o 1 - ATEN��O: TEVE QUE SER AQUI PORQUE PRECISO DE OPERA��ES DA LISTA DOBRADA!
                                                 // lista dobrada
void concatenar2Listas(TLista_A l1, TLista_A l2, TLista_A_Dobro &l3){ // observe a refer�ncia s� na terceira
    // pegando os itens da L1
    if (estaVazia(l1)){
        cout << "Lista 1 vazia. Nenhum elemento para copiar. " << endl;
    }
    else{
        for (int i=l1.primeiro;i<l1.ultimo;i++){
            inserirD(l3,l1.vetItens[i]);
        }
    }
    // pegando os itens da L2
    if (estaVazia(l2)){
        cout << "Lista 2 vazia. Nenhum elemento para copiar. " << endl;
    }
    else{
        for (int i=l2.primeiro;i<l2.ultimo;i++){
            inserirD(l3,l2.vetItens[i]);
        }
    }
    cout << "Processo de concatena��o finalizado!" << endl;
}

void intercalar2Listas(TLista_A l1, TLista_A l2, TLista_A_Dobro &l3){ // observe a refer�ncia s� na terceira
    // verificando se tem alguma lista vazia
    if (estaVazia(l1)){
        cout << "Lista 1 vazia. Nenhum elemento para copiar. " << endl;
    }
    if (estaVazia(l2)){
        cout << "Lista 2 vazia. Nenhum elemento para copiar. " << endl;
    }

    if(estaVazia(l1)){
        for (int i=l2.primeiro;i<l2.ultimo;i++){
            inserirD(l3,l2.vetItens[i]);
        }
    }
    else{
        if (estaVazia(l2)){
            for (int i=l1.primeiro;i<l1.ultimo;i++){
                inserirD(l3,l1.vetItens[i]);
            }
        }
        else{
            int auxPos = 0;

            for(int i=l3.primeiro;i<l1.ultimo+l2.ultimo;i++){
                if (auxPos < l1.ultimo){
                    inserirD(l3,l1.vetItens[auxPos]);
                }
                if (auxPos < l2.ultimo){
                    inserirD(l3,l2.vetItens[auxPos]);
                }
                auxPos++;
            }
        }
    }

    cout << "Processo de intercala��o finalizado!" << endl;
}


int main(){

    setlocale(LC_ALL,"Portuguese");//para acentua��o e caracteres especiais

    //tamanho = 5;

    cout << "\n---------------------------------------------" << endl;
    cout << "a. inserir os elementos em ordem crescente na lista; " << endl;

    TLista_A lista1A; //instancia��o

    criarListaVazia(lista1A); // prepara para o uso

    TItem iAux;

    // Fiz um procedimento para entrar com os itens! Fica mais "elegante"!
    cadastrarItens(lista1A);

//    iAux.chave = 5;
//    inserirOrdenado(lista1A,iAux);
//
//    iAux.chave = 4;
//    inserirOrdenado(lista1A,iAux);
//
//    iAux.chave = 7;
//    inserirOrdenado(lista1A,iAux);
//
//    iAux.chave = 2;
//    inserirOrdenado(lista1A,iAux);
//
//    iAux.chave = 9;
//    inserirOrdenado(lista1A,iAux);

    mostrar(lista1A);

    cout << "\n---------------------------------------------" << endl;
    cout << "b. verificar se um n�mero informado pelo usu�rio pertence � uma lista;" << endl;
    // Posso usar a fun��o buscarChave() j� implementada em aula
    int chaveBusca;
    cout << "Informe uma chave para buscar: ";
    cin >> chaveBusca;

    int retornoBusca = buscarChave(lista1A,chaveBusca);
    if (retornoBusca < 0){
        cout << "Chave n�o encontrada!" << endl;
    }
    else{
        cout << "Chave encontrada na posi��o " << retornoBusca << " do vetItens." << endl;
    }

    cout << "\n---------------------------------------------" << endl;
    cout << "c. remover um elemento de uma lista; " << endl;
    cout << "Informe uma chave do elemento para RETIRAR : ";
    cin >> chaveBusca; // usando a mesma vari�vel (economizar!)
    // chamo o procedimento retirarPorChave() j� implementado em aula tamb�m
    retirarPorChave(lista1A,chaveBusca);

    cout << "\n---------------------------------------------" << endl;
    cout << "d. mostrar os itens de uma lista; " << endl; // fazemos isso toda hora!!!
    mostrar(lista1A);

    cout << "\n---------------------------------------------" << endl;
    cout << "e. copiar os elementos de uma lista para outra lista; " << endl;
    cout << "Mostrando a lista original: " << endl;
    mostrar(lista1A);
    // vou resolver criando um procedimento para isso
    // antes temos que preparar a lista de destino (nova)
    TLista_A lista2A;
    criarListaVazia(lista2A);
    copiarLista(lista1A,lista2A);
    cout << "Mostrando a nova lista" << endl;
    mostrar(lista2A);

    cout << "\n---------------------------------------------" << endl;
    cout << "f. concatenar duas listas numa outra lista; " << endl;
    // Neste caso, a lista3A dever� ter at� 10 elementos!!!
    // Para concatenar, � simplesmente pegar todos os elementos da lista1A e colocar na lista3A
    // e depois repetir com a lista2A.
    // Isso deve funcionar indiferente da quantidade de elementos em cada uma. Neste momento,
    // se voc� seguiu literalmente a ordem do exerc�cio, cada lista tem 4 elementos, logo, lista3A
    // ter� 8 elementos (com chaves repetidas, o que n�o � comum).

    // Preparando lista3A
    TLista_A_Dobro lista3A;
    criarListaVaziaD(lista3A);

    // Fiz um procedimento tamb�m:
    concatenar2Listas(lista1A,lista2A,lista3A);
    mostrarD(lista3A);

    cout << "\n---------------------------------------------" << endl;
    cout << "g. intercalar os elementos de duas listas numa outra lista;" << endl;
    // Observe que, diferente da CONCATENA��O, agora pegamos 1 elemento da l1 e em seguida 1 da l2
    // caso alguma esteja vazia, devemos ignorar

    // Preparando lista4A
    TLista_A_Dobro lista4A;
    criarListaVaziaD(lista4A);
    // Fiz outro procedimento
    intercalar2Listas(lista1A,lista2A,lista4A);
    mostrarD(lista4A);

    return 0;
}
