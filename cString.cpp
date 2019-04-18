//James Parungao
//CPSC 301 Team
//2/14/2019

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
	string files = "output.txt";

	infile.open(filename.c_str());

	//used to open the file, count the lines, and close the file.
	while (!infile.eof())
	{
		getline(infile, lines);
		n++;

	}

	infile.close();

	PERSON * p = new PERSON[n];
	infile.open(filename.c_str()); //reopens file to actually read the contents.

	for (int i = 0; i < n; i++)
	{
		infile >> p[i].Name >> p[i].lastName;
		infile >> x;
		//strcpy(p[i].Name, g.c_str()); //used to convert the string into a character array to store in the struct
		//strcpy(p[i].lastName, b.c_str());
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



	int max = 0;
	for (int k = 0; k < n; k++)
	{
		if(p[k].balance > max)
		{
			max = p[k].balance;
			cout << "Highest Balance: " << p[k].Name << " " << p[k].lastName << endl;

		}
	}

	ofstream outfile;
	string full;
	float filler = 0.0;
	cout << "enter first name: " << endl;
	cin >> full;

	outfile.open(files.c_str());

	for (int l = 0; l < n; l++)
	{

		if(full == p[l].Name)
		{

			cout << "how much do you want to deposit? " << endl;
			cout << "amount: " << endl;
			cin >> filler;
			p[l].balance += filler;
			cout << "new balance: " << p[l].balance << endl;

			for (int m = 0; m < n; m++)
			{

				outfile << p[m].Name << " ";
				outfile << p[m].lastName << " ";
				outfile << p[m].balance << endl;

			}

		}

	}

	outfile.close();




	system("pause");
	return 0;
}
