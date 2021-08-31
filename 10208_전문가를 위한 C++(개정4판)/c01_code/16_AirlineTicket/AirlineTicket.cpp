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
	// 데이터 멤버 초기화
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
		// 우수 등급(Elite Super Rewards) 회원에게는 무료 티켓을 제공한다.
		return 0;
	}
	// 티켓 가격은 비행 거리에 0.1을 곱한 값이다.
	// 실제로 항공사에서 적용하는 공식은 이보다 복잡하다.
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
