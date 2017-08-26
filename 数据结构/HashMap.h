

#ifndef HASHMAP_H
#define HASHRMAP_H
#include <vector>

template<class Key, class Value>
class HashMap   //��ϣӳ��
{
public:
	HashMap(int size = 101) :arr(size)   //�����size������,arr(size)�ǵ�����vector�Ĺ��캯����������ô������顣
	{
		currentsize = 0;      //ʵ�ʵ����ݶ���
	}
	void Put(const Key&k, const Value &v)
	{
		int myhash = myHash(k);
		arr[myhash] = DataEntry(k,v);  //����һ��Ҫ�ǵð��������Ž�ȥ
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
	unsigned  hash(const Key &k)  const      //��ϣ����
	{
		unsigned int hashValue = 0;
		//const char *keyp =reinterpret_cast<const char *>(&k);  //ת�ͳ��ַ�
		//for (size_t i = 1; i < sizeof(Key); i++)  //������28����
		//{
		//	std::cout << keyp[i];      //�����ã����������������
		//	hashValue = 37*hashValue + keyp[i];            //�����е��ַ���ascii���������

		//}
		//��Ƶ������ôд�ģ�������д����ÿ�εõ��Ĺ�ϣ������һ�������Ը��������á��ҿ������
		//��Ƶ����ôд��ԭ�򣬾����������������Ҿ�ת����char*��ָ�룬Ȼ��ȥ������ת����ascii�룬����˵
		//�õ��Ĺ�ϣֵ��һ���ģ�ʵ�����Ұ�key[i]����������£�����ܶ࣬����ÿ�����붼��һ������ʹ��
		//ͬһ�����в�ͬ�ε��õõ���Ҳ�����ã��Ҿ�����Ҫԭ������������ط���һ��ǿ������ת����һ��sizeof��

		//�������ַ����������д�ġ�ѧϰѧϰ��
		//���˵��c++11��������ԣ����Ժܷ���ı���Ԫ�ء���Ҫ̫���㡣�����Ͷ��ˡ�

		for (auto i : k)
		{
			hashValue = 37 * hashValue + i;    //��ÿ��Ԫ�ص�asci�������������ÿ�γ���37�����˵İɣ�

		}
		return hashValue;
	}
		int myHash(const Key&k) const         //̫���ˣ���ת��СһЩ��
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
			DataEntry(const Key&k = Key(), const Value &v = Value()) :key(k), value(v) {}  //���캯��
		};

		std::vector<DataEntry>  arr;  //����vector�����Ķ�̬����
		int currentsize;   //����������ݶ��� 

	
};

#endif