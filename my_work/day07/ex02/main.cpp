#include "Array.hpp"

void	print_arr(Array<std::string> &arr)
{
	std::cout << "Size: " << arr.size() << std::endl;
	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << "\t[" << i << "] \"" << arr[i] << "\"" << std::endl;
	}
}

int	main()
{
	Array<std::string> arr(5);

	print_arr(arr);

	arr[0] = "hello";
	arr[1] = "world";
	arr[2] = "or";
	arr[3] = "something";
	arr[4] = "it doesn't matter";

	print_arr(arr);

	std::cout << "Access an out of bounds element: " << arr[5] << std::endl;

}