#include<iostream>
#include<stdlib.h>
using namespace std;


class Foo
{
private:
	int id;//4个字节 ,8(虚指针)+4(int)+4(内存对齐) =16
	//char c;//加上以后，Foo类还是16字节，4+4+8=16 
public:
       
	   Foo()	{cout <<"ctor"<<endl;
	   }	
	   ~Foo(){cout<<"dtor"<<endl;
	   }
		static void* operator new(size_t size){
			Foo *p=(Foo*)malloc(size);
			cout<<"operator new"<<endl;
			return p;
		}
		static void operator delete(void* pdead,size_t size){
			cout<<"operator delete"<<endl;
			free(pdead);
		}
		
		virtual void fun2(){}//虚指针，64位，位于头部8个字节 
	
};

/*output
sizeof(Foo)16
sizeof pointer:8
operator new
ctor
dtor
operator delete

new先调用 operator new,再转型，再调用构造函数 
*/
int main()
{
	cout<<"sizeof(Foo)"<<sizeof(Foo)<<endl;
	
	cout<<"sizeof pointer:"<<sizeof(int*)<<endl;
	Foo* p=new Foo();
	delete p;
}

