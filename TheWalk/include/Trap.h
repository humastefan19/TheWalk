#ifndef TRAP_H
#define TRAP_H
#include"Robot.h"
enum tip_trap
{
	slowTrap, spedyTrap, fastTrap
};

struct Poz_Trap
{
	int linie;
	int coloana;
};
class Robot;
class Trap
{
protected:
	tip_trap T;
	Poz_Trap PT;
public:
	Trap();
	~Trap();
	void Pozitie_Trap(int i, int j);
	Poz_Trap returneaza_poz_tr();
	Trap& operator =(Trap &A);
	tip_trap get_type();
};

class SlowRobotTrap : public Trap
{
    public:
        SlowRobotTrap();
        ~SlowRobotTrap();
        static Trap* Create();

};


class SpeedyRobotTrap : public Trap
{
    public:
        SpeedyRobotTrap();
        ~SpeedyRobotTrap();
        static Trap* Create();


};

class FastRobotTrap : public Trap
{
    public:
        FastRobotTrap();
        ~FastRobotTrap();
        static Trap *Create();

};

//TrapFactory creeaza un vector de metode Create din fiecare tip de trap
//pentru a creea noi trap-uri

class TrapFactory
{
    typedef Trap* (*CreateRandom)();
public:
    static Trap* RandomFactory();
};

#endif // TRAP_H
