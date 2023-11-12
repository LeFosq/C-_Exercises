#include <iostream>
using namespace std;
int main()
{
	int linhas , colunas;
	cout << "Escolha uma quantidade de linhas e depois colunas para a sua matriz" << endl;
	cin >> linhas >> colunas;
	const int L = linhas;
	const int C = colunas;
	int i, j, soma = 0, vetor [5];	
	int m[L][C] , t[C][L];
	for (i = 0 ; i < L ; i++)
	{
		for (j = 0 ; j < C ; j++)
		{
			cout << "Escolha o componente" << i << "," << j << endl;
			cin >> m[i][j];
		}
	}
	for (i = 0 ; i < L ; i++)
	{
		for (j = 0 ; j < C ; j++)
		{
			t[j][i] = m[i][j];
		}
	}
	for (i = 0 ; i < L ; i++)
	{
		for (j = 0 ; j < C ; j++)
		{
			cout << t[i][j] << "\t";
		}
		cout << endl;
	}
	return 0;
}
