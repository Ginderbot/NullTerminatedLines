#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

void InputLine(char str[], const int n);
int StrLend(char str[]); //считает длинну массива
void UpperCase(char str[]);// Всё большими
void LowerCase(char str[]);// Всё маленькими
void Capitalize(char str[]); // Каждее слово с большой буквы
void Shrink(char str[]);// Удаляет лишние пробелы
void RemoveSpaces(char str[]);// Удаляет все пробелы
bool isPalindrome(char str[]); // Проверяет палиндром
bool isNumber(char str[]);//Проверяет является ли символ номером
int strToInt(char str[]);


bool isBin(char str[]); //проверка на двоичный код
int BintoDec(char str[]); //возвращает десятичное значение двоичного числа
bool isHex(char str[]); // проверяет является ли строка шеснадцатиричным числом
int HexToDec(char str[]);//возвращает десятичное значение шеснадцатиричного числа


//int calck(char str[]);
//int Умножение(char str[], int num, int sum);
//int Деление(char str[], int num, int sum);
//int Сложение(char str[], int num, int sum);
//int Отнимание(char str[], int num, int sum);


void main()
{
	setlocale(LC_ALL, "");
	//char str[]={'H','e','l','l','o'}
	/*char str[] = "Hello";
	cout << str << endl;
	cout << sizeof(str) << endl;*/
	const int n = 200;
	char str[n];
	cout << "Введите строку: ";
	InputLine(str, n);
	//UpperCase(str); 
	//cout << str << endl;
	//LowerCase(str); 
	//cout << str << endl;
	//Capitalize(str);
	//cout << str << endl;
	//Shrink(str);
	//cout << str << endl;
	//RemoveSpaces(str); 
	//cout << str << endl;
	//(isPalindrome(str)) ? cout << "Полиндром" : cout << "Не полиндром"; cout << endl; 
	//cout << str << endl;
	//cout << isNumber(str) << endl;
	/*cout << strToInt(str) * 2 << endl;*/
	//cout << calck(str) << endl;
	//(isBin(str)) ? cout << "Двуичный код" : cout << "Не двуичный код"; cout << endl;
	//(BintoDec(str) == 0) ? cout << "Не двуичный код" : cout << BintoDec(str); cout << endl;
	//(isHex(str)) ? cout << "Шеснадцатиричное число" : cout << "Не шеснадцатиричное число"; cout << endl;
	(HexToDec(str) == 0) ? cout << "Не шеснадцатиричное число" : cout << HexToDec(str); cout << endl;

	//cout << StrLend(str) << endl;
}
void InputLine(char str[], const int n)
{
	SetConsoleCP(1251);
	cin.getline(str, n);
	SetConsoleCP(866);
}
int StrLend(char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void UpperCase(char str[])
{
	cout << "\t\t\t\tВсё большими буквами" << endl;
	for (int i = 0; str[i]; i++)
	{
		(str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а'&&str[i] <= 'я') ? str[i] -= 32 : str[i];
	}
}
void LowerCase(char str[])
{
	cout << "\t\t\t\tВсё маленькими буквами" << endl;
	for (int i = 0; str[i]; i++)
	{
		(str[i] >= 'A' && str[i] <= 'Z' || str[i] >= 'А' && str[i] <= 'Я') ? str[i] += 32 : str[i];
	}
}
void Capitalize(char str[])
{
	cout << "\t\t\t\tПервые буквы большие" << endl;
	(str[0] >= 'a' && str[0] <= 'z' || str[0] >= 'а'&&str[0] <= 'я') ? str[0] -= 32 : str[0];
	for (int i = 0; str[i]; i++)
	{
		((str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'а'&&str[i] <= 'я') && str[i - 1] == ' ') ? str[i] -= 32 : str[i];
	}
}
void Shrink(char str[])
{
	cout << "\t\t\t\tТолько один пробел" << endl;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}
void RemoveSpaces(char str[])
{
	cout << "\t\t\t\tСовсем без пробелов" << endl;
	for (int i = 0; str[i]; i++)
	{
		if (str[i] == ' ')
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
		}
	}
}
bool isPalindrome(char str[])
{
	cout << "\t\t\t\tПроверка на полиндром" << endl;
	int n = StrLend(str);
	for (int i = 0; str[i]; i++)
	{
		(str[i] == str[n - 1 - i] && str[i] == 32) ? i++ : (str[i] == ' ') ? i++ && n++ : (str[n - 1 - i] == ' ') ? n-- : false/*костыль*/;  // Проверка пробелов
		if (str[i] != str[n - 1 - i])
		{
			if (str[i] + 32 != str[n - 1 - i] && str[i] != str[n - 1 - i] + 32) return false; // Проверка больших букв и возврат не полиндрома
		}
	}
	return true;
}
bool isNumber(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (!(str[i] >= 0 && str[i] <= 9)) return false;
	}
	return true;
}
int strToInt(char str[])
{
	int num = 0;
	if (isNumber(str))
	{
		for (int i = 0; str[i]; i++)
		{
			num *= 10;
			num += str[i] - '48';
		}
	}
	return num;
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
int BintoDec(char str[])
{
	int sum = 0;
	int plus = 0;
	StrLend(str);
	if (isBin)
	{
		for (int i = StrLend(str); i >= 0; i--)
		{
			(str[i] == '1') ? sum += plus : false;
			(plus == 0) ? plus = 1 : plus *= 2;
		}
	}
	return sum;
}
bool isHex(char str[])
{
	bool number = false;
	bool abc = false;

	if (str[0] == '0'&&str[1] != 'x'&&str[2] == '0')return false;
	for (int i = 0; str[i]; i++)
	{
		if (str[0] == '0' && str[1] == 'x'&&str[2] != '0'&&str[i] == 'x')i++;
		if (str[i] >= '0'&&str[i] <= '9')number = true;
		else if (str[i] >= 'A'&&str[i] <= 'F')abc = true;
		else return false;
	}
	if (number||abc)
	{
		return true;
	}
	else return false;
}
int HexToDec(char str[])
{
	int Dec = 0;
	int step = 1;
	if (isHex(str))
	{
		for (int i = StrLend(str) - 1; i >= 0; i--)
		{
			if (str[i] == 'x')return Dec;
			(str[i] >= 'A'&&str[i] <= 'F') ? Dec += (str[i] - 55) * step : Dec += (str[i] - 48) * step;
			step *= 16;
		}
		return Dec;
	}
}
int calck(char str[])
{
	int a = 0, b = 0;
	int start = 0, finish = 0;
	int summ = 0;

	for (int i = 0; str[i]; i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			a = b;
			b = 0;
			for (int j = start; j < i; j++)
			{
				b = b * 10;
				b += str[j] - '0';
				finish = j;
			}
			/*cout << "a" << a << endl;
			cout << "b" << b << endl;
			cout << "Действие" << endl;*/
			if (str[i] == '*')
			{
				for (int j = start; str[j]; j++)
				{
					str[start] = a * b;
					str[j] = str[j - finish - start];
				}
			}
			for (int j = 0; str[j]; j++)
			{
				cout << str[j] << endl;

			}
			i++;
			start = i;
			if (str[i] == '*')
			{
				//return a * b;
			}
		}
	}
	return a;
}