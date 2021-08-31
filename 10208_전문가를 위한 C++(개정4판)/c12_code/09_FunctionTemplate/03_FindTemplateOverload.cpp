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
			return i; // 값을 찾으면 인덱스를 리턴한다.
		}
	}
	return NOT_FOUND; // 값을 찾지 못하면 NOT_FOUND를 리턴한다.
}

template <typename T, size_t N>
size_t Find(const T& value, const T(&arr)[N])
{
	return Find(value, arr, N);
}

size_t Find(const char* const& value, const char* const* arr, size_t size)
{
	cout << "overload" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; // 값을 찾으면 인덱스를 리턴한다.
		}
	}
	return NOT_FOUND; // 값을 찾지 못하면 NOT_FOUND를 리턴한다.
}

int main()
{
	const char* word = "two";
	const char* words[] = { "one", "two", "three", "four" };
	const size_t sizeWords = std::size(words);
	size_t res;
	res = Find<const char*>(word, words, sizeWords); // T=const char*인 템플릿 호출
	res = Find(word, words, sizeWords);              // 비템플릿(일반) Find() 호출
	if (res != NOT_FOUND)
		cout << res << endl;
	else
		cout << "Not found" << endl;

	return 0;
}
