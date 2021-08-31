#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <stdexcept>

template <typename T>
class AssociativeArray
{
public:
	virtual ~AssociativeArray() = default;
	
	T& operator[](std::string_view key);
	const T& operator[](std::string_view key) const;

private:
	class Element
	{
	public:
		Element(std::string_view key, const T& value)
			: mKey(key), mValue(value) {}
		std::string mKey;
		T mValue;
	};

	std::vector<Element> mData;
};

template <typename T>
T& AssociativeArray<T>::operator[](std::string_view key)
{
	// Ű�� �̹� �ִ��� Ȯ���Ѵ�.
	for (auto& element : mData) {
		if (element.mKey == key)
			return element.mValue;
	}

	// �� �κп� �����ߴٸ� Ű�� �������� �ʴ´ٴ� ���̹Ƿ� Ű�� �߰��Ѵ�.
	mData.push_back(Element(key, T()));
	// ��� �߰��� ���� ���� ���۷����� �����Ѵ�.
	return mData.back().mValue;
}

template <typename T>
const T& AssociativeArray<T>::operator[](std::string_view key) const
{
	for (auto& element : mData) {
		if (element.mKey == key)
			return element.mValue;
	}
	throw std::invalid_argument(std::string(key.data()) + " doesn't exist");
	//throw std::invalid_argument("Key '"s + key.data() + "' doesn't exist");
}