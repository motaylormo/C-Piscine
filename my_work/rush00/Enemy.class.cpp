#include "Enemy.class.hpp"

Enemy::Enemy() {}
Enemy::~Enemy() {}
Enemy::Enemy(const Enemy &ref) { *this = ref; }
Enemy& Enemy::operator=(const Enemy &rhs) 
{
	_hp		= rhs._hp;
	_points = rhs._points;
	_velocity = rhs._velocity;
	_isAlive = rhs._isAlive;
	_a = rhs._a;
	_symbol = rhs._symbol;	
	_size = rhs._size;
	return *this;
}

Enemy::Enemy(int x, int y) : Entity(x, y, 2, 'X') 
{
	_hp = 1;
	_points = 10;
	_velocity = 1;
	_isAlive = true;
	_a = Bullet(x - 3, y);
	_a.setVelocity(2);
	this->print();
}

void Enemy::print(void)
{
	attron(COLOR_PAIR(3));
	this->Entity::print();
	attroff(COLOR_PAIR(3));
}

void Enemy::setCoord(int x, int y) { this->_x = x; this->_y = y; }

void Enemy::fireBullet(int min)
{
	//fire bullet here; (Update bullet position);
	this->_a.flyRev(min);
	if (this->_a._isActive == false && this->_x > 50) // if bullet is dead
	{
		this->_a._isActive = true;
		this->_a.setCoord(this->_x - 3, this->_y);
	}
	
}

bool Enemy::flyRev(int min)
{
	if (this->_isAlive == true && (this->_x > min + this->_size))
	{
		this->_x -= this->_velocity;
		this->fireBullet(min);
		this->print();
		return (true);
	}
	return (false);
}

int	Enemy::getPoints(void) const
{
	return this->_points;
}
