#pragma once
#ifndef  QUEUELI_H
#define	 QUEUELI_H	

template<class T>
class ListQueue
{
public:
	ListQueue();
	~ListQueue();

	bool IsEmpty()  const;     //�Ƿ�Ϊ��
	const T& getFront()  const;  //���׻������
	void  enqueue(const T&x);    //�������ݣ���β
	T dequeue();              //ɾ����������
	void makeEmpty();       //��ն���
private:
	
	struct ListNode
	{
		T element;
		ListNode *next;           //ָ����һ����ָ�롣
		ListNode(const T& theelement,ListNode *n=0):element(theelement),next(n){}
		//���캯��������ʼ���б�

	};
	ListNode *front;     //����ָ�룬һ������һ����β 
	ListNode *back;
};

template<class T>       //���캯��
ListQueue<T>::ListQueue()
{
	front = back = 0;
}


template<class T>            //��������
ListQueue<T>::~ListQueue()
{
	makeEmpty();
}

template<class T>      
void ListQueue<T>::makeEmpty()
{
	while (!IsEmpty())
		dequeue();      //������в��վ�һֱɾ������
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
void ListQueue<T>::enqueue(const T&x)  //�������ݣ��ڶ�β
{
	if (IsEmpty())
		back = front = new ListNode(x);
	//���ԭ���ǿյģ�����һ�����ݵĻ����Ƕ�βҲ�Ƕ���
	else
	{
		back->next = new ListNode(x);    //������ǿյģ�back��ָ�����
		back = back->next;    
		//Ҳ��д����back = back->next= new ListNode(x);  ��ֵ�Ǵ��������
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
	//�������²��ð����oldɾ��Ҳ��û����ģ��������ڴ�й¶�������������ȷʵû���ˡ�����ɾ���á�
	return frontItem;
}

#endif