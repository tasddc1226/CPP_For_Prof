#pragma once

#include <cstddef>
#include <vector>
#include <list>
#include <iterator> 
#include <string>
#include <initializer_list>
#include <functional>

namespace ProCpp {

	// ����Ʈ �ؽ� ��ü
	template <typename T>
	class hash
	{
	public:
		size_t operator()(const T& key) const;
	};

	// string�� ���� �ؽ� Ư��ȭ
	template <>
	class hash<std::string>
	{
	public:
		size_t operator()(const std::string& key) const;
	};




	// const_hash_map_iterator Ŭ���� ����
	template <typename HashMap>
	class const_hash_map_iterator
	{
		// hash_map Ŭ������ const_hash_map_iterator�� ��� ���ҿ� ������ �� �־�� �Ѵ�.
		friend HashMap;

	public:
		using value_type = typename HashMap::value_type;
		using difference_type = ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = value_type*;
		using reference = value_type&;
		using list_iterator_type = typename HashMap::ListType::const_iterator;

		// ����� �ݺ��ڴ� �ݵ�� �⺻ �����ڸ� �����ؾ� �Ѵ�.
        // �⺻ �����ڷ� ���� �ݺ��ڸ� ����ϴ� ����� Ư���� ������ ���� �����Ƿ�
        // ���ϴ� ������� �ʱ�ȭ�ϸ� �ȴ�.
		const_hash_map_iterator() = default;

		const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* hashmap);

		// ���� �����ڳ� operator=�� ������ �ʿ�� ����.
		// �⺻ ���۸����� ����ϱ� �����̴�.

		// �Ҹ��� ���� �⺻ ����(mHashmap�� �������� �ʴ� ��)���� ����ϹǷ�
		// ������ ������ �ʿ� ����.

		const value_type& operator*() const;

		// ->�����ڸ� ������ �� �ִ� Ÿ���� �����ؾ� �Ѵ�.
		// pair<const Key, T>�� ���� �����͸� �����Ѵ�.
		// �׷��� �����Ϸ��� ���⿡ ->�� �ٽ� �����Ѵ�.
		const value_type* operator->() const;

		const_hash_map_iterator<HashMap>& operator++();
		const_hash_map_iterator<HashMap> operator++(int);

		const_hash_map_iterator<HashMap>& operator--();
		const_hash_map_iterator<HashMap> operator--(int);

		// ��� �Լ��� ������ ���� �����ص� �ȴ�.
		// �پ��� Ÿ�԰� ���ϴ� ����� �������� �ʱ� �����̴�.
		bool operator==(const const_hash_map_iterator<HashMap>& rhs) const;
		bool operator!=(const const_hash_map_iterator<HashMap>& rhs) const;

	protected:
		size_t mBucketIndex = 0;
		list_iterator_type mListIterator;
		const HashMap* mHashmap = nullptr;

		// operator++�� operator--�� ���� ���� �޼���
		void increment();
		void decrement();
	};

	template <typename HashMap>
	class hash_map_iterator : public const_hash_map_iterator<HashMap>
	{
		// hash_map Ŭ������ const_hash_map_iterator�� ��� ���ҿ� ������ �� �־�� �Ѵ�.
		friend HashMap;

	public:
		using value_type = typename const_hash_map_iterator<HashMap>::value_type;
		using difference_type = ptrdiff_t;
		using iterator_category = std::bidirectional_iterator_tag;
		using pointer = value_type*;
		using reference = value_type&;
		using list_iterator_type = typename HashMap::ListType::iterator;

		hash_map_iterator() = default;
		hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap* hashmap);
		
		value_type& operator*();
		value_type* operator->();

		hash_map_iterator<HashMap>& operator++();
		hash_map_iterator<HashMap> operator++(int);

		hash_map_iterator<HashMap>& operator--();
		hash_map_iterator<HashMap> operator--(int);
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
		using hasher = Hash;
		using key_equal = KeyEqual;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = size_t;
		using difference_type = ptrdiff_t;
		using hash_map_type = hash_map<Key, T, KeyEqual, Hash>;
		using iterator = hash_map_iterator<hash_map_type>;
		using const_iterator = const_hash_map_iterator<hash_map_type>;

	private:
		using ListType = std::list<value_type>;
	public:
		using local_iterator = typename ListType::iterator;
		using const_local_iterator = typename ListType::const_iterator;

		// iterator Ŭ������ hash_map�� ��� ���ҿ� ������ �� �־�� �Ѵ�.
		friend class hash_map_iterator<hash_map_type>;
		friend class const_hash_map_iterator<hash_map_type>;

		// ���� �Ҹ���
		virtual ~hash_map() = default;

		// ��Ŷ ���� ���� ������ invalid_argument �ͼ����� ������.
		explicit hash_map(const KeyEqual& equal = KeyEqual(), size_type numBuckets = 101, const Hash& hash = Hash());

		// ��Ŷ ���� ���� ������ invalid_argument �ͼ����� ������.
		template <typename InputIterator>
		hash_map(InputIterator first, InputIterator last, const KeyEqual& equal = KeyEqual(),
			size_type numBuckets = 101, const Hash& hash = Hash());

		// �̴ϼȶ����� ����Ʈ ������
		// ��Ŷ ���� ���� ������ invalid_argument �ͼ����� ������.
		explicit hash_map(std::initializer_list<value_type> il, const KeyEqual& equal = KeyEqual(),
			size_type numBuckets = 101, const Hash& hash = Hash());

		// ���� ������
		hash_map(const hash_map_type& src) = default;
		// �̵� ������
		hash_map(hash_map_type&& src) noexcept = default;

		// ���� ���� ������
		hash_map_type& operator=(const hash_map_type& rhs);
		// �̵� ���� ������
		hash_map_type& operator=(hash_map_type&& rhs) noexcept;
		// �̴ϼȶ����� ����Ʈ ���� ������
		hash_map_type& operator=(std::initializer_list<value_type> il);

		// �ݺ��� �޼���
		iterator begin();
		iterator end();
		const_iterator begin() const;
		const_iterator end() const;
		const_iterator cbegin() const;
		const_iterator cend() const;

		// ũ�� ���� �޼���
		bool empty() const;
		size_type size() const;
		size_type max_size() const;

		// ���� �߰� �޼���
		T& operator[](const key_type& k);
		std::pair<iterator, bool> insert(const value_type& x);
		iterator insert(const_iterator hint, const value_type& x);
		template <typename InputIterator>
		void insert(InputIterator first, InputIterator last);
		void insert(std::initializer_list<value_type> il);

		// ���� ���� �޼���
		size_type erase(const key_type& k);
		iterator erase(iterator position);
		iterator erase(iterator first, iterator last);

		// ��Ÿ ���� ��ƿ��Ƽ
		void swap(hash_map_type& other) noexcept;
		void clear() noexcept;

		// ǥ�� ���̺귯�� ���ǿ� ���߱� ���� ���� �޼���
		key_equal key_eq() const;
		hasher hash_function() const;

		// ��� �޼���
		iterator find(const key_type& k);
		const_iterator find(const key_type& k) const;
		std::pair<iterator, iterator> equal_range(const key_type& k);
		std::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

		size_type count(const key_type& k) const;

		size_type bucket_count() const;
		size_type max_bucket_count() const;
		size_type bucket(const Key& k) const;
		size_type bucket_size(size_type n) const;
		local_iterator begin(size_type n);
		const_local_iterator begin(size_type n) const;
		const_local_iterator cbegin(size_type n) const;
		local_iterator end(size_type n);
		const_local_iterator end(size_type n) const;
		const_local_iterator cend(size_type n) const;

	private:
		// �־��� Ű�� �߰��� ���ҿ� ���� �ݺ��ڿ� �� ������ ��Ŷ �ε����� ������ ��
		std::pair<typename ListType::iterator, size_t> findElement(const key_type& k);

		std::vector<ListType> mBuckets;
		size_type mSize = 0;
		KeyEqual mEqual;
		Hash mHash;
	};

}

#include "hash_map.inl"
