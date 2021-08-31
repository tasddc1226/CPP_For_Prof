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

// map�� ���� vector�� ���ÿ� ������ �̸��� set���� �����Ѵ�.
//
// �� �ڵ�� map�� ��� ���Ϳ� �ִ� �̸����� ������ �Ŵ��� ���� �ϳ��� �����ؼ� ������ ����,
// adjacent_find()�� ���ĵ� ���Ϳ� �ߺ��� ���Ҹ� ã�Ƴ���.
set<string> getDuplicates(const VotersMap& votersByDistrict)
{
	// ��� ���Ϳ� ���� �̸��� ��� ���� �Ŵ��� ���� �ϳ��� �����.
	vector<string> allNames;
	for (auto& district : votersByDistrict) {
		allNames.insert(end(allNames), begin(district.second), end(district.second));
	}

	// �̷��� ���� ���͸� �����Ѵ�.
	sort(begin(allNames), end(allNames));

	// �����ϰ� ���� �ߺ��� �̸��� ���޾� ���� ���̴�.
	// adjacent_find()�� �̿��Ͽ� �� �� �̻� ���޾� ������ �̸��� ã�´�.
	// adjacent_find()�� �� �ݺ��ڸ� ������ ������ �ݺ��Ѵ�.
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

// ���� �ٸ� ������ �̸��� Ű�� ����ϰ� �� �������� ��ϵ� ��� �������� ���� ���͸� ������ ����
// string/vector<string> pair�� ���� map�� �޴´�.
//
// �� ���Ϳ��� convictedFelons ���Ϳ� �ִ� ��� �̸��� ������ ���Ϳ� �ִ� �̸��� �����Ѵ�.
void auditVoterRolls(VotersMap& votersByDistrict,
	const vector<string>& convictedFelons)
{
	// �ߺ��� �̸��� ��� �����´�.
	set<string> toRemove = getDuplicates(votersByDistrict);

	// �ߺ��� �̸��� �������� ��ģ��.
	// ������ ��� ���Ϳ��� �տ��� ��ģ �̸����� ��� ������ ���̴�.
	toRemove.insert(cbegin(convictedFelons), cend(convictedFelons));

	// ������ �̸��� ��ø�� ���� ǥ���İ� remove-erase �������� �����Ѵ�.
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
	// ������ �ʱ�ȭ�� ���� �ʱ�ȭ�Ѵ�.
	VotersMap voters = {
		{ "Orange", { "Amy Aardvark", "Bob Buffalo", "Charles Cat", "Dwayne Dog" } },
		{ "Los Angeles", { "Elizabeth Elephant", "Fred Flamingo", "Amy Aardvark" } },
		{ "San Diego", { "George Goose", "Heidi Hen", "Fred Flamingo" } }
	};

	vector<string> felons = { "Bob Buffalo", "Charles Cat" };

	// �������� ����ϴ� ���� ���� ǥ����
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
