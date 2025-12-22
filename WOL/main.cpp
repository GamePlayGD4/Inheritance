#include <fstream>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//#define WOL
#define DHCPD

void main()
{
	setlocale(LC_ALL, "");

#ifdef WOL
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
#endif // WOL

	std::fstream fin("201 RAW.txt");
	std::ofstream fout("201.dhcpd");
	if (fin.is_open())
	{
		const int IP_BUFFER_SIZE = 16;
		const int MAC_BUFFER_SIZE = 18;
		char sz_IP_buffer[IP_BUFFER_SIZE] = {};
		char sz_MAC_buffer[MAC_BUFFER_SIZE] = {};
		for (int i = 0; !fin.eof(); i++)
		{
			fin >> sz_IP_buffer >> sz_MAC_buffer;
			if (sz_IP_buffer[0] == 0 || sz_MAC_buffer[0] == 0)continue;
			for (int i = 0; sz_MAC_buffer[i]; i++)
				if (sz_MAC_buffer[i] ==  '-')sz_MAC_buffer[i] = ':';
			cout << "host- " << i << endl;
			cout << "{\n";
			cout << "\thardware ethernet\t" << sz_MAC_buffer << ";\n";
			cout << "\tfixed_address\t\t" << sz_IP_buffer << ";\n";
			cout << "}\n";
			cout << endl;
			
			//alt + shift + downarrow + delete + f / Чтобы cout поменять на fout
			fout << "host- " << i << endl;
			fout << "{\n";
			fout << "\thardware ethernet\t" << sz_MAC_buffer << ";\n";
			fout << "\tfixed_address\t\t" << sz_IP_buffer << ";\n";
			fout << "}\n";
			fout << endl;
		}
	}
	else
	{
		std::cerr << "Error: file not found" << endl;
	}
	fin.close();
	fout.close();
	system("notepad 201.dhcpd");

}