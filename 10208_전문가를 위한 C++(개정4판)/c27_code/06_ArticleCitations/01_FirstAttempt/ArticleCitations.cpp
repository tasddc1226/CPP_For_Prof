#include "ArticleCitations.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

ArticleCitations::ArticleCitations(string_view fileName)
	: mCitations(nullptr), mNumCitations(0)
{
	// ���⼭�� ������ �б⸸ �Ѵ�.
	readFile(fileName);
}

ArticleCitations::ArticleCitations(const ArticleCitations& src)
{
	copy(src);
}

ArticleCitations& ArticleCitations::operator=(const ArticleCitations& rhs)
{
	// �ڱ� �ڽ��� �����ϴ��� �˻��Ѵ�.
	if (this == &rhs) {
		return *this;
	}
	// ������ �Ҵ�� �޸𸮸� �����Ѵ�.
	delete [] mCitations;
	// �����͸� �����Ѵ�.
	copy(rhs);

	return *this;
}

void ArticleCitations::copy(const ArticleCitations& src)
{
	// �� ����, ���� ���� �����Ѵ�.
	mArticle = src.mArticle;
	// �ο� Ƚ���� �����Ѵ�.
	mNumCitations = src.mNumCitations;
	// ��Ȯ�� ũ�⸸ŭ �迭�� �Ҵ��Ѵ�.
	mCitations = new string[mNumCitations];
	// �迭�� �� ���Ҹ� �����Ѵ�.
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
	// ������ ����. �� �������� ������ �߻��ߴ��� Ȯ���Ѵ�.
	ifstream inputFile(fileName.data());
	if (inputFile.fail()) {
		throw invalid_argument("Unable to open file");
	}
	// �� ����, ���� ���� ��� ���� �д´�.
	getline(inputFile, mArticle);

	// �ο� ���� �տ� ���� ������ �ǳʶڴ�.
	inputFile >> ws;

	int count = 0;
	// ���� ��ġ�� �����Ѵ�. �׷��� ���߿� ������ �� �ִ�.
	streampos citationsStart = inputFile.tellg();
	// �ο� �� ���� ����.
	while (!inputFile.eof()) {
		// ���� �׸� �տ� ���� ������ �ǳʶڴ�.
		inputFile >> ws;
		string temp;
		getline(inputFile, temp);
		if (!temp.empty()) {
			count++;
		}
	}

	if (count != 0) {
		// �ο� ������ ���� ��Ʈ�� �迭�� �Ҵ��Ѵ�.
		mCitations = new string[count];
		mNumCitations = count;
		// �ο� ������ ù �׸����� ���ư���.
		inputFile.seekg(citationsStart);
		// �ο� ������ �ϳ��� �о� �迭�� �����Ѵ�.
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
