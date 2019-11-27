#include "ABC.h"

using namespace std;

ABC::ABC( const ABC &dinArb )
{
	rad = NULL;
	Nod *nodCurent = dinArb.rad;
	inserareInord( nodCurent );
}
int ABC::inaltime(Nod* nod) 
{
    if (!nod) 
    {
        return 0;
    }
    return max(inaltime(nod->left), inaltime(nod->right)) + 1;
}

int ABC::calculeaza_nr_noduri(Nod* nod) 
{
    if (!nod) 
    {
        return 0;
    }
    return calculeaza_nr_noduri(nod->left) + calculeaza_nr_noduri(nod->right) + 1;
}
void ABC::inserareInord( Nod* nod )
{ 
    if (nod != NULL) 
    { 
        inserareInord( nod->left ); 
        inserare( nod->info ); 
        inserareInord( nod->right );  
    } 
}

ABC& ABC::operator= (const ABC &arbCurent)
{
	Nod *nodCurent = arbCurent.rad;
	inserareInord( nodCurent );
	return (*this);
}
void ABC::inserareArbRad(Nod* &nod, int info ) 
{ 
    // Arbore vid
    if (nod == NULL) 
	{
		nod = new Nod;
		nod->info = info; 
		nod->left = nod->right = NULL;
        schimba_nr_noduri(obtine_nr_noduri() + 1);
		return;
	}
	// Arbore nevid
   if (info < nod->info) 
        inserareArbRad(nod->left, info); 
    else if (info > nod->info) 
        inserareArbRad(nod->right, info);  
 }

void ABC::inserare( int info ) 
{ 
    //Nod* p = rad;
	inserareArbRad ( rad, info );
}

void ABC::inordine(ostream &stream, Nod* nod )
{ 
    if (nod != NULL) 
    { 
        inordine(stream, nod->left); 
        stream << nod->info << " "; 
        inordine(stream, nod->right);  
    } 
}

void ABC::inordine(ostream &stream)
{
	//Nod* p = rad;
	inordine(stream, rad );
}

Nod* ABC::maxValueNode(Nod* nod) 
{ 
    Nod* current = nod; 
  
    // cel mai din dreapta nod
	while (current && current->right != NULL) 
		current = current->right; 
  
    return current; 
}

void ABC::stergereArbRad(Nod* &nod, int info) 
{ 
    if (nod == NULL) 
		return; 
  
    // cheia(de sters) mai mica decat cheia radacinii -> se afla in subarborele stang
    if (info < nod->info) 
        stergereArbRad(nod->left, info); 
    // cheia(de sters) mai mare decat cheia radacinii -> se afla in subarborele drept
    else if (info > nod->info) 
        stergereArbRad(nod->right, info); 
    // cheia(de sters) egala cheia radacinii
    else
    {
        // root cu cel mult un descendent
        if (nod->left == NULL && nod->right == NULL) {
            delete nod;
            nod = NULL;
            schimba_nr_noduri(obtine_nr_noduri() - 1);
            return;
        }
        else if (nod->left == NULL) 
        { 
            Nod *temp = nod->right; 
            delete nod; 
            nod = temp;
            schimba_nr_noduri(obtine_nr_noduri() - 1);
			return;
        } 
        else if (nod->right == NULL) 
        { 
            Nod *temp = nod->left; 
            delete nod;
            nod = temp;
            schimba_nr_noduri(obtine_nr_noduri() - 1);
			return;
        }
 		// varianta predecesor
		// root cu exact doi descendenti: cautam predecesorul in inordine (cel mai mare din subarborele stang) 
		Nod* temp = maxValueNode(nod->left);

        // copiem in radacina cheia predecesorul in inordine
        nod->info = temp->info;
 		// stergem predecesorul in inordine
		stergereArbRad(nod->left, temp->info);
    } 
}

void ABC::stergere( int info)
{
	Nod* p = rad;
	stergereArbRad(p, info);
}

void ABC::stergere_postorder(Nod* nod) 
{
    if (nod == NULL) {
        return;
    }
    stergere_postorder(nod->left);
    stergere_postorder(nod->right);
    nod->left = NULL;
    nod->right = NULL;
    nod->parinte = NULL;
    delete nod;
}