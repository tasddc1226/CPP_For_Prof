#include <iostream>
#include <memory>
#include "AirlineTicket.h"

using namespace std;

int main()
{
	AirlineTicket myTicket; // ���� ��� AirlineTicket
	myTicket.setPassengerName("Sherman T. Socketwrench");
	myTicket.setNumberOfMiles(700);
	double cost = myTicket.calculatePriceInDollars();
	cout << "This ticket will cost $" << cost << endl;

	// ����Ʈ �����͸� ����� �� ��� AirlineTicket
	auto myTicket2 = make_unique<AirlineTicket>();
	myTicket2->setPassengerName("Laudimore M. Hallidue");
	myTicket2->setNumberOfMiles(2000);
	myTicket2->setHasEliteSuperRewardsStatus(true);
	double cost2 = myTicket2->calculatePriceInDollars();
	cout << "This other ticket will cost $" << cost2 << endl;
	// ���⼭�� myTicket2�� �ڵ����� �����ǹǷ� �ڵ�� �ۼ��� �ʿ� ����.

	// ����Ʈ �����͸� ������� �ʴ� �� ��� AirlineTicket(�ٶ������� ���� ���)
	AirlineTicket* myTicket3 = new AirlineTicket();
	// ... Ƽ�� 3�� ����Ѵ�.
	delete myTicket3; // �� ��ü�� �����Ѵ�.


	return 0;
} 
