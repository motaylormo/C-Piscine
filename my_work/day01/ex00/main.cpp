#include "Pony.hpp"

void	ponyOnTheHeap(void)
{
	std::cout << "ponyOnTheHeap function!!" << std::endl;

	std::cout << "create it" << std::endl;
	Pony *heap_pony = new Pony();
	std::cout << "and we can access it" << std::endl;
	heap_pony->display();
	std::cout << "then delete it" << std::endl;
	delete heap_pony;
}

void	ponyOnTheStack(void)
{
	std::cout << "ponyOnTheStack function!!" << std::endl;

	std::cout << "create it" << std::endl;
	Pony stack_pony;
	std::cout << "and we can access it" << std::endl;
	stack_pony.display();
	std::cout << "then leave the scope (in this case this function) and thus delete it" << std::endl;
}

int	main(void)
{
	ponyOnTheHeap();
	std::cout << std::endl;
	ponyOnTheStack();
}