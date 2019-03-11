#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\Item.h"
#include<random>

Item::Item()
{
	PI.linie = -1;
	PI.linie = -1;
}


Item::~Item()
{
}

void Item::Pozitie_Item(int i, int j)
{
	PI.linie = i;
	PI.coloana = j;
}

Poz_Item Item::returneaza_poz_it()
{
    return PI;
}

Item& Item::operator=(Item &A)
{
    I = A.I;
    PI = A.returneaza_poz_it();
    return A;
}

tip_item Item::get_type()
{
    return I;
}

SlowRobotItem::SlowRobotItem()
{
    I = slowItem;
}

SlowRobotItem::~SlowRobotItem()
{
    //dtor
}

Item* SlowRobotItem::Create()
{
   return new SlowRobotItem();
}



SpeedyRobotItem::SpeedyRobotItem()
{
    I = spedyItem;
}

SpeedyRobotItem::~SpeedyRobotItem()
{
    //dtor
}

Item *SpeedyRobotItem::Create()
{
   return new SpeedyRobotItem();
}

FastRobotItem::FastRobotItem()
{
    I = fastItem;
}

FastRobotItem::~FastRobotItem()
{
    //dtor
}

Item* FastRobotItem::Create()
{
   return new FastRobotItem();
}

//pentru a genera itemele random pe harta

Item* ItemFactory::RandomFactory()
{
   CreateRandom create[] = {
            SlowRobotItem::Create,
            SpeedyRobotItem::Create,
            FastRobotItem::Create
    };
    int dim = sizeof(create)/sizeof(*create);
    return create[ rand() % dim ]();
}
