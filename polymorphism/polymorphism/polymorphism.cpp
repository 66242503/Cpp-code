#include <iostream>

using namespace std;
#if 0
class Person
{
public:
	virtual void BuyTicket() { cout << "��Ʊ=ȫ��" << endl; }
};

class Student : public Person
{
public:
	virtual void BuyTicket() { cout << "��Ʊ=���" << endl; }
};

void Func(Person& p) 
{ 
	p.BuyTicket();
}

int main()
{
	Person ps;
	Student st;
	Func(ps);
	Func(st);
	return 0;
}   // ��̬�Ĺ�������

class A{};
class B : public A {};
class Person
{
public:
	virtual A* f() { return new A; }
};
class Student : public Person
{
public:
	virtual B* f() { return new B; }
};  // Э��

class Person
{
public:
	virtual ~Person() { cout << "~Person()" << endl; }
};

class Student : public Person 
{
public:
	virtual ~Student() { cout << "~Student()" << endl; }
};
// ֻ��������Student������������д��Person����������

int main()
{
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	return 0;
	// delete��������������������ܹ��ɶ�̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ�����������
}

class A
{
public:
	virtual void func() = 0; // ���麯��
};  // ������

class B : public A
{
public:
	virtual void func();
};

int main()
{
	// A a; ����ʵ����������
	B b; //����ʵ���������� 
	return 0;
}


class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1" << endl;
	}
private:
	int _b = 1;
};

int main()
{
	Base b;
	return 0;
}



int main()
{
	Base b;
	Derive d;
	return 0;
}

typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};

class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};

int main()
{
	Base b;
	Derive d;
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	return 0;
}
#endif


class Base1 {
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2 {
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};

class Derive : public Base1, public Base2 {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " ����ַ>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" ��%d���麯����ַ :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);
	return 0;
}