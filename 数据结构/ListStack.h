#pragma once
#ifndef ListStack_H
#define ListStack_H
#include<iostream>
using namespace std;
template<class T>
class ListStack;         //前置声明


template<class T>
class ChainNode        //链式栈的节点
{
	friend class ListStack<T>;
private:
	ChainNode(const T&theData, ChainNode<T> *n = 0):data(theData),link(n)
	{
	}
	T data;
	ChainNode<T> *link;

};



template<class T>
class ListStack
{
public:
	ListStack():top(0){}  //构造函数，空堆栈
	~ListStack()
	{
		MakeEmpty();     //删除所有堆栈的数据
	}
	bool IsEmpty() const;
	T& Top()  const;    //返回栈顶数据
	void Pop();         //删除栈顶数据
	void Push(const T& e);  //栈顶压入一个数据
	void MakeEmpty();      //清空栈
private:
	ChainNode<T> *top;       //指向栈顶的指针
};


template<class T>
bool ListStack<T>::IsEmpty() const
{
 	return top == 0;    //栈顶指针为0，表示栈为空
}

template<class T>
void ListStack<T>::Push(const T&e)
{
	
	top = new ChainNode<T>(e, top);   //top指向link了

	//调用ChainNode的构造函数,指向一个新的ChainNode。
	//新的节点的数据时e，top指针指向这个指针。
}




template<class T>
T& ListStack<T>::Top() const
{
	if (this->IsEmpty())
		cout<< "Stack IS EMPTY";
	else
		return top->data;   //如果不为空，就返回栈顶的数据
}

template<class T>
void ListStack<T>::Pop()
{
	if (this->IsEmpty())
		throw "stack is empty,can not be deleted";
	else
	{
		ChainNode<T> *DelNode = top;  
		top = top->link;
		delete DelNode;
	}
		
}

template<class T>
void ListStack<T>::MakeEmpty()
{
	while (!IsEmpty())
	{
		Pop();
	}	
}

#endif
