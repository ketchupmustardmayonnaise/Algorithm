#include <iostream>
using namespace std;

class Person
{
private:
	char* name;
	int age;

public:
	Person(const char name[], int age)
	{
		int len = strlen(name) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, name);
		this->age = age;
	}

	~Person()
	{
		delete[] name;
	}

	void Print()
	{
		cout << "나는 " << this->name << "이며, 나이는 " << this->age << "살입니다.\n";
	}
};

int main()
{
	Person me("홍길동", 20);
	Person you = me;

	me.Print();
	you.Print();
}