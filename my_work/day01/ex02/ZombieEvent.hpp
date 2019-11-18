#include "Zombie.hpp"

class ZombieEvent {

public:

	typedef ZombieEvent		t;

	ZombieEvent(void);
	~ZombieEvent(void);

	void	setZombieType(Zombie *z, std::string type);
	Zombie*	newZombie(std::string name);
	Zombie*	randomChump(void);

private:


};