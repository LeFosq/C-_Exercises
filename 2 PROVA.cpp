#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int var = 10;
	int subs = 5;
	void *pont;
	pont = &subs;
	var = *(int *)pont;
	pont = &var;
	cout << "O novo valor da variavel e " << *(int *)pont;
	return 0;
}
