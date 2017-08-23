#pragma once
#ifndef ListStack_H
#define ListStack_H
#include<iostream>
using namespace std;
template<class T>
class ListStack;         //ǰ������


template<class T>
class ChainNode        //��ʽջ�Ľڵ�
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
	ListStack():top(0){}  //���캯�����ն�ջ
	~ListStack()
	{
		MakeEmpty();     //ɾ�����ж�ջ������
	}
	bool IsEmpty() const;
	T& Top()  const;    //����ջ������
	void Pop();         //ɾ��ջ������
	void Push(const T& e);  //ջ��ѹ��һ������
	void MakeEmpty();      //���ջ
private:
	ChainNode<T> *top;       //ָ��ջ����ָ��
};


template<class T>
bool ListStack<T>::IsEmpty() const
{
 	return top == 0;    //ջ��ָ��Ϊ0����ʾջΪ��
}

template<class T>
void ListStack<T>::Push(const T&e)
{
	
	top = new ChainNode<T>(e, top);   //topָ��link��

	//����ChainNode�Ĺ��캯��,ָ��һ���µ�ChainNode��
	//�µĽڵ������ʱe��topָ��ָ�����ָ�롣
}




template<class T>
T& ListStack<T>::Top() const
{
	if (this->IsEmpty())
		cout<< "Stack IS EMPTY";
	else
		return top->data;   //�����Ϊ�գ��ͷ���ջ��������
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
