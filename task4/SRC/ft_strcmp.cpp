#include <iostream>
#include <string>

int checkStars(std::string str)
{
	int i = 0;
	while (i < str.size())
	{
		if (str[i] == '*')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

std::string ft_strcmp(std::string str1, std::string str2)
{
	int i = 0;
	int star = checkStars(str2);
	while (i < str1.size() && i < str2.size())
	{
		if (str1[i] != str2[i] && star == 0)
		{
			return ("KO");
		}	
		i++;
	}
	if (str1[i] != '\0' && star == 0)
	{
		return ("KO");
	}
	if (str2[i] != '\0' && star == 0)
	{
		return ("KO");
	}
	return ("OK");
}

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		std::cout << "Result : " << ft_strcmp(argv[1], argv[2]) << std::endl;
	}
	return (0);
}
