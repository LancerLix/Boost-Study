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

//与scoped_ptr不同在于shared_ptr不会独占对象，多个shared_ptr可以共享一个对象，内部维护引用计数，当没有任何一个shared_ptr占有对象时，才调用delete析构对象
int main() 
{
	//stl的容器内部都是以copy out、copy in的实现，传统的std::auto_ptr无法存储在std的容器，因为std::atuo_ptr在copy时会转移所有权，使copy in时的原有auto_ptr失效
	//同样对于独占对象的scoped_ptr也不行
	vector<boost::shared_ptr<int> > v;
	v.push_back(boost::shared_ptr<int>(new int(1))); 
	v.push_back(boost::shared_ptr<int>(new int(2)));

	boost::shared_ptr<int> i1(new int(1)); 
	boost::shared_ptr<int> i2(i1); 
	i1.reset(new int(2));
	cout << i1.use_count() << endl;//获取i1引用计数

	*i1 = 2;
	*i2.get() = 3;//i1调用了reset,但是i2指向的对象并没有销毁
	cout << i2.use_count() << endl;//获取i2引用计数

	boost::shared_ptr<int> i3(new test); 
	i3->a = 4;

	//自定义释放函数
	boost::shared_ptr<test> i4(new int, release_shared_ptr);//函数指针形式
	boost::shared_ptr<test> i5(new int, release_shared_ptr1());//函数对象形式
	boost::shared_ptr<test> i6(new int, [] (const int* a){delete a});//lambda函数形式

	int* b = new int(5);
	boost::shared_ptr<int> k(b);
	boost::shared_ptr<int> l(b);//error 对同一个指针使用多次shared_ptr会导致析构多次，引起内存边界问题，一般使用boost::shared_ptr<test> l(k)形式不会出现问题

	return 0;
} 