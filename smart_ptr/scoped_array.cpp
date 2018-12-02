#include <boost/scoped_array.hpp> 

//scoped_ptr内部使用delete析构，无法析构数组，scoped_array内部使用delete[]析构
int main() 
{ 
	boost::scoped_array<int> i(new int[2]); 
	*i.get() = 1; 
	i[1] = 2; 
	i.reset(new int[3]);

	return 0;
} 