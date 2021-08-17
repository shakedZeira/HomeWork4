#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void mission1()
{
	//mission 1
	ifstream myfile;
	string line;
	myfile.open("new5.txt");
	if (myfile.is_open())
	{
		while (getline(myfile,line))
		{
			cout << line << endl;
		}
		myfile.close();
	}
	else
	{
		cout << "unable to open file" << endl;
	}
}
void mission2()
{
	//mission 2
	ifstream InputFile;
	InputFile.open("inputFile.txt");
	ofstream OutputFile;
	OutputFile.open("outputFile.txt");
	string word;
	if (InputFile.is_open())
	{
		while (InputFile >> word)
		{
			cout << word << endl;
			OutputFile << word;
		}
	}
	InputFile.close();
	OutputFile.close();
}
void mission3()
{
	//to work on
	ifstream InputFile;
	InputFile.open("inputFile.txt");
	ofstream OutputFile;
	OutputFile.open("outputFile.txt");
	string word;
	if (InputFile.is_open())
	{
		while (InputFile >> word)
		{
			cout << word << endl;
			OutputFile << word;
		}
	}
	InputFile.close();
	OutputFile.close();
}

int main()
{
	mission1();
	mission2();
}