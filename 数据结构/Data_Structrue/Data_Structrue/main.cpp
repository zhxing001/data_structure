#pragma warning(disable:4996)

#include"myUtil.h"
#include<iostream>
#include"MyStack.h"
#include"Queue.h"
using namespace std;


int main()
{
	MyQueue<char> q(4);
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
	cout << q.Rear() << endl;

	
	
	
	
	//¶ÑÕ»²âÊÔ
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