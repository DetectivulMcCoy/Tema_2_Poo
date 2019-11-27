#ifndef NOD_ROSU_NEGRU_H
#define NOD_ROSU_NEGRU_H

//#include "Arbore_bicolor.h"
#include "Nod.h"

class Nod_rosu_negru : public Nod
{
private:
	char* culoare;
    friend class Arbore_bicolor;
public:
	Nod_rosu_negru() { left = NULL; right = NULL; parinte = NULL; culoare = NULL;}
	Nod_rosu_negru(int info, Nod* left, Nod* right, char* culoare) : Nod(info, left, right), culoare(culoare) {}
	~Nod_rosu_negru() {}

	Nod_rosu_negru(const Nod_rosu_negru& fromNod); ///Constructor de copiere
	Nod_rosu_negru& operator= (const Nod_rosu_negru &nodCurent);
	friend istream& operator>> (istream &stream, Nod_rosu_negru &nod);
    friend ostream &operator<< (ostream &stream, const Nod_rosu_negru & nod );
};

#endif