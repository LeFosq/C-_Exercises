#include <iostream>
using namespace std;
#define n 20
typedef int tipochave;
struct Registro
{
	tipochave ch;
	float preco;
};
struct Lista 
{
	Registro A[n+1];
	int nroElem;
};
void InicializarLista(Lista *l)
{
	l->nroElem = 0;
}
inserirElemListaOrd(Lista *l, Registro reg)
{
	if (l->nroElem >= n)
	{
		return false;
	}
	else
	{
		int pos = l->nroElem;
		while (pos > 0 && l->A[pos-1].ch > reg.ch)
		{
			l->A[pos] = l->A[pos-1];
			pos --;
		}
		l->A[pos] = reg;
		l->nroElem++;
		return true;
	}
}
int TamanhoLista (Lista *l)
{
	return l->nroElem;
}
void exibirLista (Lista *l)
{
	int i;
	cout << "A lista contem os seguintes elementos: " << endl;
	for (i = 0; i < l->nroElem; i++)
	{
		cout <<"Código: " <<  l->A[i].ch <<" Preço: "<< l->A[i].preco << " R$" << endl;
	}
}
int buscaSentinela (Lista *l , tipochave ch1)
{
	int i = 0;
	l->A[l->nroElem].ch = ch1;
	while (l->A[i].ch != ch1)
	{
		i++;
	}
	if (i == l->nroElem)
	{
		return -1;
	}
	else
	{
		return i;
	}
}
bool excluirElemLista (tipochave ch1, Lista *l)
{
	int posElem, j;
	posElem = buscaSentinela(l , ch1);
	if (posElem == -1)
	{
		return false;
	}
	else
	{
		for (j = posElem; j < l->nroElem; j++)
		{
			l->A[j] = l->A[j+1];
		}
		l->nroElem--;
	}
	return true;
}
void ReinicializarLista (Lista *l)
{
	l->nroElem = 0;
}
void Algoritmo1 (Lista *l)
{
	int aux, i, j;
	for (i = 0; i < l->nroElem; i++)
	{
		for (j = 0; j < l->nroElem; j++)
		{
			if(l->A[i].ch > l->A[j].ch)
			{
				aux = l->A[i].ch;
				l->A[i].ch = l->A[j].ch;
				l->A[j].ch = aux;
			}
		}
	}
} 
void Algoritmo2 (Lista *l)
{
	int i ,j,menor, temp;
	for (i = 0; i < l->nroElem-1; i++)
	{
		menor = i;
		for (j = i+1; j < l->nroElem; j++)
		{
			if (l->A[j].ch < l->A[menor].ch)
			{
				menor = j;
			}
		}
		temp = l->A[i].ch;
		l->A[i].ch = l->A[menor].ch;
		l->A[menor].ch = temp;	
	}	
} 
int buscaBinaria (Lista *l, int x)
{
	int esq = 0, dir = l->nroElem-1;
	while (esq <= dir)
	{
		int meio = ((esq+dir)/2);
		if (l->A[meio].ch == x)
		{
			return meio;
		}
		if (l->A[meio].ch < x)
		{
			esq = meio + 1;
		}
		else
		{
			dir = meio - 1;
		}
	}
	return -1;
	
}						 
int main()
{
	int menu;
	Lista l;
	Registro r;
	InicializarLista(&l);
	do
	{
		cout << "0 - Sair \n1 - Inserir um produto \n2 - Contar a quantidade de produtos na lista \n3 - Mostrar todos os produtos da lista \n4 - Ordernar lista usando algoritmo 1 \n5 - Ordernar lista usando algoritmo 2 \n6 - Fazer busca sequencial \n7 - Fazer busca binaria \n8 - Eliminar um produto da lista" << endl;
		cin >> menu;
		switch (menu)
		{
			case 0:
				break;
			case 1:
				cout << "Insira o codigo do produto" << endl;
				cin >> r.ch;
				cout << "Insira o preço do produto" << endl;
				cin >> r.preco;
				inserirElemListaOrd(&l , r);
				break;
			case 2:
				int t;
				t = TamanhoLista (&l);
				cout << "O tamanho da lista é: " << t << endl;
				break;
			case 3:
				exibirLista(&l);
				break;
			case 4:
				Algoritmo1(&l);
				break;
			case 5:
				Algoritmo2(&l);
				break;
			case 6:
				int i;
				tipochave ch;
				cout << "Insira o codigo que será procurada" << endl;
				cin >> ch;
				i = buscaSentinela(&l ,ch);
				if (i != -1)
				{
					cout << "O produto de codigo " << ch << " esta na lista" << endl;
				}
				else
				{
					cout << "Produto nao encontrado" << endl;
				}
				break;
			case 7:
				int r,h;
				cout << "Insira o código a ser buscado" << endl << "Obs: a lista será ordenada automaticamente para que a busca binária possa ser executada" << endl;
				cin >> h;
				Algoritmo2(&l);
				r = buscaBinaria(&l,h);
				if (r == -1)
				{
					cout << "Produto não encontrado" << endl;
				}
				else
				{
					cout << "O produto foi encontrado" << endl;
				}
				break;
			case 8:
				bool k;
				tipochave ch2;
				cout << "Insira o código do produto que você quer excluir" << endl;
				cin >> ch2;
				k = excluirElemLista(ch2 , &l);
				if (k == true)
				{
					cout << "Produto excluido com sucesso" << endl;
				}
				else
				{
					cout << "Falha ao excluir" << endl;
				}
				break;
				
		
		}
	}while (menu != 0);
}
