#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\GestionareJoc.h"
#include<cstdlib>


GestionareJoc::GestionareJoc()
{
}


GestionareJoc::~GestionareJoc()
{
}

//metoda care gestioneaza o runda de joc si verifica daca pozitia robotului
//este pe un item sau trap

void GestionareJoc::runda_joc(Robot *C, Harta &B)
{
    int nr_runda=1;
    cout << "\n\nHarta initiala este: \n\n";
    cout << B;
	do
	{   cout << "\n\nHarta din runda " << nr_runda << " este\n\n";
        nr_runda++;
        Trap* T;
        Item* I;
        Poz_Item Ite;
        Poz_Trap Tra;
        Poz p = C->returnare_poz();
        B.celula('0', p.linie, p.coloana);
        C->next_position(B);
        B.move_robot(*C);
        for(int k = 1;k <= B.nr_item;k++)
        {
            Poz Rob = C->returnare_poz();
            I = B.get_item(k);
            T = B.get_trap(k);
            Ite=I->returneaza_poz_it();
            Tra=T->returneaza_poz_tr();
            if(Rob.linie == Ite.linie && Rob.coloana == Ite.coloana)
            {
                C->item(*I);
            }
            else if(Rob.linie == Tra.linie && Rob.coloana == Tra.coloana)
            {
                C->trap(*T);
            }
        }
        cout << B << "\n";
        system("pause");
	}while (B.verificare_robot() != true);
	cout << "\n\nRobotul a ajuns la destinatie\n\n";
	exit(0);
}


