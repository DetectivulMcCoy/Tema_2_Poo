#ifndef ARBORE_BICOLOR_H
#define ARBORE_BICOLOR_H

#include "ABC.h"
#include "Nod.h"
#include "Arbore.h"
#include "Nod_rosu_negru.h"

#include <iostream>

class Arbore_bicolor : public Arbore 
{
private:
	Nod_rosu_negru* rad;
    // santinela este representata printr-un Nod care contine info -1 si este de culoare neagra
    Nod_rosu_negru* santinela;
	
	virtual int adancime(Nod_rosu_negru* rad);

	int calculeaza_nr_noduri(Nod_rosu_negru* nod);

    void preorder(ostream &stream, Nod_rosu_negru* nod);

    void delete_fixup(Nod_rosu_negru * & rad, Nod_rosu_negru * &fi);

    // rotatii implementate din https://www.geeksforgeeks.org/red-black-tree-set-3-delete-2/
    void rotatie_stanga(Nod_rosu_negru* & rad, Nod_rosu_negru* & t);

    void rotatie_dreapta(Nod_rosu_negru* & rad, Nod_rosu_negru* & t);

    void adauga_santinela(Nod_rosu_negru* rad);

    void stergere_postorder(Nod_rosu_negru* rad);
	void inserarePreord( Nod_rosu_negru* nod );

public:
    Arbore_bicolor(): Arbore(){ rad = NULL; santinela = new Nod_rosu_negru(-1, NULL, NULL, (char*)"N"); }; 

	Arbore_bicolor(Nod_rosu_negru* rad) : Arbore(calculeaza_nr_noduri(rad)), rad(rad), santinela(new Nod_rosu_negru(-1, NULL, NULL, (char*)"N"))
	{
		// ne asiguram ca toate foile arborelui egale cu NIL sunt defapt egale cu santinela.
		adauga_santinela(rad);
	}
	Arbore_bicolor( const Arbore_bicolor &dinArb ); ///Constructor de copiere

    // Cum am adaugat santinela, aceastea nu trebuie stearsa de mai multe ori.
	virtual ~Arbore_bicolor() 
	{
        stergere_postorder(rad);
        santinela->parinte = NULL;
        delete santinela;
    }
	// Clasa derivata trebuie sa contina o functie virtuala prin care inaltimea arborelui bicolor sa
	// fie identificata prin Adancimea neagra a radacinii.
	virtual int inaltime() 
	{
		return adancime(rad);
	}

    void preorder(ostream &stream);

    virtual void inserare(int info);

    virtual void stergere(int info);

	Arbore_bicolor& operator= (const Arbore_bicolor &arbCurent);

    friend ostream &operator<< (ostream &stream, Arbore_bicolor & arbore) 
	{
        stream << "Arborele contine " << arbore.obtine_nr_noduri() << " noduri" << endl; 
        stream << "Arbore preordine  ";
        arbore.preorder(stream);
        stream << endl;
        stream << "Arbore are o adancime egala cu " << arbore.inaltime() << endl;
		return stream;
    }

    friend istream &operator>> (istream &stream, Arbore_bicolor & arbore) 
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