#include <iostream>
#include <fstream>
 
using namespace std;
 
int main()
{
	const int len = 7, strings = 3;
	const char breaker = '\n';
	char mass[len][strings];
	
	ifstream fs("Mat4es.txt"); 
	
	for(int r = 0; r<strings; r++)
	{
		fs.getline(mass[r], len-1,'\n');
		cout << mass[r] << endl; 
	}
	fs.close(); //Закрываем файл
	return 0;
}