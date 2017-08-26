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
		Verlist = new T*[n];   //�����¶�����
		headNodes = new list<int>[n];  //ÿ������Ԫ�ض�������
		nVerts = 0;   //��ʼû�ж��㡣
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
	T **Verlist;          //����ж���ָ�룬ָ��ָ��Ļ���һ��ָ�룬����ָ�����ָ������
	std::list<int> *headNodes;       
	//����Ī�������˺þã��ټ�סһ�ߣ�list��std�µģ�Ҫô���������ռ䣬Ҫô����std��ʮ�������ѵ
	int n;     //���Ķ�����
	int nVerts;   //�����ֶ��ٶ���

};

template<class T>
inline void Graph_L<T>::addVertex(T *v)  //��Ϊ�����ﱣ�����ָ�룬��������ҲҪ����ָ��
{
	Verlist[nVerts++] = v;   //�Ѷ���������顣
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
			std::cout << *iter;      //�����������ָ�롣
		}
		std::cout << endl;
	}
}
