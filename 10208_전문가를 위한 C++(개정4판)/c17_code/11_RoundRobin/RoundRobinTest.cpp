#include "RoundRobin.h"
#include <stdexcept>
#include <iostream>
#include <string>
#include <string_view>
using namespace std;

// 간단한 Process 클래스
class Process final
{
public:
	// 프로세스 이름을 인수로 받는 생성자
	Process(string_view name) : mName(name) {}

	// 프로세스마다 주어진 시간 동안만 실행될 동작을 구현한다.
	// 실제 동작은 생략한다.
	void doWorkDuringTimeSlice() {
		cout << "Process " << mName
			<< " performing work during time slice." << endl;
	}

	// RoundRobin::remove() 메서드에 필요한 연산자
	bool operator==(const Process& rhs) {
		return mName == rhs.mName;
	}

private:
	string mName;
};

// 간단한 라운드 로빈 방식 프로세스 스케줄러
class Scheduler final
{
public:
	// 프로세스에 대한 벡터를 인수로 받는 생성자
	Scheduler(const vector<Process>& processes);

	// 라운드 로빈 스케줄링 알고리즘에 따라 다음 프로세스를 선택해서
	// 그 프로세스에 할당된 타임 슬라이스 동안 주어진 작업을 수행한다.
	void scheduleTimeSlice();

	// 인수로 지정한 프로세스를 리스트에서 삭제한다.
	void removeProcess(const Process& process);

private:
	RoundRobin<Process> mProcesses;
};

Scheduler::Scheduler(const vector<Process>& processes)
{
	// 프로세스를 추가한다.
	for (auto& process : processes) {
		mProcesses.add(process);
	}
}

void Scheduler::scheduleTimeSlice()
{
	try {
		mProcesses.getNext().doWorkDuringTimeSlice();
	} catch (const out_of_range&) {
		cerr << "No more processes to schedule." << endl;
	}
}

void Scheduler::removeProcess(const Process& process)
{
	mProcesses.remove(process);
}

int main()
{
	vector<Process> processes = { Process("1"), Process("2"), Process("3") };

	Scheduler scheduler(processes);
	for (int i = 0; i < 4; ++i)
		scheduler.scheduleTimeSlice();

	scheduler.removeProcess(processes[1]);
	cout << "Removed second process" << endl;

	for (int i = 0; i < 4; ++i)
		scheduler.scheduleTimeSlice();

	return 0;
}
