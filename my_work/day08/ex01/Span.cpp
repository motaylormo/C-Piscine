#include "Span.hpp"

// ************************************************************************** //
//		Coplien's form
// ************************************************************************** //
Span::Span(void):
	_size(0) {}

Span::Span(unsigned int n):
	_size(n), _set() {}

Span::~Span(void) {}

Span& Span::operator=(const Span &rhs)
{
	this->_size = rhs._size;
	this->_set = rhs._set;
	return (*this);
}

Span::Span(const Span &ref)	{
	*this = ref;
}

// ************************************************************************** //
//		getter
// ************************************************************************** //
std::set<int>	Span::getSet(void) const
{
	return (this->_set);
}

// ************************************************************************** //
//		member
// ************************************************************************** //
void	Span::addNumber(int num)
{
	if (this->_set.size() < this->_size)
		this->_set.insert(num);
	else
		throw std::exception();
}

int		Span::shortestSpan(void)
{
	if (this->_set.size() < 2)
		return (0);

	std::set<int>::iterator it = this->_set.begin();
	int min = *it;
	++it;
	return (*it - min);
}

int		Span::longestSpan(void)
{
	std::set<int>::iterator min = this->_set.begin();
	std::set<int>::reverse_iterator max = this->_set.rbegin();
	return (*max - *min);
}