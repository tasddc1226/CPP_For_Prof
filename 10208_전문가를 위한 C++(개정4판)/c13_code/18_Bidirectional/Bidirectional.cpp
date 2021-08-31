#include <iostream>
#include <fstream>
#include <string>
#include <string_view>

using namespace std;

// 에러가 발생하면 false를 리턴한다.
bool changeNumberForID(string_view filename, int id, string_view newNumber);

int main()
{
	changeNumberForID("data.txt", 263, "415-555-3333");
	// data.txt 파일을 프로젝트 폴더 안에 복사한다.
	// 간단한 방법은 솔루션 탐색기 창의 프로젝트 이름 위에서 마우스 오른쪽 클릭한 뒤
	// '파일 탐색기에서 폴더 열기'를 선택해서 나타나는 폴더 안에 data.txt 파일을 넣는다.

	return 0;
}

bool changeNumberForID(string_view filename, int id, string_view newNumber)
{
	fstream ioData(filename.data());
	if (!ioData) {
		cerr << "Error while opening file " << filename << endl;
		return false;
	}

	// 파일 끝까지 반복한다.
	while (ioData) {
		int idRead;
		string number;

		// 다음 ID를 읽는다.
		ioData >> idRead;
		if (!ioData)
			break;

		// 현재 레코드가 수정할 대상인지 확인한다.
		if (idRead == id) {
			// 쓰기 위치를 현재 읽기 위치로 이동한다.
			ioData.seekp(ioData.tellg());
			// 한 칸 띄운 뒤 새 번호를 쓴다.
			ioData << " " << newNumber;
			break;
		}

		// 현재 위치에서 숫자를 읽어서 스트림의 위치를 다음 레코드로 이동한다.
		ioData >> number;
	}
	return true;
}