//#include"Double.h"        //˫������
//#include"ListStack.h"        //��ʽջ
//#include "ListQueue.h"            //��ʽ����
//#include "BinTree.h"         //������
//#include"BinarySearchTree.h"     //���������
//#include"MaxHeap.h"              //�󶥶�
//#include"LinearMap.h"          //����ӳ��
#include"HashMap.h"                //��ϣӳ��
                              
#include<unordered_map>          //c++�Լ���hashӳ��(΢������)
//��ǰ�õ�hash_map  �������Ƴ��ˣ�������hash_map�Ļ��ͻ��д���ȡ����֮������⡣
#include<iostream>

using namespace std;

int  main()
{
	//-------------------����ϣӳ����Գ���--------------------------
	cout << "test" << endl;
	HashMap<string,int> H;
	H.Put("marry", 999);
	H.Put("zhxing", 99);
	H.Put("lyzhen", 199);
	H.Put("xxx", 234);
	H.Put("zzs", 456);

	cout <<"marry�� "<< H.Get("marry") << endl;
	cout << "xxx�� " << H.Get("xxx") << endl;

	cout << "ʹ��c++�Լ���hashӳ��" << endl;
	unordered_map<string, int> h;
	h["bill"] = 12;
	h["tom"] = 22;
	h["marry"] = 23;
	h["tomeq"] = 232;
	h["marew"] = 24;
	cout << h["marry"];
	
	//---------------------end-----------------------------------------







	//---------------------������ӳ��-����-���Գ���-------------------
	/*LinearMap<string, int> lm;
	lm.Put("bill", 99);
	lm.Put("tom", 88);
	lm.Put("lyzhen", 55);
	lm.Put("anshubing", 82);
	lm.Put("zhxing", 100);
	cout << lm.Get("zhxing") << endl;  */
	//--------------------------end-------------------------------------

	//-----------------�����Ѳ��Գ���---------------------------
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
	//��ʵ������������������򰡣������Ƕ���������ٶ�
    //-----------------------end---------------------------------

	//------------------��������������Գ���------------------
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
	cout <<"�ݹ��ҵ����ǣ�"<< p->data.key<<endl;
	p = TREE.IterSearch(f);
	cout << "ѭ���ҵ����ǣ�" << p->data.key << endl;*/
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