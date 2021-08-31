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
	delete[] mCitations;
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

void printStreamState(const istream& inputStream)
{
	if (inputStream.good()) {
		cout << "stream state is good" << endl;
	}
	if (inputStream.bad()) {
		cout << "stream state is bad" << endl;
	}
	if (inputStream.fail()) {
		cout << "stream state is fail" << endl;
	}
	if (inputStream.eof()) {
		cout << "stream state is eof" << endl;
	}
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
	cout << "readFile(): counting number of citations" << endl;
	while (!inputFile.eof()) {
		// ���� �׸� �տ� ���� ������ �ǳʶڴ�.
		inputFile >> ws;
		printStreamState(inputFile);
		string temp;
		getline(inputFile, temp);
		printStreamState(inputFile);
		if (!temp.empty()) {
			cout << "Citation " << count << ": " << temp << endl;
			count++;
		}
	}

	cout << "Found " << count << " citations" << endl;
	cout << "readFile(): reading citations" << endl;
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
			printStreamState(inputFile);
			if (!temp.empty()) {
				cout << temp << endl;
				mCitations[count] = temp;
			}
		}
	} else {
		mNumCitations = -1;
	}

	cout << "readFile(): finished" << endl;
}
