#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#include <iostream>
#include <utility>
#include <string>
#include <set>

using namespace std;

using VotersMap = map<string, vector<string>>;
using DistrictPair = pair<const string, vector<string>>;

// map의 여러 vector에 동시에 나오는 이름을 set으로 리턴한다.
//
// 이 코드는 map의 모든 벡터에 있는 이름으로 구성된 거대한 벡터 하나를 생성해서 정렬한 다음,
// adjacent_find()로 정렬된 벡터에 중복된 원소를 찾아낸다.
set<string> getDuplicates(const VotersMap& votersByDistrict)
{
	// 모든 벡터에 나온 이름을 모두 합쳐 거대한 벡터 하나로 만든다.
	vector<string> allNames;
	for (auto& district : votersByDistrict) {
		allNames.insert(end(allNames), begin(district.second), end(district.second));
	}

	// 이렇게 만든 벡터를 정렬한다.
	sort(begin(allNames), end(allNames));

	// 정렬하고 나면 중복된 이름이 연달아 나올 것이다.
	// adjacent_find()를 이용하여 두 번 이상 연달아 나오는 이름을 찾는다.
	// adjacent_find()가 끝 반복자를 리턴할 때까지 반복한다.
	set<string> duplicates;
	for (auto lit = cbegin(allNames); lit != cend(allNames); ++lit) {
		lit = adjacent_find(lit, cend(allNames));
		if (lit == cend(allNames)) {
			break;
		}
		duplicates.insert(*lit);
	}

	return duplicates;

	/*
	set<string> allNames;
	set<string> duplicates;
	for (auto&[district, voters] : votersByDistrict) {
		for (auto& name : voters) {
			if (!allNames.insert(name).second) {
				duplicates.insert(name);
			}
		}
	}
	return duplicates;
	*/
}

// 서로 다른 지역구 이름을 키로 사용하고 각 지역구에 등록된 모든 선거인을 담은 벡터를 값으로 갖는
// string/vector<string> pair에 대한 map을 받는다.
//
// 각 벡터에서 convictedFelons 벡터에 있는 모든 이름과 나머지 벡터에 있는 이름을 제거한다.
void auditVoterRolls(VotersMap& votersByDistrict,
	const vector<string>& convictedFelons)
{
	// 중복된 이름을 모두 가져온다.
	set<string> toRemove = getDuplicates(votersByDistrict);

	// 중복된 이름과 범죄인을 합친다.
	// 선거인 명부 벡터에서 앞에서 합친 이름들을 모두 제거할 것이다.
	toRemove.insert(cbegin(convictedFelons), cend(convictedFelons));

	// 제거할 이름을 중첩된 람다 표현식과 remove-erase 구문으로 삭제한다.
	for_each(begin(votersByDistrict), end(votersByDistrict),
		[&toRemove](DistrictPair& district) {
			auto it = remove_if(begin(district.second),
				end(district.second), [&toRemove](const string& name) {
					return (toRemove.count(name) > 0);
				}
			);
			district.second.erase(it, end(district.second));
		}
	);

	/*
	for (auto&[district, voters] : votersByDistrict) {
		auto it = remove_if(begin(voters), end(voters),
			[&toRemove](const string& name) {
				return (toRemove.count(name) > 0);
			}
		);
		voters.erase(it, end(voters));
	}
	*/
}

int main()
{
	// 유니폼 초기화로 맵을 초기화한다.
	VotersMap voters = {
		{ "Orange", { "Amy Aardvark", "Bob Buffalo", "Charles Cat", "Dwayne Dog" } },
		{ "Los Angeles", { "Elizabeth Elephant", "Fred Flamingo", "Amy Aardvark" } },
		{ "San Diego", { "George Goose", "Heidi Hen", "Fred Flamingo" } }
	};

	vector<string> felons = { "Bob Buffalo", "Charles Cat" };

	// 지역구를 출력하는 로컬 람다 표현식
	auto printDistrict = [](const DistrictPair& district) {
		cout << district.first << ":";
		for (auto& str : district.second) {
			cout << " {" << str << "}";
		}
		cout << endl;
	};

	cout << "Before Audit:" << endl;
	for (const auto& district : voters) { printDistrict(district); }
	cout << endl;

	auditVoterRolls(voters, felons);
	
	cout << "After Audit:" << endl;
	for (const auto& district : voters) { printDistrict(district); }
	cout << endl;

	return 0;
}
