#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include<queue>   //使用队列来进行层序遍历

template<class T>
class BinaryTree;

//树节点类
template<class T>    
class TreeNode
{
public:
	TreeNode(const T &x)
	{
		data = x;
		leftChild=nullptr;
		rightChild = nullptr;

	}
	T data;
	TreeNode<T>  *leftChild;
	TreeNode<T>  *rightChild;

};


template<class T>
class BinaryTree
{
public:   
	void InOrder();      //中序遍历
	void InOrder(TreeNode<T> *currentNode);
	void PreOrder();     //前序遍历
	void PreOrder(TreeNode<T> *currentNode);
	void PostOrder();    //后序遍历
	void PostOrder(TreeNode<T> *currentNode);    
	void LevelOrder();   //层序遍历
	void Visit(TreeNode<T> *currentNode)
	{
		//这里也可以做其他的处理
		std::cout << currentNode->data << "--";
	}
	TreeNode<T> *root;
};


template<class T>
inline void BinaryTree<T>::InOrder()  
{
	InOrder(root);
}

//这是一个递归的写法
template<class T>
inline void BinaryTree<T>::InOrder(TreeNode<T> *currentNode)
{
	if (currentNode)    //不为空就可以做迭代
	{
		InOrder(currentNode->leftChild);  
		Visit(currentNode);
		InOrder(currentNode->rightChild);
	}

}

template<class T>
inline void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}


template<class T>
inline void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		Visit(currentNode);
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
	}
}

template<class T>
inline void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}

template<class T>
inline void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		PostOrder(currentNode->leftChild);
		PostOrder(currentNode->rightChild);
		Visit(currentNode);
	}

}

//层序遍历使用队列来做，先进先出。
template<class T>
inline void BinaryTree<T>::LevelOrder()
{
	if (root == nullptr)
		return;
	std::queue<TreeNode<T> *> q;   //新建一个队列
	q.push(root);      //把根放进去
	while (!q.empty())
	{
		Visit(q.front());
		if(q.front()->leftChild)         //如果有左树，放进队列，右树同理
			q.push(q.front()->leftChild);
		if (q.front()->rightChild)
			q.push(q.front()->rightChild);
		q.pop();
	}
}





#endif // !BINARYTREE_H


