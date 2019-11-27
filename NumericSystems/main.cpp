#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

char* dec_to_bin(int dec);
int bin_to_dec(char* binary);

void main()
{
	setlocale(LC_ALL, "");
	int dec;
	cout << "������� ���������� �����: "; cin >> dec;
	char* binary = dec_to_bin(dec);
	cout << binary << endl;
	cout << "My binary: " << binary << endl;
	cout << bin_to_dec(binary);
	delete[] binary;
}

char* dec_to_bin(int dec)
{
	int n = 0;
	[&n, dec]()
	{
		for (; dec; n++)dec /= 2;
	};
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

int bin_to_dec(char* binary)
{
	int sum = 0;
	int plus = 0;
	strlen(binary);
		for (int i = strlen(binary); i >= 0; i--)
		{
			(binary[i] == '1') ? sum += plus : false;
			(plus == 0) ? plus = 1 : plus *= 2;
		}
	return sum;
}