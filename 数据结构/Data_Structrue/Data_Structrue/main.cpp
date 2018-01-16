#pragma warning(disable:4996)

#include"myUtil.h"
#include<iostream>
#include"MyStack.h"
using namespace std;


int main()
{
	MYstack<int> stack1(10);
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
	stack1.Pop();
	stack1.Pop();
	stack1.Pop();
	stack1.Pop();
	
	return 0;
}