#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vec;

    // push_back을 호출하면 복제 연산이 발생한다.
    string myElement(5, 'a');  // "aaaaa"란 스트링을 만든다.
    vec.push_back(myElement);

    // 다음과 같이 작성하면 이동 의미론이 적용되어 복제 연산이 발생하지 않는다.
	vec.push_back(move(myElement));
    vec.push_back(string(5, 'a'));

    return 0;
}
