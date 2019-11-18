#include "Form.hpp"

int	main()
{
	Form		f("paper", 50, 10);
	Bureaucrat	b("B", 55);
	while (1)
	{
		std::cout << b << std::endl;
		b.increment();
		if (f.signForm(b))
			break;
	}

	Form		ff("paper2", 2, 10);
	Bureaucrat	bb("B2", 3);
	ff.signForm(bb);
	ff.beSigned(bb);
}