#ifndef __MYSTRING__
#define __MYSTRING__

class String
{
public:
	//���캯��
	String(const char* cstr=0);
	//�������� 
	String(const String& str);
	//������ֵ 
	String& operator=(const String& str);
	~String();
	//������Ա������������������һ�����ʹ�� 
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
	//û�д���Ĭ��ֵΪ0 
    else{
	   m_data=new char[1];
	   //"\0"���ַ����ս�� 
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
	//��ֹ�ظ����� 
	if(this==&str)
	return *this;
	
	//ɾ��ԭ�пռ䣬������� 
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

