#include "Nod_rosu_negru.h"

Nod_rosu_negru::Nod_rosu_negru(const Nod_rosu_negru& fromNod)
{
	info = fromNod.info;
	left = fromNod.left;
	right = fromNod.right;
	parinte = fromNod.parinte;
	culoare = new char;
	*culoare = *fromNod.culoare;
}

ostream &operator<< (ostream &stream, const Nod_rosu_negru & nod ) 
{
	stream << nod.info << nod.culoare;
	return stream;
}

istream& operator>> (istream &stream, Nod_rosu_negru &nod)
{
    stream >> nod.info;
	nod.culoare = new char;
	stream >> nod.culoare[0];
	return stream;
}
Nod_rosu_negru& Nod_rosu_negru::operator= (const Nod_rosu_negru &nodCurent)
{
	info = nodCurent.info;
	delete left;
	left = nodCurent.left;
	delete right;
	right = nodCurent.right;
	delete culoare;
	culoare = new char;
	*culoare = *nodCurent.culoare;
	return (*this);
}
