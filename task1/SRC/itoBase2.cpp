#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Converter{
private:
	std::vector<int>a;
	int iriginal;
public:
	Converter(std::string str, int original) : iriginal(original)
	{
		for ( int i = 0; i < str.length(); i++)
		{
			this->a.push_back(charToInt(str[i]));
		}
	}

	int charToInt(char c)
	{
		if (c >= '0' && c <= '9' && (c - '0') < this->iriginal)
		{
			return (c - '0');
		}
		else
		{
			if (c >= 'A' && c <= 'Z' && (c - 'A') < this->iriginal)
			{
				return (c - 'A' + 10);
			}
			else 
			{
				return (-1);
			}
		}
	}

	char intToChar(int c)
	{
		if (c >= 0 && c <= 9)
		{
			return (c + '0');
		}
		else
		{
			return (c + 'A' - 10);
		}
	}

	int nextNumber(int final)
	{
		int temp = 0;
		for ( int i = 0; i < this->a.size(); i++)
		{
			temp = temp * this->iriginal + this->a.at(i);
			a.at(i) = temp / final;
			temp = temp % final;
		}
		return (temp);
	}

	bool zero()
	{
		for (int i=0; i < this->a.size(); i++)
		{
			if (a.at(i) != 0 )
			{
				return (false);
			}
		}
		return (true);
	}

	std::string convertTo(int final)
	{
		std::vector<int> b;
		int size = 0;
		do
		{
			b.push_back(this->nextNumber(final));
			size++;
		}
		while (!this->zero());

		std::string sTemp="";
		for (int i = b.size() - 1; i >= 0; i--)
		{
			sTemp += intToChar(b.at(i));
		}
	return (sTemp);
	}
};

int main(int argc, char **argv)
{
	std::string inputFile = argv[1];
	int original = atol(argv[2]);
	int final = atol(argv[3]);
	std::string origNumber;

	std::ifstream fin(inputFile.c_str());
	if (fin.is_open())
	{
		fin >> origNumber;
	}
	else
	{
		std::cout << "File " << inputFile << " not open" <<std::endl;
		origNumber = inputFile;
	}
	fin.close();
	Converter conv(origNumber,original);
	if ( argc > 4 )
	{
		std::string outputFile = argv[4];
		std::ofstream fout(outputFile.c_str());
		if (fout.is_open())
		{
			fout << conv.convertTo(final);
		}
		else
		{
			std::cout << "File " << outputFile << " not create" << std::endl;
			std::cout << conv.convertTo(final) << std::endl;
		}
	}
	else
	{
		std::cout << conv.convertTo(final) << std::endl;
	}
	return (0);
}
