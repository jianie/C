// 04��-BankSimulator.cpp: ���� �ùķ��̼� ���α׷�
#include <time.h>
#include "BankSimulator.h"
void main()
{
	srand( (unsigned int)time(NULL) );
	BankSimulator	sim;
	sim.readSimulationParameters( );
	sim.run();		
	sim.printStat();
}