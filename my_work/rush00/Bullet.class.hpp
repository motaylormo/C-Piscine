#ifndef BULLET_H
#define	BULLET_H

#include "Entity.class.hpp"
#include <curses.h>

#define SIZE 1

class Bullet : public Entity {
	public:

		Bullet(void)	:	Entity(0, 0, SIZE, '*'), _isActive(false){}
		Bullet(int x, int y);
		
		void	print(void);
		bool	fly(int max);
		bool	flyRev(int min);
		void	setCoord(int x, int y);
		bool	_isActive;
		bool	setVelocity(int velocity);

	private:
		int		_velocity;
};

#endif
