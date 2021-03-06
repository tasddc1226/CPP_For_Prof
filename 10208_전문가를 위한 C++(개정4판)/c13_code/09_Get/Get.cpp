#include <iostream>
#include <string>

using namespace std;

string readName(istream& stream);

int main()
{
	cout << "Type a name followed by Enter followed by Control-D (Control-Z in Windows) and another Enter: ";
	string theName = readName(cin);

	cout << "The name is \"" << theName << "\"" << endl;

	return 0;
}


string readName(istream& stream)
{
	string name;
	while (stream) { // 또는: while (!stream.fail()) {
		int next = stream.get();
		if (!stream || next == std::char_traits<char>::eof())
			break;
		name += static_cast<char>(next);// 문자 추가
	}
	return name;
}


/*
string readName(istream& stream)
{
	string name;
	char next;
	while (stream.get(next)) {
		name += next;
	}

	return name;
}
*/