#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#define DEBUG_MODE

#ifdef DEBUG_MODE
	class Logger
	{
	public:
		template<typename... Args>
		static void log(const Args&... args)
		{
			ofstream logfile(msDebugFileName, ios_base::app);
			if (logfile.fail()) {
				cerr << "Unable to open debug file!" << endl;
				return;
			}
			// C++17 단항 우측 폴드를 적용한다. (22장 참조)
			((logfile << args), ...);
			logfile << endl;
		}

	private:
		static const string msDebugFileName;
	};
	const string Logger::msDebugFileName = "debugfile.out";

	#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)
#else
	#define log(...)
#endif

// 주의:
//		프로그램의 정상 동작에 관련된 코드를 log() 호출 안에 넣지 않도록 주의한다.
//      예를 들어 다음과 같이 작성하면 문제가 발생할 수 있다.
//		    log("Result: ", myFunctionCall());
//		DEBUG_MODE가 정의되어 있지 않으면 전처리기는 코드에 나온 모든 log() 호출문을 no-op으로 바꾼다.
//      그래서 myFunctionCall()를 호출하는 문장도 함께 제거된다.

class ComplicatedClass
{
	// 코드 생략
};
ostream& operator<<(ostream& ostr, const ComplicatedClass& /* src */)
{
	ostr << "ComplicatedClass";
	return ostr;
}

class UserCommand
{
	// 코드 생략
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
	log("given argument: ", *obj);

	for (size_t i = 0; i < 100; ++i) {
		UserCommand cmd = getNextCommand(obj);
		log("retrieved cmd ", i, ": ", cmd);

		try {
			processUserCommand(cmd);
		} catch (const exception& e) {
			log("received exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
#ifdef DEBUG_MODE
	// 트레이스에 대한 커맨드라인 인수를 출력한다.
	for (int i = 0; i < argc; i++) {
		log(argv[i]);
	}
#endif

	ComplicatedClass obj;
	trickyFunction(&obj);

	// 나머지 코드 생략
	return 0;
}
