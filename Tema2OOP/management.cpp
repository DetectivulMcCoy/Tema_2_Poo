#include "management.h"

Management::Management()
 {
	n = 0;
	t = NULL;            
}
 Management::Management(int n)
 {
	this->n = n;
	this->t = new Arbore_bicolor[n];            
	//cout<<"Apel constructor cu parametri"<<endl;
}
 Management::Management(const Management &v)
 {
    int i;
    this->n = v.n;
    this->t = new Arbore_bicolor[n];            
    for (i = 0; i < n; i++)
        this->t[i] =v.t[i];
    //cout<<"Apel constructor de copiere"<<endl;
 }
 Management::~Management()
 {
   delete []t;
   t = NULL;                                
 }
 
 istream & operator>>(istream &stream, Management &v)
{
	for(int i=0; i < v.n; i++)
        stream >> v.t[i];
    return stream;
}
ostream & operator<<(ostream & out, Management &v)
{
    out << "Numarul de arbori este:" << endl;
    out << v.n <<endl;;
    for(int i = 0; i < v.n; i++)
    {
        out<<"Arborele "<< i+1 <<": "<<endl;
		out<<v.t[i];
    }
    return out;
}
 void Management::citire()
{
	cout<<"Introduceti arborii:"<<endl;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i];
		cout << "Arborele " << i+1 << " citit \n";
	}
	cout<<endl;
}
 void Management::afisare() {
      for (int i = 0; i < n; i++)
           cout<<t[i]<<endl;

	  cout<<endl;
 }
