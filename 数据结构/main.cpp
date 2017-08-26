//#include"Double.h"        //双向链表
//#include"ListStack.h"        //链式栈
//#include "ListQueue.h"            //链式队列
//#include "BinTree.h"         //二叉树
//#include"BinarySearchTree.h"     //二叉查找树
//#include"MaxHeap.h"              //大顶堆
//#include"LinearMap.h"          //线性映射
#include"HashMap.h"                //哈希映射
                              
#include<unordered_map>          //c++自己的hash映射(微软做的)
//以前用的hash_map  即将被移除了，这里用hash_map的话就会有错误，取而代之用这个库。
#include<iostream>

using namespace std;

int  main()
{
	//-------------------【哈希映射测试程序】--------------------------
	cout << "test" << endl;
	HashMap<string,int> H;
	H.Put("marry", 999);
	H.Put("zhxing", 99);
	H.Put("lyzhen", 199);
	H.Put("xxx", 234);
	H.Put("zzs", 456);

	cout <<"marry： "<< H.Get("marry") << endl;
	cout << "xxx： " << H.Get("xxx") << endl;

	cout << "使用c++自己的hash映射" << endl;
	unordered_map<string, int> h;
	h["bill"] = 12;
	h["tom"] = 22;
	h["marry"] = 23;
	h["tomeq"] = 232;
	h["marew"] = 24;
	cout << h["marry"];
	
	//---------------------end-----------------------------------------







	//---------------------【线性映射-很慢-测试程序】-------------------
	/*LinearMap<string, int> lm;
	lm.Put("bill", 99);
	lm.Put("tom", 88);
	lm.Put("lyzhen", 55);
	lm.Put("anshubing", 82);
	lm.Put("zhxing", 100);
	cout << lm.Get("zhxing") << endl;  */
	//--------------------------end-------------------------------------

	//-----------------【最大堆测试程序】---------------------------
	/*cout << "test" << endl;
	MaxHeap<int>  H(30);
	
	H.Push(6);
	H.Push(5);
	H.Push(8);
	H.Push(90);
	H.Push(1);
	H.Push(3);
	cout << H.Top() << "  ";
	H.Pop();
	cout << H.Top() << "  ";
	H.Pop();
	cout << H.Top() << "  ";
	H.Pop();
	cout << H.Top() << "  ";
	H.Pop();
	cout << H.Top() << "  ";
	H.Pop();
	cout << H.Top() << "  ";*/
	//其实这个方法可以用来排序啊，而且是二分排序的速度
    //-----------------------end---------------------------------

	//------------------【二叉查找树测试程序】------------------
	/*cout << "test" << endl;
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
	cout << "循环找到的是：" << p->data.key << endl;*/
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