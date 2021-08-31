#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <stdexcept>
#include "RingBuffer.h"

using namespace std;

// ��Ȯ�� numEntries�� ������ ������ŭ�� �㵵�� vector�� �ʱ�ȭ�Ѵ�.
// vector�� ũ��� ��ü�� ������ ������ �Ҹ��� ������ ������ �ʴ´�.
// �ٸ� ����� �ʱ�ȭ�Ѵ�.
RingBuffer::RingBuffer(size_t numEntries, ostream* ostr)
	: mEntries(numEntries)
	, mOstr(ostr)
	, mWrapped(false)
{
	if (numEntries == 0)
		throw invalid_argument("Number of entries must be > 0.");
	mNext = begin(mEntries);
}

// addStringEntry�� ����� �˰����� �����ϴ�. �־��� �׸��� ������° ���ڸ��� �ְ�,
// mNext�� �״��� ��° ���ڸ��� ����Ű���� �����Ѵ�.
// mNext�� vector�� ���� �����ϸ� 0���� �ٽ� �����Ѵ�.
//
// �� ���۴� ���� ���θ� �˾ƾ� �Ѵ�.
// �׷��� operator<<���� mNext ������ �׸��� ������� ������ �� �ִ�.
void RingBuffer::addStringEntry(string&& entry)
{
	// ostream�� ������ ������ ���⿡ �־��� �׸��� ����.
	if (mOstr) {
		*mOstr << entry << endl;
	}

	// �־��� �׸��� ���� ��° ���ڸ��� �̵���Ų��.
	// �׷� ���� mNext�� �ϳ� �������� �״��� ���ڸ��� ����Ű�� �����.
	*mNext = std::move(entry);
	++mNext;

	// ������ ���� �����ߴ��� Ȯ���Ѵ�. �׷��ٸ� �ٽ� �� ���� ���ٰ� ǥ���Ѵ�.
	if (mNext == end(mEntries)) {
		mNext = begin(mEntries);
		mWrapped = true;
	}
}

// ��� ��Ʈ���� �����Ѵ�.
ostream* RingBuffer::setOutput(ostream* newOstr)
{
	return std::exchange(mOstr, newOstr);
}

// operator<<�� ostream_iterator�� �̿��ؼ�
// �׸���� vector���� ��� ��Ʈ������ ���� �����Ѵ�.
//
// operator<<�� �ݵ�� �׸��� ������� ����ؾ� �Ѵ�. ���۰� �� ���� ���Ҵٸ�
// ���� ���� ����� �׸��� ���� �ֱ� �׸�(mNext�� ����Ű�� �׸�)�� �ٷ� ������ ���´�.
// ���� ���� mNext �׸���� ������ ����Ѵ�.
//
// �׷��� ���� (���۰� �� ���� ���� �ʴ���) ���ۺ��� mNext-1���� ����Ѵ�.
ostream& operator<<(ostream& ostr, RingBuffer& rb)
{
	if (rb.mWrapped) {
		// ���۰� �� ���� ���Ҵٸ� ���� ������ �׸���� ������ ����Ѵ�.
		copy(rb.mNext, end(rb.mEntries), ostream_iterator<string>(ostr, "\n"));
	}

	// ���� ���� �ֱ� �׸���� ����Ѵ�.
	// mNext���� �Ž��� �ö󰣴�. �� ������ ������ �׸��� �������� �ʱ� �����̴�.
	copy(begin(rb.mEntries), rb.mNext, ostream_iterator<string>(ostr, "\n"));

	return ostr;
}
