#include <iostream>

class Bureaucrat {

public:

	Bureaucrat(void);
	~Bureaucrat(void);
	Bureaucrat(const Bureaucrat &ref);
	Bureaucrat& operator=(const Bureaucrat &rhs);

	Bureaucrat(std::string name, int grade);

	std::string	getName(void) const;
	int			getGrade(void) const;

	void	increment(void);
	void	decrement(void);

private:
	std::string	_name;
	int			_grade;

	class GradeTooLowException: public std::exception {
		virtual const char * what() const throw();
	};

	class GradeTooHighException: public std::exception {
		virtual const char * what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat &ref);