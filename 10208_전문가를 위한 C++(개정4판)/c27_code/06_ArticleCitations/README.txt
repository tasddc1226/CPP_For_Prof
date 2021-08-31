ArticleCitationsTest.cpp 파일은 여기 나온 디렉토리 안에 있는 ArticleCitations.cpp 파일과 함께 컴파일한다.
각 디렉토리에 있는 ArticleCitations.h는 모두 같기 때문에 ArticleCitationsTest.cpp에 ArticleCitations.h를 인클루드할 때마다 경로를 변경할 필요는 없다.


리눅스 커맨드라인에서 이 예제를 실행하는 방법은 다음과 같다.

>g++ -o Test ArticleCitationsTest.cpp 05_FinalVersion/ArticleCitations.cpp
