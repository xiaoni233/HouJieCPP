#include<iostream>
#include<stdlib.h>
using namespace std;


class Foo
{
private:
	int id;//4���ֽ� ,8(��ָ��)+4(int)+4(�ڴ����) =16
	//char c;//�����Ժ�Foo�໹��16�ֽڣ�4+4+8=16 
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
		
		virtual void fun2(){}//��ָ�룬64λ��λ��ͷ��8���ֽ� 
	
};

/*output
sizeof(Foo)16
sizeof pointer:8
operator new
ctor
dtor
operator delete

new�ȵ��� operator new,��ת�ͣ��ٵ��ù��캯�� 
*/
int main()
{
	cout<<"sizeof(Foo)"<<sizeof(Foo)<<endl;
	
	cout<<"sizeof pointer:"<<sizeof(int*)<<endl;
	Foo* p=new Foo();
	delete p;
}

