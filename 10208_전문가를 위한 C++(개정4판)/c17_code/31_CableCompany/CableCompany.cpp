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
	// ������ ��Ű���� ���� ���۷����� ���Ѵ�.
	auto it = mPackages.find(packageName.data());
	if (it == end(mPackages)) {
		// ������ ��Ű���� �������� ������ �ͼ����� ������.
		throw out_of_range("Invalid package");
	}
	return it->second;
}

void CableCompany::newCustomer(string_view name, string_view package)
{
	// ������ ��Ű���� ���� ä���� �����´�.
	auto& packageChannels = getPackage(package);
	// �����ڰ� ������ ��Ű���� ������ bitset���� ������ ������ �����Ѵ�.
	newCustomer(name, packageChannels);
}

void CableCompany::newCustomer(string_view name,
	const bitset<kNumChannels>& channels)
{
	// ������ �ʿ� �����ڸ� �߰��Ѵ�.
	auto result = mCustomers.emplace(name, channels);
	if (!result.second) {
		// �����ڰ� �̹� �����ͺ��̽��� �����ϸ� �������� �ʴ´�.
		throw invalid_argument("Duplicate customer");
	}
}

void CableCompany::addChannel(string_view name, int channel)
{
	// ������ �����ڰ� ���� ������ ä���� ��ȸ�Ѵ�.
	auto& customerChannels = getCustomerChannelsHelper(name);
	// �����ڸ� ã�Ҵٸ� ä���� �����Ѵ�.
	customerChannels.set(channel);
}

void CableCompany::removeChannel(string_view name, int channel)
{
	// ������ �����ڰ� ���� ��û�� ä���� �����´�.
	auto& customerChannels = getCustomerChannelsHelper(name);
	// �����ڸ� ã�Ҵٸ� ä���� �����Ѵ�.
	customerChannels.reset(channel);
}

void CableCompany::addPackageToCustomer(string_view name, string_view package)
{
	// ������ ��Ű���� ���� ä���� �����´�.
	auto& packageChannels = getPackage(package);
	// ������ �����ڰ� ������ ä���� �����´�.
	auto& customerChannels = getCustomerChannelsHelper(name);
	// ���� �����ڰ� ��û�� ä�ο� ��Ű�� ä���� or �������� �߰��Ѵ�.
	customerChannels |= packageChannels;
}

void CableCompany::deleteCustomer(string_view name)
{
	mCustomers.erase(name.data());
}

const bitset<kNumChannels>& CableCompany::getCustomerChannels(string_view name) const
{
	// �ڵ� �ߺ��� ���ϵ��� const_cast()�� getCustomerChannelsHelper()�� �����Ѵ�.
	// to avoid code duplication.
	return const_cast<CableCompany*>(this)->getCustomerChannelsHelper(name);
}

bitset<kNumChannels>& CableCompany::getCustomerChannelsHelper(string_view name)
{
	// �����ڿ� ���� ���۷����� �����´�.
	auto it = mCustomers.find(name.data());
	if (it == end(mCustomers)) {
		throw invalid_argument("Unknown customer");
	}
	// �����ڸ� ã�� ���.
	// �� ���� name/bitset pair�� ���� ���۷����ӿ� �����Ѵ�.
	// bitset�� �� ��° �ʵ忡 �ִ�.
	return it->second;
}
