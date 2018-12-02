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

//shared_ptr内部默认使用delete析构，默认无法析构数组，shared_array内部使用delete[]析构
int main() 
{ 
	boost::shared_array<int> i1(new int[2]); 
	boost::shared_array<int> i2(i1); 
	i1[0] = 1; 
	cout << i2[0] << endl;

	//也可以使用shared_ptr的自定义释放函数来析构数组
	boost::shared_ptr<int> i3(new int [2], release_shared_array);//函数指针形式
	boost::shared_ptr<int> i4(new int [2], release_shared_array1());//函数对象形式

	return 0;
} 