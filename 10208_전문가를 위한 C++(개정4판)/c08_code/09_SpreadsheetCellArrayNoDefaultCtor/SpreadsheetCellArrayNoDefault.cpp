#include "SpreadsheetCell.h"

int main()
{
  // 세 번째 줄을 테스트하려면 다음 두 줄을 주석 처리한다.
  SpreadsheetCell cells[3]; // 디폴트 생성자가 없어서 컴파일 에러가 발생한다.
  SpreadsheetCell* myCellp = new SpreadsheetCell[10]; // 여기서도 마찬가지다.

  // 이 문장은 디폴트 생성자가 없어도 컴파일 된다.
  SpreadsheetCell cells[3] = {SpreadsheetCell(0), SpreadsheetCell(23),
			      SpreadsheetCell(41)};

  return 0;
}
