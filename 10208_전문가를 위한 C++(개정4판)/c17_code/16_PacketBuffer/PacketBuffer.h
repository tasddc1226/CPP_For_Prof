#pragma once

#include <cstddef>
#include <queue>
#include <stdexcept>

template <typename T>
class PacketBuffer
{
public:
	// maxSize가 0이면 크기에 제한 없다. 버퍼의 크기가 0이 될 수는 없기 때문이다.
	// maxSize가 0이 아닌 다른 값이라면, 한 번에 그 수만큼만 저장할 수 있다.
	PacketBuffer(size_t maxSize = 0);

	virtual ~PacketBuffer() = default;

	// 버퍼에 패킷을 저장한다.
	// 버퍼에 공간이 없어서 패킷을 무시할 때는 false를 리턴하고,
	// 그렇지 않으면 true를 리턴한다.
	bool bufferPacket(const T& packet);

	// 다음 패킷을 리턴한다. 버퍼가 비었다면 out_of_range 익셉션을 던진다.
	T getNextPacket();

private:
	std::queue<T> mPackets;
	size_t mMaxSize;
};

template <typename T>
PacketBuffer<T>::PacketBuffer(size_t maxSize/* = 0 */)
	: mMaxSize(maxSize)
{
}

template <typename T>
bool PacketBuffer<T>::bufferPacket(const T& packet)
{
	if (mMaxSize > 0 && mPackets.size() == mMaxSize) {
		// 더 이상 공간이 없으므로 패킷을 버린다.
		return false;
	}

	mPackets.push(packet);
	return true;
}

template <typename T>
T PacketBuffer<T>::getNextPacket()
{
	if (mPackets.empty()) {
		throw std::out_of_range("Buffer is empty");
	}
	// 맨 앞(head) 원소를 가져온다.
	T temp = mPackets.front();
	// 맨 앞 원소를 제거한다.
	mPackets.pop();
	// 맨 앞 원소를 리턴한다.
	return temp;
}
