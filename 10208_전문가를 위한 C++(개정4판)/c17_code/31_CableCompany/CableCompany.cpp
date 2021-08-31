#include "CableCompany.h"
#include <stdexcept>
#include <utility>

using namespace std;

void CableCompany::addPackage(string_view packageName,
	const bitset<kNumChannels>& channels)
{
	mPackages.emplace(packageName, channels);
}

void CableCompany::removePackage(string_view packageName)
{
	mPackages.erase(packageName.data());
}

const bitset<kNumChannels>& CableCompany::getPackage(string_view packageName) const
{
	// 지정한 패키지에 대한 레퍼런스를 구한다.
	auto it = mPackages.find(packageName.data());
	if (it == end(mPackages)) {
		// 지정한 패키지가 존재하지 않으면 익셉션을 던진다.
		throw out_of_range("Invalid package");
	}
	return it->second;
}

void CableCompany::newCustomer(string_view name, string_view package)
{
	// 지정한 패키지에 속한 채널을 가져온다.
	auto& packageChannels = getPackage(package);
	// 가입자가 선택한 패키지가 ㅍ현된 bitset으로 설정된 계정을 생성한다.
	newCustomer(name, packageChannels);
}

void CableCompany::newCustomer(string_view name,
	const bitset<kNumChannels>& channels)
{
	// 가입자 맵에 가입자를 추가한다.
	auto result = mCustomers.emplace(name, channels);
	if (!result.second) {
		// 가입자가 이미 데이터베이스에 존재하면 변경하지 않는다.
		throw invalid_argument("Duplicate customer");
	}
}

void CableCompany::addChannel(string_view name, int channel)
{
	// 지정한 가입자가 현재 가입한 채널을 조회한다.
	auto& customerChannels = getCustomerChannelsHelper(name);
	// 가입자를 찾았다면 채널을 설정한다.
	customerChannels.set(channel);
}

void CableCompany::removeChannel(string_view name, int channel)
{
	// 지정한 가입자가 현재 신청한 채널을 가져온다.
	auto& customerChannels = getCustomerChannelsHelper(name);
	// 가입자를 찾았다면 채널을 삭제한다.
	customerChannels.reset(channel);
}

void CableCompany::addPackageToCustomer(string_view name, string_view package)
{
	// 지정한 패키지에 속한 채널을 가져온다.
	auto& packageChannels = getPackage(package);
	// 지정한 가입자가 선택한 채널을 가져온다.
	auto& customerChannels = getCustomerChannelsHelper(name);
	// 현재 가입자가 신청한 채널에 패키지 채널을 or 연산으로 추가한다.
	customerChannels |= packageChannels;
}

void CableCompany::deleteCustomer(string_view name)
{
	mCustomers.erase(name.data());
}

const bitset<kNumChannels>& CableCompany::getCustomerChannels(string_view name) const
{
	// 코드 중복을 피하도록 const_cast()로 getCustomerChannelsHelper()에 전달한다.
	// to avoid code duplication.
	return const_cast<CableCompany*>(this)->getCustomerChannelsHelper(name);
}

bitset<kNumChannels>& CableCompany::getCustomerChannelsHelper(string_view name)
{
	// 가입자에 대한 레퍼런스를 가져온다.
	auto it = mCustomers.find(name.data());
	if (it == end(mCustomers)) {
		throw invalid_argument("Unknown customer");
	}
	// 가입자를 찾은 경우.
	// 이 값은 name/bitset pair에 대한 레퍼런스임에 주의한다.
	// bitset은 두 번째 필드에 있다.
	return it->second;
}
