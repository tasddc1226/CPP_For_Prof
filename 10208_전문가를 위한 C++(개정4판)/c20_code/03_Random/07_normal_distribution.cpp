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

	// �յ� �޸��� Ʈ������
	random_device seeder;
	const auto seed = seeder.entropy() ? seeder() : time(nullptr);
	mt19937 eng(static_cast<mt19937::result_type>(seed));
	normal_distribution<double> dist(50, 10);
	auto gen = bind(dist, eng);
	map<int, int> m;
	for (unsigned int i = 0; i < kIterations; ++i) {
		int rnd = static_cast<int>(gen());
		// �ʿ��� key = rnd�� �׸��� ã�´�. ã�Ҵٸ� �� Ű�� ���� 1�� ���Ѵ�.
		// ã�� ���ߴٸ� �� Ű�� ���� 1�� �����ؼ� �ʿ� �����Ѵ�.
		++(m[rnd]);
	}

	// CSV ���Ͽ� ����.
	ofstream of("res.csv");
	for (unsigned int i = kStart; i <= kEnd; ++i) {
		of << i << "," << m[i] << endl;
	}

	return 0;
}
