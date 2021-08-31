#include <cstddef>
#include <iostream>
#include <cstring>
#include <array>

using namespace std;

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	cout << "original" << endl;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i; // ���� ã���� �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // ���� ã�� ���ϸ� NOT_FOUND�� �����Ѵ�.
}

template <typename T, size_t N>
size_t Find(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}

template<>
size_t Find<const char*>(const char* const& value, const char* const* arr, size_t size)
{
	cout << "Specialization" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // ���� ã���� �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // ���� ã�� ���ϸ� NOT_FOUND�� �����Ѵ�.
}

size_t Find(const char* const& value, const char* const* arr, size_t size)
{
	cout << "overload" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // ���� ã���� �ε����� �����Ѵ�.
		}
	}
	return NOT_FOUND; // ���� ã�� ���ϸ� NOT_FOUND�� �����Ѵ�.
}

int main()
{
	const char* word = "two";
	const char* words[] = { "one", "two", "three", "four" };
	const size_t sizeWords = std::size(words);
	size_t res;
	res = Find<const char*>(word, words, sizeWords); // const char*�� ���� Ư��ȭ�� ������ ȣ���Ѵ�.
	res = Find(word, words, sizeWords);              //�Ϲ� �Լ��� ������ Find()�� ȣ���Ѵ�.
	if (res != NOT_FOUND)
		cout << res << endl;
	else
		cout << "Not found" << endl;

	return 0;
}
