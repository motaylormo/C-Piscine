#ifndef ENEMY_H
# define ENEMY_H

#include <curses.h> 
#include "Entity.class.hpp"
#include "Bullet.class.hpp"

class Enemy: public Entity {
	public:
		Enemy();
		~Enemy();
		Enemy(const Enemy &ref);
		Enemy& operator=(const Enemy &rhs);
		
		Enemy(int x, int y);
		void	fireBullet(int min);	
		void	setCoord(int x, int y);	
		void	print(void);
		bool	_isAlive;
		bool	flyRev(int min);
		int		getPoints(void) const;
		Bullet	_a;
	private:
		int		_hp;
		int		_points;
		int		_velocity;
};

#endif
