#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <ostream>
#include <sstream>

// RingBuffer  클래스는 디버깅에 사용할 링 버퍼를 간단히 정의한 것이다.
// 클라이언트는 이 클래스의 생성자에 항목 수를 지정한다.메시지는a ddEntry()  메서드로 추가한다.
// 항목 수가 허용 범위를 벗어나면 다음번 항목이 기존 항목이 있던 자리를 덮어쓴다.

// 이 버퍼는 항목이 버퍼에 추가될 때 스트림에 출력하는 옵션도 제공한다.
// 클라이언트는 RingBuffer 의 생성자에 출력 스트림을 지정할 수 있고, 
// 스트림을 setOutput()  메서드로 리셋할 수 있다.

// 마지막으로 operator<< 로 버퍼 전체를 출력 스트림으로 내보낸다.
class RingBuffer
{
public:
	// numEntries에 지정한 공간만큼 링 버퍼를 생성한다.
	// 항목은 *ostr에 큐처럼 추가한다(옵션).
	explicit RingBuffer(size_t numEntries = kDefaultNumEntries, std::ostream* ostr = nullptr);
	virtual ~RingBuffer() = default;

	// 링 버퍼에 항목을 추가한다. 버퍼가 차면 기존 항목을 덮어쓴다.
	template<typename... Args>
	void addEntry(const Args&... args)
	{
		std::ostringstream os;
		// C++17의 단항 우측 폴드로 구현한다(22장 참조).
		((os << args), ...);
		addStringEntry(os.str());
	}

	// 버퍼에 있는 항목을 ostr 스트링에 줄 단위로 보낸다.
	friend std::ostream& operator<<(std::ostream& ostr, RingBuffer& rb);

	// 항목을 지정한 스트림에 추가할 때마다 스트림으로 내보낸다.
	// 이 기능을 끄려면 nullptr를 지정한다.
	// 이 메서드는 예전에 지정했던 출력 스트림을 리턴한다.
	std::ostream* setOutput(std::ostream* newOstr);

private:
	std::vector<std::string> mEntries;
	std::vector<std::string>::iterator mNext;

	std::ostream* mOstr;
	bool mWrapped;

	static const size_t kDefaultNumEntries = 500;

	void addStringEntry(std::string&& entry);
};
