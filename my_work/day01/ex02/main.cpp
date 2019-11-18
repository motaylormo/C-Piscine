#include "ZombieEvent.hpp"

int	main(void)
{
	ZombieEvent ze;

	Zombie *handmade = ze.newZombie("one zombie");
	handmade->announce();
	Zombie *random = ze.randomChump();
	random->announce();

}