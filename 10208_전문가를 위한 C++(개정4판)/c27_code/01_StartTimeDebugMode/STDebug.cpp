#include <cstddef>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

class Logger
{
public:
	static void enableLogging(bool enable) { msLoggingEnabled = enable; }
	static bool isLoggingEnabled() { return msLoggingEnabled; }

	template<typename... Args>
	static void log(const Args&... args)
	{
		if (!msLoggingEnabled)
			return;

		ofstream logfile(msDebugFileName, ios_base::app);
		if (logfile.fail()) {
			cerr << "Unable to open debug file!" << endl;
			return;
		}
		// C++17 단항 우측 폴드를 적용한다. (22장 참조)
		((logfile << args),...);
		logfile << endl;
	}

private:
	static const string msDebugFileName;
	static bool msLoggingEnabled;
};

const string Logger::msDebugFileName = "debugfile.out";
bool Logger::msLoggingEnabled = false;



#define log(...) Logger::log(__func__, "(): ", __VA_ARGS__)



bool isDebugSet(int argc, char* argv[])
{
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "-d") == 0) {
			return true;
		}
	}
	return false;
}



class ComplicatedClass
{
	// 클래스 코드 생략
};
ostream& operator<<(ostream& ostr, const ComplicatedClass& /* src */)
{
	ostr << "ComplicatedClass";
	return ostr;
}

class UserCommand
{
	// 클래스 코드 생략
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
			log("exception from processUserCommand(): ", e.what());
		}
	}
}

int main(int argc, char* argv[])
{
	Logger::enableLogging(isDebugSet(argc, argv));

	if (Logger::isLoggingEnabled()) {
		// 트레이스에 대한 커맨드라인 인수를 출력한다.
		for (int i = 0; i < argc; i++) {
			log(argv[i]);
		}
	}

	ComplicatedClass obj;
	trickyFunction(&obj);

	// 나머지 코드 생략
	return 0;
}
