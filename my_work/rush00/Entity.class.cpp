#include "Entity.class.hpp"
#include <curses.h>

// ************************************************************************** //
//		Coplien's form
// ************************************************************************** //
Entity::Entity(void):
	_x(0), _y(0), _size(1), _symbol('O'){ }

Entity::Entity(int x, int y, int size, char c):
	_x(x), _y(y), _size(size), _symbol(c){ }

Entity::Entity(const Entity &ref)	{ *this = ref; }

Entity&	Entity::operator=(Entity const &rhs)//	rhs "right hand side"
{
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->_size = rhs._size;
	this->_symbol = rhs._symbol;
	return (*this);
}

Entity::~Entity(void){ }

// ************************************************************************** //
//		on screen
// ************************************************************************** //
void	Entity::print(char c) const
{
	for (int i = 0; i < this->_size; ++i)
	{
		for (int j = 0; j < this->_size; ++j)
			mvprintw(this->_y + i, this->_x + j, (char[2]){c, '\0'});
	}
}

void	Entity::print(void)	const	{ this->print(this->_symbol); }

// ************************************************************************** //
//		incrementers
// ************************************************************************** //

bool	Entity::increment(int *ptr, int max)
{
	if (*ptr < max - this->_size)
	{
		*ptr += 1;
		return (true);
	}
	return (false);
}
bool	Entity::decrement(int *ptr, int min)
{
	if (*ptr > min)
	{
		*ptr -= 1;
		return (true);
	}
	return (false);
}

bool	Entity::left(int min)	{ return (this->decrement(&(this->_x), min)); }
bool	Entity::up(int min)		{ return (this->decrement(&(this->_y), min)); }
bool	Entity::right(int max)	{ return (this->increment(&(this->_x), max)); }
bool	Entity::down(int max)	{ return (this->increment(&(this->_y), max)); }

// ************************************************************************** //
//		getters
// ************************************************************************** //
int		Entity::getX(void) const		{ return (this->_x); }
int		Entity::getY(void) const		{ return (this->_y); }
int		Entity::getSize(void) const		{ return (this->_size); }
char	Entity::getSymbol(void) const	{ return (this->_symbol); }
