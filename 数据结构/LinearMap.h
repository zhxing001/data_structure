#pragma once
#ifndef LINEARMAP_H
#define LINEARMAP_H
#include <vector>

template<class Key,class Value>
class LinearMap   //线性映射，没什么用，为了学习
{
public:
	LinearMap(int size = 101) :arr(size)   //这里的size是容量,arr(size)是调用了vector的构造函数，创建这么大的数组。
	{
		currentsize = 0;      //实际的数据多少
	}
	void Put(const Key&k, const Value &v)
	{
		arr[currentsize] = DataEntry(k, v);
		currentsize++;
	}
	Value Get(const Key&k)
	{
		for (size_t i = 0; i < currentsize; i++)
		{
			if (arr[i].key == k)         //因为这是一个普通的数组，就只能遍历查找
				return arr[i].value;
		}
		return Value();
	}
private:
	struct DataEntry
	{
		Key key;
		Value value;
		DataEntry(const Key&k=Key(),const Value &v=Value()):key(k),value(v){}
	};

	std::vector<DataEntry>  arr;  //利用vector创建的动态数组
	int currentsize;   //数组里的数据多少 


};

#endif