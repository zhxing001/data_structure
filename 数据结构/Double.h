//�򵥵���˫�������в����ɾ������
#pragma once
#include <iostream>

using namespace std;


class Dblist;

class DblistNode
{
	friend class Dblist;
public:
	int data;     //����
	DblistNode *llink, *rlink;  //��ָ�����ָ��

};


class Dblist
{
public:
	Dblist()      //���캯��,����һ���յı�ͷ
	{
		first = new DblistNode();
		first->llink = first->rlink = first;
		//���ҽڵ㶼ָ���Լ�

	}

	void Insert(DblistNode*, DblistNode*);
	void Delete(DblistNode*);

	DblistNode *first;

};

void Dblist::Insert(DblistNode*p, DblistNode*x)
//�����ǰ�p���뵽x���ұߣ��໥���ӵ��ĸ�ָ�붼��Ҫ����
{
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;

	//��Ҫ������ָ�룬����ͼ�����ͺ�

}

void  Dblist::Delete(DblistNode *x)
{
	if (x == first)
		cout << "first can not be deleted" << endl;
	else
	{
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		//��xɾ����������������
	}

}