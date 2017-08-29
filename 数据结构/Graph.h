#pragma once    //仅编译一次，微软独有的防止头文件被重复包含的方法ifdef 和endif的方式可以跨平台使用

#ifndef  GRAPH_H
#define  GRAPH_H
#include<iostream>
#include<stack>     //堆栈，深度优先搜索用
#include<queue>
#define MAX_SIZE 20
class Vertex          //顶点
{
public:
	Vertex(char lab)
	{
		Label = lab;
		wasVistted = false;
	}

	bool wasVistted;   //是否被访问过
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
	void showVertex(int v);  //显示顶点
	void DFS();
	void BFS();
private:
	Vertex *verteslist[MAX_SIZE];  //20个顶点  
	int nVerts;   //实际上的顶点数
	int adjMax[MAX_SIZE][MAX_SIZE];   //邻接矩阵
	int getAdjUnivisitedVertex(int v);   //显示当前顶点相邻的未被访问的顶点的序号
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

inline void Graph::showVertex(int v)
{
	std::cout << verteslist[v]->Label << "  ";
}

inline void Graph::DFS()
{
	std::stack<int>  gStack; //对战保存顶点下标
	verteslist[0]->wasVistted = true;     //先从第一个顶点还是访问
	showVertex(0);       //显示第一个顶点
	gStack.push(0);        //访问过的顶点压入堆栈	
	int v;
	while (gStack.size() > 0) //堆栈不为空就要一直搜索
	{
		v = getAdjUnivisitedVertex(gStack.top());   //找堆栈顶的相邻的未被访问的下一个
		if (v == -1)
			gStack.pop();       //如果没有下一个，就删除当前堆栈顶部数据
		else                     //如果有的话
		{
			showVertex(v);    //说明搜索到了，显示
			verteslist[v]->wasVistted = true; //标记已经访问
			gStack.push(v);    //压入堆栈
		}
		
	}
	std::cout << std::endl;
	for (int i = 0; i < nVerts; i++)
		verteslist[i]->wasVistted = false;
	//都标记成未访问的，便于下一次搜索
}

inline void Graph::BFS()
{
	std::queue<int> gQueue;
	verteslist[0]->wasVistted = true;     //先从第一个顶点还是访问
	showVertex(0);       //显示第一个顶点
	gQueue.push(0);        //放入队列
	int vert1, vert2;
	while (gQueue.size() > 0)   //队列不空的话就继续寻找
	{
		vert1 = gQueue.front();     //把队首拿出来
		gQueue.pop();          //删掉队首
		vert2 = getAdjUnivisitedVertex(vert1);
		while (vert2 != -1)    //找到所有的和队首相连接的顶点
		{
			  
			verteslist[vert2]->wasVistted = true; //标记成已访问过
			showVertex(vert2);   //显示当前顶点
			gQueue.push(vert2);     //放到队尾
			vert2 = getAdjUnivisitedVertex(vert1);  //找到队首相邻的未访问过的。
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < nVerts; i++)
		verteslist[i]->wasVistted = false;     //设置为未访问，便于下一次搜索
}

inline int Graph::getAdjUnivisitedVertex(int v)
{
	for (int j = 0; j < nVerts; j++)
	{
		if ((adjMax[v][j] == 1) && (verteslist[j]->wasVistted == false))
			return j;   //遍历邻接矩阵的一行，要找到和其相邻的且未被访问过的。
	}

	return -1;  //代表没有找到
}

Graph::~Graph()
{
	for (int i = 0; i < nVerts; i++)
		delete verteslist[i];

}

#endif