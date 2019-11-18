#ifndef GAME_H
# define GAME_H

# include <curses.h>
# include "Entity.class.hpp"
# include "Bullet.class.hpp"

class Game {

public:

	Game(void);
	~Game(void);
	Game(const Game &ref);
	Game& operator=(Game const &rhs);


	Entity	_player;
	Bullet	_bulletArr[5];

	void	arrowKey(int key);
	bool	shoot(void);

	int		maxX(void) const;
	int		maxY(void) const;

private:
	int		_maxX;
	int		_maxY;
};

#endif
