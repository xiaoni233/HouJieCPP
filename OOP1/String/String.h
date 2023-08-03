#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:
	//构造函数
	String(const char* cstr=0);
	//拷贝构造 
	String(const String& str);
	//拷贝赋值 
	String& operator=(const String& str);
	~String();
	//常量成员函数，供常量对象还有一般对象使用 
	char* get_c_str()const{return m_data;}
private:
	char* m_data;
};

#include<cstring>
inline
String::String(const char* cstr) 
{
	if(cstr){
		m_data=new char[strlen(cstr)+1];
		strcpy(m_data,cstr);
	}
	//没有传入默认值为0 
    else{
	   m_data=new char[1];
	   //"\0"是字符串终结符 
	   *m_data='\0';
	}
} 


inline
String::~String()
{
	delete[] m_data;
}

inline
String& String::operator=(const String& str)
{
	//防止重复析构 
	if(this==&str)
	return *this;
	
	//删除原有空间，进行深拷贝 
	delete[] m_data;
	m_data=new char[strlen(str.m_data)+1];
	strcpy(m_data,str.m_data);
	return *this;
}

inline
String::String(const String& str)
{
   m_data = new char[ strlen(str.m_data) + 1 ];
   strcpy(m_data, str.m_data);
}

#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const String& str)
{
   os << str.get_c_str();
   return os;
}

#endif

