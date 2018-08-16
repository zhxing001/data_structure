#pragma once
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include<iostream>

template<class T> class BST;   //前置声明
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
	
	friend class BST<T>;    //友元类，要访问数据和节点
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

	MyBool Insert(const Element<T> &element);         //插入，这也是一种二分插入的速度
	BTreeNode<T>* Search(const Element<T> &element);   //查找,这实际上是一种二分查找
	BTreeNode<T>* Search(BTreeNode<T> *, const Element<T> &element);   //递归查找辅助函数
	BTreeNode<T>* IterSearch(const Element<T> &element);   //用循环写一个查找
	void display()
	{
		if (root)
			root->display(1);
		else
			std::cout << "empty tree!" << std::endl;

	}
private:
	BTreeNode<T> *root=nullptr;       //树根
};





template<class T>
inline MyBool BST<T>::Insert(const Element<T>& element)
{
	BTreeNode<T> *p = root;
	BTreeNode<T> *q = nullptr;

	while (p)
	{
		q = p;   //把p的父节点保存起来。
		if (element.key == p->data.key)  return FALSE;
		else if (element.key < p->data.key)
			p = p->leftChild;
		else if (element.key >p->data.key)
			p = p->rightChild;
	}
	//当循环结束之后，这个时候，就找到了一个位置，这个位置是q的左子或者右子;
	p = new BTreeNode<T>;
	p->data = element;
	if (!root)
		root = p;   //如果树本身是空的，那么新的节点就是根了。
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
	std::cout << "position:" << i;      //显式节点的位置，在二叉树中的位置
	std::cout << "\tdata：" << data.key << endl;
	if (leftChild)   leftChild->display(2 * i);
	if (rightChild)	 rightChild->display(2 * i + 1);
}



#endif // !BINARYSEARCHTREE_H