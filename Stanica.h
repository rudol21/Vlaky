#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

class Stanica
{
	int typ = -1;
	string nazov;
	double kilometraz = 0.0;
public:
	Stanica(int pTyp, string pNazov, double pKilometraz);
	~Stanica();
	int dajTyp();
	string dajNazov();
	double dajKilometraz();
};

