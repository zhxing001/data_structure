#pragma once
//�󶥶�
#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H

template<class T>
class MaxHeap
{
public:
	MaxHeap(int mx = 10);   //���캯��
	virtual ~MaxHeap();   //��������
	bool IsEmpty();          //�Ƿ�Ϊ��
	void Push(const T&x);      //��������
	void Pop();             //ɾ������
	const T& Top()  const;    //���ضѶ�
	const int getCurrentSize()
	{
		return currentSize;
	}
	
private:
	T* heapArray;        //���顣��Ŷ��õ�
	int maxSize;            //�ѵ����ݸ���
	int currentSize;        //�������ݸ���
	void trickUp(int index);          //������͸
	void trickDown(int index);       //������͸
};

template<class T>
MaxHeap<T>::MaxHeap(int mx = 10)
{
	if (mx<1)
		throw "��СҪ����1��";
	maxSize = mx;
	currentSize = 0;
	heapArray = new T[maxSize];


}

template<class T>
MaxHeap<T>::~MaxHeap()
{
	delete[] heapArray;
}

template<class T>
bool MaxHeap<T>::IsEmpty()
{
	return currentSize == 0;  
	//û���������ǿյ�
}

template<class T>
void MaxHeap<T>::Push(const T&e)
{
	if (currentSize == maxSize)  //������Ѿ�����
		throw "MaxHeap is full!";
	heapArray[currentSize] = e;     //�²�������ݷŵ����Ȼ��������͸
	trickUp(currentSize++);
	

}

template<class T>
void MaxHeap<T>::trickUp(int index)
{
	int parent = (index - 1) / 2;
	T temp = heapArray[index];   //�ȱ������������ύ��
	//ֻҪindex����0�����ӽڵ��ֵ���ڸ��ڵ㣬�Ϳ���һֱ���Ͻ���
	while (index > 0 && (heapArray[parent] < temp))
	{
		
		heapArray[index] = heapArray[parent];   //�����ͻ�����
		index = parent;
		parent = (parent - 1) / 2;      //���¸��ڵ�
		//�������ӽڵ��ֵ
	}
	heapArray[index] = temp;   //����ҵ�������ڵ���Ƿ����ݵĵط�
	//����ע�ⲻ��Ҫ��ѭ����ÿ�ν���(����Ҳ�ǿ��Ե�)�����Ǿ����˷���һ����ʱ�䣬
	//ֻ��Ҫ�ȽϾͿ����ˣ�����ȥ������������ٽ���

}


template<class T>
const T& MaxHeap<T>::Top() const
{
	return heapArray[0];    //�Ѷ�������Ŀ�ͷ
}

template<class T>
void MaxHeap<T>::Pop()
{
	heapArray[0] = heapArray[--currentSize];
	//һ��ʼд���ǣ�heapArray[0] = heapArray[currentSize-1];
	//��ʼ����û�����⣬���ǲ��Ե�ʱ���ֵ����Ľڵ��ʱ���ɾ�������ˣ�
	//���˺ܾ���ʵԭ��ܼ򵥣�ÿһ��pop֮����Ϊ�Ѿ�ɾ����һ�������ˣ���������
	//�����϶���Ҫ��һ�ģ�Ҫ����ԥcurrent�����ƾ�ֻ��ɾ��һ�������ݡ�
	trickDown(0);
}

template<class T>
void MaxHeap<T>::trickDown(int index)
{
	T Top = heapArray[index];    //��ʱ�ĸ�
	int largeChild;
	while (index <( currentSize / 2))
	{
		int leftChild = 2 * index + 1;
		int rightChild = leftChild + 1;   //������������
		if (rightChild < currentSize&&heapArray[leftChild] < heapArray[rightChild])      
			//����ҽڵ�������ҽڵ��
			largeChild = rightChild;  	  
		else
			largeChild = leftChild;       //�ҽڵ㲻���ڣ���Ϊ��ڵ��Ǵ���Ǹ��ڵ�
		if (Top >= heapArray[largeChild])
			break;          //���top������Ǿ�ֹͣ��
		else
		heapArray[index] = heapArray[largeChild];  //С�Ļ��������ƶ�
		index = largeChild;
	}
	heapArray[index] = Top;  //���Ľ���

}

#endif