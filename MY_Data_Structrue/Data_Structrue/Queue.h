#pragma once
#ifndef Queue_H
#define Queue_H
//这个队列队首是不存任何数据的，为了编程方便


template<class T>
class MyQueue
{
public:
	MyQueue(int queueCap = 10);   //构造函数
	bool IsEmpty() const;
	T & Front() const;
	T & Rear() const;
	void Push(const T &item);
	void Pop();
	int getCap()
	{
		return capacity;
	}
private:
	T *Queue;
	int front;
	int rear;
	int capacity;
};


#endif // !Queue_H

template<class T>
inline MyQueue<T>::MyQueue(int queueCap):capacity(queueCap)
{
	if (capacity < 1)  throw"queue capacity must be >=0";
	Queue = new T[capacity];
	front = 0;
	rear = 0;
}

template<class T>
inline bool MyQueue<T>::IsEmpty() const
{
	
	return (front==rear);   //队首和队尾相等就认为是空的
}

template<class T>
inline T & MyQueue<T>::Front() const
{
	if (this->IsEmpty())
		throw"empty queue has no front";
	return Queue[(front+1)%capacity];   
}

template<class T>
inline T & MyQueue<T>::Rear() const
{
	if (this->IsEmpty())
		throw"empty queue has no rear";
	return Queue[rear];
	
}

template<class T>    //主要是这个函数困难
inline void MyQueue<T>::Push(const T & item)
{
	//if (rear == capacity - 1)   //是不是最后一个
	//	rear = 0;
	//else
	//{
	//	rear++;	
	//}
	//这种写法可以写为  rear = (rear + 1) % capacity;
	if ((rear + 1) % capacity == front)   //如果满了增加一倍
	{
		T *newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (front < rear)      //如果没有发生循环回绕
		{
			std::copy(Queue+start, Queue+capacity-1, newQueue+1);
		}
		else
		{
			std::copy(Queue+start, Queue+capacity - 1, newQueue+1);   //复制后半部分
			std::copy(Queue, Queue+rear, newQueue + 1 + (capacity - front - 1));  //复制前半部分
		}

		delete[] Queue;
		Queue = newQueue;
		front = 0;
		rear = capacity;
		capacity *= 2;
	}

	else
	{
		rear = (rear + 1) % capacity;
		Queue[rear] = item;
	}
}

template<class T>
inline void MyQueue<T>::Pop()
{
	if (this->IsEmpty())
		throw"empty queue can not be deleted";
	front = (front + 1) % capacity;   //处理循环
	Queue[front].~T();   //析构掉这个数据
}


