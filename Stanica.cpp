#include "Stanica.h"






Stanica::Stanica(int pTyp, string pNazov, double pKilometraz)
{
	typ = pTyp;
	nazov = pNazov;
	kilometraz = pKilometraz;
}

Stanica::~Stanica()
{

}

int Stanica::dajTyp()
{
	return typ;
}

string Stanica::dajNazov()
{
	return nazov;
}

double Stanica::dajKilometraz()
{
	return kilometraz;
}
