#ifndef ENTITY_H
# define ENTITY_H

# include <curses.h>

class Entity {

public:

	Entity(void);
	~Entity(void);
	Entity(const Entity &ref);
	Entity& operator=(Entity const &rhs);

	Entity(int x, int y, int size, char c);

	bool	left(int min);
	bool	right(int max);
	bool	up(int min);
	bool	down(int max);

	void	print(void) const;

	int		getX(void) const;
	int		getY(void) const;
	int		getSize(void) const;
	char	getSymbol(void) const;

protected:
	int		_x;
	int		_y;
	int		_size;
	char	_symbol;

	void	print(char c) const;
	
	bool	increment(int *ptr, int max);
	bool	decrement(int *ptr, int min);

};

#endif
