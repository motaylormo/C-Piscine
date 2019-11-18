#include "Game.class.hpp"
#include "Bullet.class.hpp"
#include "Enemy.class.hpp"
#include <random>
#include <unistd.h>
#include <iostream>

void printStaticScenery(void);

bool	collision(Entity ent1, Entity ent2)
{
	if ((ent1.getX() == ent2.getX() ||
		 ent1.getX() == ent2.getX() + 1)
		&&
		(ent1.getY() == ent2.getY() ||
		 ent1.getY() == ent2.getY() + 1)
		)
	{
		return (true);
	}
	return (false);
}

int	runGame(void)
{
	Game thegame;
	int key;
	int score = 0;
	int i = 0;
	int j = 0;
	//Random Generator
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dis(14, thegame.maxY() - 20); // distribution range;
	std::uniform_int_distribution<int> disX(COLS - 20, COLS -2);
	// Usage dis(gen);

	Enemy enemySwarm[5];
	
	// init swarm
	for (int i = 0; i < 5; i++)
	{
		enemySwarm[i] = Enemy(disX(gen), dis(gen)); // Random X Y
	}

	// Collision logic:
	// Loop through array of player bullets, then check against enemy coordinates
	// If bullet coordinate matches the enemy 'hitbox' then
	// set the deactivate bullet and enemy;
	
	while (1)
	{
		refresh();
		usleep(15000);
		key = getch();
		clear();
		printw("Score: %d", score);
		printStaticScenery();
		// Moving Enemies
		for (i = 0; i < 5; i++)
		{
			if (enemySwarm[i]._isAlive && enemySwarm[i].getX() > enemySwarm[i].getSize())
			{
				// Check colision between player and enemies
				if (collision(enemySwarm[i], thegame._player) || collision(thegame._player, enemySwarm[i]))
				{
					enemySwarm[i]._isAlive = false;
					enemySwarm[i]._a._isActive = false;
					return (score);
				}
				else
					enemySwarm[i].flyRev(0);
				// Enemy bullets collision with player
				if (collision(enemySwarm[i]._a , thegame._player))
				{
					enemySwarm[i]._a._isActive = false;
					score -= 10;
				}
			} // If enemy is dead the turn them back on
			else
			{
				enemySwarm[i]._isAlive = true;
				enemySwarm[i]._a._isActive = true;
				enemySwarm[i].setCoord(disX(gen),dis(gen));
			}
		}
		thegame.arrowKey(key);
		if (key == 27)
			return (score);
		if (key == 32)
			thegame.shoot();
		for (i = 0; i < 5; i++)
		{
			// check if bullet collides with enemies
			if (thegame._bulletArr[i]._isActive == true)
			{
				for (j = 0 ; j < 5; j++)
				{
					if (collision(thegame._bulletArr[i], enemySwarm[j]) ||
						collision(enemySwarm[j], thegame._bulletArr[i]))
					{
						thegame._bulletArr[i]._isActive = false;
						enemySwarm[j]._isAlive = false;
						enemySwarm[j]._a._isActive = false;
						score += enemySwarm[j].getPoints();
					}
				}
			}
			// moving the bullets
			if (thegame._bulletArr[i]._isActive == TRUE)
				thegame._bulletArr[i].fly(thegame.maxX());
		}
	}
}

int main(void)
{
	int score = runGame();
	std::cout << "Game over! Your score was " << score << "!" << std::endl;
	return (0);
}
