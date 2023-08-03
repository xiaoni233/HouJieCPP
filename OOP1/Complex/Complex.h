#ifndef __MYComplex__
#define __MYComplex__
//防卫性声明 

class Complex;

Complex& 
__doapl(Complex* ths,const Complex& r);
Complex& 
__doami(Complex* ths,const Complex& r);
Complex& 
__doaml(Complex* ths,const Complex& r);

class Complex
{
public:
   Complex(double r=0,double i=0):re(r),im(i){ }	
   Complex& operator +=(const Complex&);
   Complex& operator -=(const Complex&);
   Complex& operator *=(const Complex&);
   Complex& operator /=(const Complex&);
   double real()const{return re;}
   double imag()const{return im;}
private:
	double re,im;
	friend	Complex& __doapl(Complex* ths,const Complex& r);
	friend  Complex& __doami(Complex* ths,const Complex& r);
	friend 	Complex& __doaml(Complex* ths,const Complex& r);
};

//同一类的各个对象互为友元 
inline Complex&
__doapl(Complex* ths,const Complex& r)
{
	ths->re+=r.re;
	ths->im+=r.im;
	return *ths;
}

inline Complex& 
__doami(Complex* ths,const Complex& r)
{
	ths->re -= r.re;
  	ths->im -= r.im;
  	return *ths;
} 

inline Complex& 
__doaml(Complex* ths,const Complex& r)
{
	double tmp=ths->re*r.re-ths->im*r.im;
 	ths->im = ths->re * r.im + ths->im * r.re;
 	ths->re = tmp;
  	return *ths;
}


inline Complex&
Complex::operator +=(const Complex& r)
{
	return __doapl(this,r);
}

inline Complex&
Complex::operator -= (const Complex& r)
{
  return __doami (this, r);
}

inline Complex&
Complex::operator *= (const Complex& r)
{
  return __doaml (this, r);
}

//对外的全局接口 
inline double
imag (const Complex& x)
{
  return x.imag ();
}


inline double
real (const Complex& x)
{
  return x.real ();
}

//全局的操作符重载 
inline Complex
operator + (const Complex& x, const Complex& y)
{
  //构造临时对象然后再返回，调用拷贝构造，调用行结束后销毁临时对象 
  return Complex (real (x) + real (y), imag (x) + imag (y));
}

inline Complex
operator + (const Complex& x, double y)
{
  return Complex (real (x) + y, imag (x));
}

inline Complex
operator + (double x, const Complex& y)
{
  return Complex (x + real (y), imag (y));
}

inline Complex
operator - (const Complex& x, const Complex& y)
{
  return Complex (real (x) - real (y), imag (x) - imag (y));
}

inline Complex
operator - (const Complex& x, double y)
{
  return Complex (real (x) - y, imag (x));
}

inline Complex
operator - (double x, const Complex& y)
{
  return Complex (x - real (y), - imag (y));
}

inline Complex
operator * (const Complex& x, const Complex& y)
{
  return Complex (real (x) * real (y) - imag (x) * imag (y),
			   real (x) * imag (y) + imag (x) * real (y));
}

inline Complex
operator * (const Complex& x, double y)
{
  return Complex (real (x) * y, imag (x) * y);
}

inline Complex
operator * (double x, const Complex& y)
{
  return Complex (x * real (y), x * imag (y));
}

Complex
operator / (const Complex& x, double y)
{
  return Complex (real (x) / y, imag (x) / y);
}

inline Complex
operator + (const Complex& x)
{
  return x;
}

inline Complex
operator - (const Complex& x)
{
  return Complex (-real (x), -imag (x));
}

inline bool
operator == (const Complex& x, const Complex& y)
{
  return real (x) == real (y) && imag (x) == imag (y);
}

inline bool
operator == (const Complex& x, double y)
{
  return real (x) == y && imag (x) == 0;
}

inline bool
operator == (double x, const Complex& y)
{
  return x == real (y) && imag (y) == 0;
}

inline bool
operator != (const Complex& x, const Complex& y)
{
  return real (x) != real (y) || imag (x) != imag (y);
}

inline bool
operator != (const Complex& x, double y)
{
  return real (x) != y || imag (x) != 0;
}

inline bool
operator != (double x, const Complex& y)
{
  return x != real (y) || imag (y) != 0;
}

#include <cmath>

inline Complex
polar (double r, double t)
{
  return Complex (r * cos (t), r * sin (t));
}

inline Complex
conj (const Complex& x) 
{
  return Complex (real (x), -imag (x));
}

inline double
norm (const Complex& x)
{
  return real (x) * real (x) + imag (x) * imag (x);
}

#endif   //__MYComplex__




