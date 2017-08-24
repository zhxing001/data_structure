#pragma once
#ifndef  QUEUELI_H
#define	 QUEUELI_H	

template<class T>
class ListQueue
{
public:
	ListQueue();
	~ListQueue();

	bool IsEmpty()  const;     //是否为空
	const T& getFront()  const;  //队首获得数据
	void  enqueue(const T&x);    //插入数据，队尾
	T dequeue();              //删除队首数据
	void makeEmpty();       //清空队列
private:
	
	struct ListNode
	{
		T element;
		ListNode *next;           //指向下一个的指针。
		ListNode(const T& theelement,ListNode *n=0):element(theelement),next(n){}
		//构造函数，带初始化列表

	};
	ListNode *front;     //两个指针，一个队首一个队尾 
	ListNode *back;
};

template<class T>       //构造函数
ListQueue<T>::ListQueue()
{
	front = back = 0;
}


template<class T>            //析构函数
ListQueue<T>::~ListQueue()
{
	makeEmpty();
}

template<class T>      
void ListQueue<T>::makeEmpty()
{
	while (!IsEmpty())
		dequeue();      //如果队列不空就一直删除数据
}


template<class T>
bool ListQueue<T>::IsEmpty() const
{
	return front == 0;

}

template<class T>
const T& ListQueue<T>::getFront()  const
{
	if (IsEmpty())
		throw "Queue is Empty";
	return front->element;
}

template<class T>
void ListQueue<T>::enqueue(const T&x)  //插入数据，在队尾
{
	if (IsEmpty())
		back = front = new ListNode(x);
	//如果原来是空的，插入一个数据的话既是队尾也是队首
	else
	{
		back->next = new ListNode(x);    //如果不是空的，back就指向后面
		back = back->next;    
		//也可写作：back = back->next= new ListNode(x);  赋值是从右往左的
	} 
}

template<class T>
T ListQueue<T>::dequeue()
{
	T frontItem = getFront();
	ListNode *old;
	old = front;
	front = front->next;
	delete old;    
	//我试了下不用把这个old删除也是没问题的，不会有内存泄露，但是这个数据确实没用了。还是删除好、
	return frontItem;
}

#endif