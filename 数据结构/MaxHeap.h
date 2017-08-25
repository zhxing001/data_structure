#pragma once
//大顶堆
#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H

template<class T>
class MaxHeap
{
public:
	MaxHeap(int mx = 10);   //构造函数
	virtual ~MaxHeap();   //析构函数
	bool IsEmpty();          //是否为空
	void Push(const T&x);      //插入数据
	void Pop();             //删除数据
	const T& Top()  const;    //返回堆顶
	const int getCurrentSize()
	{
		return currentSize;
	}
	
private:
	T* heapArray;        //数组。存放堆用的
	int maxSize;            //堆的数据个数
	int currentSize;        //现有数据个数
	void trickUp(int index);          //向上渗透
	void trickDown(int index);       //向下渗透
};

template<class T>
MaxHeap<T>::MaxHeap(int mx = 10)
{
	if (mx<1)
		throw "大小要大于1！";
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
	//没有数据则是空的
}

template<class T>
void MaxHeap<T>::Push(const T&e)
{
	if (currentSize == maxSize)  //如果堆已经满了
		throw "MaxHeap is full!";
	heapArray[currentSize] = e;     //新插入的数据放到最后，然后向上渗透
	trickUp(currentSize++);
	

}

template<class T>
void MaxHeap<T>::trickUp(int index)
{
	int parent = (index - 1) / 2;
	T temp = heapArray[index];   //先保存起来，待会交换
	//只要index不是0，且子节点的值大于父节点，就可以一直向上交换
	while (index > 0 && (heapArray[parent] < temp))
	{
		
		heapArray[index] = heapArray[parent];   //如果大就换下来
		index = parent;
		parent = (parent - 1) / 2;      //更新父节点
		//交换父子节点的值
	}
	heapArray[index] = temp;   //最后找到的这个节点就是放数据的地方
	//这里注意不需要在循环里每次交换(这样也是可以的)，但是就是浪费了一倍的时间，
	//只需要比较就可以了，不用去交换，到最后再交换

}


template<class T>
const T& MaxHeap<T>::Top() const
{
	return heapArray[0];    //堆顶在数组的开头
}

template<class T>
void MaxHeap<T>::Pop()
{
	heapArray[0] = heapArray[--currentSize];
	//一开始写得是：heapArray[0] = heapArray[currentSize-1];
	//开始觉得没有问题，但是测试的时候发现到最后的节点的时候就删除不了了，
	//想了很久其实原因很简单：每一次pop之后，因为已经删除了一个数据了，所以数据
	//综述肯定是要减一的，要不犹豫current的限制就只能删除一部分数据。
	trickDown(0);
}

template<class T>
void MaxHeap<T>::trickDown(int index)
{
	T Top = heapArray[index];    //临时的根
	int largeChild;
	while (index <( currentSize / 2))
	{
		int leftChild = 2 * index + 1;
		int rightChild = leftChild + 1;   //计算左右子树
		if (rightChild < currentSize&&heapArray[leftChild] < heapArray[rightChild])      
			//如果右节点存在且右节点大
			largeChild = rightChild;  	  
		else
			largeChild = leftChild;       //右节点不存在，认为左节点是大的那个节点
		if (Top >= heapArray[largeChild])
			break;          //如果top本身大，那就停止。
		else
		heapArray[index] = heapArray[largeChild];  //小的话就向上移动
		index = largeChild;
	}
	heapArray[index] = Top;  //最后的交换

}

#endif