#ifndef HARTA_H
#define HARTA_H

#include "Robot.h"
#include "Item.h"
#include "Trap.h"
#include<vector>
using namespace std;
struct Poz_Dest
{
	int i, j;
};

class Trap;
class Item;

class Harta
{
protected:
	char **H;
	int dim_harta;
	Poz_Dest D;
	vector <Item*> IT;
	vector <Trap*> TR;
	int nr_item;
	int nr_trap;
public:
	Harta();
	~Harta();
	bool verificare_robot();
	friend ostream & operator<<(ostream	 &os, const Harta &A);
	Poz_Dest Destinatie();
	void celula(char c, int l, int co);
	void move_robot(Robot &C);
	Item* get_item(int i);
	Trap* get_trap(int i);
	char get_celula(int i, int j);
	int get_dim();
	int get_nr_item();
	int get_nr_trap();
	friend class GestionareJoc;  //am folosit friend pentru a acesa variabilele in gestionarejoc
};

#endif // HARTA_H
