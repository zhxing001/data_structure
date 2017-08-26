

#ifndef HASHMAP_H
#define HASHRMAP_H
#include <vector>

template<class Key, class Value>
class HashMap   //哈希映射
{
public:
	HashMap(int size = 101) :arr(size)   //这里的size是容量,arr(size)是调用了vector的构造函数，创建这么大的数组。
	{
		currentsize = 0;      //实际的数据多少
	}
	void Put(const Key&k, const Value &v)
	{
		int myhash = myHash(k);
		arr[myhash] = DataEntry(k,v);  //这里一定要记得把两个都放进去
		currentsize++;
		
	}
	Value Get(const Key&k)
	{
		int myhash = myHash(k);
		if (arr[myhash].key == k)
			return arr[myhash].value;
		else
			return Value();
		
	}
	unsigned  hash(const Key &k)  const      //哈希函数
	{
		unsigned int hashValue = 0;
		//const char *keyp =reinterpret_cast<const char *>(&k);  //转型成字符
		//for (size_t i = 1; i < sizeof(Key); i++)  //这里又28个？
		//{
		//	std::cout << keyp[i];      //测试用，这里出来都是乱码
		//	hashValue = 37*hashValue + keyp[i];            //把所有的字符的ascii码加起来。

		//}
		//视频里是这么写的，我这样写下来每次得到的哈希数都不一定，所以根本不能用。我可以理解
		//视频里这么写的原因，就是任意类型来了我就转换成char*的指针，然后去遍历都转换成ascii码，按理说
		//得到的哈希值是一样的，实际上我把key[i]输出来看了下，乱码很多，而且每次乱码都不一样，即使是
		//同一次运行不同次调用得到的也不能用，我觉得主要原因就是着两个地方：一个强制类型转换，一个sizeof。

		//下面这种方法是是振哥写的。学习学习。
		//振哥说是c++11里的新特性，可以很方便的遍历元素。不要太方便。这样就对了。

		for (auto i : k)
		{
			hashValue = 37 * hashValue + i;    //把每个元素的asci码加上来。而且每次乘以37（随便乘的吧）

		}
		return hashValue;
	}
		int myHash(const Key&k) const         //太大了，再转换小一些。
		{
			unsigned hashValue = hash(k);
			hashValue %= arr.size();
			return hashValue;

		}
	private:
		struct DataEntry
		{
			Key key;
			Value value;
			DataEntry(const Key&k = Key(), const Value &v = Value()) :key(k), value(v) {}  //构造函数
		};

		std::vector<DataEntry>  arr;  //利用vector创建的动态数组
		int currentsize;   //数组里的数据多少 

	
};

#endif