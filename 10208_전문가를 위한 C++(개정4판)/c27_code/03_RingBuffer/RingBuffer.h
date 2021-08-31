#pragma once

#include <cstddef>
#include <vector>
#include <string>
#include <ostream>
#include <sstream>

// RingBuffer  Ŭ������ ����뿡 ����� �� ���۸� ������ ������ ���̴�.
// Ŭ���̾�Ʈ�� �� Ŭ������ �����ڿ� �׸� ���� �����Ѵ�.�޽�����a ddEntry()  �޼���� �߰��Ѵ�.
// �׸� ���� ��� ������ ����� ������ �׸��� ���� �׸��� �ִ� �ڸ��� �����.

// �� ���۴� �׸��� ���ۿ� �߰��� �� ��Ʈ���� ����ϴ� �ɼǵ� �����Ѵ�.
// Ŭ���̾�Ʈ�� RingBuffer �� �����ڿ� ��� ��Ʈ���� ������ �� �ְ�, 
// ��Ʈ���� setOutput()  �޼���� ������ �� �ִ�.

// ���������� operator<< �� ���� ��ü�� ��� ��Ʈ������ ��������.
class RingBuffer
{
public:
	// numEntries�� ������ ������ŭ �� ���۸� �����Ѵ�.
	// �׸��� *ostr�� ťó�� �߰��Ѵ�(�ɼ�).
	explicit RingBuffer(size_t numEntries = kDefaultNumEntries, std::ostream* ostr = nullptr);
	virtual ~RingBuffer() = default;

	// �� ���ۿ� �׸��� �߰��Ѵ�. ���۰� ���� ���� �׸��� �����.
	template<typename... Args>
	void addEntry(const Args&... args)
	{
		std::ostringstream os;
		// C++17�� ���� ���� ����� �����Ѵ�(22�� ����).
		((os << args), ...);
		addStringEntry(os.str());
	}

	// ���ۿ� �ִ� �׸��� ostr ��Ʈ���� �� ������ ������.
	friend std::ostream& operator<<(std::ostream& ostr, RingBuffer& rb);

	// �׸��� ������ ��Ʈ���� �߰��� ������ ��Ʈ������ ��������.
	// �� ����� ������ nullptr�� �����Ѵ�.
	// �� �޼���� ������ �����ߴ� ��� ��Ʈ���� �����Ѵ�.
	std::ostream* setOutput(std::ostream* newOstr);

private:
	std::vector<std::string> mEntries;
	std::vector<std::string>::iterator mNext;

	std::ostream* mOstr;
	bool mWrapped;

	static const size_t kDefaultNumEntries = 500;

	void addStringEntry(std::string&& entry);
};
