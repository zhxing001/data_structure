//#include"Double.h"
//#include"ListStack.h"
//#include "ListQueue.h"
//#include "BinTree.h"
#include"BinarySearchTree.h"
#include<iostream>
using namespace std;
int  main()
{
	//------------------【二叉查找树测试程序】------------------
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
	cout <<"递归找到的是："<< p->data.key<<endl;
	p = TREE.IterSearch(f);
	cout << "循环找到的是：" << p->data.key << endl;
	//----------------------end--------------------------------












	//-----------------【二叉树测试程序】----------------
	/*BinaryTree<char>  tree;
	TreeNode<char>  加, 减, 乘, 除, a, b, c, d, e;
	加.data = '+';
	减.data = '-';
	乘.data = '*';                             
	除.data = '/';
	a.data = 'A';
	b.data = 'B';
	c.data = 'C';
	d.data = 'D';
	e.data = 'E';
	           

	tree.root = &加;
	加.leftChild = &减;
	加.rightChild = &e;
	减.leftChild = &乘;
	减.rightChild = &d;
	乘.leftChild = &除;
	乘.rightChild = &c;
	除.leftChild = &a;
	除.rightChild = &b;

	cout << "中序遍历：";
	tree.InOrder();
	cout<<endl;
	cout << "前序遍历：";
	tree.PreOrder();
	cout << endl;
	cout << "后序遍历：";
	tree.PostOrder();
	cout << endl;
	cout << "层序遍历：";
	tree.LevelOrder();
	cout << endl;*/
	//-----------------end-------------------------------
	
	
	
	
	
	
	
	//-------------【链式队列测试程序】----------------
	/*cout << "test" << endl;
	ListQueue<int> myQ;
	myQ.enqueue(10);
	myQ.enqueue(20);
	myQ.enqueue(30);
	cout << myQ.dequeue() << endl;
	cout << myQ.getFront() << endl;*/
	//-----------------end-----------------------------



	//--------【链式栈的测试程序】-------------------------
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


	//-----------------【双向链表测试代码】------------------
	//cout << "双向链表测试" << endl;
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
	////顺序插入四个节点
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