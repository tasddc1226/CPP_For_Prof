#include "AirlineTicket.h"

using namespace std;

AirlineTicket::AirlineTicket()
	: mPassengerName("Unknown Passenger")
	, mNumberOfMiles(0)
	, mHasEliteSuperRewardsStatus(false)
{
}

/*
AirlineTicket::AirlineTicket()
{
	// ������ ��� �ʱ�ȭ
	mPassengerName = "Unknown Passenger";
	mNumberOfMiles = 0;
	mHasEliteSuperRewardsStatus = false;
}
*/

AirlineTicket::~AirlineTicket()
{
	// Nothing much to do in terms of cleanup
}

double AirlineTicket::calculatePriceInDollars() const
{
	if (hasEliteSuperRewardsStatus()) {
		// ��� ���(Elite Super Rewards) ȸ�����Դ� ���� Ƽ���� �����Ѵ�.
		return 0;
	}
	// Ƽ�� ������ ���� �Ÿ��� 0.1�� ���� ���̴�.
	// ������ �װ��翡�� �����ϴ� ������ �̺��� �����ϴ�.
	return getNumberOfMiles() * 0.1;
}


const string& AirlineTicket::getPassengerName() const
{
	return mPassengerName;
}

void AirlineTicket::setPassengerName(const string& name)
{
	mPassengerName = name;
}


int AirlineTicket::getNumberOfMiles() const
{
	return mNumberOfMiles;
}

void AirlineTicket::setNumberOfMiles(int miles)
{
	mNumberOfMiles = miles;
}

bool AirlineTicket::hasEliteSuperRewardsStatus() const
{
	return mHasEliteSuperRewardsStatus;
}

void AirlineTicket::setHasEliteSuperRewardsStatus(bool status)
{
	mHasEliteSuperRewardsStatus = status;
}
