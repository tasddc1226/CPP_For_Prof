#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <stdexcept>
#include "RingBuffer.h"

using namespace std;

// 정확히 numEntries에 지정된 갯수만큼만 담도록 vector를 초기화한다.
// vector의 크기는 객체를 생성할 때부터 소멸할 때까지 변하지 않는다.
// 다른 멤버도 초기화한다.
RingBuffer::RingBuffer(size_t numEntries, ostream* ostr)
	: mEntries(numEntries)
	, mOstr(ostr)
	, mWrapped(false)
{
	if (numEntries == 0)
		throw invalid_argument("Number of entries must be > 0.");
	mNext = begin(mEntries);
}

// addStringEntry에 적용된 알고리즘은 간단하다. 주어진 항목을 다음번째 빈자리에 넣고,
// mNext가 그다음 번째 빈자리를 가리키도록 리셋한다.
// mNext가 vector의 끝에 도달하면 0부터 다시 시작한다.
//
// 이 버퍼는 래핑 여부를 알아야 한다.
// 그래야 operator<<에서 mNext 다음번 항목을 출력할지 결정할 수 있다.
void RingBuffer::addStringEntry(string&& entry)
{
	// ostream에 문제가 없으면 여기에 주어진 항목을 쓴다.
	if (mOstr) {
		*mOstr << entry << endl;
	}

	// 주어진 항목을 다음 번째 빈자리로 이동시킨다.
	// 그런 다음 mNext를 하나 증가시켜 그다음 빈자리를 가리키게 만든다.
	*mNext = std::move(entry);
	++mNext;

	// 버퍼의 끝에 도달했는지 확인한다. 그렇다면 다시 한 바퀴 돈다고 표시한다.
	if (mNext == end(mEntries)) {
		mNext = begin(mEntries);
		mWrapped = true;
	}
}

// 출력 스트림을 지정한다.
ostream* RingBuffer::setOutput(ostream* newOstr)
{
	return std::exchange(mOstr, newOstr);
}

// operator<<는 ostream_iterator를 이용해서
// 항목들을 vector에서 출력 스트림으로 직접 복제한다.
//
// operator<<는 반드시 항목을 순서대로 출력해야 한다. 버퍼가 한 바퀴 돌았다면
// 가장 먼저 저장된 항목이 가장 최근 항목(mNext가 가리키는 항목)의 바로 다음에 나온다.
// 따라서 먼저 mNext 항목부터 끝까지 출력한다.
//
// 그러고 나서 (버퍼가 한 바퀴 돌지 않더라도) 시작부터 mNext-1까지 출력한다.
ostream& operator<<(ostream& ostr, RingBuffer& rb)
{
	if (rb.mWrapped) {
		// 버퍼가 한 바퀴 돌았다면 가장 오래된 항목부터 끝까지 출력한다.
		copy(rb.mNext, end(rb.mEntries), ostream_iterator<string>(ostr, "\n"));
	}

	// 이제 가장 최근 항목까지 출력한다.
	// mNext까지 거슬러 올라간다. 이 범위는 오른쪽 항목을 포함하지 않기 때문이다.
	copy(begin(rb.mEntries), rb.mNext, ostream_iterator<string>(ostr, "\n"));

	return ostr;
}
