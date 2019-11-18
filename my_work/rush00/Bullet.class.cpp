#include "Bullet.class.hpp"

// ************************************************************************** //
//		Coplien's form
// ************************************************************************** //
Bullet::Bullet(int x, int y):
	Entity(x, y, SIZE, '*'),
	_isActive(true)
{
	this->_velocity = 1;
	this->print();
}

// ************************************************************************** //
//		on screen
// ************************************************************************** //
void	Bullet::print(void)
{
	attron(COLOR_PAIR(2));
	this->Entity::print();
	attroff(COLOR_PAIR(2));
}

bool	Bullet::fly(int max)
{
	if (this->_isActive == true && (this->_x < max - this->_size))
	{
		this->_x += this->_velocity;
		this->print();
		return (true);
	}
	this->_isActive = false;
	return (false);
}


bool	Bullet::flyRev(int min)
{
	if (this->_isActive == true && (this->_x > min + this->_size))
	{
		this->_x -= this->_velocity;
		this->print();
		return (true);
	}
	this->_isActive = false;
	return (false);
}

void Bullet::setCoord(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

bool Bullet::setVelocity(int velocity)
{
	if (velocity < 0)
		return false;
	else
		this->_velocity = velocity;
	return true;
}
