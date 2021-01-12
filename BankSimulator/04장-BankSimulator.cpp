// 04장-BankSimulator.cpp: 은행 시뮬레이션 프로그램
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