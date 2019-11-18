#include <iostream>
#include <set>

class Span {

public:

	Span(void);
	Span(unsigned int n);
	~Span(void);
	Span& operator=(const Span &rhs);
	Span(const Span &ref);

	std::set<int>	getSet(void) const;
	int				getMaxSize(void) const;

	void	addNumber(int num);
	int		shortestSpan(void);
	int		longestSpan(void);

private:
	unsigned int	_size;
	std::set<int>	_set;

};