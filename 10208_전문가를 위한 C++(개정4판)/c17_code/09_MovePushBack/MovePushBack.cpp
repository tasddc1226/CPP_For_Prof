#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> vec;

    // push_back�� ȣ���ϸ� ���� ������ �߻��Ѵ�.
    string myElement(5, 'a');  // "aaaaa"�� ��Ʈ���� �����.
    vec.push_back(myElement);

    // ������ ���� �ۼ��ϸ� �̵� �ǹ̷��� ����Ǿ� ���� ������ �߻����� �ʴ´�.
	vec.push_back(move(myElement));
    vec.push_back(string(5, 'a'));

    return 0;
}
