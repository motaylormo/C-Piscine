#include <iostream>
#include <typeinfo>

// ************************************************************************** //
//		iter
// ************************************************************************** //
template<typename T, typename R>
void	iter(T arr[], std::size_t len, R (*f)(T&))
{
	for (int i = 0; i < len; ++i)
		(*f)(arr[i]);
}

// ************************************************************************** //
//		test main
// ************************************************************************** //
template<typename F>
void	print(F &a)
{
	std::cout << a << std::endl;
}

template<typename F>
F	add42(F &a)
{
	a += 42;
	return (a);
}

#define PRINT_HEADER(x)	(std::cout << "\e[1m" << x << "\e[0m" << std::endl)

template<typename T>
void	tests_set(T arr[], std::size_t len)
{
	PRINT_HEADER("print");
	iter(arr, len, print<T>);
	PRINT_HEADER("add 42");
	iter(arr, len, add42<T>);
	PRINT_HEADER("print");
	iter(arr, len, print<T>);
}

int		main(void)
{
	PRINT_HEADER("\e[42m" "int tests");
	{
		int arr[4] = {1, 2, 4, 5};
		tests_set(arr, 4);
	}
	PRINT_HEADER(std::endl << "\e[42m" "char tests");
	{
		char arr[5] = {'a', 'b', 'c', 'd', '\0'};
		tests_set(arr, 5);
	}
	PRINT_HEADER(std::endl << "\e[42m" "string tests");
	{
		std::string arr[4] = {"one", "two", "three", "four"};
		tests_set(arr, 4);
	}
}
