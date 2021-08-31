#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main()
{
    unordered_map<int, string> m = {
        {1, "Item 1"},
        {2, "Item 2"},
        {3, "Item 3"},
        {4, "Item 4"},
    };

	// C++17 구조적 바인딩을 사용한 경우
	for (const auto&[key, value] : m) {
		cout << key << " = " << value << endl;
	}

	// 구조적 바인딩을 사용하지 않은 경우
	for (const auto& p : m) {
		cout << p.first << " = " << p.second << endl;
	}
    
    return 0;
}
