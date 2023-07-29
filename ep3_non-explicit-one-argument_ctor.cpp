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
		//�����ﲻ����ͨ�� 
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

	ostream& operator <<(ostream &os,const Fraction &x)//����Ӧ�ý�ostream������Ϊ���ô��ݸ�operator<<����������Ӧ��д��&os������os����������Ϊ�˱����ں����д���ostream����ĸ��������Ч�ʲ����ⲻ��Ҫ���ڴ濪�����������޸ĺ�Ĵ��룺
	{
		return os<<x.get_m_num()<<"/"<<x.get_m_den();
	}



int main()
{
	Fraction f(3,5);
	//4û�취��ʽת����Fration 
   //	Fraction d2=f+4;//	[Error] conversion from 'double' to non-scalar type 'Fraction' requested
     Fraction d2=f+Fraction(4); //����������ʽ���ù��캯�� 
     cout<<d2;
     system("pause");
	return 0;
}
