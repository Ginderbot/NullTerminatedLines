#include <iostream>

void main()
{
	setlocale(LC_ALL, "");
	const int n = 256;
	/*char str[n] = {};
	std::cout << "¬ведите строку ";
	std::cin.getline(str,n);
	std::cout << str << std::endl;
	std::cout << strlen(str) << std::endl;

	char buff[n] = {};
	strcpy(buff, str);
	std::cout << buff << std::endl;*/

	char str1[n] = "Hello";
	char str2[n] = "World";
	strncat(str1, str2, 2);
	std::cout << str1 << std::endl;

	const char* words[] =
	{
			"Hello",
			"Woeld",
			"Computer",
			"C++",
			"A",
	};
	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		std::cout << words[i] << std::endl;
	}
	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		for (int j = 0; j < sizeof(words) / sizeof(const char*); j++)
		{
			int strcmp(const char* words[5]);
			if (j < i)
			{
				words[i] = words[i - 1];
			}

		}

	}

	for (int i = 0; i < sizeof(words) / sizeof(const char*); i++)
	{
		std::cout << words[i] << std::endl;
	}
}