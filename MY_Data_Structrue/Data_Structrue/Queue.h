#pragma once
#ifndef Queue_H
#define Queue_H
//������ж����ǲ����κ����ݵģ�Ϊ�˱�̷���


template<class T>
class MyQueue
{
public:
	MyQueue(int queueCap = 10);   //���캯��
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
	
	return (front==rear);   //���׺Ͷ�β��Ⱦ���Ϊ�ǿյ�
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

template<class T>    //��Ҫ�������������
inline void MyQueue<T>::Push(const T & item)
{
	//if (rear == capacity - 1)   //�ǲ������һ��
	//	rear = 0;
	//else
	//{
	//	rear++;	
	//}
	//����д������дΪ  rear = (rear + 1) % capacity;
	if ((rear + 1) % capacity == front)   //�����������һ��
	{
		T *newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (front < rear)      //���û�з���ѭ������
		{
			std::copy(Queue+start, Queue+capacity-1, newQueue+1);
		}
		else
		{
			std::copy(Queue+start, Queue+capacity - 1, newQueue+1);   //���ƺ�벿��
			std::copy(Queue, Queue+rear, newQueue + 1 + (capacity - front - 1));  //����ǰ�벿��
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
	front = (front + 1) % capacity;   //����ѭ��
	Queue[front].~T();   //�������������
}


