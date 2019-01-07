#include "Stanica.h"
#include "SietStanic.h"
int main(int argc, char * argv[])
{
	SietStanic *siet = new SietStanic();
	siet->citajData("suborNaCitanie.txt");
	siet->usporiadaj();
	siet->vypisNaKonzolu();
	siet->odchodyVlaku(11,21);
	siet->odchodyRychlika(11,36);
	delete siet;
}