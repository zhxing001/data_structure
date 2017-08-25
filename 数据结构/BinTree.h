#pragma once
#ifndef TREE_H
#define TREE_H
#include<iostream>
#include<queue>
using namespace std;

template<class T>  class BinaryTree;

template<class T>
class TreeNode
{
public:
	TreeNode()     //构造函数
	{
		leftChild = NULL;
		rightChild = NULL;
	}
	T data;
	TreeNode<T> *leftChild;
	TreeNode<T> *rightChild;
};

template<class T>
class BinaryTree 
{ public:
	void InOrder();      //中序遍历
	void InOrder(TreeNode<T> *currentNode);
	void PreOrder();     //前序遍历
	void PostOrder();      //后序遍历
	void LevelOrder();    //层序遍历
	void Visit(TreeNode<T> *currentNode);
	void PreOrder(TreeNode<T> *currentNode);
	void PostOrder(TreeNode<T> *currentNode);
	TreeNode<T> *root;       // 树根

};

template<class T>
void BinaryTree<T>::LevelOrder()
{
	queue<TreeNode<T>*>  q;     //定义一个队列，存放节点指针，是一个对象指针
	TreeNode<T>  *currentNode = root;  //开始的节点,根节点
	while(currentNode)         //队列不空的话
	{
		Visit(currentNode);         //显示当前节点
		if (currentNode->leftChild)        
			q.push(currentNode->leftChild);       //这里是指针，不要把数据传入
		 //如果左子存在，放入队列
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		//如果右子存在，放入队列
		if (q.empty())
			break;        //如果队列为空，则跳出当前遍历程序
		currentNode = q.front();   //更新队首为当前新的节点。
		q.pop();    //删除队首节点
	}

}


template<class T>
void BinaryTree<T>::Visit(TreeNode<T> *currentNode)
{
	cout << currentNode->data<<"  ";
	//这里也能对节点进行一些处理，
}


template<class T>
void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

template<class T>
void BinaryTree<T>::InOrder(TreeNode<T> *currentNode)
{
	if (currentNode)
	{
		InOrder(currentNode->leftChild);
		Visit(currentNode);
		InOrder(currentNode->rightChild);
	}     //使用递归做这个还是比较简洁的，需要去理解。
}

template<class T>
void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}


template<class T>
void BinaryTree<T>::PreOrder(TreeNode<T> *currentNode)
{
	if (currentNode)
	{
		Visit(currentNode);
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
	}
}


template<class T>
void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}


template<class T>
void BinaryTree<T>::PostOrder(TreeNode<T> *currentNode)
{
	if (currentNode)
	{
		PostOrder(currentNode->leftChild);
		PostOrder(currentNode->rightChild);
		Visit(currentNode);
	}
}

#endif

