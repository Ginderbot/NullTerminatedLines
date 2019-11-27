#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

char* dec_to_bin(int dec);

void main()
{
	setlocale(LC_ALL, "");
	int dec;
	cout << "Введите десятичное число: "; cin >> dec;
	char* binary = dec_to_bin(dec);
	cout << binary << endl;
	cout << "My binary: " << binary << endl;
	delete[] binary;
}

char* dec_to_bin(int dec)
{
	int n = 32;
	char* binary = new char[n] {0};
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