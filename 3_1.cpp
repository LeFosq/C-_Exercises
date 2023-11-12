#include <iostream>
using namespace std;
#define size 50
typedef int tipochave;
typedef float tipopreco;
struct elemento 
{
    tipochave chave;
    tipopreco preco;
};

class pilha
{
    private:
        elemento *dado;
        int tamanho;
    
    public:
        pilha(); // função criadora
        bool cheia (); //1 cheia 0 não cheia
        bool vazia (); // 1 vazia 0 não vazia
        void inserir (elemento e); // push
        tipochave remover(); //pop
        void mostrar ();
        int gettamanho (); 
        void destruir(); 
        bool busca (tipochave ch);
};

int main()
{
    pilha p1, p2;
    elemento e1;
    tipochave ch1;
    tipopreco pr1;
    int menu, menuu;
    do
    {
    cout<<"Escolha a opção: ";
        cout<<"Digite: \n";
        cout<<"0 para encerrar o programa.\n";
        cout<<"1 Para gerenciar a pilha 1.\n";
        cout<<"2 Para gerenciar a pilha 2.\n";
        cin>>menuu;
        switch (menuu)
        {
            case 0: cout<<"Programa encerrado"; break;
            case 1: cout<<"O usuario esta gerenciando a pilha 1.\n";
                cout<<"faça uma escolha \n";
                do
                {
                    cout<<"digite: \n";
                    cout<<" 0 para retornar ao menu inicial \n";
                    cout<<" 1 para inserir um elemento \n"; 
                    cout<<" 2 para remover um elemento \n"; 
                    cout<<" 3 para ver todos os elementos da pilha\n"; 
                    cout<<" 4 para ver o tamanho da pilha \n"; 
                    cout<<" 5 para buscar por um elemento \n";
                    cout<<" 6 para destruir a pilha \n";
                    cin>>menu;
                        switch (menu)
                        {
                            case 0: break;
                            case 1: cout<<"digite a chave do elemento a ser inserido: ";
                                cin>>e1.chave;
                                cout<<"\nDigite o preco do elemento: ";
                                cin>>e1.preco;
                                p1.inserir (e1);  break;
                            case 2: cout<<p1.remover() <<"\n";  break;
                            case 3:  p1.mostrar();  break;
                            case 4:  cout<< "o tamanho da pilha é: " <<p1.gettamanho() <<"\n";
                                     break;
                            case 5: cout<<"digite a chave do elemento a ser procurado\n";
                                cin>>ch1;
                                if (p1.busca(ch1)==1){  cout<<"o elemnto já está na pilha\n"; }
                                else { cout<<"o elemnto não está na pilha\n";} break;
                            default: cout<<"opção invalida \n"; break;
                            case 6: cout<<"\nPilha sera destruida.\n";
                            	p1.destruir();
                            	break;
                        }
        
                } while(menu!=0); break;
            case 2: cout<<"O usuario esta gerenciando a pilha 2.\n";
                cout<<"faça uma escolha \n";
                do
                {
                    cout<<"digite: \n";
                    cout<<" 0 para retornar ao menu inicial \n";
                    cout<<" 1 para inserir um elemento \n"; 
                    cout<<" 2 para remover um elemento \n"; 
                    cout<<" 3 para ver todos os elementos da pilha\n"; 
                    cout<<" 4 para ver o tamanho da pilha \n"; 
                    cout<<" 5 para buscar por um elemento \n";
                    cout<<" 6 para destruir a pilha \n";
                    cin>>menu;
                        switch (menu)
                        {
                            case 0: break;
                            case 1: cout<<"digite a chave do elemento a ser inserido";
                                cin>>e1.chave;
                                cout<<"\nDigite o preco do elemento: ";
                                cin>>e1.preco;
                                p2.inserir (e1);  break;
                            case 2: cout<<p2.remover() <<"\n";  break;
                            case 3:  p2.mostrar();  break;
                            case 4:  cout<< "o tamanho da pilha é: " <<p2.gettamanho() <<"\n";
                                     break;
                            case 5: cout<<"digite a chave do elemento a ser procurado\n";
                                cin>>ch1;
                                if (p2.busca(ch1)==1){  cout<<"o elemnto já está na pilha\n"; }
                                else { cout<<"o elemnto não está na pilha\n";} break;
                            default: cout<<"opção invalida \n"; break;
                            case 6: cout<<"\nPilha sera destruida.\n";
                            	p1.destruir();
                            	break;
                        }
        
                } while(menu!=0);
        }
    }
     while(menuu!=0);
    return 0;
}
pilha::pilha ()
{
    tamanho=0; 
    dado=new elemento [size];
}

bool pilha::cheia ()
{
    if(tamanho==size) {return true;}
    else { return false;}
}
bool pilha::vazia()
{
    if(tamanho==0) {return true;}
    else { return false;}
}
bool pilha::busca (tipochave ch)
{
     int i;
    for(i=0; i<tamanho; i++)
    {
        if (dado[i].chave==ch) 
        {
            return true;
        }
    }
     return false;
}
void pilha::inserir (elemento e)
{
    int a;
    a=cheia(); 
    if(a==1) 
    {
        cout<<"a pilha já está cheia\n";
    }
    else
    {  
        if (busca (e.chave)==1)
        {
            cout<<"o elemento com chave " <<e.chave << " já está na pilha\n";
        }
        else
        {
        dado [tamanho]=e;
        tamanho=tamanho+1;
        }
    }
}
tipochave pilha::remover()
{
    int a;
    a=vazia(); 
    if(a==1) 
    {
        cout<<" Não foi possivel remover: a pilha já estã vazia\n";
         return 0;
    }
    else 
    {
        tamanho=tamanho-1;
        cout<<"foi removido o elemento com chave: \n";
        return dado[tamanho].chave; 

    }
}
void pilha::mostrar ()
{
    cout<<"os elementos da pilha são:\n";
    int i;
    for(i=0; i<tamanho; i++)
    {
        cout<<dado[i].chave<<" R$"<<dado[i].preco <<" \n";
    }

}
int pilha::gettamanho ()
{
    return tamanho;
}
void pilha::destruir()
{
	while (tamanho !=0)
	{
	tamanho--;
	}
	cout<<"\nPilha limpa.\n";
}
