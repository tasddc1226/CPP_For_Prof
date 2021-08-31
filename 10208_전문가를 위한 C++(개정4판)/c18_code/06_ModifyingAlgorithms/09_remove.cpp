#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void removeEmptyStrings(vector<string>& strings)
{
	auto it = remove_if(begin(strings), end(strings),
		[](const string& str){ return str.empty(); });
	// 제거된 원소를 모두 지운다.
	strings.erase(it, end(strings));
}

void removeEmptyStringsWithoutAlgorithms(vector<string>& strings)
{
	for (auto iter = begin(strings); iter != end(strings); ) {
		if (iter->empty())
			iter = strings.erase(iter);
		else
			++iter;
	}
}

int main()
{
	vector<string> myVector = { "", "one", "", "two", "three", "four" };

	for (auto& str : myVector) { cout << "\"" << str << "\"  "; }
	cout << endl;
	removeEmptyStrings(myVector);
	for (auto& str : myVector) { cout << "\"" << str << "\"  "; }
	cout << endl;

	return 0;
}
