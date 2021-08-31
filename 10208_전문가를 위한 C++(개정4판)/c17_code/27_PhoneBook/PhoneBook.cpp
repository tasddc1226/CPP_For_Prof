#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

template<class T>
void printMap(const T& m)
{
	for (auto& [key, value] : m) {
		cout << key << " (Phone: " << value << ")" << endl;
	}
	
	// ���� ����ϴ� �����Ϸ��� C++17 ������ ���ε��� �������� �ʴ´ٸ�
	// ������ ���� for������ �����Ѵ�.
	//for (auto& p : m) {
	//	cout << p.first << " (Phone: " << p.second << ")" << endl;
	//}

	cout << "-------" << endl;
}

int main()
{
	// �ؽ� ���̺��� �����Ѵ�.
	unordered_map<string, string> phoneBook = {
		{ "Marc G.", "123-456789" },
		{ "Scott K.", "654-987321" } };
	printMap(phoneBook);

	// ��ȭ ��ȣ �� ���� �߰��ϰų� �����Ѵ�.
	phoneBook.insert(make_pair("John D.", "321-987654"));
	phoneBook["Johan G."] = "963-258147";
	phoneBook["Freddy K."] = "999-256256";
	phoneBook.erase("Freddy K.");
	printMap(phoneBook);

	// �־��� Ű�� ��Ŷ �ε����� ã�´�.
	const size_t bucket = phoneBook.bucket("Marc G.");
	cout << "Marc G. is in bucket " << bucket
	     << " which contains the following "
	     << phoneBook.bucket_size(bucket) << " elements:" << endl;
	// ��Ŷ�� �ִ� ���ҿ� ���� ���۰� �� �ݺ��ڸ� �����´�.
	// ���⼭�� Ÿ���� 'auto'�� �����ߴ�. �����Ϸ��� �� �ݺ��� Ÿ����
	// unordered_map<string, string>::const_local_iterator�� �߷��Ѵ�.
	auto localBegin = phoneBook.cbegin(bucket);
	auto localEnd = phoneBook.cend(bucket);
	for (auto iter = localBegin; iter != localEnd; ++iter) {
		cout << "\t" << iter->first << " (Phone: "
			<< iter->second << ")" << endl;
	}
	cout << "-------" << endl;

	// �ؽ� ���̺� ���� ��踦 ȭ�鿡 ����Ѵ�.
	cout << "There are " << phoneBook.bucket_count() << " buckets." << endl;
	cout << "Average number of elements in a bucket is " << phoneBook.load_factor() << endl;

	return 0;
}
