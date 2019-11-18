#include "Bureaucrat.hpp"

int	main()
{
	Bureaucrat b("B", 12);
	while (1)
	{
		std::cout << b << std::endl;
		b.increment();
	}
}