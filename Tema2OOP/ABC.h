#ifndef ABC_H
#define ABC_H

#include "Nod.h"
#include "Arbore.h"

#include <algorithm>
#include <iostream>
#include <stddef.h>

class ABC : public Arbore 
{
private:
	Nod* rad;

	int inaltime(Nod* nod);

	int calculeaza_nr_noduri(Nod* nod);

	void inserareArbRad( Nod* &rad, int info );
	void inordine(ostream& stream, Nod* rad );
	void stergereArbRad(Nod* &nod, int info);
	Nod* maxValueNode(Nod* nod);

public:
	ABC(): Arbore(){ rad = NULL;}; 
	ABC(Nod* rad) : Arbore(calculeaza_nr_noduri(rad)), rad(rad) {}

	ABC( const ABC &dinArb ); ///Constructor de copiere

	virtual ~ABC() { stergere_postorder(rad); }

	virtual int inaltime() 
	{
		return inaltime(rad);
	}
	virtual void inserare(int info); 
	void inordine(ostream &stream);
	virtual void stergere(int info);

    void stergere_postorder(Nod* rad);
	void inserareInord( Nod* nod );

	ABC& operator= (const ABC &arbCurent);

    friend ostream &operator<< (ostream &stream, ABC & arbore) 
	{
        stream << "Arborele contine " << arbore.obtine_nr_noduri() << " noduri" << endl; 
        stream << "Arbore inordine  ";
        arbore.inordine(stream);
        stream << endl;
        stream << "Arbore are o inaltime egala cu " << arbore.inaltime() << endl;
		return stream;
    }

    friend istream &operator>> (istream &stream, ABC & arbore) 
	{
        int nr_noduri;
        stream >> nr_noduri;
        for (int i=0;i<nr_noduri;++i)
        {
            int info_nod;
            stream >> info_nod;
            arbore.inserare(info_nod);
        }
		return stream;
    }
};

#endif