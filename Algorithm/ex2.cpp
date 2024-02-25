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
		cout << "���� " << this->name << "�̸�, ���̴� " << this->age << "���Դϴ�.\n";
	}
};

int main()
{
	Person me("ȫ�浿", 20);
	Person you = me;

	me.Print();
	you.Print();
}