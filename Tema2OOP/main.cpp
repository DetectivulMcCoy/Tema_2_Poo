#include "Arbore.h"
#include "Arbore_bicolor.h"
#include "ABC.h"
#include "Nod.h"
#include "Nod_rosu_negru.h"
#include "management.h"
#include <iostream>
#include <algorithm>

using namespace std;
/*
Un arbore Roşu-şi-Negru este un arbore binar de căutare în care fiecare nod are asociată o culoare (roşu sau negru) conform următoarelor reguli : 
1. orice nod extern (frunză) este negru ;
2. dacă un nod este roşu, ambii fii sunt negri ;
3. toate drumurile de la rădăcină la nodurile terminale conţin acelaşi număr de noduri negre.
Obs. 
1. Pentru ca toate nodurile care conţin o cheie să fie noduri interne, am adăugat în arbore noduri fictive, marcate , pe care le-am numit externe şi care vor constitui frunzele negre ale arborelui.
2. Din definiţie deducem că orice subarbore a unui arbore Roşu-şi-Negru este arbore Roşu-şi-Negru. 
3. Regula 3 poate fi reformulată echivalent astfel: toate drumurile de la un nod la nodurile frunză descendente conţin acelaşi număr de noduri negre.
Definiţie 
Fiind dat un nod x, numim adâncime neagră a nodului x, numărul de noduri negre de la nodul x (exclusiv) la o frunză (inclusiv).
Obs. Datorită regulii 3 din definiţia arborilor Roşu-şi-Negru, adâncimea neagră a nodului x este bine definita.
*/
int main() 
{
	//  Arbore binar cu inaltime 4 
	//                    1
	//                   / \
    //                  2   3
	//                 /   / \
    //                4   6   5
	//               / \            
	//              7   8
	try
	{
		Nod* nod_7 = new Nod(7, NULL, NULL);
		Nod* nod_8 = new Nod(8, NULL, NULL);
		Nod* nod_4 = new Nod(4, nod_7, nod_8);
		Nod* nod_2 = new Nod(2, nod_4, NULL);
		Nod* nod_6 = new Nod(6, NULL, NULL);
		Nod* nod_5 = new Nod(5, NULL, NULL);
		Nod* nod_3 = new Nod(3, nod_6, nod_5);
		Nod* nod_1 = new Nod(1, nod_2, nod_3);
		ABC* arbore_abc = new ABC(nod_1);
		cout << "Numar de noduri in arborele binar de cautare: " << arbore_abc->obtine_nr_noduri() << endl;
		cout << "Inaltime arbore binar: " << arbore_abc->inaltime() << endl;
		delete arbore_abc;
	}
	catch (...)
	{
		cout << "Eroare generala alocare noduri!";
	}

	try
	{
		ABC arbore1_abc;
		arbore1_abc.inserare(7);
		arbore1_abc.inserare(8);
		arbore1_abc.inserare(4);
		arbore1_abc.inserare(2);
		arbore1_abc.inserare(6);
		arbore1_abc.inserare(5);
		arbore1_abc.inserare(3);
		arbore1_abc.inserare(1);
		cout << arbore1_abc;
		arbore1_abc.stergere(4);
		cout << "\n";
		cout << arbore1_abc;
		arbore1_abc.stergere(5);
		cout << "\n";
		cout << arbore1_abc;
		arbore1_abc.stergere(6);
		cout << "\n";
		cout << arbore1_abc;
		cout << "\n";
		arbore1_abc.inserare(11);
		cout << arbore1_abc;
		cout << "\n";
		arbore1_abc.inserare(4);
		cout << arbore1_abc;
		cout << "\n";
		arbore1_abc.stergere(3);
		cout << "\n";
		cout << arbore1_abc;
	}
	catch (...)
	{
		cout << "Eroare generala manipulare arbori!";
	}

	// Arbore bicolor cu adancime 3 din exemplul : 
	// https://writer.zoho.com/public/miha_cio/Arbori-bicolori1/noband (21 de noduri)
	
	//						       14N
	//						 /             \
    //                    8R                20N
	//                 /       \           /    \
    //               5N        12N        16R    21N
	//            /     \      /  \      /   \   /\ 
	//          3R       7N   10N  13N  15N   18N
	//        /    \    / \  /   \  /\  /\   /   \
	//       2N    4N  6R   9R   11R      17R   19R
	//      /  \   / \ /\   /\   /\       /\    /\
	//     1R  
	//    /  \            
	//    

	try
	{
		Nod_rosu_negru* rosu_1 = new Nod_rosu_negru(1, NULL, NULL, (char*)"R");
		Nod_rosu_negru* negru_2 = new Nod_rosu_negru(2, rosu_1, NULL, (char*)"N");
		Nod_rosu_negru* negru_4 = new Nod_rosu_negru(4, NULL, NULL, (char*)"N");
		Nod_rosu_negru* rosu_3 = new Nod_rosu_negru(3, negru_2, negru_4, (char*)"R");
		Nod_rosu_negru* rosu_6 = new Nod_rosu_negru(6, NULL, NULL, (char*)"R");
		Nod_rosu_negru* negru_7 = new Nod_rosu_negru(7, rosu_6, NULL, (char*)"N");
		Nod_rosu_negru* negru_5 = new Nod_rosu_negru(5, rosu_3, negru_7, (char*)"N");
		Nod_rosu_negru* rosu_9 = new Nod_rosu_negru(9, NULL, NULL, (char*)"R");
		Nod_rosu_negru* rosu_11 = new Nod_rosu_negru(11, NULL, NULL, (char*)"R");
		Nod_rosu_negru* negru_10 = new Nod_rosu_negru(10, rosu_9, rosu_11, (char*)"N");
		Nod_rosu_negru* negru_13 = new Nod_rosu_negru(13, NULL, NULL, (char*)"N");
		Nod_rosu_negru* negru_12 = new Nod_rosu_negru(12, negru_10, negru_13, (char*)"N");
		Nod_rosu_negru* rosu_8 = new Nod_rosu_negru(8, negru_5, negru_12, (char*)"R");
		Nod_rosu_negru* negru_15 = new Nod_rosu_negru(15, NULL, NULL, (char*)"N");
		Nod_rosu_negru* rosu_17 = new Nod_rosu_negru(17, NULL, NULL, (char*)"R");
		Nod_rosu_negru* rosu_19 = new Nod_rosu_negru(19, NULL, NULL, (char*)"R");
		Nod_rosu_negru* negru_18 = new Nod_rosu_negru(18, rosu_17, rosu_19, (char*)"N");
		Nod_rosu_negru* rosu_16 = new Nod_rosu_negru(16, negru_15, negru_18, (char*)"R");
		Nod_rosu_negru* negru_21 = new Nod_rosu_negru(21, NULL, NULL, (char*)"N");
		Nod_rosu_negru* negru_20 = new Nod_rosu_negru(20, rosu_16, negru_21, (char*)"N");
		Nod_rosu_negru* negru_14 = new Nod_rosu_negru(14, rosu_8, negru_20, (char*)"N");

		Arbore_bicolor* arbore_bicolor_14 = new Arbore_bicolor(negru_14);
		cout << "Numar de noduri in arborele bicolor: " << arbore_bicolor_14->obtine_nr_noduri() << endl;
		cout << "Adancime arbore bicolor incepand cu negru 14: " << arbore_bicolor_14->inaltime() << endl;
		cout << *arbore_bicolor_14;
		cout << "\n";

		delete arbore_bicolor_14;
	}
	catch (...)
	{
		cout << "Eroare generala arbore bicolor arbori!";
	}

	// Arbore bicolor cu adancime 3 din exemplul : 
    //
	//						       8N
	//						 /              \
    //                    4R                 12R
	//                 /       \           /      \
    //               2N        6N        10N          16N
	//            /     \      /  \      /   \     /       \  
	//          1N       3N   5N  7N   9N   11N  14R        18R
	//         / \      / \  /\   /\  /\     /   / \       /    \ 
	//                                      17R   13N 15N   17N   20N
	//                                       /\    /\   /\   / \  / \ 
	//                                                           19R 21R
	//                                                            /\  /\ 
    //

	try
	{
		Arbore_bicolor* arbore_bicolor = new Arbore_bicolor(NULL);
		for (int i = 1; i <= 21; ++i) {
			arbore_bicolor->inserare(i);
		}
		cout << *arbore_bicolor;;

		arbore_bicolor->stergere(18);

		cout << *arbore_bicolor;

		arbore_bicolor->stergere(1);
		cout << *arbore_bicolor;
		cout << "\n";

		delete arbore_bicolor;

		cout << "Introduceti un arbore (numarul de noduri si informatia nodurilor):\n";
		Arbore_bicolor arbore_bicolor_input;

		cin >> arbore_bicolor_input;
		cout << arbore_bicolor_input;

		cout << "\nCitirea informatiilor complete a n obiecte (arbori) si afisarea acestora\n";
		int n;
		cout << "Introduceti numarul de arbori: ";
		cin >> n;
		Management v(n);
		cout << "Introduceti fiecare arbore (numarul de noduri si informatia nodurilor):\n";
		v.citire();
		cout << "Afisarea arborilor\n";
		v.afisare();
	}
	catch (...)
	{
		cout << "Eroare generala manipulare colectie arbori!";
	}

	return 0;
}