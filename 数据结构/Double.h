//简单地数双向链表，有插入和删除功能
#pragma once
#include <iostream>

using namespace std;


class Dblist;

class DblistNode
{
	friend class Dblist;
public:
	int data;     //数据
	DblistNode *llink, *rlink;  //左指针和右指针

};


class Dblist
{
public:
	Dblist()      //构造函数,建立一个空的表头
	{
		first = new DblistNode();
		first->llink = first->rlink = first;
		//左右节点都指向自己

	}

	void Insert(DblistNode*, DblistNode*);
	void Delete(DblistNode*);

	DblistNode *first;

};

void Dblist::Insert(DblistNode*p, DblistNode*x)
//这里是把p插入到x的右边，相互连接的四个指针都需要调整
{
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;

	//需要调整的指针，看着图来做就好

}

void  Dblist::Delete(DblistNode *x)
{
	if (x == first)
		cout << "first can not be deleted" << endl;
	else
	{
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		//把x删掉，把两边连起来
	}

}