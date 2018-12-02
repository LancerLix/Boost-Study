#include <boost/shared_ptr.hpp> 
#include <vector> 
#include <iostream> 

using namespace std;

struct test
{
	int a;
};

void release_shared_ptr(const int* a)
{
	delete a;
}

struct release_shared_ptr1
{
	void operator ()(const int* a)
	{
		delete a;
	}
};

//��scoped_ptr��ͬ����shared_ptr�����ռ���󣬶��shared_ptr���Թ���һ�������ڲ�ά�����ü�������û���κ�һ��shared_ptrռ�ж���ʱ���ŵ���delete��������
int main() 
{
	//stl�������ڲ�������copy out��copy in��ʵ�֣���ͳ��std::auto_ptr�޷��洢��std����������Ϊstd::atuo_ptr��copyʱ��ת������Ȩ��ʹcopy inʱ��ԭ��auto_ptrʧЧ
	//ͬ�����ڶ�ռ�����scoped_ptrҲ����
	vector<boost::shared_ptr<int> > v;
	v.push_back(boost::shared_ptr<int>(new int(1))); 
	v.push_back(boost::shared_ptr<int>(new int(2)));

	boost::shared_ptr<int> i1(new int(1)); 
	boost::shared_ptr<int> i2(i1); 
	i1.reset(new int(2));
	cout << i1.use_count() << endl;//��ȡi1���ü���

	*i1 = 2;
	*i2.get() = 3;//i1������reset,����i2ָ��Ķ���û������
	cout << i2.use_count() << endl;//��ȡi2���ü���

	boost::shared_ptr<int> i3(new test); 
	i3->a = 4;

	//�Զ����ͷź���
	boost::shared_ptr<test> i4(new int, release_shared_ptr);//����ָ����ʽ
	boost::shared_ptr<test> i5(new int, release_shared_ptr1());//����������ʽ
	boost::shared_ptr<test> i6(new int, [] (const int* a){delete a});//lambda������ʽ

	int* b = new int(5);
	boost::shared_ptr<int> k(b);
	boost::shared_ptr<int> l(b);//error ��ͬһ��ָ��ʹ�ö��shared_ptr�ᵼ��������Σ������ڴ�߽����⣬һ��ʹ��boost::shared_ptr<test> l(k)��ʽ�����������

	return 0;
} 