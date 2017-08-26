#pragma once
#ifndef LINEARMAP_H
#define LINEARMAP_H
#include <vector>

template<class Key,class Value>
class LinearMap   //����ӳ�䣬ûʲô�ã�Ϊ��ѧϰ
{
public:
	LinearMap(int size = 101) :arr(size)   //�����size������,arr(size)�ǵ�����vector�Ĺ��캯����������ô������顣
	{
		currentsize = 0;      //ʵ�ʵ����ݶ���
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
			if (arr[i].key == k)         //��Ϊ����һ����ͨ�����飬��ֻ�ܱ�������
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

	std::vector<DataEntry>  arr;  //����vector�����Ķ�̬����
	int currentsize;   //����������ݶ��� 


};

#endif