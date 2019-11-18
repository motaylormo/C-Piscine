#include <iostream>
#include <iterator>

template <typename T>
int	easyfind(T &cont, int needle)
{
	for (typename T::const_iterator
		it = cont.begin(); it != cont.end(); ++it)
	{
		if (*it == needle)
			return (*it);
	}
	throw std::exception();
}