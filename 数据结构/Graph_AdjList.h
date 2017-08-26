#pragma once

#include<iostream>
#include<list>


class Vertex_L
{
public:
	char Label;
	Vertex_L(char lab)
	{
		Label = lab;
	}
};




template<class T>
class Graph_L
{
public:
	Graph_L(const int Vertices):n(Vertices)
	{
		Verlist = new T*[n];   //创建新额数组
		headNodes = new list<int>[n];  //每个数组元素都是链表
		nVerts = 0;   //开始没有顶点。
	}
	~Graph_L()
	{
		delete[]  Verlist;
		delete[] headNodes;
	}
	void addVertex(T *v);
	void addEdge(int start, int end);
	void printVertex();
	void printAdjList();

private:
	T **Verlist;          //这个叫二级指针，指针指向的还是一个指针，二级指针待会指向链表
	std::list<int> *headNodes;       
	//这里莫名错误了好久，再记住一边，list是std下的，要么包含明明空间，要么加上std，十分钟买教训
	int n;     //最多的顶点数
	int nVerts;   //现在又多少顶点

};

template<class T>
inline void Graph_L<T>::addVertex(T *v)  //因为数组里保存的是指针，所以这里也要传入指针
{
	Verlist[nVerts++] = v;   //把顶点存入数组。
}

template<class T>
inline void Graph_L<T>::addEdge(int start, int end)
{
	headNodes[start].push_back(end);

}

template<class T>
inline void Graph_L<T>::printVertex()
{
	for (int i = 0; i < nVerts; i++)
		std::cout << *Verlist[i] << " ";
	std::cout << endl;
}

template<class T>
inline void Graph_L<T>::printAdjList()
{
	for (int i = 0; i < nVerts; i++)
	{
		std::cout << i ;
		for (list<int>::iterator iter = headNodes[i].begin(); iter != headNodes[i].end(); iter++)
		{
			std::cout << "->";
			std::cout << *iter;      //迭代器里就是指针。
		}
		std::cout << endl;
	}
}
