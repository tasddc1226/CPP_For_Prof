#pragma once

#include <cstddef>
#include <vector>
#include <list>
#include <string>
#include <functional>

namespace ProCpp {

	// 디폴트 해시 객체
	template <typename T>
	class hash
	{
	public:
		size_t operator()(const T& key) const;
	};

	// 스트링에 대한 해시 특수화
	template <>
	class hash<std::string>
	{
	public:
		size_t operator()(const std::string& key) const;
	};




	template <typename Key, typename T,
		typename KeyEqual = std::equal_to<>,
		typename Hash = hash<Key>>
	class hash_map
	{
	public:
		using key_type = Key;
		using mapped_type = T;
		using value_type = std::pair<const Key, T>;

		// 가상 소멸자
		virtual ~hash_map() = default;

		// 버킷 수가 맞지 않으면 invalid_argument를 던진다.
		explicit hash_map(const KeyEqual& equal = KeyEqual(), size_t numBuckets = 101, const Hash& hash = Hash());

		// 복제 생성자
		hash_map(const hash_map<Key, T, KeyEqual, Hash>& src) = default;
		// 이동 생성자
		hash_map(hash_map<Key, T, KeyEqual, Hash>&& src) noexcept = default;

		// 복제 대입 연산자
		hash_map<Key, T, KeyEqual, Hash>& operator=(const hash_map<Key, T, KeyEqual, Hash>& rhs);
		// 이동 대입 연산자
		hash_map<Key, T, KeyEqual, Hash>& operator=(hash_map<Key, T, KeyEqual, Hash>&& rhs) noexcept;

		// 키/값 쌍 x를 추가한다.
		void insert(const value_type& x);

		// 키가 k인 원소가 있다면 삭제한다.
		void erase(const key_type& k);

		// 모든 원소를 삭제한다.
		void clear() noexcept;

		// 키가 k인 원소에 대한 포인터를 리턴한다.
		// 그 키에 대한 원소가 없으면 nullptr를 리턴한다.
		value_type* find(const key_type& k);
		const value_type* find(const key_type& k) const;

		// operator[]는 키가 k인 원소를 찾거나
		// 그 키의 원소가 없다면 새로 추가한다. 
		// 그러고 나서 해당 키의 값에 대한 레퍼런스를 리턴한다.
		T& operator[] (const key_type& k);

		// 두 해시 맵을 맞바꾼다.
		void swap(hash_map<Key, T, KeyEqual, Hash>& other) noexcept;

	private:
		using ListType = std::list<value_type>;

		// 주어진 키에 대한 원소를 가리키는 반복자와 그 원소의 버킷 인덱스로 구성된 쌍을 리턴한다.
		std::pair<typename ListType::iterator, size_t> findElement(const key_type& k);

		std::vector<ListType> mBuckets;
		size_t mSize = 0;
		KeyEqual mEqual;
		Hash mHash;
	};

}

#include "hash_map.inl"
