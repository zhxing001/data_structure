#ifndef  MY_stack
#define  MY_stack
#include"myUtil.h"

template<class T>
class MYstack
{
public:
	MYstack(int stackCapacity = 10);   //Ĭ�ϴ�С��10
	~MYstack();
	bool IsEmpty() const;
	T &Top() const;   //ջ��Ԫ��
	void Push(const T& item);
	void Pop();    //ɾ��ջ��Ԫ��
private:
	T * stack;  //�������ָ�붯̬��������
	int top;   //��¼ջ����λ��
	int capacity;   //����

};


//���캯��
template<class T>
MYstack<T>::MYstack(int stackCapacity) :capacity(stackCapacity)
{
	if (capacity < 1) throw "stack size must be >0";
	stack = new T[capacity];
	top = -1;   //��ʾ��ջ�ǿյ�

}

//��������
template<class T>
MYstack<T>::~MYstack()
{
	delete[] stack;
}

//�Ƿ�Ϊ��
template<class T>
inline bool MYstack<T>::IsEmpty() const
{
	return top==-1;
}

//ջ��Ԫ��
template<class T>
inline T & MYstack<T>::Top() const
{
	if (this->IsEmpty())  throw "the stack is empty";
	return stack[top];
}

//��ջ
template<class T>
inline void MYstack<T>::Push(const T & item)
{
	if (top == capacity - 1)   //������ˣ�������Ŵ�
	{
		ChangeSize1D(stack, capacity, capacity * 2);
		capacity *= 2;
	}
	stack[++top] = item;   //�Ȱ�top++��Ȼ���������Ž�ȥ��
}

//ɾ��ջ��
template<class T>
inline void MYstack<T>::Pop()
{
	if (IsEmpty())
		throw "the stack is empty,can not be deleted!";
	//top--;   //�򵥵�ɾ�������Ϳ�����
	stack[top--].~T();
}
#endif // ! MY_stack
