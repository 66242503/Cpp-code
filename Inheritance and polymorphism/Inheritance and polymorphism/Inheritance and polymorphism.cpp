#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

// �麯����ʵ�ֶ�̬������֮һ

class Person {
public:
	// �麯��
	virtual void BuyTicket() { cout << "Person ��Ʊ-ȫ��" << endl; }
};

// Student���麯���ĺ�����������������ֵ��Perosn�е��麯������ͬ��Student���麯����д��Person�е��麯��
class Student : public Person {
public:
	virtual void BuyTicket() { cout << "Student ��Ʊ-���" << endl; }
};

// �ﵽ��̬��������
// 1.�麯������д��
// 2.�����ָ��/����ȥ�����麯��
// ��̬��ȥ���ĳһ��Ϊ����ͬ�Ķ���ȥ��ɣ�Ч���ǲ�һ���ġ�

//ʤ��oid Func(Person* ptr)
//{
//	ptr->BuyTicket();
//}

// �������̬������˭�ĺ���->������
// �����̬������˭�ĺ���->��ָ��Ķ���

void Func(Person& rp)
{
	rp.BuyTicket();
}

int main()
{
	Person p;
	Student s;
	Func(p);
	Func(s);

	return 0;
}
