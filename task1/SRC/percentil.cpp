#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <vector>

void ft_qsort(std::vector<int> &v, int first, int last)
{
	int i = first;
	int j = last;
	int x = v.at(((first + last) / 2));
	while (i <= j)
       	{
		while (v.at(i) < x) i++;
		while (v.at(j) > x) j--;

		if (i <= j)
		{
			int tmp = v.at(i);
			v.at(i) = v.at(j);
			v.at(j) = tmp;
			i++;
			j--;
		}
	}

	if (i < last) ft_qsort(v, i, last);
	if (first < j) ft_qsort(v, first, j);
}

void func(std::vector<std::string>str)
{
	std::vector<int> vec;
	for (auto i : str)
	{
		vec.push_back(atoi(i.c_str()));
	}
	ft_qsort(vec, 0, vec.size() - 1);
	int proc = vec.size() * 10 / 9;
	int mid = vec.size() / 2;
	int res = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec.at(i) == ((mid + proc) / 2))
		{
			res = vec.at(i);
		}
	}
	std::cout << res << std::endl;
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
