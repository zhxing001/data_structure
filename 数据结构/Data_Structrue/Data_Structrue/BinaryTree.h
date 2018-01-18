#pragma once
#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>
#include<queue>   //ʹ�ö��������в������

template<class T>
class BinaryTree;

//���ڵ���
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
	void InOrder();      //�������
	void InOrder(TreeNode<T> *currentNode);
	void PreOrder();     //ǰ�����
	void PreOrder(TreeNode<T> *currentNode);
	void PostOrder();    //�������
	void PostOrder(TreeNode<T> *currentNode);    
	void LevelOrder();   //�������
	void Visit(TreeNode<T> *currentNode)
	{
		//����Ҳ�����������Ĵ���
		std::cout << currentNode->data << "--";
	}
	TreeNode<T> *root;
};


template<class T>
inline void BinaryTree<T>::InOrder()  
{
	InOrder(root);
}

//����һ���ݹ��д��
template<class T>
inline void BinaryTree<T>::InOrder(TreeNode<T> *currentNode)
{
	if (currentNode)    //��Ϊ�վͿ���������
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

//�������ʹ�ö����������Ƚ��ȳ���
template<class T>
inline void BinaryTree<T>::LevelOrder()
{
	if (root == nullptr)
		return;
	std::queue<TreeNode<T> *> q;   //�½�һ������
	q.push(root);      //�Ѹ��Ž�ȥ
	while (!q.empty())
	{
		Visit(q.front());
		if(q.front()->leftChild)         //������������Ž����У�����ͬ��
			q.push(q.front()->leftChild);
		if (q.front()->rightChild)
			q.push(q.front()->rightChild);
		q.pop();
	}
}





#endif // !BINARYTREE_H


