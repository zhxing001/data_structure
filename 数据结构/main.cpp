//#include"Double.h"
//#include"ListStack.h"
#include "ListQueue.h"
#include<iostream>
using namespace std;
int  main()
{
	
	
	
	
	
	
	
	
	//-------------����ʽ���в��Գ���----------------
	cout << "test" << endl;
	ListQueue<int> myQ;
	myQ.enqueue(10);
	myQ.enqueue(20);
	myQ.enqueue(30);
	cout << myQ.dequeue() << endl;
	cout << myQ.getFront() << endl;
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