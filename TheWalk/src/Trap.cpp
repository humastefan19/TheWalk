#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\Trap.h"
#include <random>

Trap::Trap()
{
}


Trap::~Trap()
{
}

void Trap::Pozitie_Trap(int i, int j)
{
	PT.linie = i;
	PT.coloana = j;
}

Poz_Trap Trap::returneaza_poz_tr()
{
    return PT;
}

Trap& Trap::operator =(Trap &A)
{
    T = A.T;
    PT = A.returneaza_poz_tr();
    return A;
}

tip_trap Trap::get_type()
{
    return T;
}
SlowRobotTrap::SlowRobotTrap()
{
    T = slowTrap;
}

SlowRobotTrap::~SlowRobotTrap()
{
    //dtor
}

Trap *SlowRobotTrap::Create()
{
    return new SlowRobotTrap();
}


SpeedyRobotTrap::SpeedyRobotTrap()
{
    T = spedyTrap;
}

SpeedyRobotTrap::~SpeedyRobotTrap()
{
    //dtor
}

Trap *SpeedyRobotTrap::Create()
{
    return new SpeedyRobotTrap();
}

FastRobotTrap::FastRobotTrap()
{
    T = fastTrap;
}

FastRobotTrap::~FastRobotTrap()
{
    //dtor
}

Trap *FastRobotTrap::Create()
{
    return new FastRobotTrap();
}

//metoda din TrapFactory care genereaza Trap-uri

Trap *TrapFactory::RandomFactory()
{
    CreateRandom create[] = {
            SlowRobotTrap::Create,
            SpeedyRobotTrap::Create,
            FastRobotTrap::Create
    };
    int dim = sizeof(create)/sizeof(*create);
    return create[ rand() % dim ]();
}
