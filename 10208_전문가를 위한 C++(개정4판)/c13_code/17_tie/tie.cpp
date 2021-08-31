#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	// 주의: input.txt가 반드시 있어야 한다.
	// 간단한 방법은 솔루션 탐색기 창의 프로젝트 이름 위에서 마우스 오른쪽 클릭한 뒤
	// '파일 탐색기에서 폴더 열기'를 선택해서 나타나는 폴더 안에 input.txt 파일을 만든다.
	ifstream inFile("input.txt");
	ofstream outFile("output.txt");
	// inFile과 outFile을 연결한다.
	inFile.tie(&outFile);
	// outFile에 텍스트를 쓴다. std::endl이 입력되기 전까지는 내보내지 않는다.
	outFile << "Hello there!";
	// outFile을 아직 내보내지 않은 상태다.
	// inFile에서 텍스트를 읽는다. 그러면 outFile에 대해 flush()가 호출된다.
	string nextToken;
	inFile >> nextToken;
	// 이제 outFile이 내보내졌다.

	return 0;
}
