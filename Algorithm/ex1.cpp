#include <iostream>
using namespace std;

void swap1(int a, int b)
{
	// Call By Value
	int temp = a;
	a = b;
	b = temp;
}

void swap2(int& a, int& b)
{
	// Call By Reference
	int temp = a;
	a = b;
	b = temp;
}

void swap3(int* a, int* b)
{
	int temp = *a;
	a = b;
	b = &temp;
}

void swap4(int*& a, int*& b)
{
	// int 포인터에 대한 레퍼런스!
	int* temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	swap1(a, b);
	cout << "==== Swap (Call by Value) ====" << endl;
	cout << "a: " << a << ", b: " << b << endl; // 10, 20

	int c = a;
	int d = b;
	swap2(c, d);
	cout << "==== Swap (Call by Reference) ====" << endl;
	cout << "c: " << c << ", d: " << d << endl; // 20, 10

	int* e = &a;
	int* f = &b;
	swap3(e, f);
	cout << "==== Swap (Call by Pointer) ====" << endl;
	cout << "e: " << *e << ", f: " << *f << endl; // 10, 20

	int* g = &a;
	int* h = &b;
	swap4(g, h);
	cout << "==== Swap (Pointer+Reference) ====" << endl;
	cout << "g: " << *g << ", h: " << *h << endl; // 10, 20
}