#include <boost/scoped_array.hpp> 

//scoped_ptr�ڲ�ʹ��delete�������޷��������飬scoped_array�ڲ�ʹ��delete[]����
int main() 
{ 
	boost::scoped_array<int> i(new int[2]); 
	*i.get() = 1; 
	i[1] = 2; 
	i.reset(new int[3]);

	return 0;
} 