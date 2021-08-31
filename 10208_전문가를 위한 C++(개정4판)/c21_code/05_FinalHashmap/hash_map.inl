#include <stdexcept>
#include <algorithm>
#include <utility>

namespace ProCpp {

	// Ű�� ����Ʈ �������� ����ϰ� �� ����Ʈ�� �ƽ�Ű ���� ��� ���ϴ� ������� �ؽø� ����Ѵ�.
	template <typename T>
	size_t hash<T>::operator()(const T& key) const
	{
		size_t bytes = sizeof(key);
		size_t sum = 0;
		for (size_t i = 0; i < bytes; ++i) {
			unsigned char b = *(reinterpret_cast<const unsigned char*>(&key) + i);
			sum += b;
		}
		return sum;
	}




	// ��� ������ �ƽ�Ű ���� ���ؼ� �ؽø� ����Ѵ�.
	size_t hash<std::string>::operator()(const std::string& key) const
	{
		size_t sum = 0;
		for (auto c : key) {
			sum += static_cast<unsigned char>(c);
		}
		return sum;
	}




	template<typename HashMap>
	const_hash_map_iterator<HashMap>::const_hash_map_iterator(size_t bucket, list_iterator_type listIt, const HashMap* hashmap)
		: mBucketIndex(bucket), mListIterator(listIt), mHashmap(hashmap)
	{
	}

	// ���� ���ҿ� ���� ���۷����� �����Ѵ�.
	template<typename HashMap>
	const typename const_hash_map_iterator<HashMap>::value_type&
		const_hash_map_iterator<HashMap>::operator*() const
	{
		return *mListIterator;
	}

	// ���� ���ҿ� ���� �����͸� �����Ѵ�.
	// �׷��� �����Ϸ��� ���ϴ� �ʵ忡 ������ �� ->�� �����Ѵ�.
	template<typename HashMap>
	const typename const_hash_map_iterator<HashMap>::value_type*
		const_hash_map_iterator<HashMap>::operator->() const
	{
		return &(*mListIterator);
	}

	// ��ü���� �۾��� increment() ���� �޼���� ó���Ѵ�.
	template<typename HashMap>
	const_hash_map_iterator<HashMap>& const_hash_map_iterator<HashMap>::operator++()
	{
		increment();
		return *this;
	}

	// ��ü���� �۾��� increment() ���� �޼���� ó���Ѵ�.
	template<typename HashMap>
	const_hash_map_iterator<HashMap> const_hash_map_iterator<HashMap>::operator++(int)
	{
		auto oldIt = *this;
		increment();
		return oldIt;
	}

	// ��ü���� �۾��� decrement() ���� �޼���� ó���Ѵ�.
	template<typename HashMap>
	const_hash_map_iterator<HashMap>& const_hash_map_iterator<HashMap>::operator--()
	{
		decrement();
		return *this;
	}

	// ��ü���� �۾��� decrement() ���� �޼���� ó���Ѵ�.
	template<typename HashMap>
	const_hash_map_iterator<HashMap> const_hash_map_iterator<HashMap>::operator--(int)
	{
		auto oldIt = *this;
		decrement();
		return oldIt;
	}

	template<typename HashMap>
	bool const_hash_map_iterator<HashMap>::operator==(const const_hash_map_iterator<HashMap>& rhs) const
	{
		// �ݺ��ڰ� ����Ű�� hash_map�� ������ ��� �ʵ尡 �ݵ�� ���ƾ� �Ѵ�.
		return (mHashmap == rhs.mHashmap &&
			mBucketIndex == rhs.mBucketIndex &&
			mListIterator == rhs.mListIterator);
	}

	template<typename HashMap>
	bool const_hash_map_iterator<HashMap>::operator!=(const const_hash_map_iterator<HashMap>& rhs) const
	{
		return !(*this == rhs);
	}

	// mListIterator�� �̹� ������ ���� �ٷ� ������ ����Ű�� �ִٸ� ������������ �۵��ϰų�
	// �߸��� ����� ���´�.
	// element, or is otherwise invalid.
	template<typename HashMap>
	void const_hash_map_iterator<HashMap>::increment()
	{
		// mListIterator�� �� ��Ŷ�� ���� �ݺ��ڴ�. �ϳ� ������Ų��.
		++mListIterator;

		// ���� ��Ŷ�� ���� �ִٸ� ���� ��Ŷ�� ã�´�.
		auto& buckets = mHashmap->mBuckets;
		if (mListIterator == end(buckets[mBucketIndex])) {
			for (size_t i = mBucketIndex + 1; i < buckets.size(); i++) {
				if (!buckets[i].empty()) {
					// ��� ���� ���� ��Ŷ�� �߰��� ���.
					// mListIterator�� �� ��Ŷ�� ù��° ���Ҹ� ����Ű�� �Ѵ�.
					mListIterator = begin(buckets[i]);
					mBucketIndex = i;
					return;
				}
			}
			// �� �̻� ��� ���� ���� ��Ŷ�� ������
			// mListIterator�� ������ ����Ʈ�� �� �ݺ��ڸ� ����Ű���� �����Ѵ�.
			mBucketIndex = buckets.size() - 1;
			mListIterator = end(buckets[mBucketIndex]);
		}
	}

	// mListIterator�� ù ��° ���Ҹ� ����Ű�� ���� ���� ������ ���ǵǾ� ���� �ʴ�.
	// �� ���¿��� �����ϸ� ������ �߻��Ѵ�.
	template<typename HashMap>
	void const_hash_map_iterator<HashMap>::decrement()
	{
		// mListIterator�� �� ��Ŷ�� ���� �ݺ��ڴ�.
		// ���� ��Ŷ�� ���� ������ ����Ű�� �ִٸ� ���ҽ�Ű�� �ʰ�,
		// ���� �������� �տ� �ִ� ��Ŷ �߿��� ��� ���� �ʴ� ���� ã�´�.
		auto& buckets = mHashmap->mBuckets;
		if (mListIterator == begin(buckets[mBucketIndex])) {
			for (int i = mBucketIndex - 1; i >= 0; --i) {
				if (!buckets[i].empty()) {
					mListIterator = --end(buckets[i]);
					mBucketIndex = i;
					return;
				}
			}
			// �� �̻� ��� ���� ���� ��Ŷ�� ���ٸ� ���ҽ�Ű�� �� �ȴ�.
			// mListIterator�� ������ ����Ʈ�� �� �ݺ��ڸ� ����Ű���� �����Ѵ�.
			mBucketIndex = buckets.size() - 1;
			mListIterator = end(buckets[mBucketIndex]);
		} else {
			// ��Ŷ�� ���� ������ ���� �������� �ʾ����Ƿ� �� ĭ ������ �̵��Ѵ�.
			--mListIterator;
		}
	}




	template<typename HashMap>
	hash_map_iterator<HashMap>::hash_map_iterator(size_t bucket, list_iterator_type listIt, HashMap* hashmap)
		: const_hash_map_iterator<HashMap>(bucket, listIt, hashmap)
	{
	}

	// ���� ���ҿ� ���� ���۷����� �����Ѵ�.
	template<typename HashMap>
	typename hash_map_iterator<HashMap>::value_type&
		hash_map_iterator<HashMap>::operator*()
	{
		return const_cast<value_type&>(*this->mListIterator);
	}

	// ���� ���ҿ� ���� �����͸� �����Ѵ�. �׷��� �����Ϸ��� ���ϴ� �ʵ忡 ������ ��->�� ����Ѵ�.
	template<typename HashMap>
	typename hash_map_iterator<HashMap>::value_type*
		hash_map_iterator<HashMap>::operator->()
	{
		return const_cast<value_type*>(&(*this->mListIterator));
	}

	// ��ü���� �۾��� ���̽� Ŭ������ increment() ���� �޼���� ó���Ѵ�.
	template<typename HashMap>
	hash_map_iterator<HashMap>& hash_map_iterator<HashMap>::operator++()
	{
		this->increment();
		return *this;
	}

	// ��ü���� �۾��� ���̽� Ŭ������ increment() ���� �޼���� ó���Ѵ�.
	template<typename HashMap>
	hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator++(int)
	{
		auto oldIt = *this;
		this->increment();
		return oldIt;
	}

	//��ü���� �۾��� ���̽� Ŭ������ decrement() ���� �޼���� ó���Ѵ�.
	template<typename HashMap>
	hash_map_iterator<HashMap>& hash_map_iterator<HashMap>::operator--()
	{
		this->decrement();
		return *this;
	}

	//��ü���� �۾��� ���̽� Ŭ������ decrement() ���� �޼���� ó���Ѵ�.
	template<typename HashMap>
	hash_map_iterator<HashMap> hash_map_iterator<HashMap>::operator--(int)
	{
		auto oldIt = *this;
		this->decrement();
		return oldIt;
	}




	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void swap(hash_map<Key, T, KeyEqual, Hash>& first, hash_map<Key, T, KeyEqual, Hash>& second) noexcept
	{
		first.swap(second);
	}




	// mBuckets�� ũ�⸦ ������ ��Ŷ ���� �����Ѵ�.
	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>::hash_map(const KeyEqual& equal, size_type numBuckets, const Hash& hash)
		: mBuckets(numBuckets), mEqual(equal), mHash(hash)
	{
		if (numBuckets == 0) {
			throw std::invalid_argument("Number of buckets must be positive");
		}
	}

	// ���Ҹ� ������ �߰��ϵ��� insert()�� ȣ���Ѵ�.
	template <typename Key, typename T, typename KeyEqual, typename Hash>
	template <typename InputIterator>
	hash_map<Key, T, KeyEqual, Hash>::hash_map(InputIterator first, InputIterator last, const KeyEqual& equal, size_type numBuckets, const Hash& hash)
		: hash_map(equal, numBuckets, hash)
	{
		insert(first, last);
	}

	// �̴ϼȶ����� ����Ʈ ������
	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>::hash_map(std::initializer_list<value_type> il, const KeyEqual& equal, size_type numBuckets, const Hash& hash)
		: hash_map(equal, numBuckets, hash)
	{
		insert(std::begin(il), std::end(il));
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>&
		hash_map<Key, T, KeyEqual, Hash>::operator=(const hash_map_type& rhs)
	{
		// �ڱ� �ڽ� ���� ���� Ȯ��
		if (this == &rhs) {
			return *this;
		}

		// ���� �� �¹ٲٱ� ����
		auto copy = rhs;  // ��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
		swap(copy);       // ó���� ����� �ͼ����� ������ �ʴ� �������� �ݿ��Ѵ�.
		return *this;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>&
		hash_map<Key, T, KeyEqual, Hash>::operator=(hash_map_type&& rhs) noexcept
	{
		swap(rhs);
		return *this;
	}

	// �̴ϼȶ����� ����Ʈ ���� ������
	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>&
		hash_map<Key, T, KeyEqual, Hash>::operator=(std::initializer_list<value_type> il)
	{
		// ��� �۾��� �ӽ� �ν��Ͻ����� ó���Ѵ�.
		hash_map_type newHashMap(il, mEqual, mBuckets.size(), mHash);
		swap(newHashMap);  // ó���� ����� �ͼ����� ������ �ʴ� �������� �ݿ��Ѵ�.
		return *this;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	std::pair<typename hash_map<Key, T, KeyEqual, Hash>::ListType::iterator, size_t>
		hash_map<Key, T, KeyEqual, Hash>::findElement(const key_type& k)
	{
		// Ű�� �ؽ��ؼ� ��Ŷ�� ���Ѵ�.
		size_t bucket = mHash(k) % mBuckets.size();

		// ��Ŷ���� �־��� Ű�� ���� ���Ҹ� ã�´�.
		auto iter = find_if(std::begin(mBuckets[bucket]), std::end(mBuckets[bucket]),
			[this, &k](const auto& element) { return mEqual(element.first, k); });

		// �ݺ��ڿ� ��Ŷ �ε����� ������ ���� �����Ѵ�.
		return std::make_pair(iter, bucket);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::iterator
		hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k)
	{
		// findElement() ���ۿ� C++17 ������ ���ε��� ����Ѵ�.
		auto[it, bucket] = findElement(k);
		if (it == std::end(mBuckets[bucket])) {
			// ���Ҹ� �߰����� ���� ��� -- �� �ݺ��ڸ� �����Ѵ�.
			return end();
		}
		// ���Ҹ� �߰��� ��� -- ��Ŷ/�ݺ��ڸ� hash_map_iterator�� ��ȯ�Ѵ�.
		return hash_map_iterator<hash_map_type>(bucket, it, this);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_iterator
		hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k) const
	{
		return const_cast<hash_map_type*>(this)->find(k);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	std::pair<typename hash_map<Key, T, KeyEqual, Hash>::iterator,
		typename hash_map<Key, T, KeyEqual, Hash>::iterator>
		hash_map<Key, T, KeyEqual, Hash>::equal_range(const key_type& k)
	{
		auto it = find(k);
		return std::make_pair(it, it);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	std::pair<typename hash_map<Key, T, KeyEqual, Hash>::const_iterator,
		typename hash_map<Key, T, KeyEqual, Hash>::const_iterator>
		hash_map<Key, T, KeyEqual, Hash>::equal_range(const key_type& k) const
	{
		auto it = find(k);
		return std::make_pair(it, it);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::count(const key_type& k) const
	{
		// �־��� k�� ��ġ�ϴ� ���Ҵ� 1�� �ƴϸ� 0����.
		// ���Ҹ� ã���� 1��, �׷��� ������ 0�� �����Ѵ�.
		if (find(k) == end()) {
			return 0;
		} else {
			return 1;
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	T& hash_map<Key, T, KeyEqual, Hash>::operator[] (const key_type& k)
	{
		// �ڵ尡 �ټ� ����������, ������ �ϴ� ����
        // k��� Ű�� ���� ���ο� Ű/�� ���� �߰��ϰ� 0���� �ʱ�ȭ�ϴ� ���̴�.
        // insert ������ ���� ���ο� ������� interator�� bool�� ������ ���� �����Ѵ�.
        // ���⿡ �ִ� �ݺ��ڴ� key/value ���� ����Ű��, �� ��° ���Ұ� �����ؾ� �� ���̴�.

		return ((insert(std::make_pair(k, T()))).first)->second;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	std::pair<typename hash_map<Key, T, KeyEqual, Hash>::iterator, bool>
		hash_map<Key, T, KeyEqual, Hash>::insert(const value_type& x)
	{
		// ���Ҹ� ã�ƺ���.
		auto[it, bucket] = findElement(x.first);
		bool inserted = false;
		if (it == std::end(mBuckets[bucket])) {
			// ���Ҹ� �� ã�Ҵٸ� ���� �߰��Ѵ�.
			it = mBuckets[bucket].insert(it, x);
			inserted = true;
			mSize++;
		}
		return std::make_pair(hash_map_iterator<hash_map_type>(bucket, it, this), inserted);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::iterator
		hash_map<Key, T, KeyEqual, Hash>::insert(const_iterator /*hint*/, const value_type& x)
	{
		// ��ġ�� ������ �����Ѵ�.
		return insert(x).first;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	template <typename InputIterator>
	void hash_map<Key, T, KeyEqual, Hash>::insert(InputIterator first, InputIterator last)
	{
		// insert_iterator ����͸� �̿��Ͽ� �־��� ������ �ִ� ���Ҹ� ��� �����Ѵ�.
		// �־��� begin()�� ��ġ�� ū �ǹ̰� ����. insert �޼���� ������ �� ���� �����Ѵ�.
		std::insert_iterator<hash_map_type> inserter(*this, begin());
		std::copy(first, last, inserter);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::insert(std::initializer_list<value_type> il)
	{
		insert(std::begin(il), std::end(il));
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::erase(const key_type& k)
	{
		// ���� ���Ҹ� ã�ƺ���.
		auto[it, bucket] = findElement(k);
		if (it != std::end(mBuckets[bucket])) {
			// ���Ҹ� ã�Ҵٸ� �����Ѵ�.
			mBuckets[bucket].erase(it);
			mSize--;
			return 1;
		}
		else {
			return 0;
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::iterator
		hash_map<Key, T, KeyEqual, Hash>::erase(iterator position)
	{
		iterator next = position;
		++next;

		// �ش� ��Ŷ���� ���Ҹ� �����Ѵ�.
		mBuckets[position.mBucketIndex].erase(position.mListIterator);
		mSize--;

		return next;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::iterator
		hash_map<Key, T, KeyEqual, Hash>::erase(iterator first, iterator last)
	{
		// �־��� ������ �ִ� ���Ҹ� ��� �����Ѵ�.
		for (iterator next = first; next != last;) {
			next = erase(next);
		}

		return last;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::clear() noexcept
	{
		// �� ��Ŷ���� clear()�� ȣ���Ѵ�.
		for (auto& bucket : mBuckets) {
			bucket.clear();
		}
		mSize = 0;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	bool hash_map<Key, T, KeyEqual, Hash>::empty() const
	{
		return mSize == 0;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::size() const
	{
		return mSize;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::max_size() const
	{
		// �־��� ���, ��� ���Ұ� ������ ����Ʈ�� �ؽ̵� �� �ִ�. ���� max_size�� �� ����Ʈ�� �ִ� ũ��� ��´�.
		// �� �ڵ�� ��� ����Ʈ�� ũ�Ⱑ max_size��� �����Ѵ�.
		return mBuckets[0].max_size();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::swap(hash_map_type& other) noexcept
	{
		using std::swap;

		swap(mBuckets, other.mBuckets);
		swap(mSize, other.mSize);
		swap(mEqual, other.mEqual);
		swap(mHash, other.mHash);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::iterator
		hash_map<Key, T, KeyEqual, Hash>::begin()
	{
		if (mSize == 0) {
			// Ư���� ���: ���Ұ� ������ �� �ݺ��ڸ� �����Ѵ�.
			return end();
		}

		// ���Ұ� �ּ� �ϳ��� �ִٸ� ù ��° ���Ҹ� �˻��Ѵ�.
		for (size_t i = 0; i < mBuckets.size(); ++i) {
			if (!mBuckets[i].empty()) {
				return hash_map_iterator<hash_map_type>(i, std::begin(mBuckets[i]), this);
			}
		}
		// ������� �� ���� ������ Ȥ�ö� ���� �Ǹ� �� �ݺ��ڸ� �����Ѵ�.
		return end();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_iterator
		hash_map<Key, T, KeyEqual, Hash>::begin() const
	{
		// const_cast�� �̿��Ͽ� begin()�� non-const ������ ȣ���Ѵ�.
		// �׷��� const_iterator�� ��ȯ�� �� �ִ� �ݺ��ڷ� ��ȯ�Ѵ�.
		return const_cast<hash_map_type*>(this)->begin();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_iterator
		hash_map<Key, T, KeyEqual, Hash>::cbegin() const
	{
		return begin();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::iterator
		hash_map<Key, T, KeyEqual, Hash>::end()
	{
		// ���⼭ �� �ݺ��ڴ� ������ ��Ŷ�� �ִ� ����Ʈ�� �� �ݺ��ڴ�.
		size_t bucket = mBuckets.size() - 1;
		return hash_map_iterator<hash_map_type>(bucket, std::end(mBuckets[bucket]), this);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_iterator
		hash_map<Key, T, KeyEqual, Hash>::end() const
	{
		// const_cast�� �̿��Ͽ� end()�� non-const ������ ȣ���Ѵ�.
		// �׷��� const_iterator�� ��ȯ�� �� �ִ� �ݺ��ڷ� ��ȯ�Ѵ�.
		return const_cast<hash_map_type*>(this)->end();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_iterator
		hash_map<Key, T, KeyEqual, Hash>::cend() const
	{
		return end();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::key_equal
		hash_map<Key, T, KeyEqual, Hash>::key_eq() const
	{
		return mEqual;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::hasher
		hash_map<Key, T, KeyEqual, Hash>::hash_function() const
	{
		return mHash;
	}


	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::bucket_count() const
	{
		return mBuckets.size();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::max_bucket_count() const
	{
		return mBuckets.max_size();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::bucket(const Key& k) const
	{
		return const_cast<hash_map_type*>(this)->findElement(k).second;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::size_type
		hash_map<Key, T, KeyEqual, Hash>::bucket_size(size_type n) const
	{
		return mBuckets[n].size();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::local_iterator
		hash_map<Key, T, KeyEqual, Hash>::begin(size_type n)
	{
		return mBuckets[n].begin();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_local_iterator
		hash_map<Key, T, KeyEqual, Hash>::begin(size_type n) const
	{
		return mBuckets[n].begin();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_local_iterator
		hash_map<Key, T, KeyEqual, Hash>::cbegin(size_type n) const
	{
		return mBuckets[n].cbegin();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::local_iterator
		hash_map<Key, T, KeyEqual, Hash>::end(size_type n)
	{
		return mBuckets[n].end();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_local_iterator
		hash_map<Key, T, KeyEqual, Hash>::end(size_type n) const
	{
		return mBuckets[n].end();
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::const_local_iterator
		hash_map<Key, T, KeyEqual, Hash>::cend(size_type n) const
	{
		return mBuckets[n].cend();
	}

}