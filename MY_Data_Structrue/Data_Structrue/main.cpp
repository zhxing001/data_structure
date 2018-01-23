#pragma warning(disable:4996)

#include"myUtil.h"
#include<iostream>
#include"MyStack.h"
#include"Queue.h"
#include"BinaryTree.h"
#include"BinarySearchTree.h"
using namespace std;


int main()
{
	BST<int> BT;
	Element<int> a, b, c, d, e, f, g, h, i, j, k, l;
	a.key = 5;
	b.key = 3;
	c.key = 11;
	d.key = 3;
	e.key = 15;
	f.key = 2;
	g.key = 8;
	h.key = 22;
	i.key = 20;
	j.key = 9;
	
	cout << BT.Insert(a) << endl;	
	cout << BT.Insert(b) << endl;	
	cout << BT.Insert(c) << endl;	
	cout << BT.Insert(d) << endl;
	cout << BT.Insert(e) << endl;
	cout << BT.Insert(f) << endl;
	cout << BT.Insert(g) << endl;
	cout << BT.Insert(h) << endl;
	BT.display();
	auto s=BT.Search(f);
	cout <<"查找到的数据是：" <<s->data.key<<endl;
	auto SEarch = BT.IterSearch(c);
	cout << "查找到的数据是："<<SEarch->data.key << endl;
	BT.display();






	//二叉树测试程序
	//BinaryTree<char> Tree;
	//TreeNode<char>  a('A');
	//TreeNode<char>  b('B');
	//TreeNode<char>  c('C');
	//TreeNode<char>  d('D');
	//TreeNode<char>  e('E');
	//TreeNode<char>  f('F');
	//TreeNode<char>  g('G');

	////          A
 //   //        /    \
	////      B        C
	////    /   \     /  \
	////   D     E   F     G
	//Tree.root = &a;
	//a.leftChild = &b;
	//a.rightChild = &c;       
	//b.leftChild = &d;
	//b.rightChild = &e;
	//c.leftChild = &f;
	//c.rightChild = &g;

	//Tree.InOrder();
	//cout << endl;
	//Tree.PreOrder();
	//cout << endl;
	//Tree.PostOrder();
	//cout << endl;
	//Tree.LevelOrder();


	//队列测试程序
	/*MyQueue<char> q(4);
	q.Push('A');
	q.Push('B');
	q.Push('c');
	q.Push('D');
	q.Push('e');
	q.Push('f');
	q.Push('D');
	q.Push('e');
	q.Push('f');
	q.Push('D');
	q.Push('e');
	q.Push('f');
	q.Pop();
	cout << q.getCap() << endl;
	cout << q.Front() << "   ";
	cout << q.Rear() << endl;
	q.Pop();
	q.Pop();
	q.Pop();

	cout << q.getCap() << endl;
	cout << q.Front() << "   ";
	cout << q.Rear() << endl;
	q.Push('G');
	q.Push('D');
	q.Push('e');
	q.Push('G');
	cout << q.getCap() << endl;
	cout << q.Front() << "   ";
	cout << q.Rear() << endl;*/

	
	
	
	
	//堆栈测试
	/*MYstack<int> stack1(10);
	stack1.Push(1);
	stack1.Push(2);
	stack1.Push(3);
	stack1.Push(4);
	stack1.Push(18);
	stack1.Push(30);
	cout << stack1.Top() << endl;
	stack1.Pop();
	cout << stack1.Top() << endl;
	stack1.Pop();
	stack1.Pop();
	stack1.Pop();
	stack1.Pop();*/

	
	return 0;
}