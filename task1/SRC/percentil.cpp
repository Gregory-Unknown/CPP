#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

void func(std::vector<std::string>str)
{
	std::vector<int>vec;
	for (auto i : str)
	{
		vec.push_back(atoi(i.c_str()));
	}
	sort(vec.begin(), vec.end());
	int proc = vec.size() * 10 / 9;
	int mid = vec.size() / 2;
	int summ = 0;
	for (int i = mid; i < proc; i++)
	{
		std::cout << vec.at(i) << std::endl;
		summ += vec.at(i);
	}
	std::cout << summ << std::endl;
}

int main(int argc, char **argv)
{
	if ( argc == 2)
	{
		std::vector<std::string>str;
		std::ifstream input;

		input.open(argv[1]);
		while (!input.eof())
		{
			std::string s;
			std::getline(input, s);
			str.push_back(s);
		}
		func(str);
		input.close();
	}
	return (0);
}
