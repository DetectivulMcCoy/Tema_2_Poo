#include "Nod.h"

Nod::Nod(const Nod& fromNod)
{
	info = fromNod.info;
	left = new Nod;
	left = fromNod.left;
	right = new Nod;
	right = fromNod.right;
	parinte = new Nod;
	parinte = fromNod.parinte;
}

ostream &operator<< (ostream &stream, const Nod & nod ) 
{
	try
	{
		if (&nod == NULL)
			throw 1;

		stream << nod.info;
		return stream;
	}
	catch (int x)
	{
		cout << "Eroare alocare nod scriere ostream; nod nealocat";
		cout << endl << "cod eroare " << x << endl;
	}
	catch (...)
	{
		cout <<endl << "Eroare nedefinita alocare nod scriere ostream" << endl;
	}
}
istream& operator>> (istream &stream, Nod &nod)
{
	try
	{
		if (&nod == NULL)
			throw 2;

		stream >> nod.info;
		return stream;
	}
	catch (int x)
	{
		cout << "Eroare alocare nod citire istream; nod nealocat";
		cout << endl << "cod eroare " << x << endl;
	}
	catch (...)
	{
		cout << endl << "Eroare nedefinita alocare nod citire istream" << endl;
	}
   
}
Nod& Nod::operator= (const Nod &nodCurent)
{
	info = nodCurent.info;
	delete left;
	left = nodCurent.left;
	delete right;
	right = nodCurent.right;
	delete parinte;
	parinte = nodCurent.parinte;
	return (*this);
}
