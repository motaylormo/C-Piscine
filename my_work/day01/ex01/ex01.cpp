#include <iostream>

void memoryLeak()
{
	std::string* panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
}

void fix1()//heap
{
	std::string* panthere = new std::string("String panthere");
	std::cout << *panthere << std::endl;
	delete panthere;
}

void fix2()//stack
{
	std::string panthere = std::string("String panthere");
	std::cout << panthere << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		switch (argv[1][0])
		{
			case '1': memoryLeak();
					break;
			case '2': fix1();
					break;
			case '3': fix2();
					break;
		}
		while (1);
	}
}