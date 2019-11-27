#ifndef ARBORE_H
#define ARBORE_H

// clasa abstracta
class Arbore 
{
//protected:
	int nr_noduri;
public:
	Arbore(){ nr_noduri = 0;};
	Arbore(int nr_noduri) : nr_noduri(nr_noduri) {}
	virtual ~Arbore() {};

	virtual int inaltime() = 0;

    virtual void inserare(int info) = 0;

    virtual void stergere(int info) = 0;

	int obtine_nr_noduri()  {
		return nr_noduri;
	}

    void schimba_nr_noduri(int nou_nr_noduri) {
        nr_noduri = nou_nr_noduri;
    }
};

#endif