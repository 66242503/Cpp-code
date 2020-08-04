#include <iostream>
using namespace std;

#if 0
class Person
{
public:
	void Print()
	{
		cout << "name:"  << _name << endl;
		cout << "age:" << _age << endl;
	}
protected:
	char* _name = "peter"; // ����
	int _age = 18; // ����
};

/* �̳к����Person�ĳ�Ա����Ա����+��Ա�����������������һ���֡��������ֳ���Student��
Teacher������Person�ĳ�Ա����������ʹ�ü��Ӵ��ڲ鿴Student��Teacher���󣬿��Կ��������ĸ��á�
����Print���Կ�����Ա�����ĸ��á�*/
class Student : public Person
{
protected:
	int _stuid; // ѧ��
};

class Teacher : public Person
{
protected:
	int _jobid; // ����
};

int main()
{
	Student s;
	Teacher t;
	s.Print();
	t.Print();
	return 0;
}

// ���е�˽�кͱ����ڵ�ǰ��û���
// �ڼ̳еĺ���������в��private�������в��ɼ�

// ʵ����ʾ���ּ̳й�ϵ�»����Ա�ĸ����ͳ�Ա���ʹ�ϵ�ı仯

class Person
{
protected:
	string _name; // ����
	string _sex; // �Ա�
	int _age; // ����
};
class Student : public Person
{
public:
	int _No; // ѧ��
};

void Test()
{
	Student sobj;
	// 1.���������Ը�ֵ���������/ָ��/����
	Person pobj = sobj;
	Person* pp = &sobj;
	Person& rp = sobj;
	// 2.��������ܸ�ֵ�����������
	// sobj = pobj;
	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
	pp = &sobj;
	Student* ps1 = (Student*)pp; // �������ת��ʱ���Ե�
	ps1->_No = 10;
	pp = &pobj;
	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����
	ps2->_No = 10;
}

// Student��_num��Person��_num�������ع�ϵ�����Կ�������������Ȼ���ܣ����Ƿǳ����׻���
class Person
{
protected:
	string _name = "С����"; // ����
	int _num = 111; // ����֤��
};
class Student : public Person
{
public:
	void Print()
	{
		cout << " ����:" << _name << endl;
		cout << " ����֤��:" << Person::_num << endl;
		cout << " ѧ��:" << _num << endl;
	}
protected:
	int _num = 999; // ѧ��
};
void Test()
{
	Student s1;
	s1.Print();
};
// B�е�fun��A�е�fun���ǹ������أ���Ϊ������ͬһ������
// B�е�fun��A�е�fun�������أ���Ա�������㺯������ͬ�͹������ء�
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B : public A
{
public:
	void fun(int i)
{
	A::fun();
	cout << "func(int i)->" << i << endl;
}
};
void Test()
{
	B b;
	b.fun(10);
};

class Person
{
public:
	Person(const char* name = "peter")
		: _name(name)
	{
		cout << "Person()" << endl;
	}
	Person(const Person& p)
		: _name(p._name)
	{
		cout << "Person(const Person& p)" << endl;
	}
	Person& operator=(const Person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
		if (this != &p)
			_name = p._name;
		return *this;
	}
	~Person()
	{
		cout << "~Person()" << endl;
	}
protected:
	string _name; // ����
};
class Student : public Person
{
public:
	Student(const char* name, int num)
		: Person(name)
		, _num(num)
	{
		cout << "Student()" << endl;
	}
	Student(const Student& s)
		: Person(s)
		, _num(s._num)
	{
		cout << "Student(const Student& s)" << endl;
	}
	Student& operator = (const Student& s)
	{
		cout << "Student& operator= (const Student& s)" << endl;
		if (this != &s)
		{
			Person::operator =(s);
			_num = s._num;
		}
		return *this;
	}
	~Student()
	{
		cout << "~Student()" << endl;
	}
protected:
	int _num; //ѧ��
};
void Test()
{
	Student s1("jack", 18);
	Student s2(s1);
	Student s3("rose", 17);
	s1 = s3;
}


class Person
{
public:
	friend void Display(const Person& p, const Student& s);
protected:
	string _name; // ����
};

class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};

void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	cout << s._stuNum << endl;
}

int main()
{
	Person p;
	Student s;
	Display(p, s); // �����޷�����ͨ��
	return 0;
}


class Person
{
public:
	Person() { ++_count; }
	
public:
	string _name; // ����
	static int _count; // ͳ���˵ĸ���
};

int Person::_count = 0;

class Student : public Person
{
protected:
	int _stuNum; // ѧ��
};

int main()
{
	Person p;
	Student s;
	p._name = "zhang";
	p._name = "fei";
	p._count = 1;
	s._count = 2;

	Person::_count = 3;
	cout << Person::_count << endl;
	cout << Student::_count << endl;
	return 0;
}


class Person
{
public:
	string _name; // ����
};

class Student : public Person
{
protected:
	int _num; //ѧ��
};
class Teacher : public Person
{
protected:
	int _id; // ְ�����
};
class Assistant : public Student, public Teacher
{
protected:
	string _majorCourse; // ���޿γ�
};
void Test()
{
	// �������ж������޷���ȷ֪�����ʵ�����һ��
	Assistant a;
	// ��Ҫ��ʾָ�������ĸ�����ĳ�Ա���Խ�����������⣬�����������������޷����
	a.Student::_name = "xxx";
	a.Teacher::_name = "yyy";
}


class A
{
public:
	int _a;
};

class B : virtual public A
{
public:
	int _b;
};

class C : virtual public A
{
public:
	int _c;
};

class D : public B, public C
{
public:
	int _d;
};

int main()
{
	D d;
	d.B::_a = 1;
	d.C::_a = 2;
	d._b = 3;
	d._c = 4;
	d._d = 5;
	return 0;
}
#endif

// Car��BMW Car��Benz����is-a�Ĺ�ϵ
class Car
{
protected:
	string _colour = "��ɫ"; // ��ɫ
	string _num = "��ABIT00"; // ���ƺ�
};

class BMW : public Car
{
public:
	void Drive() { cout << "�ÿ�-�ٿ�" << endl; }
};

class Benz : public Car
{
public:
	void Drive() { cout << "����-����" << endl; }
};

// Tire��Car����has-a�Ĺ�ϵ
class Tire
{
protected:
	string _brand = "Michelin"; // Ʒ��
	size_t _size = 17; // �ߴ�
};

class Car
{
protected:
	string _colour = "��ɫ"; // ��ɫ
	string _num = "��ABIT00"; // ���ƺ�
	Tire _t; // ��̥
};