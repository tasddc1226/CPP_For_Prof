#include <iostream>
#include <memory>
#include "AirlineTicket.h"

using namespace std;

int main()
{
	AirlineTicket myTicket; // 스택 기반 AirlineTicket
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	double cost = myTicket.calculatePriceInDollars();
	cout << "This ticket will cost $" << cost << endl;

	// 스마트 포인터를 사용한 힙 기반 AirlineTicket
	auto myTicket2 = make_unique<AirlineTicket>();
	myTicket2->setPassengerName("Laudimore M. Hallidue");
	myTicket2->setNumberOfMiles(2000);
	myTicket2->setHasEliteSuperRewardsStatus(true);
	double cost2 = myTicket2->calculatePriceInDollars();
	cout << "This other ticket will cost $" << cost2 << endl;
	// 여기서는 myTicket2가 자동으로 삭제되므로 코드로 작성할 필요 없다.

	// 스마트 포인터를 사용하지 않는 힙 기반 AirlineTicket(바람직하지 않은 방식)
	AirlineTicket* myTicket3 = new AirlineTicket();
	// ... 티켓 3을 사용한다.
	delete myTicket3; // 힙 객체를 삭제한다.


	return 0;
} 
