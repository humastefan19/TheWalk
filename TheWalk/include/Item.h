#ifndef ITEM_H
#define ITEM_H
#include<iostream>
using namespace std;
enum tip_item
{
	slowItem, spedyItem, fastItem
};

struct Poz_Item
{
	int linie;
	int coloana;
};

class Robot;
class SlowRobot;
class SpeedyRobot;
class FastRobot;

class Item
{
protected:
	tip_item I;
	Poz_Item PI;
public:
	Item();
	~Item();
	void Pozitie_Item(int i, int j);
	Poz_Item returneaza_poz_it();
    Item& operator =(Item &A);
    tip_item get_type();
    friend class GestionareJoc;

};

class SlowRobotItem : public Item
{
   public:
	SlowRobotItem();
	~SlowRobotItem();
	static Item* Create();

};


class SpeedyRobotItem : public Item
{

public:
	SpeedyRobotItem();
	~SpeedyRobotItem();
	static Item* Create();

};

class FastRobotItem : public Item
{
public:
	FastRobotItem();
	~FastRobotItem();
	static Item* Create();
};

//ItemFactory creeaza un vector de metode Create din fiecare tip de item
//pentru a creea noi iteme

class ItemFactory
{
    typedef Item* (*CreateRandom)();
public:
    static Item* RandomFactory();
};
#endif // ITEM_H
