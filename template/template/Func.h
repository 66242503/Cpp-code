#include <iostream>
using namespace std;

void F1();

template<class T>
void F2(const T& x)
{
	cout << "void F2(const T& x)" << endl;
}