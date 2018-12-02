#include <boost/shared_array.hpp> 
#include <iostream>

using namespace std;

void release_shared_array(const int* a)
{
	delete[] a;
}

struct release_shared_array1
{
	void operator ()(const int* a)
	{
		delete[] a;
	}
};

//shared_ptr�ڲ�Ĭ��ʹ��delete������Ĭ���޷��������飬shared_array�ڲ�ʹ��delete[]����
int main() 
{ 
	boost::shared_array<int> i1(new int[2]); 
	boost::shared_array<int> i2(i1); 
	i1[0] = 1; 
	cout << i2[0] << endl;

	//Ҳ����ʹ��shared_ptr���Զ����ͷź�������������
	boost::shared_ptr<int> i3(new int [2], release_shared_array);//����ָ����ʽ
	boost::shared_ptr<int> i4(new int [2], release_shared_array1());//����������ʽ

	return 0;
} 