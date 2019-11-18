#include "Span.hpp"
#include <iostream>

void	print_set(std::set<int> s)
{
	std::set<int>::iterator it;
	for (it = s.begin(); it != s.end(); ++it)
	{
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;
}

void	print_update(Span &sp, int add)
{	
	std::cout << "Add " << add << std::endl;
	sp.addNumber(add);
	print_set(sp.getSet());
	std::cout << "\tmin: " << sp.shortestSpan() << std::endl;
	std::cout << "\tmax: " << sp.longestSpan() << std::endl;
}

int main()
{
	Span sp = Span(5);

	print_update(sp, 5);
	print_update(sp, 3);
	print_update(sp, 17);
	print_update(sp, 9);
	print_update(sp, 11);
	print_update(sp, 1);
}