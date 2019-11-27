#include "Arbore_bicolor.h"

#include <cstring>

using namespace std;

Arbore_bicolor::Arbore_bicolor( const Arbore_bicolor &dinArb )
{
	rad = NULL;
	Nod_rosu_negru *nodCurent = dinArb.rad;
	inserarePreord( nodCurent );
}
int Arbore_bicolor::adancime(Nod_rosu_negru* rad) 
{
    Nod_rosu_negru* curent = (Nod_rosu_negru*)rad->left;
    int resultat = 1;
    while (curent) 
    {
        if (curent->culoare == "N") 
        {
            resultat++;
        }
        curent = (Nod_rosu_negru*)curent->left;
    }
    return resultat;
}

int Arbore_bicolor::calculeaza_nr_noduri(Nod_rosu_negru* nod) 
{
    if (!nod) 
    {
        return 0;
    }
    return calculeaza_nr_noduri((Nod_rosu_negru*)nod->left) +
        calculeaza_nr_noduri((Nod_rosu_negru*)nod->right) + 1;
}

void Arbore_bicolor::preorder(ostream& stream)
{
	//Nod* p = rad;
	return preorder(stream, rad);
}

void Arbore_bicolor::preorder(ostream& stream, Nod_rosu_negru* nod)
{ 
    if (nod != NULL) 
    { 
        stream << nod->info << nod->culoare << " "; 
        preorder(stream, (Nod_rosu_negru *)nod->left); 
        preorder(stream, (Nod_rosu_negru *)nod->right);
    }
}

void Arbore_bicolor::inserarePreord( Nod_rosu_negru* nod )
{ 
    if (nod != NULL) 
    { 
        inserare( nod->info ); 
        inserarePreord( (Nod_rosu_negru*)nod->left ); 
        inserarePreord( (Nod_rosu_negru*)nod->right );  
    } 
}

Arbore_bicolor& Arbore_bicolor::operator= (const Arbore_bicolor &arbCurent)
{
	Nod *nodCurent = arbCurent.rad;
	inserarePreord( (Nod_rosu_negru*)nodCurent );
	return (*this);
}

void Arbore_bicolor::inserare(int info) {

	try {

		Nod_rosu_negru* q, * b, * u;
		bool gasit, inserat;
		q = new Nod_rosu_negru(info, santinela, santinela, (char*)"R");
		// daca arborele este vid
		if (rad == NULL) {
			rad = q;
			schimba_nr_noduri(obtine_nr_noduri() + 1);
		}
		else
		{
			// caută în arbore un nod cu cheia x
			Nod_rosu_negru* t = rad;
			gasit = false; inserat = false;
			while (!gasit && !inserat) {
				if (t->info == info) {
					gasit = true;
					delete q;
				}
				else if (t->info < info) {
					if (t->right == santinela) {
						t->right = q;
						q->parinte = t;
						inserat = true;
					}
					else {
						t = (Nod_rosu_negru*)t->right;
					}
				}
				else {
					if (t->left == santinela) {
						t->left = q;
						q->parinte = t;
						inserat = true;
					}
					else {
						t = (Nod_rosu_negru*)t->left;
					}
				}
			}
			if (inserat) {
				//am inserat  nodul q cu cheia x; t este nodul tată
				//nodul q este roşu; restaurăm, dacă este cazul, arborele
				while (q != rad && t->culoare == "R")
				{
					b = (Nod_rosu_negru*)t->parinte;
					if (b == NULL) // t este radacina arborelui
					{
						t->culoare = (char*)"N";
					}
					else
					{
						if (t == b->left)
						{
							u = (Nod_rosu_negru*)b->right;
							if (u && u->culoare == "R") // cazul 1
							{
								t->culoare = (char*)"N";
								u->culoare = (char*)"N";
								b->culoare = (char*)"R";
								q = b;
								t = (Nod_rosu_negru*)q->parinte;
							}
							else
							{
								if (q == t->right) // cazul 3 
								{
									// rotatie stanga
									b->left = q;
									q->parinte = b;
									t->right = q->left;
									Nod_rosu_negru* q_left = (Nod_rosu_negru*)q->left;
									q_left->parinte = t;
									q->left = t;
									t->parinte = q;
									q = t;
									t = (Nod_rosu_negru*)q->parinte;
								}
								else
								{ // cazul 2
									t->culoare = (char*)"N";
									b->culoare = (char*)"R";
									// rotatie dreapta
									t->parinte = b->parinte;
									Nod_rosu_negru* b_parinte = (Nod_rosu_negru*)b->parinte;
									if (b->parinte == NULL)
									{
										rad = t;
									}
									else if (b_parinte->left == b)
									{
										b_parinte->left = t;
									}
									else
									{
										b_parinte->right = t;
									}
									b->left = t->right;
									Nod_rosu_negru* t_right = (Nod_rosu_negru*)(t->right);
									if (t_right) {
										t_right->parinte = b;
									}
									t->right = b;
									b->parinte = t;
								}
							}
						}
						// caz simetric, t este b->right
						else
						{
							u = (Nod_rosu_negru*)b->left;
							if (u && u->culoare == "R") // cazul 1
							{
								t->culoare = (char*)"N";
								u->culoare = (char*)"N";
								b->culoare = (char*)"R";
								q = b;
								t = (Nod_rosu_negru*)q->parinte;
							}
							else
							{
								if (q == t->left) // cazul 3
								{
									// rotatie dreapta
									b->right = q;
									q->parinte = b;
									t->left = q->right;
									Nod_rosu_negru* q_right = (Nod_rosu_negru*)q->right;
									q_right->parinte = t;
									q->right = t;
									t->parinte = q;
									q = t;
									t = (Nod_rosu_negru*)q->parinte;
								}
								t->culoare = (char*)"N";
								b->culoare = (char*)"R";
								// rotatie stanga
								t->parinte = b->parinte;
								Nod_rosu_negru* b_parinte = (Nod_rosu_negru*)b->parinte;
								if (b->parinte == NULL)
								{
									rad = t;
								}
								else if (b_parinte->left == b)
								{
									b_parinte->left = t;
								}
								else
								{
									b_parinte->right = t;
								}
								b->right = t->left;
								Nod_rosu_negru* t_left = (Nod_rosu_negru*)(t->left);
								if (t_left) {
									t_left->parinte = b;
								}
								t->left = b;
								b->parinte = t;
							}
						}
					}
				}
				schimba_nr_noduri(obtine_nr_noduri() + 1);
			}
		}
	}
	catch (...)
	{
		cout << endl << "Eroare inserare in arbore bicolor!" << endl;
	}
}

void Arbore_bicolor::stergere(int info) {

	try
	{
		Nod_rosu_negru* q, * f, * maximum;
		// cauta in arbore un nod q cu cheia x
		q = rad;
		while (q != santinela && q->info != info) {
			if (q->info < info)
			{
				q = (Nod_rosu_negru*)q->right;
			}
			else
			{
				q = (Nod_rosu_negru*)q->left;
			}
		}
		if (q == santinela) {
			cout << "Nodul cu cheia " << q << "nu se gaseste in arbore" << endl;
		}
		else
		{
			if (q->left != santinela && q->right != santinela) {
				// q are doi fii;
				// determin nodul cu cheia maximă din stânga
				maximum = (Nod_rosu_negru*)q->left;
				while (maximum->right != santinela)
					maximum = (Nod_rosu_negru*)maximum->right;
				q->info = maximum->info;
				q = maximum;
			}
			if (q->left != santinela) {
				//acum nodul q are cel mult un fiu indicat de f
				f = (Nod_rosu_negru*)q->left;
			}
			else {
				f = (Nod_rosu_negru*)q->right;
			}
			f->parinte = q->parinte;


			//şterg nodul q; chiar dacă fiul este NULL, câmpul p va fi definit
			if (q == rad) {
				rad = f;
			}
			else {
				Nod_rosu_negru* q_parinte = (Nod_rosu_negru*)q->parinte;
				if (q == q_parinte->left) {
					q_parinte->left = f;
				}
				else {
					q_parinte->right = f;
				}
			}
			if (q->culoare == "N") {
				delete_fixup(rad, f);
			}
			q->left = NULL;
			q->right = NULL;
			delete q;
			schimba_nr_noduri(obtine_nr_noduri() - 1);
		}
	}
	catch (...)
	{
		cout << endl << "Eroare stergere din arbore bicolor!" << endl;
	}
}

void Arbore_bicolor::delete_fixup(Nod_rosu_negru * & rad, Nod_rosu_negru * &f)
{
	try
	{
		Nod_rosu_negru* u, * t;
		while (f != rad && f->culoare == "N") {
			t = (Nod_rosu_negru*)f->parinte;
			if (f == t->left) {
				u = (Nod_rosu_negru*)t->right;
				Nod_rosu_negru* u_left = (Nod_rosu_negru*)u->left;
				Nod_rosu_negru* u_right = (Nod_rosu_negru*)u->right;
				if (u->culoare == "R")
				{
					u->culoare = (char*)"N";
					t->culoare = (char*)"R";
					rotatie_stanga(rad, t);
					u = (Nod_rosu_negru*)t->right;
				}
				else if (u_left->culoare == "N" && u_right->culoare == "N") // cazul 2.1 din link
				{
					u->culoare = (char*)"R";
					f = t;
				}
				else // cazul 2.2 din link
				{
					if (u_right->culoare == "N") // cazul 2.2.a
					{
						u_left->culoare = (char*)"N";
						u->culoare = (char*)"R";
						rotatie_dreapta(rad, u);
						u = (Nod_rosu_negru*)t->right;
					}
					u->culoare = t->culoare;
					t->culoare = (char*)"N";
					Nod_rosu_negru* u_right = (Nod_rosu_negru*)u->right;
					u_right->culoare = (char*)"N";
					rotatie_stanga(rad, t);
					f = rad;
				}
			}
			else
			{
				u = (Nod_rosu_negru*)t->left;
				Nod_rosu_negru* u_left = (Nod_rosu_negru*)u->left;
				Nod_rosu_negru* u_right = (Nod_rosu_negru*)u->right;
				if (u->culoare == "R")
				{
					u->culoare = (char*)"N";
					t->culoare = (char*)"R";
					rotatie_dreapta(rad, t);
					u = (Nod_rosu_negru*)t->left;
				}
				else if (u_left->culoare == "N" && u_right->culoare == "N") // cazul 2.1 din link
				{
					u->culoare = (char*)"R";
					f = t;
				}
				else // cazul 2.2 din link
				{
					if (u_left->culoare == "N") // cazul 2.2.a
					{
						u_right->culoare = (char*)"N";
						u->culoare = (char*)"R";
						rotatie_stanga(rad, u);
						u = (Nod_rosu_negru*)t->left;
					}
					u->culoare = t->culoare;
					t->culoare = (char*)"N";
					Nod_rosu_negru* u_left = (Nod_rosu_negru*)u->left;
					u_left->culoare = (char*)"N";
					rotatie_dreapta(rad, t);
					f = rad;
				}
			}
		}
	}
	catch (...)
	{
		cout << endl << "Eroare stergere din arbore bicolor!" << endl;
	}
}

void Arbore_bicolor::rotatie_stanga(Nod_rosu_negru* & rad, Nod_rosu_negru* & t)
{
    Nod_rosu_negru* parinte = (Nod_rosu_negru*) t->right;
    if (t == rad) {
        rad = parinte;
    }
    if (t->parinte != NULL) {
        Nod_rosu_negru* t_parinte = (Nod_rosu_negru*) t->parinte;
        if (t_parinte->left == t) {
            t_parinte->left = parinte;
        } 
        else 
        {
            t_parinte->right = parinte;
        }
        parinte->parinte = t->parinte;
    }
    t->right = parinte->left;
    if (parinte->left != NULL) {
        Nod_rosu_negru * parinte_left = (Nod_rosu_negru *) parinte->left;
        parinte_left->parinte = t;
    }
    parinte->left = t;
}


void Arbore_bicolor::rotatie_dreapta(Nod_rosu_negru* & rad, Nod_rosu_negru* & t)
{
    Nod_rosu_negru* parinte = (Nod_rosu_negru*) t->left;
    if (t == rad) {
        rad = parinte;
    }
    if (t->parinte != NULL) {
        Nod_rosu_negru* t_parinte = (Nod_rosu_negru*) t->parinte;
        if (t_parinte->left == t) {
            t_parinte->left = parinte;
        } 
        else 
        {
            t_parinte->right = parinte;
        }
        parinte->parinte = t->parinte;
    }
    t->left = parinte->right;
    if (parinte->right != NULL) {
        Nod_rosu_negru * parinte_right = (Nod_rosu_negru *) parinte->right;
        parinte_right->parinte = t;
    }
    parinte->right = t;
}

 void Arbore_bicolor::adauga_santinela(Nod_rosu_negru* nod) {
    if (nod == NULL) {
        return;
    }
    if (nod->left == NULL) {
        nod->left = santinela;
    }
    else
    {
        adauga_santinela((Nod_rosu_negru*) nod->left);
    }
    if (nod->right == NULL) {
        nod->right = santinela;
    }
    else
    {
        adauga_santinela((Nod_rosu_negru*) nod->right);
    }
 }

void Arbore_bicolor::stergere_postorder(Nod_rosu_negru* nod) {
    if (nod == santinela) {
        return;
    }
    if (! nod->left || ! nod->right) {
    }
    stergere_postorder((Nod_rosu_negru*) nod->left);
    stergere_postorder((Nod_rosu_negru*) nod->right);
    nod->left = NULL;
    nod->right = NULL;
    nod->parinte = NULL;
    delete nod;
}