#include "easyfind.hpp"
#include <iostream>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>

int	main()
{
	int array[10] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90};
	std::array<int,10>		arr = {{0, 10, 20, 30, 40, 50, 60, 70, 80, 90}};
	std::vector<int>		vec(array, array + 10);
	std::deque<int>			deq(array, array + 10);
	std::list<int>			lst(array, array + 10);
	std::forward_list<int>	flst(array, array + 10);
	std::set<int>			st(array, array + 10);

	std::cout << "       array: " << easyfind(arr, 10) << std::endl;
	std::cout << "      vector: " << easyfind(vec, 50) << std::endl;
	std::cout << "       deque: " << easyfind(deq, 30) << std::endl;
	std::cout << "forward_list: " << easyfind(flst, 70) << std::endl;
	std::cout << "        list: " << easyfind(lst, 80) << std::endl;
	std::cout << "         set: " << easyfind(st, 10) << std::endl;
}