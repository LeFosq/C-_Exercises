#include <iostream>
#include <cmath>
using namespace std;
int fcontagem(char vetor[] , int linhas)
{
	int contagem = 0 , i, escolha;
	cout << "Selecione qual tipo de planta voce quer contar nesta linha (1 para pitangas, 2 guabirobas e 3 cerejas)" << endl;
	cin >> escolha;
	switch (escolha)
	{
		case 1: 
		for (i = 0 ; i < linhas ; i++)
			{
				if (vetor[i] == 'P')
				{
					contagem++;
				}
			}
		return (contagem);
		break;
		case 2: 
		for (i = 0 ; i < linhas ; i++)
			{
				if (vetor[i] == 'G')
				{
					contagem++;
				}
			}
		return (contagem);
		break;
		case 3: 
		for (i = 0 ; i < linhas ; i++)
			{
				if (vetor[i] == 'C')
				{
					contagem++;
				}
			}
		return (contagem);
		break;
		default: cout << "Opcao invalida" << endl;
		return 0;
		break;
		
	}
}
int main()
{
	int linhas, colunas, i, j, slinha, resultado;
	cout << "Escolha o numeros de linhas e colunas do plantio respectivamente" << endl;
	cin >> linhas >> colunas;
	char matriz[linhas][colunas], vlinha[linhas];
	for (i = 0 ; i < colunas ; i++)
	{
		for (j = 0 ; j < linhas ; j++)
		{
			cout << "Insira o componente " << i << " " << j << endl; 
			cin >> matriz[i][j];
		}
	}
	cout << "Selecione uma linha" << endl;
	cin >> slinha;
	for (i = 0 ; i < colunas ; i++)
	{
		vlinha[i] = matriz[slinha][i];
	}
	resultado = fcontagem(vlinha , linhas);
	cout << resultado << " Plantas";
}

