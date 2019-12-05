#include<iostream>
#include<fstream>


//#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	std::cout << "Hello World";
	std::ofstream fout;
	fout.open("File.txt", std::ios::app); // app - Дозапись

	fout << "Hello World" << std::endl;
	/*fout.open("AnotherFile.txt");
	fout << "Sam privet";*/

	fout.close();

	system("notepad File.txt");
#endif // WRITE_TO_FILE

#ifdef READ_FROM_FILE
	std::ifstream fin;
	fin.open("File.txt");

	const int n = 256;
	char sz_buff[n] = {};


	while (!fin.eof())
	{
		//	fin >> sz_buff; // до пробела
		fin.getline(sz_buff, n); // до ентера
		std::cout << sz_buff << std::endl;
		i++;
	}

	fin.close();
#endif // READ_FROM_FILE

	//std::ifstream fout;
	std::ifstream fin;
	fin.open("File.txt");

	const int n = 256;
	char buff_mac[n] = {};
	char buff_ip[n] = {};

	std::ofstream fout("final.txt");

	while (!fin.eof())
	{
		fin >> buff_mac;
		fin >> buff_ip;

		std::cout << buff_ip << "\t"<<buff_mac<< std::endl;
		fout << buff_ip << "\t"<<buff_mac<< std::endl;
	}

	fin.close();
	fout.close();

	system("notepad final.txt");

}