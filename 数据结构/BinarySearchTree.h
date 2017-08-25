#pragma once
#ifndef  BinarySearchTree_H
#define  BinarySearchTree_H
#include<iostream>

enum Boolean
{
	FALSE,TRUE
};

template<class T>
class BST;      //前置声明


template<class T>
class Element   //键值
{public:
	T key;        //键值
};


template<class T>
class BstNode    //树节点
{
public:
	friend class BST<T>;
	Element<T>  data;

	
	BstNode *LeftChild;
	BstNode *RightChild;    // 这里不指定这两个地址也可以
	void dispaly(int i);   //显示
};

template<class T>
class BST
{
public:

	BST(BstNode<T> *init=0)
	{
		root = init;      //初始化，建立空树
	}
	Boolean  Insert( const Element<T> &x);  //bool返回成功或者不成功
	BstNode<T>* Search(const Element<T> &x);   //查找，找到返回指针
	BstNode<T>* Search(BstNode<T>*, const Element<T> &x);
	BstNode<T>* IterSearch(const Element<T> &x);   //迭代的查找
	void dispaly()
	{
		cout << endl;
		if (root)
			root->dispaly(1);
		else
			cout << "no tree" << endl;
	}
private:
	BstNode<T> *root;
};
template<class T>
BstNode<T>* BST<T>::Search(const Element<T> &x)
{
	return Search(root, x);
}


template<class T>
BstNode<T>* BST<T>::Search(BstNode<T> *b, const Element<T> &x)
{
	if (!b)  return 0;     //如果节点为空
	if (x.key == b->data.key)    //data不是指针，访问key要用"."
		return b;     //如果就是这个，返回当前地址
	if (x.key < b->data.key)   
		return Search(b->LeftChild, x);
	else 
		return Search(b->RightChild, x);
}

template<class T>
BstNode<T>* BST<T>::IterSearch(const Element<T> &x)
{
	for (BstNode<T> *t = root;t;)      //只要不是空节点，就可以一直找。
	{
		if (x.key == t->data.key)   return  t;
		if (x.key < t->data.key)
			t = t->LeftChild;       
		else
			t = t->RightChild;   //根据具体情况，表示指向左还是右。

	}
	return 0;      //如果没找到，返回空指针。
	
}


template<class T>
void BstNode<T>::dispaly(int i)
{
	std::cout << "position in BST: " << i << "  " << 
		       "data.key: " << data.key << endl;
	if (LeftChild)   LeftChild->dispaly(2 * i);
	if (RightChild)  RightChild->dispaly(2 * i + 1);
	//这里其实是一种递归的写法。

}

template<class T>
Boolean BST<T>::Insert(const Element<T> &x)  //插入
{
	BstNode<T> *p = root;      //树根节点
	BstNode<T> *q = 0;         //指向p的父节点，一开始root没有父节点，这里是0，记录下这个节点有用。
	//首先得找到一个合适的位置
	while (p)   //这个p是定义的一开始指向树根的指针
	{
		q = p;       //把p要保存下来，这时一个父节点，可能要往这里插入
		if (x.key == p->data.key)    return FALSE;  //不允许重复插入
		if (x.key < p->data.key)   
			p = p->LeftChild;     //如果小的话指向左边
		else
			p = p->RightChild;    //如果大的话指向右边
	}
	//找到的位置
	p = new BstNode<T>;
	p->LeftChild = p->RightChild = 0;  //新建的节点不分配左右子树的指针
	p->data = x;
	//新建一个节点
	if (!root)  root = p;
	else if (x.key < q->data.key)   q->LeftChild = p;
	else  q->RightChild = p;
	//根据具体情况把节点指向左边或者右边。
	return TRUE;   //表示插入成功
}




#endif // ! BinarySearchTree
