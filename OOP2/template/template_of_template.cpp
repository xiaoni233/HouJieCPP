#include<iostream>
#include <deque>


namespace template_of_template {
	
/*
Container = std::vectorģ��Ĭ��ֵ 
�ڶ�����������Ϊģ���ģ���������ʾ�������һ����������������ָ�������������ģ�������) 
template<typename T,
         template<typename> class Container = std::vector>
         
std::deque��ģ����stl���еĶ������������Ͳ�����
��һ��������Ԫ�����ͣ��ڶ��������Ƿ�����allocator�����͡�
��Ȼstd::deque�ĵڶ������Ͳ�����Ĭ��ֵ��
���ǵ�������ʹ��std::deque�滻Containerʱȴ���ϸ�ƥ�������Ĭ��ֵ��������

*/ 
template<class T1,
         template<class Elem, class Allocator = std::allocator<Elem> > class Container = std::deque>
struct Stack
{
   

private:
    Container<T1> elems;//t1��Ӧ��һ������t1 
};
void  test()
{
 Stack<int, std::deque> intStack;
 
}

}



