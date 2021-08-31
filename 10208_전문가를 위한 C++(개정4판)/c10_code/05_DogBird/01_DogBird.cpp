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
	//using Dog::eat;       // Dog ������ eat()�� ��������� ����Ѵ�.
};

//void DogBird::eat()
//{
//	Dog::eat();  // Dog ������ eat()�� ��������� ȣ���Ѵ�.
//}

int main()
{
	DogBird myConfusedAnimal;

	myConfusedAnimal.bark();
	myConfusedAnimal.chirp();
	//myConfusedAnimal.eat();                   // ����! eat() �޼����� �Ҽ��� ��ȣ�ϴ�.
	dynamic_cast<Dog&>(myConfusedAnimal).eat(); // Dog::eat()�� ȣ���Ѵ�.
	myConfusedAnimal.Dog::eat();                // Dog::eat()�� ȣ���Ѵ�.

	return 0;
}
