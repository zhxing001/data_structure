#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<iostream>

template<class T> class BST;   //ǰ������
enum MyBool {FALSE,TRUE};

template<class T>
class Element
{
public:
	T key;
};

template<class T>


class BTreeNode
{
public:
	
	friend class BST<T>;    //��Ԫ�࣬Ҫ�������ݺͽڵ�
	Element<T> data;
private:
	BTreeNode *leftChild=nullptr;
	BTreeNode *rightChild=nullptr;  
	void display(int i);
};


template<class T>
class BST
{
public:
	BST(BTreeNode<T> *init)
	{
		root = init;

	}
	BST()
	{
		root = nullptr;
	}

	MyBool Insert(const Element<T> &element);         //���룬��Ҳ��һ�ֶ��ֲ�����ٶ�
	BTreeNode<T>* Search(const Element<T> &element);   //����,��ʵ������һ�ֶ��ֲ���
	BTreeNode<T>* Search(BTreeNode<T> *, const Element<T> &element);   //�ݹ���Ҹ�������
	BTreeNode<T>* IterSearch(const Element<T> &element);   //��ѭ��дһ������
	void display()
	{
		if (root)
			root->display(1);
		else
			std::cout << "empty tree!" << std::endl;

	}
private:
	BTreeNode<T> *root=nullptr;       //����
};





template<class T>
inline MyBool BST<T>::Insert(const Element<T>& element)
{
	BTreeNode<T> *p = root;
	BTreeNode<T> *q = nullptr;

	while (p)
	{
		q = p;   //��p�ĸ��ڵ㱣��������
		if (element.key == p->data.key)  return FALSE;
		else if (element.key < p->data.key)
			p = p->leftChild;
		else if (element.key >p->data.key)
			p = p->rightChild;
	}
	//��ѭ������֮�����ʱ�򣬾��ҵ���һ��λ�ã����λ����q�����ӻ�������;
	p = new BTreeNode<T>;
	p->data = element;
	if (!root)
		root = p;   //����������ǿյģ���ô�µĽڵ���Ǹ��ˡ�
	else if (element.key < q->data.key)
		q->leftChild = p;
	else if (element.key > q->data.key)
		q->rightChild = p;
	
	return TRUE;
}



template<class T>
inline BTreeNode<T>* BST<T>::Search(const Element<T>& element)
{
	return Search(root, element);
}

template<class T>
inline BTreeNode<T>* BST<T>::Search(BTreeNode<T>* b, const Element<T>& element)
{
	if (!b)  return nullptr;
	if (element.key == b->data.key)  return b;
	if (element.key < b->data.key)   
		return Search(b->leftChild,element);
	if (element.key > b->data.key)
		return Search(b->rightChild, element);
}

template<class T>
inline BTreeNode<T>* BST<T>::IterSearch(const Element<T>& element)
{
	BTreeNode<T> *tmp = root;
	if (tmp == nullptr)
		return nullptr;
	while (tmp)
	{
		if (tmp->data.key == element.key)
			return tmp;
		else if (tmp->data.key < element.key)
			tmp = tmp->rightChild;
		else 
			tmp = tmp->leftChild;
	}

	return nullptr;
}

template<class T>
inline void BTreeNode<T>::display(int i)
{
	std::cout << "position:" << i;      //��ʽ�ڵ��λ�ã��ڶ������е�λ��
	std::cout << "\tdata��" << data.key << endl;
	if (leftChild)   leftChild->display(2 * i);
	if (rightChild)	 rightChild->display(2 * i + 1);
}



#endif // !BINARYSEARCHTREE_H