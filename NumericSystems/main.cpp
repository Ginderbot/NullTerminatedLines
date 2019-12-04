#include<iostream>
#include<conio.h>
#include<Windows.h>

char* dec_to_bin(int dec);
int bin_to_dec(char* binary);
bool isBin(char str[]);
bool isHex(char str[]);
int HexToDec(const char* hex);

void main()
{
	setlocale(LC_ALL, "");
	/*int dec;
	cout << "Введите десятичное число: "; cin >> dec;
	char* binary = dec_to_bin(dec);
	cout << binary << endl;
	cout << "My binary: " << binary << endl;
	cout <<"10 "<< bin_to_dec(binary);
	delete[] binary;*/
	//const int n = 33;
	//char*binary = new char[n] {};
	//cout << "Введите двоичное число: "; cin >> binary;
	//cout << bin_to_dec(binary) << endl;
	//(HexToDec(binary) == 0) ? cout << "Не шеснадцатиричное число" : cout << HexToDec(binary); cout << endl;
	const int n = 11;
	char hex[n]{};
	std::cout << "Введите Hex число "; std::cin >> hex;
	std::cout << isHex(hex) << std::endl;
	std::cout << HexToDec(hex) << std::endl;
}

char* dec_to_bin(int dec)
{
	int n = 24;
	/*[&n, dec](int dec)
	{
		for (; dec; n++)
			dec /= 2;
	};*/

	std::cout << n << std::endl;
	std::cout << dec << std::endl;
	char* binary = new char[n] {};
	for (int i = 0; dec; i++, dec /= 2)binary[i] = dec % 2 + 48;
	/*for (n--; n >= 0; n--)
	{
		cout << binary[n];
		if (n % 8 == 0)cout << " ";
		if (n % 4 == 0)cout << " ";
	}*/
	/*cout << endl;*/
	n = strlen(binary);
	for (int i = 0; i < n / 2; i++)std::swap(binary[i], binary[n - 1 - i]);
	return binary;
}

bool isBin(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] == '0' || str[i] == '1'))
		{
			return false;
		}
	}
	return true;
}

int bin_to_dec(char* binary)
{
	int sum = 0;
	int plus = 0;
	for (int i = strlen(binary); i >= 0; i--)
	{
		(binary[i] == '1') ? sum += plus : false;
		(plus == 0) ? plus = 1 : plus *= 2;
	}
	return sum;
}

bool isHex(char str[])
{
	/*bool number = false;
	bool abc = false;

	if (str[0] == '0'&&str[1] != 'x'&&str[2] == '0')return false;
	for (int i = 0; str[i]; i++)
	{
		if (str[0] == '0' && str[1] == 'x'&&str[2] != '0'&&str[i] == 'x')i++;
		if (str[i] >= '0'&&str[i] <= '9')number = true;
		else if (str[i] >= 'A'&&str[i] <= 'F'|| str[i] >= 'a'&&str[i] <= 'f')abc = true;
		else return false;
	}
	if (number || abc)
	{
		return true;
	}
	else return false;*/
	int  i = 0;
	if (str[0] == '0' && (str[1] == 'x' || str[i] == 'X'))i = 2;
	if (i == 2 && str[2] == 0)return false;
	for (; str[i]; i++)
	{
		if (!(str[i] >= '0'&&str[i] <= '9') && !(str[i] <= 'a'&&str[i] <= 'f') && !(str[i] <= 'A'&&str[i] <= 'a'))return false;
	}
	return true;
}
int HexToDec(const char* hex)
{
	int Dec = 0;
	int step = 1;
	if (isHex)return 0;
	for (int i = hex[1]=='x' || hex[1]=='X'?2:0; hex[i]; i++)
	{
		step *= 16;
		if (hex[i] >= '0' &&hex[i] <= '9')step += hex[i] - 48;
		else if (hex[i] >= 'A' &&hex[i] <= 'F')step += hex[i] - 'A' + 10;
		else if (hex[i] >= 'a' &&hex[i] <= 'f')step += hex[i] - 'a' + 10;
		else throw 0;
	}
	//{
	//	for (int i = strlen(str) - 1; i >= 0; i--)
	//	{
	//		if (str[i] == 'x')return Dec;
	//		(str[i] >= 'A'&&str[i] <= 'F') ? Dec += (str[i] - 55) * step : Dec += (str[i] - 48) * step;
	//		(str[i] >= 'a'&&str[i] <= 'f') ? Dec += (str[i] - 55) * step : Dec += (str[i] - 48) * step;
	//		step *= 16;
	//	}
	//	return Dec;
	//}
	//return 0;
}