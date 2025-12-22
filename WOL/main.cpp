#include <fstream>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");
	
	std::ofstream fout("201 WOL.txt");
	std::ifstream fin("201 RAW.txt");  

	if (fin.is_open())
	{
		const int IP_BUFFER_SIZE = 16;
		const int MAC_BUFFER_SIZE = 18;
		char sz_IP_BUFFER[IP_BUFFER_SIZE] = {};
		char sz_MAC_BUFFER[MAC_BUFFER_SIZE] = {};
		while (!fin.eof())
		{
			fin >> sz_IP_BUFFER >> sz_MAC_BUFFER; 
			cout << sz_MAC_BUFFER << "\t" << sz_IP_BUFFER << endl;
			fout << sz_MAC_BUFFER << "\t" << sz_IP_BUFFER << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found." << endl;
	}
	fout.close();
	fin.close();
	system("notepad 201 WOL.txt");
}