#include <boost/shared_ptr.hpp> 
#include <vector> 
#include <boost/ptr_container/ptr_vector.hpp> 

/*ָ�������Ǳ�ר����������̬�����ڴ�������������ptr_vector���ƵĻ���
  boost::ptr_deque�� boost::ptr_list�� boost::ptr_set�� boost::ptr_map�� boost::ptr_unordered_set �� boost::ptr_unordered_map���÷���std�������÷�һ��*/
int main() 
{
	/*ʹ�ñ�׼std�����洢shared_ptr�����2�����⣺
	  1.��Ҫ����ķ���shared_ptr����
	  2.std�����ڲ�Ƶ����copy in��copy out���Ӽ������ü�����Ч�ʲ��� */
	std::vector<boost::shared_ptr<int> > v; 
	v.push_back(boost::shared_ptr<int>(new int(1))); 
	v.push_back(boost::shared_ptr<int>(new int(2)));

	//ptr_vector��ռ������������Ȩ������ָ������һ���������shared_ptr���෴��
	boost::ptr_vector<int> v; 
	v.push_back(new int(1)); 
	v.push_back(new int(2));

	return 0;
} 