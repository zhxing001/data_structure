
//
//һЩͨ�õĹ��ߺ���

#ifndef _MYUTIL_H
#define  _MYUTIL_H

int min(int a, int b)
{
	if (a < b)
		return a;
	else return b;
}

template<class T>
void ChangeSize1D(T * &a, const int oldSize, const int newSize)
{
	if (newSize < 0)  throw "new length must be >=0";
	T *temp = new T[newSize];
	int number=min(oldSize,newSize);    //��ô����
	std::copy(a, a + number, temp);        //������ȥ
	delete[] a;
	a = temp;   //ָ��ָ���½������
}

#endif
