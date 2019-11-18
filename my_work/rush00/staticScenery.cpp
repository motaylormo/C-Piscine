#include "Game.class.hpp"
#include <iostream>
#include <string.h>

std::string		moon[] = {
	"        ___---___        ",
	"     .--         --.     ",
	"   ./   ()      .-. \\.  ",
	"  /   o    .   (   )  \\ ",
	" / .            '-'    \\",
	"|                       |",
	"|    o           ()     |",
	"|       .--.          O |",
	" | .   |    |          | ",
	"  \\    `.__.'   o  .  / ",
	"   \\                 /  ",
	"    `\\  o    ()     /'  ",
	"      `--___   ___--'    ",
	"            ---          ",
};

std::string	mountain[] = {
	"        _    .  ,   .           .                            ",
	"    *  / \\_ *  / \\_      _  *        *   /\\'__        *      ",
	"      /    \\  /    \\,   ((        .    _/  /  \\  *'.         ",
	" .   /\\/\\  /\\/ :' __ \\_  `          _^/  ^/    `--.          ",
	"    /    \\/  \\  _/  \\-'\\      *    /.' ^_   \\_   .'\\         *",
	"  /\\  .-   `. \\/     \\ /==~=-=~=-=-;.  _/ \\ -. `_/   \\       ",
	" /  `-.__ ^   / .-'.--\\ =-=~_=-=~=^/  _ `--./ .-'  `-        ",
	"/        `.  / /       `.~-^=-=~=^=.-'      '-._ `._         "
};
static void printMoon(void)
{
	attron(COLOR_PAIR(1));
	for (int i = 0; i < 14; ++i)
		mvprintw(i, COLS - moon[i].length(), moon[i].c_str());
	attroff(COLOR_PAIR(1));
}
static void printMountain(void)
{
	attron(COLOR_PAIR(4));
	for (int i = 0; i < 14; ++i)
		mvprintw(LINES - 10 + i, COLS/2 - mountain[i].length(), mountain[i].c_str());
	attroff(COLOR_PAIR(4));
}

void printStaticScenery(void)
{
	printMoon();
	printMountain();
}
