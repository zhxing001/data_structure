#pragma once    //������һ�Σ�΢����еķ�ֹͷ�ļ����ظ������ķ���ifdef ��endif�ķ�ʽ���Կ�ƽ̨ʹ��

#ifndef  GRAPH_H
#define  GRAPH_H
#include<iostream>
#define MAX_SIZE 20
class Vertex          //����
{
public:
	Vertex(char lab)
	{
		Label = lab;
	}
private:
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
private:
	Vertex *verteslist[MAX_SIZE];  //20������  
	int nVerts;   //ʵ���ϵĶ�����
	int adjMax[MAX_SIZE][MAX_SIZE];   //�ڽӾ���

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

Graph::~Graph()
{
	for (int i = 0; i < nVerts; i++)
		delete verteslist[i];

}

#endif