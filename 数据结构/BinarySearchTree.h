#pragma once
#ifndef  BinarySearchTree_H
#define  BinarySearchTree_H
#include<iostream>

enum Boolean
{
	FALSE,TRUE
};

template<class T>
class BST;      //ǰ������


template<class T>
class Element   //��ֵ
{public:
	T key;        //��ֵ
};


template<class T>
class BstNode    //���ڵ�
{
public:
	friend class BST<T>;
	Element<T>  data;

	
	BstNode *LeftChild;
	BstNode *RightChild;    // ���ﲻָ����������ַҲ����
	void dispaly(int i);   //��ʾ
};

template<class T>
class BST
{
public:

	BST(BstNode<T> *init=0)
	{
		root = init;      //��ʼ������������
	}
	Boolean  Insert( const Element<T> &x);  //bool���سɹ����߲��ɹ�
	BstNode<T>* Search(const Element<T> &x);   //���ң��ҵ�����ָ��
	BstNode<T>* Search(BstNode<T>*, const Element<T> &x);
	BstNode<T>* IterSearch(const Element<T> &x);   //�����Ĳ���
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
	if (!b)  return 0;     //����ڵ�Ϊ��
	if (x.key == b->data.key)    //data����ָ�룬����keyҪ��"."
		return b;     //���������������ص�ǰ��ַ
	if (x.key < b->data.key)   
		return Search(b->LeftChild, x);
	else 
		return Search(b->RightChild, x);
}

template<class T>
BstNode<T>* BST<T>::IterSearch(const Element<T> &x)
{
	for (BstNode<T> *t = root;t;)      //ֻҪ���ǿսڵ㣬�Ϳ���һֱ�ҡ�
	{
		if (x.key == t->data.key)   return  t;
		if (x.key < t->data.key)
			t = t->LeftChild;       
		else
			t = t->RightChild;   //���ݾ����������ʾָ�������ҡ�

	}
	return 0;      //���û�ҵ������ؿ�ָ�롣
	
}


template<class T>
void BstNode<T>::dispaly(int i)
{
	std::cout << "position in BST: " << i << "  " << 
		       "data.key: " << data.key << endl;
	if (LeftChild)   LeftChild->dispaly(2 * i);
	if (RightChild)  RightChild->dispaly(2 * i + 1);
	//������ʵ��һ�ֵݹ��д����

}

template<class T>
Boolean BST<T>::Insert(const Element<T> &x)  //����
{
	BstNode<T> *p = root;      //�����ڵ�
	BstNode<T> *q = 0;         //ָ��p�ĸ��ڵ㣬һ��ʼrootû�и��ڵ㣬������0����¼������ڵ����á�
	//���ȵ��ҵ�һ�����ʵ�λ��
	while (p)   //���p�Ƕ����һ��ʼָ��������ָ��
	{
		q = p;       //��pҪ������������ʱһ�����ڵ㣬����Ҫ���������
		if (x.key == p->data.key)    return FALSE;  //�������ظ�����
		if (x.key < p->data.key)   
			p = p->LeftChild;     //���С�Ļ�ָ�����
		else
			p = p->RightChild;    //�����Ļ�ָ���ұ�
	}
	//�ҵ���λ��
	p = new BstNode<T>;
	p->LeftChild = p->RightChild = 0;  //�½��Ľڵ㲻��������������ָ��
	p->data = x;
	//�½�һ���ڵ�
	if (!root)  root = p;
	else if (x.key < q->data.key)   q->LeftChild = p;
	else  q->RightChild = p;
	//���ݾ�������ѽڵ�ָ����߻����ұߡ�
	return TRUE;   //��ʾ����ɹ�
}




#endif // ! BinarySearchTree
