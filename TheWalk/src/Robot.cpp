#include "C:\Facultate Anul 1\Semestrul II\POO\TheWalk\include\Robot.h"
#include <cstdlib>
#include <random>

Robot::Robot()
{
	A.linie = 1;
	A.coloana = 1;
	visual = 0;
	power = 0;
}

Robot::~Robot()
{
}

//verificare daca urmatoarea pozitie este valida pentru a se deplasa pe ea
//algoritmul meu de deplasare nu cred ca este cel mai eficient dar nu am avut
//alta idee

bool Robot::verificare_pozitie(Harta &B ,int i,int j, float dist_actuala)
{
    Poz_Dest Dest = B.Destinatie();
    float dist_urmatoare = sqrt( ( i - Dest.i ) * ( i - Dest.i ) + ( j - Dest.j ) * ( j - Dest.j ) );
    if( B.get_celula(i , j) != 'T' && i <= B.get_dim() && j <= B.get_dim())
        {
            if(dist_actuala > dist_urmatoare)
               {
                   return true;
               }
        }
    return false;
}

//directiile pe care le poate lua robotul

void Robot::next_position(Harta &B)
{
            Poz_Dest Dest = B.Destinatie();
            float dist_actuala = sqrt( ( A.linie - Dest.i ) * ( A.linie - Dest.i ) + ( A.coloana - Dest.j ) * ( A.coloana - Dest.j ) );
            if ( verificare_pozitie( B , A.linie+1 , A.coloana+1 , dist_actuala ) )  //mutare sudvest
			{
				A.coloana++;
				A.linie++;
			}
			else if ( A.coloana - 1 != 0 && verificare_pozitie( B , A.linie+1 , A.coloana-1 , dist_actuala ) )  //mutare sudest
			{
			    A.linie++;
				A.coloana--;
			}
			else if ( ( A.coloana - 1 != 0 && A.linie - 1 != 0 ) && verificare_pozitie( B , A.linie-1 , A.coloana-1 , dist_actuala ) )  //mutare nordest
			{
			    A.coloana--;
				A.coloana--;
			}
			else if ( A.linie - 1 != 0 && verificare_pozitie( B , A.linie-1 , A.coloana+1 , dist_actuala ) )  //mutare nordvest
			{
			    A.linie--;
				A.coloana++;
			}
			else if ( A.linie - 1 != 0 && verificare_pozitie( B , A.linie-1 , A.coloana , dist_actuala ) )    //mutare nord
			{
				A.linie--;
			}
			else if ( verificare_pozitie( B , A.linie+1 , A.coloana , dist_actuala ) )   //mutare sud
			{
				A.linie++;
			}
			else if ( A.coloana - 1 != 0 && verificare_pozitie( B , A.linie , A.coloana-1 , dist_actuala ) )  //mutare est
			{
				A.coloana--;
			}
			else if ( verificare_pozitie( B , A.linie , A.coloana+1 , dist_actuala ) )  //mutare vest
			{
				A.coloana++;
			}
			else
            {
                A.coloana = A.coloana + rand() % 1;
                A.linie = A.linie + rand() % 1;
                cout<<"da";
            }

}

Poz Robot::returnare_poz()
{
    return A;
}

void Robot::set_poz(Poz &ro)
{
    A.linie = ro.linie;
    A.coloana = ro.coloana;
}

void Robot::set_power(int i)
{
    power = i;
}

void Robot::set_visual(int i)
{
    visual = i;
}
int Robot::get_power()
{
    return power;
}

Robot& Robot::operator = (Robot &C)
{
    R = C.R;
    power = C.power;
    visual = C.visual;
    A = C.returnare_poz();
    return C;
}

void Robot::get_type()
{
    if(R == 0)
    {
        cout << "SlowRobot";
    }
    else if(R == 1)
    {
        cout << "SpeedyRobot";
    }
    else{
        cout << "FastRobot";
    }
}

SlowRobot::SlowRobot()
{
	power = 1;
	visual = 1;
	R = slow;
}


SlowRobot::~SlowRobot()
{
}

void SlowRobot::item(Item I)
{
    if(I.get_type() == 0)
	{
	    power++;
        if (visual < 4)
        {
            visual++;
            cout << "\nVisual a crescut cu 1\n";
        }
        else
        {
            cout << "\nVisual este maxim\n";
        }
        cout << "\nVisual este: " << visual << "\n";
	}
	else
    {
        cout << "\nItem-ul nu este corespunzator\n";
    }
}

void SlowRobot::trap(Trap T)
{
    if(T.get_type() == 0)
    {   if (visual > 0)
        {
            visual--;
            cout << "\nVisual a scazut cu 1\n";
        }
        else if (power > 0)
        {
            power--;
            cout << "\nPower a sczaut cu 1\n";
        }
    }
    else
    {
        cout << "\nTrap-ul nu este corespunzator\n";
    }
}

Robot* SlowRobot::Create()
{
    return new SlowRobot();
}


SpeedyRobot::SpeedyRobot()
{
	power = 2;
	visual = 2;
	R = spedy;
}


SpeedyRobot::~SpeedyRobot()
{
}

void SpeedyRobot::item(Item I)
{
    if(I.get_type() == 1)
    {
        if (power == 4 && visual < 4)
        {
            visual++;
            power = 0;
            cout << "\nVisual a crescut cu 1 pentru 4 puncte la putere, puterea a ajuns la 0\n";
        }
        else {
                power++;
                cout << "\nNu ai suficienta putere pentru 1 visual, puterea a crescut cu 1\n";
             }

    }
    else
    {
        cout << "\nItem-ul nu este corespunzator\n";
    }
}

void SpeedyRobot::trap(Trap T)
{
    if(T.get_type() == 1)
	{   cout << "\nGame over\n";
        exit(0);
	}
	else
    {
        cout << "\nTrap-ul nu este corespunzator\n";
    }
}

Robot* SpeedyRobot::Create()
{
    return new SpeedyRobot();
}

FastRobot::FastRobot()
{
	power = 3;
	visual = 3;
	R = fast;
}


FastRobot::~FastRobot()
{
}

void FastRobot::item(Item I)
{
    if(I.get_type() == 2)
	{   if (visual < 4)
        {
            visual++;
            cout << "\nVisual a crescut cu 1\n";
            cout << "\nVisual este: " << visual << "\n";
        }
        else
        {
            cout << "\nVisual este maxim\n";
        }
	}
	else
    {
        cout << "\nItem-ul nu este corespunzator\n";
    }
}

void FastRobot::trap(Trap T)
{
    if(T.get_type() == 2)
	{
	    visual = 1;
	    cout << "\nVisual a ajuns la 1\n";
	}
	else
    {
        cout << "\nTrap-ul nu este corespunzator\n";
    }
}

Robot* FastRobot::Create()
{
    return new FastRobot();
}

//pentru alegerea robotului in main

Robot* RobotFactory::Factory(int i)
{
    CreateRobot create[] = {
            SlowRobot::Create,
            SpeedyRobot::Create,
            FastRobot::Create
    };
    return create[ i ]();
}
