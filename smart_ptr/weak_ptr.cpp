#include <boost/shared_ptr.hpp> 
#include <boost/weak_ptr.hpp> 
#include <iostream> 
#include <pthread.h>

using namespace std;

void* reset(void* arg) 
{ 
	boost::shared_ptr<int> *sh = static_cast<boost::shared_ptr<int>*>(arg); 
	sh->reset(); //����shared_ptr��Ӧ�Ķ���
	return 0; 
} 

void* print(void* arg) 
{ 
	boost::weak_ptr<int> *w = static_cast<boost::weak_ptr<int>*>(arg); 
	boost::shared_ptr<int> sh = w->lock();//��������Ѿ�������weak_ptr��lock����0�����򷵻��빹��weak_ptrʱ��shared_ptr�����������Ȩ��shared_ptr
	if (sh) //���shared_ptr����Ӧ�Ķ����Ƿ�Ϸ�
		cout << *sh << endl; 
	return 0; 
} 

//weak_ptrһ��ʹ���ڶ�Ӧ������������ڲ������ڵ��ú�����������
int main() 
{ 
	boost::shared_ptr<int> sh(new int(99));
	boost::weak_ptr<int> w(sh);
	pthread_t threads[2]; 
	pthread_create(&threads[0], NULL/* pthread_attr_t* */, reset, &sh); 
	pthread_create(&threads[1], NULL/* pthread_attr_t* */, print, &w);

	return 0;
}