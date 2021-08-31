#pragma once

#include <cstddef>
#include <vector>
#include <list>
#include <string>
#include <functional>

namespace ProCpp {

	// ����Ʈ �ؽ� ��ü
	template <typename T>
	class hash
	{
	public:
		size_t operator()(const T& key) const;
	};

	// ��Ʈ���� ���� �ؽ� Ư��ȭ
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

		// ���� �Ҹ���
		virtual ~hash_map() = default;

		// ��Ŷ ���� ���� ������ invalid_argument�� ������.
		explicit hash_map(const KeyEqual& equal = KeyEqual(), size_t numBuckets = 101, const Hash& hash = Hash());

		// ���� ������
		hash_map(const hash_map<Key, T, KeyEqual, Hash>& src) = default;
		// �̵� ������
		hash_map(hash_map<Key, T, KeyEqual, Hash>&& src) noexcept = default;

		// ���� ���� ������
		hash_map<Key, T, KeyEqual, Hash>& operator=(const hash_map<Key, T, KeyEqual, Hash>& rhs);
		// �̵� ���� ������
		hash_map<Key, T, KeyEqual, Hash>& operator=(hash_map<Key, T, KeyEqual, Hash>&& rhs) noexcept;

		// Ű/�� �� x�� �߰��Ѵ�.
		void insert(const value_type& x);

		// Ű�� k�� ���Ұ� �ִٸ� �����Ѵ�.
		void erase(const key_type& k);

		// ��� ���Ҹ� �����Ѵ�.
		void clear() noexcept;

		// Ű�� k�� ���ҿ� ���� �����͸� �����Ѵ�.
		// �� Ű�� ���� ���Ұ� ������ nullptr�� �����Ѵ�.
		value_type* find(const key_type& k);
		const value_type* find(const key_type& k) const;

		// operator[]�� Ű�� k�� ���Ҹ� ã�ų�
		// �� Ű�� ���Ұ� ���ٸ� ���� �߰��Ѵ�. 
		// �׷��� ���� �ش� Ű�� ���� ���� ���۷����� �����Ѵ�.
		T& operator[] (const key_type& k);

		// �� �ؽ� ���� �¹ٲ۴�.
		void swap(hash_map<Key, T, KeyEqual, Hash>& other) noexcept;

	private:
		using ListType = std::list<value_type>;

		// �־��� Ű�� ���� ���Ҹ� ����Ű�� �ݺ��ڿ� �� ������ ��Ŷ �ε����� ������ ���� �����Ѵ�.
		std::pair<typename ListType::iterator, size_t> findElement(const key_type& k);

		std::vector<ListType> mBuckets;
		size_t mSize = 0;
		KeyEqual mEqual;
		Hash mHash;
	};

}

#include "hash_map.inl"
