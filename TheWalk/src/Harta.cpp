#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\Harta.h"
#include<random>
#include<time.h>
#include<cstring>
#include<cmath>

//initializare harti si in plus punem in vectorul de trap si item
//pozitiile pentru fiecare

Harta::Harta()
{
    const char gol = '_';
	dim_harta = 15;
	nr_trap = dim_harta * 2;
	nr_item = dim_harta * 2;
	int tr = nr_trap, it = nr_item;
	try
	{
		H = new char*[dim_harta+2];
	}
	catch (bad_alloc)
	{
		cout << "Eroare la initializarea matrici";
	}
	for (int i = 1;i <= dim_harta+1;i++)
	{
		try
		{
			H[i] = new char[dim_harta+2];
		}
		catch (bad_alloc)
		{
			cout << "Eroare la initializarea matrici";
		}
	}
	for (int i = 1;i <= dim_harta+1;i++)
	{
		for (int j = 1;j <= dim_harta+1;j++)
		{
			H[i][j] = gol;
		}
	}
	int i, j;
	H[1][1] = 'R';

    srand(time(NULL));
	IT.resize(nr_item);
    int k = 1;
	while (it != 0)
	{


		i = rand() % dim_harta+1;
		j = rand() % dim_harta+1;
		if (i != 1 || j != 1)
		{
            H[i][j] = 'I';
		}
		IT[k] = ItemFactory::RandomFactory();
		IT[k]->Pozitie_Item(i, j);
		k++;
		it--;

	}
	TR.resize(nr_trap);
	k = 1;
	while (tr != 0)
	{


		i = rand() % dim_harta+1;
		j = rand() % dim_harta+1;
		if (i != 1 || j != 1)
		{
			H[i][j] = 'T';
		}
		TR[k] = TrapFactory::RandomFactory();
		TR[k]->Pozitie_Trap(i, j);
		k++;
		tr--;
	}
	D.i = rand() % dim_harta+1;
	D.j = rand() % dim_harta+1;
	H[D.i][D.j] = 'D';
}


Harta::~Harta()
{
	for (int i = 1;i <= dim_harta;i++)
	{
		delete[] H[i];
	}
	delete[] H;
}

//verificam daca robotul a ajuns la destinatie

bool Harta::verificare_robot()
{
	if (H[D.i][D.j] == 'R')
		return true;
	return false;
}



ostream &operator<<(ostream & os, const Harta & A)
{
	int i, j;
	for (i = 1;i <= A.dim_harta;i++)
	{
		for (j = 1;j <= A.dim_harta;j++)
		{
			os << A.H[i][j] << ' ';

		}
		os << "\n";
	}
	return os;
}

Poz_Dest Harta::Destinatie()
{
    return D;
}

void Harta::celula(char c, int l, int co)
{
    H[l][co] = c;
}

void Harta::move_robot(Robot &C)
{
    Poz p = C.returnare_poz();
    H[p.linie][p.coloana] = 'R';
}
Item* Harta::get_item(int i)
{
    return IT[i];
}

Trap* Harta::get_trap(int i)
{
    return TR[i];
}

char Harta::get_celula(int i, int j)
{
    return H[i][j];
}

int Harta::get_dim()
{
    return dim_harta;
}

int Harta::get_nr_item()
{
    return nr_item;
}

int Harta::get_nr_trap()
{
    return nr_trap;
}
