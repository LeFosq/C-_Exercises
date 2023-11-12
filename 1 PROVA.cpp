#include <iostream>
#include <cmath>
using namespace std;
struct ponto
{
	float x;
	float y;
};
float distancia (struct ponto p1 , struct ponto p2)
{
	float dist, a , b;
	a = p2.x - p1.x;
	b = p2.y - p1.y; 
	dist = sqrt(a * a + b * b);
	return (dist);
}
int main()
{
	float dista;
	ponto p1; 
	ponto p2;
	cout << "Insira o x e o y do primeiro ponto" << endl;
	cin >> p1.x >> p1.y;	
	cout << "Agora insira o x e o y do segundo ponto" << endl;
	cin >> p2.x >> p2.y;
	dista = distancia(p1 , p2);
	cout << "A menor distancia entre os pontos e " << dista << " unidades";
	return 0; 
}
