#ifndef  MY_stack
#define  MY_stack
#include"myUtil.h"

template<class T>
class MYstack
{
public:
	MYstack(int stackCapacity = 10);   //默认大小是10
	~MYstack();
	bool IsEmpty() const;
	T &Top() const;   //栈顶元素
	void Push(const T& item);
	void Pop();    //删除栈顶元素
private:
	T * stack;  //利用这个指针动态创建数组
	int top;   //记录栈顶的位置
	int capacity;   //容量

};


//构造函数
template<class T>
MYstack<T>::MYstack(int stackCapacity) :capacity(stackCapacity)
{
	if (capacity < 1) throw "stack size must be >0";
	stack = new T[capacity];
	top = -1;   //表示堆栈是空的

}

//析构函数
template<class T>
MYstack<T>::~MYstack()
{
	delete[] stack;
}

//是否为空
template<class T>
inline bool MYstack<T>::IsEmpty() const
{
	return top==-1;
}

//栈顶元素
template<class T>
inline T & MYstack<T>::Top() const
{
	if (this->IsEmpty())  throw "the stack is empty";
	return stack[top];
}

//进栈
template<class T>
inline void MYstack<T>::Push(const T & item)
{
	if (top == capacity - 1)   //如果满了，把数组放大
	{
		ChangeSize1D(stack, capacity, capacity * 2);
		capacity *= 2;
	}
	stack[++top] = item;   //先把top++，然后把这个数放进去。
}

//删除栈顶
template<class T>
inline void MYstack<T>::Pop()
{
	if (IsEmpty())
		throw "the stack is empty,can not be deleted!";
	//top--;   //简单的删除这样就可以了
	stack[top--].~T();
}
#endif // ! MY_stack
