#include <boost/shared_ptr.hpp> 
#include <vector> 
#include <boost/ptr_container/ptr_vector.hpp> 

/*指针容器是被专门用来管理动态分配内存对象的容器，与ptr_vector类似的还有
  boost::ptr_deque， boost::ptr_list， boost::ptr_set， boost::ptr_map， boost::ptr_unordered_set 和 boost::ptr_unordered_map，用法与std的容器用法一致*/
int main() 
{
	/*使用标准std容器存储shared_ptr会存在2个问题：
	  1.需要额外的分配shared_ptr对象；
	  2.std容器内部频繁的copy in、copy out增加减少引用计数，效率不高 */
	std::vector<boost::shared_ptr<int> > v; 
	v.push_back(boost::shared_ptr<int>(new int(1))); 
	v.push_back(boost::shared_ptr<int>(new int(2)));

	//ptr_vector独占分配对象的所有权，其他指针容器一样，这点与shared_ptr是相反的
	boost::ptr_vector<int> v; 
	v.push_back(new int(1)); 
	v.push_back(new int(2));

	return 0;
} 