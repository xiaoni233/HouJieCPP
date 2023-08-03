#include<iostream>
using namespace std;



class Fraction
{
 public:
    explicit  Fraction(int num,int den=1):m_num(num), m_den(den){
	 }
	operator double() const{
	  return (double)(m_num/m_den);
	}
	Fraction operator+(const Fraction&f)
	{
		//我这里不进行通分 
		return Fraction(this->m_num*f.m_den+f.m_num*this->m_den,this->m_den*f.m_den);//1/2+3/4==1*4/2*4+3*2/4*2; 
	}
    int get_m_num ()const{
    	return m_num;
	}
	 int get_m_den ()const{
    	return m_den;
	}
  private:
	int m_num;
	int m_den;
};

	ostream& operator <<(ostream &os,const Fraction &x)//这里应该将ostream对象作为引用传递给operator<<函数，所以应该写成&os而不是os。这样做是为了避免在函数中创建ostream对象的副本，提高效率并避免不必要的内存开销。以下是修改后的代码：
	{
		return os<<x.get_m_num()<<"/"<<x.get_m_den();
	}



int main()
{
	Fraction f(3,5);
	//4没办法隐式转换成Fration 
   //	Fraction d2=f+4;//	[Error] conversion from 'double' to non-scalar type 'Fraction' requested
     Fraction d2=f+Fraction(4); //匿名对象，显式调用构造函数 
     cout<<d2;
     system("pause");
	return 0;
}
