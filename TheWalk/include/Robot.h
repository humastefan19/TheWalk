#ifndef ROBOT_H
#define ROBOT_H
#include "Item.h"
#include "Trap.h"
#include "Harta.h"
#include<iostream>
#include<cmath>
using namespace std;

class Harta;

enum tip_robot
{
	slow, spedy, fast
};
struct Poz
{
	int linie, coloana;
};

class Robot
{
protected:
	tip_robot R;
	int power;
	int visual;
	Poz A;
public:
	Robot();
	~Robot();
	virtual void item(Item I) = 0;
	virtual void trap(Trap T) = 0;
	bool verificare_pozitie(Harta &B,int i, int j, float dist_actuala);
	void next_position(Harta &B);
	Robot& operator=(Robot& C);
	Poz returnare_poz();
	void set_poz(Poz &ro);
	void set_power(int i);
	void set_visual(int i);
	void get_type();
	int get_power();
	int get_visual();
	friend class Harta;
};

class SlowRobot :
	public Robot
{
public:
	SlowRobot();
	~SlowRobot();
	void item(Item I);
	void trap(Trap T);
	static Robot *Create();
};


class SpeedyRobot :
	public Robot
{
public:

	SpeedyRobot();
	~SpeedyRobot();
    void item(Item I);
	void trap(Trap T);
	static Robot *Create();
};

class FastRobot :
	public Robot
{
public:
	FastRobot();
	~FastRobot();
	void item(Item I);
	void trap(Trap T);
	static Robot *Create();
};

//RobotFactory creaza in vector de metode create din ficare tip de robot
//pentru a alege tipul de robot cu care vrem sa jucam

class RobotFactory
{
    typedef Robot* (*CreateRobot)();
public:
    static Robot* Factory(int i);
};

#endif // ROBOT_H
