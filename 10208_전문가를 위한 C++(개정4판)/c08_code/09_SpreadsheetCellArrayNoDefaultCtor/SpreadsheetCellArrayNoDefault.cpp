#include "SpreadsheetCell.h"

int main()
{
  // �� ��° ���� �׽�Ʈ�Ϸ��� ���� �� ���� �ּ� ó���Ѵ�.
  SpreadsheetCell cells[3]; // ����Ʈ �����ڰ� ��� ������ ������ �߻��Ѵ�.
  SpreadsheetCell* myCellp = new SpreadsheetCell[10]; // ���⼭�� ����������.

  // �� ������ ����Ʈ �����ڰ� ��� ������ �ȴ�.
  SpreadsheetCell cells[3] = {SpreadsheetCell(0), SpreadsheetCell(23),
			      SpreadsheetCell(41)};

  return 0;
}
