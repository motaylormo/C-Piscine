#include "Contactbook.class.hpp"
#include <string>	//	for str.compare

std::string	command_str[] = {
	"ADD",
	"SEARCH",
	"EXIT",
};

void (Contactbook::*func[])(void) = {
	&Contactbook::add,
	&Contactbook::search,
	&Contactbook::exit,
};

static int	get_command(Contactbook& phonebook)
{
	std::string str;
	std::cin >> str;
	for (int i = 0; i < 3; ++i)
	{
		if (str.compare(command_str[i]) == 0)
		{
			(phonebook.*func[i])();
			return (1);
		}
	}
	return (0);
}

int	main(void)
{
	Contactbook	phonebook;
	while (1)
	{
		std::cout << "Command: ";
		if ((get_command(phonebook)))
			;
		else
			std::cout << "Invalid command." <<
			" The valid commands are \"ADD\", \"SEARCH\", and \"EXIT\"."
			 << std::endl;
	}
}