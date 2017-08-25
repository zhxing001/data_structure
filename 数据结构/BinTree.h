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
	TreeNode()     //���캯��
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
	void InOrder();      //�������
	void InOrder(TreeNode<T> *currentNode);
	void PreOrder();     //ǰ�����
	void PostOrder();      //�������
	void LevelOrder();    //�������
	void Visit(TreeNode<T> *currentNode);
	void PreOrder(TreeNode<T> *currentNode);
	void PostOrder(TreeNode<T> *currentNode);
	TreeNode<T> *root;       // ����

};

template<class T>
void BinaryTree<T>::LevelOrder()
{
	queue<TreeNode<T>*>  q;     //����һ�����У���Žڵ�ָ�룬��һ������ָ��
	TreeNode<T>  *currentNode = root;  //��ʼ�Ľڵ�,���ڵ�
	while(currentNode)         //���в��յĻ�
	{
		Visit(currentNode);         //��ʾ��ǰ�ڵ�
		if (currentNode->leftChild)        
			q.push(currentNode->leftChild);       //������ָ�룬��Ҫ�����ݴ���
		 //������Ӵ��ڣ��������
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		//������Ӵ��ڣ��������
		if (q.empty())
			break;        //�������Ϊ�գ���������ǰ��������
		currentNode = q.front();   //���¶���Ϊ��ǰ�µĽڵ㡣
		q.pop();    //ɾ�����׽ڵ�
	}

}


template<class T>
void BinaryTree<T>::Visit(TreeNode<T> *currentNode)
{
	cout << currentNode->data<<"  ";
	//����Ҳ�ܶԽڵ����һЩ����
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
	}     //ʹ�õݹ���������ǱȽϼ��ģ���Ҫȥ��⡣
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

