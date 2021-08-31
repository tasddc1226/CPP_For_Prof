#include "RingBuffer.h"
#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

RingBuffer debugBuf;

#define log(...) debugBuf.addEntry(__func__, "(): ", __VA_ARGS__)

class ComplicatedClass
{
};
ostream& operator<<(ostream& ostr, const ComplicatedClass& /* src */)
{
	ostr << "ComplicatedClass";
	return ostr;
}

class UserCommand
{
};
ostream& operator<<(ostream& ostr, const UserCommand& /* src */)
{
	ostr << "UserCommand";
	return ostr;
}



UserCommand getNextCommand(ComplicatedClass* /* obj */)
{
	UserCommand cmd;
	return cmd;
}

void processUserCommand(UserCommand& /* cmd */)
{
	// 코드 생략
}

void trickyFunction(ComplicatedClass* obj)
{
	// 이 함수가 시작할 때 사용하는 값을 트레이스하도록 로그에 남긴다.
	log("given argument: ", *obj);

	for (size_t i = 0; i < 100; ++i) {
		UserCommand cmd = getNextCommand(obj);
		log("retrieved cmd ", i, ": ", cmd);

		try {
			processUserCommand(cmd);
		} catch (const exception& e) {
			log("exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
	// 커맨드라인 인수를 로그에 남긴다.
	for (int i = 0; i < argc; i++) {
		log(argv[i]);
	}

	ComplicatedClass obj;
	trickyFunction(&obj);

	// 현재 디버그 버퍼에 담긴 내용을 cout으로 출력한다.
	cout << debugBuf;

	return 0;
}
