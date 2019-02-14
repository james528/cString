#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct PERSON
{
	char Name[20];
	char lastName[20];
	float balance;
};


int main()
{
	int n = 0;
	float x;
	string lines,
		b,
		g,
		c;
	ifstream infile;
	string filename = "data.txt";

	infile.open(filename.c_str()); 
	
	while (!infile.eof())
	{
		getline(infile, lines);
		n++;

	}

	infile.close();

	PERSON * p = new PERSON[n];
	infile.open(filename.c_str());

	for (int i = 0; i < n; i++)
	{
		infile >> g >> b;
		int n = g.length();
		int m = b.length();
		infile >> x;
		strcpy_s(p[i].Name, g.c_str());
		strcpy_s(p[i].lastName, b.c_str());
		p[i].balance = x;
		getline(infile, c);
	}

	for (int j = 0; j < n; j++)
	{
		cout << p[j].Name << " ";
		cout << p[j].lastName << " ";
		cout << fixed << setprecision(2);
		cout << p[j].balance << endl;
	}

	infile.close();

	system("pause");
	return 0;
}