#include <iostream>
#include <ctype.h>	//	isprint()
#include <stdlib.h>	//	atoi(), atof()
#include <math.h>	//	modf()

void	as_char(char *str)
{
	char val = atoi(str);
	std::cout << "char: ";
	if (isprint(val))
		std::cout << val;
	else
		std::cout << "non displayable";
	std::cout << std::endl;
}

void	as_int(char *str)
{
	int val = atoi(str);
	std::cout << "int: " << val << std::endl;
}

void	as_float(char *str)
{
	float val = atof(str);
	std::cout << "float: ";
	if (val - (int)val == 0)
		std::cout << val << ".0";
	else
		std::cout << val;
	std::cout << "f" << std::endl;
}

void	as_double(char *str)
{	
	double val = atof(str);
	std::cout << "double: ";
	if (val - (int)val == 0)
		std::cout << val << ".0";
	else
		std::cout << val;
	std::cout << std::endl;
}


int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		as_char(argv[1]);
		as_int(argv[1]);
		as_float(argv[1]);
		as_double(argv[1]);
	}
}