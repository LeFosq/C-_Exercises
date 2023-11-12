#include <iostream>
using namespace std;
int main()
{
	int linhas, linha, colunas, escolha;
	cout << "Escolha o numero de linhas" << endl;
	cin >> linhas;
	cout << "Escolha o numero de colunas" << endl;
	cin >> colunas;
	const int L=linhas;
	const int CL=colunas;
	int i,j, pitangas = 0, guabirobas = 0, cerejas = 0;
	char plantas[L][CL];
	for (i = 0 ; i < L ; i++)
	{
		for (j = 0 ; j < CL ; j++)
		{
			cout << "Escolha a planta na posicao " << i << "," << j << endl;
			cin >> plantas[i][j];
		}
	}
	cout << "Escolha a linha a ser analisada" << endl;
	cin >> linha;
	cout << "Escolha 1 para as pitangas plantadas, 2 para as guabirobas e 3 para as cerejas" << endl;
	cin >> escolha;
	switch (escolha)
	{
		case 1: 
		for (i = 0 ; i <= CL ; i++)
		{
			if (plantas[linha][i] == 'P')
			{
				pitangas++;
			}
		}
		cout << "Foram plantadas " << pitangas << " pitangas";
		break;
		case 2: 
		for (i = 0 ; i < CL ; i++)
		{
			if (plantas[linha][i] == 'G')
			{
				guabirobas++;
			}
		}
		cout << "Foram plantadas " << guabirobas << " guabirobas";
		break;
		case 3: 
		for (i = 0 ; i < CL ; i++)
		{
			if (plantas[linha][i] == 'C')
			{
				cerejas++;
			}
		}
		cout << "Foram plantadas " << cerejas << " cerejas";
		break;
	}
	return 0;
}
