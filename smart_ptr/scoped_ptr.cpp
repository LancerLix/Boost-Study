#include <boost/scoped_ptr.hpp> 

struct test
{
	int a;
};

int main() 
{ 
	boost::scoped_ptr<int> i(new int); 
	*i = 1; 
	*i.get() = 2;
	i.reset(new int);//用新对象重新初始化作用域指针，会自动调用delete释放前面的对象

	boost::scoped_ptr<test> j(new test); 
	j->a = 3;

	int* b = new int(5);
	boost::scoped_ptr<int> k(b);
	boost::scoped_ptr<int> l(b);//error 对同一个指针使用多次scoped_ptr会导致析构多次，引起内存边界问题

	return 0;
} 