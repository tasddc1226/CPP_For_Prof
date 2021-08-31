#pragma once

#include <cstddef>
#include <bitset>
#include <map>
#include <string>
#include <string_view>

const size_t kNumChannels = 10;

class CableCompany final
{
public:
	// ������ ä�ο� ���� ��Ű�� ��ǰ�� �����ͺ��̽��� �߰��Ѵ�.
	void addPackage(std::string_view packageName,
		const std::bitset<kNumChannels>& channels);

	// ������ ��Ű���� �����ͺ��̽����� �����Ѵ�.
	void removePackage(std::string_view packageName);

	// ������ ��Ű���� ä���� ��ȸ�Ѵ�.
	// ��Ű�� �̸��� �߸������� out_of_range �ͼ����� ������.
	const std::bitset<kNumChannels>& getPackage(std::string_view packageName) const;

	// �����ڸ� ��Ű���� ��� ä�η� �ʱ�ȭ�ؼ� �����ͺ��̽��� �߰��Ѵ�.
	// ��Ű�� �̸��� �߸������� out_of_range �ͼ����� ������.
	// �̹� ����� �����ڸ� �����ϸ� invalid_argument �ͼ����� ������.
	void newCustomer(std::string_view name, std::string_view package);

	// �����ڸ� ��Ű���� ��� ä�η� �ʱ�ȭ�ؼ� �����ͺ��̽��� �߰��Ѵ�.
	// �̹� ����� �����ڸ� �����ϸ� invalid_argument �ͼ����� ������.
	void newCustomer(std::string_view name, const std::bitset<kNumChannels>& channels);

	// ä���� ������ �������Ͽ��� �����Ѵ�.
	// �𸣴� �����ڸ� �����ϸ� invalid_argument �ͼ����� ������.
	void addChannel(std::string_view name, int channel);

	// ������ ä���� ������ �������Ͽ��� �����Ѵ�.
	// �𸣴� �����ڸ� �����ϸ� invalid_argument �ͼ����� ������.
	void removeChannel(std::string_view name, int channel);

	// ������ ��Ű���� ������ �������Ͽ� �߰��Ѵ�.
	// ��Ű�� �̸��� �߸������� out_of_range �ͼ����� ������.
	// �𸣴� �����ڸ� �����ϸ� invalid_argument �ͼ����� ������.
	void addPackageToCustomer(std::string_view name, std::string_view package);

	// ������ �����ڸ� �����ͺ��̽����� �����Ѵ�.
	void deleteCustomer(std::string_view name);

	// �����ڰ� ��û�� ä���� ��ȸ�Ѵ�.
	// �𸣴� �����ڸ� �����ϸ� invalid_argument �ͼ����� ������.
	const std::bitset<kNumChannels>& getCustomerChannels(std::string_view name) const;

private:
	// �����ڰ� ��û�� ä���� ��ȸ�Ѵ�.\ (non-const)
	// �𸣴� �����ڸ� �����ϸ� invalid_argument �ͼ����� ������.
	std::bitset<kNumChannels>& getCustomerChannelsHelper(std::string_view name);

	using MapType = std::map<std::string, std::bitset<kNumChannels>>;
	MapType mPackages, mCustomers;
};
