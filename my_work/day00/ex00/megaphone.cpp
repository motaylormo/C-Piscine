#include <iostream>	//	for std::cout
#include <cctype>	//	for toupper()

static char	*capitalize_string(char *str)
{
	for (int i = 0; str[i]; ++i)
		str[i] = toupper(str[i]);
	return (str);
}

using namespace std;
int	main(int argc, char **argv)
{
	if (argc < 2)
		cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; argv[i]; ++i)
			cout << capitalize_string(argv[i]);
	}
	cout << "\n";
	return (0);
}