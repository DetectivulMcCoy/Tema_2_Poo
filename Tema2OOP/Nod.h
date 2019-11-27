#ifndef NOD_H
#define NOD_H

#include <iostream>

using namespace std;

class Nod
{
protected:
	int info;
	Nod* left, * right;
    Nod* parinte;

    friend class ABC;
public:
	Nod() { left = NULL; right = NULL; parinte = NULL; }
	Nod(int info) : info(info), left(NULL), right(NULL), parinte(NULL) {}
	Nod(int info, Nod* left, Nod* right) : info(info), left(left), right(right), parinte(NULL) {}
	Nod(const Nod& fromNod); ///Constructor de copiere
	~Nod() {}
	Nod& operator= (const Nod &nodCurent);
	friend istream& operator>> (istream &stream, Nod &nod);
    friend ostream &operator<< (ostream &stream, const Nod & nod );
};

#endif