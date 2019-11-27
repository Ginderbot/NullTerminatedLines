#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

char* dec_to_bin(int dec);
int bin_to_dec(char* binary);
bool isBin(char str[]);

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
	const int n = 33;
	char*binary = new char[n] {};
	cout << "Введите двоичное число: "; cin >> binary;
	cout << bin_to_dec(binary) << endl;

}

char* dec_to_bin(int dec)
{
	int n = 24;
	/*[&n, dec](int dec)
	{
		for (; dec; n++)
			dec /= 2;
	};*/

	cout << n << endl;
	cout << dec << endl;
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
	for (int i = 0; i < n / 2; i++)swap(binary[i], binary[n - 1 - i]);
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