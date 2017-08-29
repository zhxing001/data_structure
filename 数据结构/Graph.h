#pragma once    //������һ�Σ�΢����еķ�ֹͷ�ļ����ظ������ķ���ifdef ��endif�ķ�ʽ���Կ�ƽ̨ʹ��

#ifndef  GRAPH_H
#define  GRAPH_H
#include<iostream>
#include<stack>     //��ջ���������������
#include<queue>
#define MAX_SIZE 20
class Vertex          //����
{
public:
	Vertex(char lab)
	{
		Label = lab;
		wasVistted = false;
	}

	bool wasVistted;   //�Ƿ񱻷��ʹ�
	char Label;
};

class Graph         //ͼ
{
public:
	Graph();          //���캯��
	~Graph();           //��������
	void addaVertex(char lab);     //����һ������
	void addEdge(int start, int end);   //����һ����
	void printMat();    //��ӡ�ڽӾ���
	void showVertex(int v);  //��ʾ����
	void DFS();
	void BFS();
private:
	Vertex *verteslist[MAX_SIZE];  //20������  
	int nVerts;   //ʵ���ϵĶ�����
	int adjMax[MAX_SIZE][MAX_SIZE];   //�ڽӾ���
	int getAdjUnivisitedVertex(int v);   //��ʾ��ǰ�������ڵ�δ�����ʵĶ�������
};

Graph::Graph()      //���캯��
{
	nVerts = 0; //û�ж���
	for (int i = 0; i < MAX_SIZE; i++) 
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			adjMax[i][j] = 0;
		}
	} //��ʼ���ڽӾ���ȫλ0
}

void Graph::addaVertex(char lab)
{
	verteslist[nVerts++] = new Vertex(lab);
	//����һ������ŵ��������ǰ���������1.
}

void Graph::addEdge(int start, int end)
{
	adjMax[start][end] = adjMax[end][start] = 1;
	//�Գƾ���������дλ1
}

void Graph::printMat()
{
	for (int i = 0; i < nVerts; i++)
	{
		for (int j = 0; j < nVerts; j++)
		{
			std::cout << adjMax[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

inline void Graph::showVertex(int v)
{
	std::cout << verteslist[v]->Label << "  ";
}

inline void Graph::DFS()
{
	std::stack<int>  gStack; //��ս���涥���±�
	verteslist[0]->wasVistted = true;     //�ȴӵ�һ�����㻹�Ƿ���
	showVertex(0);       //��ʾ��һ������
	gStack.push(0);        //���ʹ��Ķ���ѹ���ջ	
	int v;
	while (gStack.size() > 0) //��ջ��Ϊ�վ�Ҫһֱ����
	{
		v = getAdjUnivisitedVertex(gStack.top());   //�Ҷ�ջ�������ڵ�δ�����ʵ���һ��
		if (v == -1)
			gStack.pop();       //���û����һ������ɾ����ǰ��ջ��������
		else                     //����еĻ�
		{
			showVertex(v);    //˵���������ˣ���ʾ
			verteslist[v]->wasVistted = true; //����Ѿ�����
			gStack.push(v);    //ѹ���ջ
		}
		
	}
	std::cout << std::endl;
	for (int i = 0; i < nVerts; i++)
		verteslist[i]->wasVistted = false;
	//����ǳ�δ���ʵģ�������һ������
}

inline void Graph::BFS()
{
	std::queue<int> gQueue;
	verteslist[0]->wasVistted = true;     //�ȴӵ�һ�����㻹�Ƿ���
	showVertex(0);       //��ʾ��һ������
	gQueue.push(0);        //�������
	int vert1, vert2;
	while (gQueue.size() > 0)   //���в��յĻ��ͼ���Ѱ��
	{
		vert1 = gQueue.front();     //�Ѷ����ó���
		gQueue.pop();          //ɾ������
		vert2 = getAdjUnivisitedVertex(vert1);
		while (vert2 != -1)    //�ҵ����еĺͶ��������ӵĶ���
		{
			  
			verteslist[vert2]->wasVistted = true; //��ǳ��ѷ��ʹ�
			showVertex(vert2);   //��ʾ��ǰ����
			gQueue.push(vert2);     //�ŵ���β
			vert2 = getAdjUnivisitedVertex(vert1);  //�ҵ��������ڵ�δ���ʹ��ġ�
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < nVerts; i++)
		verteslist[i]->wasVistted = false;     //����Ϊδ���ʣ�������һ������
}

inline int Graph::getAdjUnivisitedVertex(int v)
{
	for (int j = 0; j < nVerts; j++)
	{
		if ((adjMax[v][j] == 1) && (verteslist[j]->wasVistted == false))
			return j;   //�����ڽӾ����һ�У�Ҫ�ҵ��������ڵ���δ�����ʹ��ġ�
	}

	return -1;  //����û���ҵ�
}

Graph::~Graph()
{
	for (int i = 0; i < nVerts; i++)
		delete verteslist[i];

}

#endif