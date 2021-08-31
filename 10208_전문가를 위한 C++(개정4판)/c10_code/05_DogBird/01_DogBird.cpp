#include <iostream>

using namespace std;

class Dog
{
public:
	virtual void bark() { cout << "woof!" << endl; }
	virtual void eat() { cout << "The dog ate." << endl; }
};

class Bird
{
public:
	virtual void chirp() { cout << "chirp!" << endl; }
	virtual void eat() { cout << "The bird ate." << endl; }
};

class DogBird : public Dog, public Bird
{
public:
	//void eat() override;
	//using Dog::eat;       // Dog 버전의 eat()를 명시적으로 상속한다.
};

//void DogBird::eat()
//{
//	Dog::eat();  // Dog 버전의 eat()를 명시적으로 호출한다.
//}

int main()
{
	DogBird myConfusedAnimal;

	myConfusedAnimal.bark();
	myConfusedAnimal.chirp();
	//myConfusedAnimal.eat();                   // 에러! eat() 메서드의 소속이 모호하다.
	dynamic_cast<Dog&>(myConfusedAnimal).eat(); // Dog::eat()를 호출한다.
	myConfusedAnimal.Dog::eat();                // Dog::eat()를 호출한다.

	return 0;
}
