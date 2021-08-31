#include "ArticleCitations.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

ArticleCitations::ArticleCitations(string_view fileName)
	: mCitations(nullptr), mNumCitations(0)
{
	// 여기서는 파일을 읽기만 한다.
	readFile(fileName);
}

ArticleCitations::ArticleCitations(const ArticleCitations& src)
{
	copy(src);
}

ArticleCitations& ArticleCitations::operator=(const ArticleCitations& rhs)
{
	// 자기 자신을 대입하는지 검사한다.
	if (this == &rhs) {
		return *this;
	}
	// 예전에 할당된 메모리를 해제한다.
	delete[] mCitations;
	// 데이터를 복제한다.
	copy(rhs);

	return *this;
}

void ArticleCitations::copy(const ArticleCitations& src)
{
	// 논문 제목, 저자 등을 복제한다.
	mArticle = src.mArticle;
	// 인용 횟수를 복제한다.
	mNumCitations = src.mNumCitations;
	// 정확한 크기만큼 배열을 할당한다.
	mCitations = new string[mNumCitations];
	// 배열의 각 원소를 복제한다.
	for (int i = 0; i < mNumCitations; i++) {
		mCitations[i] = src.mCitations[i];
	}
}

ArticleCitations::~ArticleCitations()
{
	delete [] mCitations;
}

void ArticleCitations::readFile(string_view fileName)
{
	// 파일을 연다. 그 과정에서 오류가 발생했는지 확인한다.
	ifstream inputFile(fileName.data());
	if (inputFile.fail()) {
		throw invalid_argument("Unable to open file");
	}
	// 논문 저자, 제목 등이 담긴 줄을 읽는다.
	getline(inputFile, mArticle);

	// 인용 정보 앞에 나온 공백은 건너뛴다.
	inputFile >> ws;

	int count = 0;
	// 현재 위치를 저장한다. 그래야 나중에 리턴할 수 있다.
	streampos citationsStart = inputFile.tellg();
	// 인용 논문 수를 센다.
	while (!inputFile.eof()) {
		// 다음 항목 앞에 나온 공백은 건너뛴다.
		inputFile >> ws;
		string temp;
		getline(inputFile, temp);
		if (!temp.empty()) {
			count++;
		}
	}
	
	if (count != 0) {
		// 인용 정보를 담은 스트링 배열을 할당한다.
		mCitations = new string[count];
		mNumCitations = count;
		// 스트림 상태를 클리어한다.
		inputFile.clear();
		// 인용 정보의 첫 항목으로 돌아간다.
		inputFile.seekg(citationsStart);
		// 인용 정보를 하나씩 읽어 배열에 저장한다.
		for (count = 0; count < mNumCitations; count++) {
			string temp;
			getline(inputFile, temp);
			if (!temp.empty()) {
				mCitations[count] = temp;
			}
		}
	} else {
		mNumCitations = -1;
	}
}
