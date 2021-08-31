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
	// 지정한 채널에 대한 패키지 상품을 데이터베이스에 추가한다.
	void addPackage(std::string_view packageName,
		const std::bitset<kNumChannels>& channels);

	// 지정한 패키지를 데이터베이스에서 삭제한다.
	void removePackage(std::string_view packageName);

	// 지정한 패키지의 채널을 조회한다.
	// 패키지 이름이 잘못됐으면 out_of_range 익셉션을 던진다.
	const std::bitset<kNumChannels>& getPackage(std::string_view packageName) const;

	// 가입자를 패키지에 담긴 채널로 초기화해서 데이터베이스에 추가한다.
	// 패키지 이름이 잘못됐으면 out_of_range 익셉션을 던진다.
	// 이미 저장된 가입자를 지정하면 invalid_argument 익셉션을 던진다.
	void newCustomer(std::string_view name, std::string_view package);

	// 가입자를 패키지에 담긴 채널로 초기화해서 데이터베이스에 추가한다.
	// 이미 저장된 가입자를 지정하면 invalid_argument 익셉션을 던진다.
	void newCustomer(std::string_view name, const std::bitset<kNumChannels>& channels);

	// 채널을 가입자 프로파일에서 삭제한다.
	// 모르는 가입자를 지정하면 invalid_argument 익셉션을 던진다.
	void addChannel(std::string_view name, int channel);

	// 지정한 채널을 가입자 프로파일에서 삭제한다.
	// 모르는 가입자를 지정하면 invalid_argument 익셉션을 던진다.
	void removeChannel(std::string_view name, int channel);

	// 지정한 패키지를 가입자 프로파일에 추가한다.
	// 패키지 이름이 잘못됐으면 out_of_range 익셉션을 던진다.
	// 모르는 가입자를 지정하면 invalid_argument 익셉션을 던진다.
	void addPackageToCustomer(std::string_view name, std::string_view package);

	// 지정한 가입자를 데이터베이스에서 삭제한다.
	void deleteCustomer(std::string_view name);

	// 가입자가 신청한 채널을 조회한다.
	// 모르는 가입자를 지정하면 invalid_argument 익셉션을 던진다.
	const std::bitset<kNumChannels>& getCustomerChannels(std::string_view name) const;

private:
	// 가입자가 신청한 채널을 조회한다.\ (non-const)
	// 모르는 가입자를 지정하면 invalid_argument 익셉션을 던진다.
	std::bitset<kNumChannels>& getCustomerChannelsHelper(std::string_view name);

	using MapType = std::map<std::string, std::bitset<kNumChannels>>;
	MapType mPackages, mCustomers;
};
