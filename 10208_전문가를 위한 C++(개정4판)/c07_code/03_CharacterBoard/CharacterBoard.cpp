#include <cstddef>

char** allocateCharacterBoard(size_t xDimension, size_t yDimension)
{
	char** myArray = new char*[xDimension]; // 첫 번째 차원의 배열을 할당한다.

	for (size_t i = 0; i < xDimension; i++) {
		myArray[i] = new char[yDimension];  // i번째 하위 배열을 할당한다.
	}

	return myArray;
}

void releaseCharacterBoard(char** myArray, size_t xDimension)
{
	for (size_t i = 0; i < xDimension; i++) {
		delete [] myArray[i];    //  i번째 하위 배열을 삭제한다.
	}

	delete [] myArray;           //  첫 번째 차원의 배열을 삭제한다.
}

int main()
{
	const size_t xDimension = 7;
	const size_t yDimension = 13;
	char** board = allocateCharacterBoard(xDimension, yDimension);
	releaseCharacterBoard(board, xDimension);

	return 0;
}
