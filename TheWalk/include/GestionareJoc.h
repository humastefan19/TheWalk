#ifndef GESTIONAREJOC_H
#define GESTIONAREJOC_H

#include "Robot.h"
#include "Item.h"
#include "Trap.h"
#include "Harta.h"
#include <iostream>
class GestionareJoc
{
    Harta M;
public:
	GestionareJoc();
	~GestionareJoc();
	void runda_joc(Robot *C, Harta &B);
};



#endif // GESTIONAREJOC_H
