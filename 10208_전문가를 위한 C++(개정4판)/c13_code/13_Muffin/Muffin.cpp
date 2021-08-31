#include <iostream>
#include <sstream>
#include <string>
#include <string_view>

using namespace std;

class Muffin
{
public:
	virtual ~Muffin() = default;

	string_view getDescription() const;
	void setDescription(string_view description);

	int getSize() const;
	void setSize(int size);

	bool hasChocolateChips() const;
	void setHasChocolateChips(bool hasChips);

	void output() const;

private:
	string mDescription;
	int mSize = 0;
	bool mHasChocolateChips = false;
};

string_view Muffin::getDescription() const { return mDescription; }
void Muffin::setDescription(string_view description) { mDescription = description; }

int Muffin::getSize() const { return mSize; }
void Muffin::setSize(int size) { mSize = size; }

bool Muffin::hasChocolateChips() const { return mHasChocolateChips; }
void Muffin::setHasChocolateChips(bool hasChips) { mHasChocolateChips = hasChips; }

void Muffin::output() const
{
	printf("%s, Size is %d, %s\n", getDescription().data(), getSize(),
		(hasChocolateChips() ? "has chips" : "no chips"));
}

Muffin createMuffin(istringstream& inStream);

int main()
{
	cout << "First, let's create a muffin in code and output it." << endl;

	Muffin myMuffin;
	myMuffin.setDescription("Giant_Blueberry_Muffin");
	myMuffin.setSize(42);
	myMuffin.setHasChocolateChips(false);

	printf("The muffin is ");
	myMuffin.output();
	printf(" -- yummy!\n");


	cout << "Now we'll create a muffin from a string stream" << endl;

	istringstream instream("My_Muffin 2 true");
	Muffin m2 = createMuffin(instream);
	m2.output();

	return 0;
}

Muffin createMuffin(istringstream& stream)
{
	Muffin muffin;
	// 데이터가 다음과 같은 형식에 맞게 들어온다고 가정한다.
    // Description(설명) size(크기) chips(초콜릿칩 존재 여부)

	string description;
	int size;
	bool hasChips;

	// 세 값 모두 읽는다. 이때 chips는 "true"나 "false"란 스트링으로 표현한다.
	stream >> description >> size >> boolalpha >> hasChips;
	if (stream) { // 읽기 연산 성공
		muffin.setSize(size);
		muffin.setDescription(description);
		muffin.setHasChocolateChips(hasChips);
	}

	return muffin;
}
