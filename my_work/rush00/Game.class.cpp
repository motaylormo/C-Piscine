#include "Game.class.hpp"

//	https://linux.die.net/man/3/mvprintw
//	int mvwprintw(WINDOW *win, int y, int x, const char *fmt, ...);

// ************************************************************************** //
//		Coplien's form
// ************************************************************************** //
Game::Game(void)
{
	initscr();
	getmaxyx(stdscr, this->_maxY, this->_maxX);
	this->_player = Entity(this->_maxX / 10, this->_maxY / 2, 2, 'A');

	curs_set(0);//	Disable cursor
	cbreak();//	no line buffering: keys typed immediately available to the program
	noecho();// No echo for key input
	keypad(stdscr, TRUE);// Get keyboard input
	nodelay(stdscr, TRUE);// Doesn't wait for user input

	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK); // Moon
	init_pair(2, COLOR_RED, COLOR_BLACK); // Bullet color
	init_pair(3, COLOR_GREEN, COLOR_BLACK); // Obj color
	init_pair(4, COLOR_YELLOW, COLOR_BLACK); // Obj color
	init_pair(5, COLOR_BLUE, COLOR_BLACK); // Obj color
	init_pair(6, COLOR_MAGENTA, COLOR_BLACK); // Obj color
	this->_player.print();
	refresh();
}

Game::~Game(void)
{
	refresh();
	endwin();// Terminate and restore window settings
}

Game::Game(const Game &ref){
	*this = ref;
}

Game&	Game::operator=(Game const &rhs)//	rhs "right hand side"
{
	this->_maxX = rhs._maxX;
	this->_maxY = rhs._maxY;
	this->_player = rhs._player;
	return (*this);
}

// ************************************************************************** //
//		class methods
// ************************************************************************** //
void	Game::arrowKey(int key)
{
	if (key == 258)
		this->_player.down(this->_maxY);
	if (key == 259)
		this->_player.up(14);
	if (key == 260)
		this->_player.left(0);
	if (key == 261)
		this->_player.right(this->_maxX);
	this->_player.print();
}

bool	Game::shoot(void)
{
	for (int i = 0; i < 5; i++) // Check which bullets is on
	{
		if (this->_bulletArr[i]._isActive == false)
		{
			this->_bulletArr[i] = Bullet(this->_player.getX() + this->_player.getSize(),
										this->_player.getY());
			return (true);
		}
	}
	return (false);
}

// ************************************************************************** //
//		getters
// ************************************************************************** //
int		Game::maxX(void) const		{ return (this->_maxX); }
int		Game::maxY(void) const		{ return (this->_maxY); }
