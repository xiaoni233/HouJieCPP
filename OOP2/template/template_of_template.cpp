#include<iostream>
#include <deque>


namespace template_of_template {
	
/*
Container = std::vector模板默认值 
第二个参数声明为模板的模板参数，表示填入的是一个容器（或者智能指针或者其他带有模板的容器) 
template<typename T,
         template<typename> class Container = std::vector>
         
std::deque类模板在stl库中的定义有两个类型参数，
第一个参数是元素类型，第二个参数是分配器allocator的类型。
虽然std::deque的第二个类型参数有默认值，
但是当编译器使用std::deque替换Container时却会严格匹配参数，默认值被忽略了

*/ 
template<class T1,
         template<class Elem, class Allocator = std::allocator<Elem> > class Container = std::deque>
struct Stack
{
   

private:
    Container<T1> elems;//t1对应第一个参数t1 
};
void  test()
{
 Stack<int, std::deque> intStack;
 
}

}



