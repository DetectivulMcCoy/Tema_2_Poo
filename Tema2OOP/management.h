#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "Arbore_bicolor.h"

using namespace std;

class Management 
{
    private:
        int n; //dimensiunea vectorului
        Arbore_bicolor *t; //pointer catre zona de memorie alocata dinamic
    public:
		Management();
        Management(int n); //Constructor
        Management(const Management &v); //Constructor de copiere
        ~Management(); //Destructor
        void citire();
        void afisare();
		friend istream & operator>>(istream &, Management &);
		friend ostream& operator <<(ostream &, Management &);
};

#endif //MANAGEMENT_H
