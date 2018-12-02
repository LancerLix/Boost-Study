#include <boost/shared_ptr.hpp> 
#include <boost/weak_ptr.hpp> 
#include <iostream> 
#include <pthread.h>

using namespace std;

void* reset(void* arg) 
{ 
	boost::shared_ptr<int> *sh = static_cast<boost::shared_ptr<int>*>(arg); 
	sh->reset(); //销毁shared_ptr对应的对象
	return 0; 
} 

void* print(void* arg) 
{ 
	boost::weak_ptr<int> *w = static_cast<boost::weak_ptr<int>*>(arg); 
	boost::shared_ptr<int> sh = w->lock();//如果对象已经析构，weak_ptr的lock返回0，否则返回与构造weak_ptr时的shared_ptr共享对象所有权的shared_ptr
	if (sh) //检查shared_ptr所对应的对象是否合法
		cout << *sh << endl; 
	return 0; 
} 

//weak_ptr一般使用在对应对象的生存周期不依赖于调用函数本身的情况
int main() 
{ 
	boost::shared_ptr<int> sh(new int(99));
	boost::weak_ptr<int> w(sh);
	pthread_t threads[2]; 
	pthread_create(&threads[0], NULL/* pthread_attr_t* */, reset, &sh); 
	pthread_create(&threads[1], NULL/* pthread_attr_t* */, print, &w);

	return 0;
}