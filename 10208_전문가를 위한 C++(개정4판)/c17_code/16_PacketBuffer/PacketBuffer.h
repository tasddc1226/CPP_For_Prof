#pragma once

#include <cstddef>
#include <queue>
#include <stdexcept>

template <typename T>
class PacketBuffer
{
public:
	// maxSize�� 0�̸� ũ�⿡ ���� ����. ������ ũ�Ⱑ 0�� �� ���� ���� �����̴�.
	// maxSize�� 0�� �ƴ� �ٸ� ���̶��, �� ���� �� ����ŭ�� ������ �� �ִ�.
	PacketBuffer(size_t maxSize = 0);

	virtual ~PacketBuffer() = default;

	// ���ۿ� ��Ŷ�� �����Ѵ�.
	// ���ۿ� ������ ��� ��Ŷ�� ������ ���� false�� �����ϰ�,
	// �׷��� ������ true�� �����Ѵ�.
	bool bufferPacket(const T& packet);

	// ���� ��Ŷ�� �����Ѵ�. ���۰� ����ٸ� out_of_range �ͼ����� ������.
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
		// �� �̻� ������ �����Ƿ� ��Ŷ�� ������.
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
	// �� ��(head) ���Ҹ� �����´�.
	T temp = mPackets.front();
	// �� �� ���Ҹ� �����Ѵ�.
	mPackets.pop();
	// �� �� ���Ҹ� �����Ѵ�.
	return temp;
}
