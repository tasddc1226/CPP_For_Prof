#include <random>
#include <functional>
#include <map>
#include <fstream>
#include <ctime>

using namespace std;

int main()
{
	const unsigned int kStart = 1;
	const unsigned int kEnd = 99;
	const unsigned int kIterations = 1'000'000;

	// 균등 메르센 트위스터
	random_device seeder;
	const auto seed = seeder.entropy() ? seeder() : time(nullptr);
	mt19937 eng(static_cast<mt19937::result_type>(seed));
	uniform_int_distribution<int> dist(kStart, kEnd);
	auto gen = bind(dist, eng);
	map<int, int> m;
	for (unsigned int i = 0; i < kIterations; ++i) {
		int rnd = gen();
		// 맵에서 key = rnd인 항목을 찾는다. 찾았다면 그 키의 값에 1을 더한다.
		// 찾지 못했다면 그 키의 값을 1로 설정해서 맵에 저장한다.
		++(m[rnd]);
	}

	// CSV 파일에 쓴다.
	ofstream of("res.csv");
	for (unsigned int i = kStart; i <= kEnd; ++i) {
		of << i << "," << m[i] << endl;
	}

	return 0;
}
