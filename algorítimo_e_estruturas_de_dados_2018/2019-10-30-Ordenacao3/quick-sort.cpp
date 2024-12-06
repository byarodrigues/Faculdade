#include <iostream>
using namespace std;

void mostra(int vetor[]){
    for(int i = 0; i < 15; i++)
	{
		cout << vetor[i] << ' ';
	}
	cout << endl;
}

void quicksort(int vetor[], int esquerda, int direita)
{
	int i, j, principal, aux;
	i = esquerda;
	j = direita-1;
	principal = vetor[(esquerda + direita) / 2];
	while(i <= j)
	{
		while(vetor[i] < principal && i < direita)
		{
			i++;
		}
		while(vetor[j] > principal && j > esquerda)
		{
			j--;
		}
		if(i <= j)
		{
			aux = vetor[i];
			vetor[i] = vetor[j];
			vetor[j] = aux;
			i++;
			j--;
		}
	}
	if(j > esquerda){
        quicksort(vetor, esquerda, j+1);
	}
	if(i < direita){
	    quicksort(vetor, i, direita);
	}
}

int main()
{
	int vetor1[15] = {9, 10, -1, 3, 6, 2, 1, -3, 1, 0, -2, 15, 8, -7, 0};
	for(int i = 0; i < 15; i++)
	{
		cout << vetor1[i] << ' ';
	}
    cout << endl;

	quicksort(vetor1, 0, 15);

	for(int i = 0; i < 15; i++)
	{
		cout << vetor1[i] << ' ';
	}

	return 0;
}
