#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "begin: " << *it << std::endl;
	std::cout << "  end: " << *ite << std::endl;

	++it;
	--it;


	std::cout << "interate through:" << std::endl;
	while (it != ite)
	{
		std::cout << "\t" << *it << std::endl;
		++it;
	}


	std::cout << mstack.top() << std::endl;
	return 0;
}
