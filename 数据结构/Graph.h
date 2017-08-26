#pragma once    //仅编译一次，微软独有的防止头文件被重复包含的方法ifdef 和endif的方式可以跨平台使用

#ifndef  GRAPH_H
#define  GRAPH_H
#include<iostream>
#define MAX_SIZE 20
class Vertex          //顶点
{
public:
	Vertex(char lab)
	{
		Label = lab;
	}
private:
	char Label;
};

class Graph         //图
{
public:
	Graph();          //构造函数
	~Graph();           //析构函数
	void addaVertex(char lab);     //增加一个顶点
	void addEdge(int start, int end);   //增加一条边
	void printMat();    //打印邻接矩阵
private:
	Vertex *verteslist[MAX_SIZE];  //20个顶点  
	int nVerts;   //实际上的顶点数
	int adjMax[MAX_SIZE][MAX_SIZE];   //邻接矩阵

};

Graph::Graph()      //构造函数
{
	nVerts = 0; //没有顶点
	for (int i = 0; i < MAX_SIZE; i++) 
	{
		for (int j = 0; j < MAX_SIZE; j++)
		{
			adjMax[i][j] = 0;
		}
	} //初始化邻接矩阵全位0
}

void Graph::addaVertex(char lab)
{
	verteslist[nVerts++] = new Vertex(lab);
	//创建一个顶点放到数组里，当前顶点个数加1.
}

void Graph::addEdge(int start, int end)
{
	adjMax[start][end] = adjMax[end][start] = 1;
	//对称矩阵，两个都写位1
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