//#include"Double.h"
//#include"ListStack.h"
//#include "ListQueue.h"
//#include "BinTree.h"
#include"BinarySearchTree.h"
#include<iostream>
using namespace std;
int  main()
{
	//------------------��������������Գ���------------------
	cout << "test" << endl;
	BST<int> TREE;
	Element<int> a, b, c, d, e, f, g;
	a.key = 2;
	b.key = 3;
	c.key = 1;
	d.key = 6;
	e.key = 4;
	f.key = 10;
	g.key = 8;
	cout << TREE.Insert(a) << endl;
	cout << TREE.Insert(b) << endl;
	cout << TREE.Insert(c) << endl;
	cout << TREE.Insert(d) << endl;
	cout << TREE.Insert(e) << endl;
	cout << TREE.Insert(f) << endl;
	cout << TREE.Insert(g) << endl;
	TREE.dispaly();
	BstNode<int> *p;
	p=TREE.Search(f);
	cout <<"�ݹ��ҵ����ǣ�"<< p->data.key<<endl;
	p = TREE.IterSearch(f);
	cout << "ѭ���ҵ����ǣ�" << p->data.key << endl;
	//----------------------end--------------------------------












	//-----------------�����������Գ���----------------
	/*BinaryTree<char>  tree;
	TreeNode<char>  ��, ��, ��, ��, a, b, c, d, e;
	��.data = '+';
	��.data = '-';
	��.data = '*';                             
	��.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';
	           

	tree.root = &��;
	��.leftChild = &��;
	��.rightChild = &e;
	��.leftChild = &��;
	��.rightChild = &d;
	��.leftChild = &��;
	��.rightChild = &c;
	��.leftChild = &a;
	��.rightChild = &b;

	cout << "���������";
	tree.InOrder();
	cout<<endl;
	cout << "ǰ�������";
	tree.PreOrder();
	cout << endl;
	cout << "���������";
	tree.PostOrder();
	cout << endl;
	cout << "���������";
	tree.LevelOrder();
	cout << endl;*/
	//-----------------end-------------------------------
	
	
	
	
	
	
	
	//-------------����ʽ���в��Գ���----------------
	/*cout << "test" << endl;
	ListQueue<int> myQ;
	myQ.enqueue(10);
	myQ.enqueue(20);
	myQ.enqueue(30);
	cout << myQ.dequeue() << endl;
	cout << myQ.getFront() << endl;*/
	//-----------------end-----------------------------



	//--------����ʽջ�Ĳ��Գ���-------------------------
	/*ListStack<int> T;
	T.Push(10);
	cout << T.Top() << endl;
	T.Push(20);
	cout << T.Top() << endl;
	T.Push(30);
	cout << T.Top() << endl;
	T.Pop();
	cout << T.Top() << endl;
	T.MakeEmpty();
	cout << T.Top() << endl;*/
	//------------------end-------------------------------


	//-----------------��˫��������Դ��롿------------------
	//cout << "˫���������" << endl;
	//Dblist intList;
	//DblistNode node1, node2, node3, node4, node5;
	//node1.data = 11;
	//node2.data = 22;
	//node3.data = 33;
	//node4.data = 44;
	//node5.data = 55;

	//intList.Insert(&node1, intList.first);
	//intList.Insert(&node2, intList.first);
	//intList.Insert(&node3, intList.first);
	//intList.Insert(&node4, intList.first);
	//intList.Insert(&node5, intList.first);
	////˳������ĸ��ڵ�
	//intList.Delete(&node3);

	//cout << intList.first->rlink->data << endl;  
	//cout << intList.first->rlink->rlink->data << endl;
	//cout << intList.first->rlink->rlink->rlink->data << endl;
	//cout << intList.first->rlink->rlink->rlink->rlink->data << endl;
	//
	//cout << intList.first->rlink->rlink->rlink->rlink->llink->data << endl;
	//cout << intList.first->rlink->rlink->rlink->rlink->llink->llink->data << endl;
	//cout << intList.first->rlink->rlink->rlink->rlink->llink->llink->llink->data << endl;
	//---------------------------------end-------------------------------------------------
	


	
	return 0;
}