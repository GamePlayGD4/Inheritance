#include <windows.h>
#include <iostream>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

//#define WRITE_TO_FILE
//#define INPUT_STRINGS

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::ofstream fout;
	fout.open("File.txt", std::ios_base::app);
	fout << "Hello files" << endl;
	fout.close();
	//system("mspaint");
	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef INPUT_STRINGS
	cout << "Your name please: ";
	const int SIZE = 256;
	char last_name[SIZE] = {};
	char first_name[SIZE] = {};
	SetConsoleCP(1251);
	cin >> first_name >> last_name;
	SetConsoleCP(866);
	cout << first_name << "\t" << last_name << endl;
#endif // INPUT_STRINGS

	const int SIZE = 256;
	char sz_buffer[SIZE] = {};

	std::ifstream fin("main.cpp");  
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			//fin >> sz_buffer; 
			fin.getline(sz_buffer, SIZE);
			cout << sz_buffer << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found." << endl;
	}
	fin.close();

}