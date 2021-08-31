#include <stdexcept>
#include <algorithm>
#include <utility>

namespace ProCpp {

	// 키를 바이트 시퀀스로 취급하고 바이트의 아스키값을 더해서 해시를 계산한다.
	template <typename T>
	size_t hash<T>::operator()(const T& key) const
	{
		const size_t bytes = sizeof(key);
		size_t sum = 0;
		for (size_t i = 0; i < bytes; ++i) {
			unsigned char b = *(reinterpret_cast<const unsigned char*>(&key) + i);
			sum += b;
		}
		return sum;
	}




	// 모든 문자의 아스키 값을 더해서 해시를 계산한다.
	size_t hash<std::string>::operator()(const std::string& key) const
	{
		size_t sum = 0;
		for (auto c : key) {
			sum += static_cast<unsigned char>(c);
		}
		return sum;
	}




	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void swap(hash_map<Key, T, KeyEqual, Hash>& first, hash_map<Key, T, KeyEqual, Hash>& second) noexcept
	{
		first.swap(second);
	}




	// mBuckets을 정확한 버킷 수만큼 생성한다.
	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>::hash_map(const KeyEqual& equal, size_t numBuckets, const Hash& hash)
		: mBuckets(numBuckets), mEqual(equal), mHash(hash)
	{
		if (numBuckets == 0) {
			throw std::invalid_argument("Number of buckets must be positive");
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>& hash_map<Key, T, KeyEqual, Hash>::operator=(const hash_map<Key, T, KeyEqual, Hash>& rhs)
	{
		// 자기 자신 대입 여부 확인
		if (this == &rhs) {
			return *this;
		}

		// 복제 후 스왑 구문
		auto copy = rhs;  // 모든 작업을 임시 인스턴스에서 처리한다.
		swap(copy);       // 익셉션을 던지지 않는 연산으로만 처리한다.
		return *this;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	hash_map<Key, T, KeyEqual, Hash>& hash_map<Key, T, KeyEqual, Hash>::operator=(hash_map<Key, T, KeyEqual, Hash>&& rhs) noexcept
	{
		swap(rhs);
		return *this;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	std::pair<typename hash_map<Key, T, KeyEqual, Hash>::ListType::iterator, size_t>
		hash_map<Key, T, KeyEqual, Hash>::findElement(const key_type& k)
	{
		// 키를 해싱해서 버킷을 구한다.
		size_t bucket = mHash(k) % mBuckets.size();

		// 버킷에 있는 키를 검색한다.
		auto iter = find_if(begin(mBuckets[bucket]), end(mBuckets[bucket]),
			[this, &k](const auto& element) { return mEqual(element.first, k); });

		// 반복자와 버킷 인덱스 쌍을 리턴한다.
		return std::make_pair(iter, bucket);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	typename hash_map<Key, T, KeyEqual, Hash>::value_type* hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k)
	{
		// findElement() 헬퍼와 C++17 구조적 바인딩을 적용한다.
		auto[it, bucket] = findElement(k);
		if (it == end(mBuckets[bucket])) {
			// 원소를 못 찾은 경우 -- nullptr을 리턴한다.
			return nullptr;
		}
		// 원소를 찾은 경우 -- 원소에 대한 포인터를 리턴한다.
		return &(*it);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	const typename hash_map<Key, T, KeyEqual, Hash>::value_type* hash_map<Key, T, KeyEqual, Hash>::find(const key_type& k) const
	{
		return const_cast<hash_map<Key, T, KeyEqual, Hash>*>(this)->find(k);
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	T& hash_map<Key, T, KeyEqual, Hash>::operator[] (const key_type& k)
	{
		// 원소를 찾는다. 없으면 새로 추가한다.
		auto[it, bucket] = findElement(k);
		if (it == end(mBuckets[bucket])) {
			mSize++;
			mBuckets[bucket].push_back(std::make_pair(k, T()));
			return mBuckets[bucket].back().second;
		} else {
			return it->second;
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::insert(const value_type& x)
	{
		// 원소를 찾는다.
		auto[it, bucket] = findElement(x.first);

		if (it != end(mBuckets[bucket])) {
			// 이미 존재하는 경우
			return;
		} else {
			// 원소가 없으면 새로 추가한다.
			mSize++;
			mBuckets[bucket].push_back(x);
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::erase(const key_type& k)
	{
		// 먼저 원소를 찾는다.
		auto[it, bucket] = findElement(k);

		if (it != end(mBuckets[bucket])) {
			// 있으면 삭제한다.
			mBuckets[bucket].erase(it);
			mSize--;
		}
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::clear() noexcept
	{
		// 각 버킷마다 clear를 호출한다.
		for (auto& bucket : mBuckets) {
			bucket.clear();
		}
		mSize = 0;
	}

	template <typename Key, typename T, typename KeyEqual, typename Hash>
	void hash_map<Key, T, KeyEqual, Hash>::swap(hash_map<Key, T, KeyEqual, Hash>& other) noexcept
	{
		using std::swap;

		swap(mBuckets, other.mBuckets);
		swap(mSize, other.mSize);
		swap(mEqual, other.mEqual);
		swap(mHash, other.mHash);
	}

}