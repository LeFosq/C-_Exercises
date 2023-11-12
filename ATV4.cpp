#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX 50

typedef int TIPOCHAVE;
typedef float PRICE;
struct Registro
{
	TIPOCHAVE Chave;
	PRICE preco;
};

struct Elemento
{
	Registro reg;
	Elemento *prox;
};

typedef Elemento * PONT ;

struct Lista
{
	PONT inicio;

};

void inicializarLista (Lista *l)
{
	l->inicio = NULL;
}

int tamanho (Lista *l)
{
	PONT end = l->inicio;
	int tam = 0;
	while (end != NULL)
	{
		tam ++;
		end = end->prox;
	}
	return tam;
}

void ExibirLista (Lista *l)
{
	PONT end = l->inicio;
	while (end != NULL)
	{
		cout <<"Cod: " << end->reg.Chave << " $:" << end->reg.preco << endl;
		end = end->prox;
	}
}

PONT buscaSeqAux (Lista *l , TIPOCHAVE ch, PONT *ant)
{
	*ant = NULL;
	PONT atual=l->inicio;
	while ((atual != NULL) && (atual->reg.Chave<ch))
	{
		*ant = atual;
		atual = atual->prox;
	}
	if ((atual != NULL) && (atual->reg.Chave == ch))
	{
		return atual;
	}
	return NULL;
}

bool inserOrd (Lista *l , Registro reg)
{
	TIPOCHAVE ch = reg.Chave;
	PONT ant, i;
	i = buscaSeqAux (l, ch, &ant);
	if (i != NULL) return false;
	i = (PONT) malloc (sizeof (Elemento));
	i->reg = reg;
	if (ant == NULL)
	{
		i->prox = l->inicio;
		l->inicio = i;
	}
	else
	{
		i->prox = ant->prox;
		ant->prox = i;
	}
	return true;
}

void ReinicializarLista (Lista *l)
{
	PONT end = l->inicio;
	while (end != NULL)
	{
		PONT apagar = end;
		end = end->prox;
		free (apagar);
	}
	l->inicio = NULL;
}

bool Excluir (Lista *l , TIPOCHAVE ch)
{
	PONT ant , i;
	i = buscaSeqAux (l , ch, &ant);
	if (i == NULL)
	{
		return false;
	}
	if (ant == NULL)
	{
		l->inicio = i->prox;
	}
	else
	{
		ant->prox = i->prox;
	}
	free (i);
	return true;
}
int main ()
{
	Lista main;
	int menu;
	Elemento e1;
	inicializarLista(&main);
	do
	{
		cout << "Bem vindo a lista principal" << endl << "0 - sair" << endl << "1 - Inserir produto" << endl << "2 - Contar quantidade de produtos" << endl << "3 - Procurar um produto pelo codigo" << endl << "4 - Mostrar produtos na lista" << endl << "5 - Eliminar produto da lista" << endl;
		cin >> menu;
		switch (menu)
		{
			case 0:
			break;
			case 1: 
			cout << "Digite o codigo do produto" << endl;
			int a;
			cin >> e1.reg.Chave;
			cout << "Digite o preco do produto" << endl;
			cin >> e1.reg.preco;
			a = inserOrd(&main , e1.reg);
			if (a == 1)
			{
				cout << "Inserido com sucesso" << endl;
			}
			else
			{
				cout << "Falha ao inserir" << endl;
			}
			break;
			case 2: 
			int b;
			b = tamanho (&main);
			cout << "O tamanho da lista e: " << b << endl;
			break;
			case 3:
			int c;
			PONT d, ant;
			cout << "Insira o codigo do produto" << endl;
			cin >> c;
			d = buscaSeqAux(&main ,c,&ant);
			if (d != NULL)
			{
				cout << "O produto esta na lista" << endl;
			}
			else
			{
				cout << "O produto nao esta na lista" << endl;
			}
			break; 
			case 4:
			ExibirLista (&main);
			break;
			case 5:
			int e, f;
			cout << "Insira o codigo do produto que voce deseja excluir" << endl;
			cin >> e;
			f = Excluir (&main ,e);
			if (f == 1)
			{
				cout << "Excluido com sucesso" << endl;
			}
			else
			{
				cout << "Falha ao excluir" << endl;
			}
			
			
		
			
		}
	} while (menu != 0);
	return 0;
}


