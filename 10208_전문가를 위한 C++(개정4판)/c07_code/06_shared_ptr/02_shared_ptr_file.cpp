#include <iostream>
#include <memory>
#include <cstdio>

using namespace std;

void CloseFile(FILE* filePtr)
{
	if (filePtr == nullptr)
		return;
	fclose(filePtr);
	cout << "File closed." << endl;
}

int main()
{
#if defined(_MSC_VER)
	// 마이크로소프트 비주얼 C++를 사용할 경
	FILE* f = nullptr;
	fopen_s(&f, "data.txt", "w");
#else
	FILE* f = fopen("data.txt", "w");
#endif
	shared_ptr<FILE> filePtr(f, CloseFile);
	if (filePtr == nullptr) {
		cerr << "Error opening file." << endl;
	} else {
		cout << "File opened." << endl;
		// filePtr를 사용하는 코드를 여기에 작성한다.
	}
	return 0;
}
