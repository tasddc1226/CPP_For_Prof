#include <iostream>
#include <string>

using namespace std;

class Book
{
public:
	virtual ~Book() = default;
	virtual string getDescription() const { return "Book"; }
	virtual int getHeight() const { return 120; }
};

class Paperback : public Book
{
public:
	virtual string getDescription() const override {
		return "Paperback " + Book::getDescription();
	}
};

class Romance : public Paperback
{
public:
	virtual string getDescription() const override {
		return "Romance " + Paperback::getDescription();
	}
	virtual int getHeight() const override { return Paperback::getHeight() / 2; }
};

class Technical : public Book
{
public:
	virtual string getDescription() const override {
		return "Technical " + Book::getDescription();
	}
};

int main()
{
	Romance novel;
	Book book;
	cout << novel.getDescription() << endl; // 결과: "Romance Paperback Book"
	cout << book.getDescription() << endl;  // 결과: "Book"
	cout << novel.getHeight() << endl;      // 결과: "60"
	cout << book.getHeight() << endl;       // 결과: "120"

	return 0;
}
