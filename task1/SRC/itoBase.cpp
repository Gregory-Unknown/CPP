#include <iostream>
#include <stdlib.h>
#include <string>
#include <math.h>

int checkBase(std::string str)
{
	int count = 0;
	int tmp = str.size();
	for (int i = 0; i < tmp; i++)
	{
		for (int j = i + 1; j < tmp; j++)
		{
			if (str.at(i) == str.at(j))
				count++;

			if (count > 1)
				return (1);
		}
		count = 0;
	}
	return (0);
}

std::string number_case(int num) {
	switch (num) 
	{
		case 0: return ("0");
		case 1: return ("1");
		case 2: return ("2");
		case 3: return ("3");
		case 4: return ("4");
		case 5: return ("5");
		case 6: return ("6");
		case 7: return ("7");
		case 8: return ("8");
		case 9: return ("9");
		case 10: return ("a");
		case 11: return ("b");
		case 12: return ("c");
		case 13: return ("d");
		case 14: return ("e");
		case 15: return ("f");
	}

	return ("Not valid symbol !");
}

std::string itoBase(unsigned int nb, std::string base)
{
	if (checkBase(base) == 1)
		return ("Not a valid base");
	int mod = 0;
	std::string result;
	int number = base.size();
	while (nb != 0) {
		mod = nb % number;
		nb = nb / number;
		result += number_case(tolower(mod));
	}
	return (result);
}



std::string itoBase(std::string nb, std::string baseSrc, std::string baseDst)
{
	if (checkBase(baseSrc) == 1 || checkBase(baseDst) == 1)
		return ("Not a valid base !");
	int lenNb = nb.size();
	int lenSrc = baseSrc.size();
	int number = 0;
	for (int i = 0; i < lenNb; i++)
	{
		int tmp = baseSrc.find(nb[i], 0);
		number += tmp * pow(lenSrc, lenNb - 1 - i);
	}
	return (itoBase(number, baseDst));
}

int main(int argc, char **argv)
{
	if (argc == 4)
		std::cout << "result : " <<  itoBase(argv[1], argv[2], argv[3]) << std::endl;
	return (0);
}
