#include "Bureaucrat.hpp"

class Form {

public:

	Form(void);
	~Form(void);
	Form(const Form &ref);
	Form& operator=(const Form &rhs);

	Form(std::string name, int toSign, int toExec);

	std::string	getName(void) const;
	bool		getState(void) const;

	bool		signForm(Bureaucrat &bur);
	void		beSigned(Bureaucrat &bur);

private:
	std::string	_name;
	bool		_signed;
	int			_gradeToSign;
	int			_gradeToExec;

	class GradeTooLowException: public std::exception {
		virtual const char * what() const throw();
	};

	class GradeTooHighException: public std::exception {
		virtual const char * what() const throw();
	};
};

std::ostream&	operator<<(std::ostream& os, const Form &ref);