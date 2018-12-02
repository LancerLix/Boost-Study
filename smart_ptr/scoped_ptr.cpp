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
	i.reset(new int);//���¶������³�ʼ��������ָ�룬���Զ�����delete�ͷ�ǰ��Ķ���

	boost::scoped_ptr<test> j(new test); 
	j->a = 3;

	int* b = new int(5);
	boost::scoped_ptr<int> k(b);
	boost::scoped_ptr<int> l(b);//error ��ͬһ��ָ��ʹ�ö��scoped_ptr�ᵼ��������Σ������ڴ�߽�����

	return 0;
} 