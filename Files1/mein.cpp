#include<iostream>
#include<fstream>

//#define NAME_FILE
#define RESULT
#define WRITE_TO_FILE
//#define READ_FROM_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
#ifdef NAME_FILE


	const int n = 256;
	char name[n] = {};

	std::cout << "Введите имя файла: " << std::endl;
	std::cin >> name;

	if (!strstr(name, ".txt"))
	{
		strcat(name, ".txt");
	}
#endif // NAME_FILE
#ifdef RESULT
	std::ofstream fout;
	std::ifstream fin;
	fin.open("list.txt");

	const int n = 256;
	char name[n] = { "404.result" };
	fout.open(name);


	const int m = 32;
	char buff[m] = {};


	int x = 1;
	while (!fin.eof())
	{
		fin.getline(buff, m);
		int i = 0;
		fout << "host 404-" << x++ << std::endl << "{" << std::endl;
		fout << "hardware ethernet" << "\t\t\t";
		do
		{
			fout << buff[i], i++;
		} while (buff[i] != '\t');
		fout << std::endl << "fixed-address" << "\t\t\t";
		do
		{
			fout << buff[i]; i++;
		} while (buff[i] != 0);
		fout << std::endl << "}" << std::endl << std::endl;
	}
	fin.close();
	fout.close();


#endif // RESULT





	//fout << "Hello World" << std::endl;
	/*fout.open("AnotherFile.txt");
	fout << "Sam privet";*/

	fout.close();

	system(name);
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

	////std::ifstream fout;
	//std::ifstream fin;
	//fin.open("File.txt");

	//const int n = 256;
	//char buff_mac[n] = {};
	//char buff_ip[n] = {};

	//std::ofstream fout("final.txt");

	//while (!fin.eof())
	//{
	//	fin >> buff_mac;
	//	fin >> buff_ip;

	//	std::cout << buff_ip << "\t" << buff_mac << std::endl;
	//	fout << buff_ip << "\t" << buff_mac << std::endl;
	//}

	//fin.close();
	//fout.close();

	//system("notepad final.txt");


	
}