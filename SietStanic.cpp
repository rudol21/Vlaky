#include "SietStanic.h"


using namespace std;
SietStanic::SietStanic()
{
}


SietStanic::~SietStanic()
{
	for (auto &p : zoznamStanic)
	{
		delete p;
	}
}

void SietStanic::citajData(const char * menoSuboru)
{
	//ifstream citac;
	//citac.open(menoSuboru);
	int typ = 0;
	string nazov ;
	double kilometraz = 0.0;
	ifstream cin(menoSuboru);
	
	while (cin >> typ >> nazov >> kilometraz)
	{
		zoznamStanic.push_back(new Stanica(typ, nazov, kilometraz));
	}
	
	
	/*
	if (menoSuboru) {
		FILE *f = fopen(menoSuboru, "rb");
		if (f)
		{

			
	
				for (int i = 0; i < 5; ++i)
				{
					fscanf(f,"%i %s %f", typ, nazov, kilometraz);
					zoznamStanic.push_back(new Stanica(typ, nazov, kilometraz));
				}

				

			
		}
		fclose(f);
	}*/

}
bool wayToSort(Stanica *s1, Stanica *s2) { return s1->dajKilometraz() < s2->dajKilometraz(); };
void SietStanic::usporiadaj()
{
	sort(zoznamStanic.begin(), zoznamStanic.end(), wayToSort);
}

void SietStanic::vypisNaKonzolu()
{
	for (int i = 0; i < zoznamStanic.size(); i++)
	{
		int typ = zoznamStanic[i]->dajTyp();
		string m;
		if (typ == 0)
			m = "     ";
		else
			m = " ";
		cout << zoznamStanic[i]->dajKilometraz() <<":"<< m << zoznamStanic[i]->dajNazov() << endl;
		//string nazov = zoznamStanic[i]->dajNazov();
		//double kilometraz = zoznamStanic[i]->dajKilometraz();
		//printf("%s",  nazov);
		//printf("\n");
		
		
	}
	
}

void SietStanic::odchodyVlaku(int startH,int startM)
{
	int hodiny = startH;
	int minuty = startM;
	int rozdielKM = 0;
	vector <int> cas;
	int casPom = 0;
	cas.push_back((hodiny * 60) + minuty);
	casPom = cas[0];
	for (int i = 1; i < zoznamStanic.size(); i++)
	{

		rozdielKM = zoznamStanic[i]->dajKilometraz();
		rozdielKM = rozdielKM - zoznamStanic[i-1]->dajKilometraz();
		if (zoznamStanic[i]->dajTyp() == 0)
			casPom = casPom + (rozdielKM / 80.00) * 60 + 2;
		else
			casPom = casPom + (rozdielKM / 80.00) * 60 + 3;

		cas.push_back(casPom);
}
	for (int i = 0; i < zoznamStanic.size(); i++)
	{
		string x;
		hodiny = cas[i] / 60;
		minuty = cas[i] - (hodiny * 60);
		if (minuty < 10)
			x = " 0";
		else
			x = " ";
		cout << hodiny <<":"<<x<<minuty<< " " << zoznamStanic[i]->dajNazov()<< endl;
	}
}

void SietStanic::odchodyRychlika(int startH, int startM)
{
	int hodiny = startH;
	int minuty = startM;
	int rozdielKM = 0;
	vector <int> cas;
	int casPom = 0;
	cas.push_back((hodiny * 60) + minuty);
	casPom = cas[0];
	int pocitadlo = 0;
	for (int i = 1; i < zoznamStanic.size(); i++)
	{
		if (zoznamStanic[i]->dajTyp() == 1)
		{
			rozdielKM = zoznamStanic[i]->dajKilometraz();
			rozdielKM = rozdielKM - zoznamStanic[pocitadlo]->dajKilometraz();
			pocitadlo = i;
			casPom = casPom + (rozdielKM / 100.00) * 60 + 3;
			cas.push_back(casPom);
		}
	}
	for (int i = 0; i < cas.size(); i++)
	{
		string x;
		hodiny = cas[i] / 60;
		minuty = cas[i] - (hodiny * 60);
		if (minuty < 10)
			x= " 0";
		else
			x = " ";
		cout << hodiny << ":" << x << minuty << " " << zoznamStanic[i]->dajNazov() << endl;
	}
}
