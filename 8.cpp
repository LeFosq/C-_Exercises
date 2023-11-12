#include <iostream>
using namespace std;
int main()
{
	int primeiro[1] , segundo[1] , i, a, b;
	cout << "Insira o x e depois o y do primeiro vetor" << endl;
	for (i = 0 ; i < 2 ; i++)
	{
		cin >> primeiro[i];
	}
	cout << "Insira o x e depois o y do segundo vetor" << endl;
	for (i = 0 ; i < 2 ; i++)
	{
		cin >> segundo[i];
	}
	a = primeiro[1] * segundo[0];
	b = primeiro[0] * segundo[1];
	cout << a-b << " k";
	return 0;
}
