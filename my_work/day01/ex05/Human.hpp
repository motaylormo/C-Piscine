#include "Brain.hpp"

class Human {

public:

	typedef Human		t;

	Human(void);
	~Human(void);

	std::string	identify(void);
	Brain&		getBrain(void);

private:

	Brain	_brain;
	
};