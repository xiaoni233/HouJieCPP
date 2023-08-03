#include<iostream>
using namespace std;

namespace functionTemplate{
	
class stone
{
	public:
		stone(int w,int h,int we):_w(w),_h(h),_weight(we){
		}
		stone(){
		}
		bool operator< (const stone& rhs)const
		{
			return _weight<rhs._weight;
		}
		int get_w()const{return _w;
		}
		int get_h()const{return _h;
		}
		int get_weight()const{return _weight;
			
		}
	private:
		int _w,_h,_weight;
};

template<class T>
inline
const T& min(const T& a,const T& b)
{
	return b<a?b:a;
}

ostream&
operator << (ostream& os, const stone& x)
{
  return os << '(' <<  x.get_w() << ',' <<  x.get_h()<<','<<x.get_weight() << ')';
}

void  test()
{
 stone r1(2,3,1),r2(3,3,3),r3;
 r3=min(r1,r2);
 cout<<r3;
 
}

}



