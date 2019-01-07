#pragma once
#include "Stanica.h"
class SietStanic
{
	vector<Stanica*> zoznamStanic;
public:
	SietStanic();
	~SietStanic();
	void citajData(const char * menoSuboru);
	void usporiadaj();
	void vypisNaKonzolu();
	void odchodyVlaku(int startH, int startM);
	void odchodyRychlika(int startH, int startM);
};

