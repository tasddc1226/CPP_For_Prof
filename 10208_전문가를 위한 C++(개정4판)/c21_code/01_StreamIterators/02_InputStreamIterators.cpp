#include <numeric>
#include <iostream>
#include <iterator>

using namespace std;

int main()
{
	// �ֿܼ��� ��Ʈ�� �� ���ڰ� ���� ������ �Էµ� ������ ���� ���Ѵ�.
	// ����e:
	//	�����쿡�� ��Ʈ�� �� ���ڴ� Ctrl+Z �Է� �� ���� Ű�� �ľ� �Էµȴ�.
	//	���������� ��Ʈ�� �� ���ڴ� ���� Ű�� �ļ� ���� �ٷ� �Ѿ �� Ctrl+D�� ������ �Էµȴ�.
	cout << "Enter numbers separated by white space." << endl;
	cout << "Press Ctrl+Z followed by Enter to stop." << endl;
	istream_iterator<int> numbersIter(cin);
	istream_iterator<int> endIter;
	int sum = accumulate(numbersIter, endIter, 0);
	cout << "Sum: " << sum << endl;

	return 0;
}
