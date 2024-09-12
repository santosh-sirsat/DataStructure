#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<utility>
#include<string>
using namespace std;

class String
{
private:
	int m_length;
	char* m_data;

public:
	String()
	{
		m_length = 0;
		m_data = nullptr;
	}

	String(const char* str)
	{
		m_length = strlen(str) + 1;
		m_data = new char[m_length];
		strcpy(m_data, str);
	}

	String(const String& str)
	{
		if (this == &str)
			return ;

		m_length = str.m_length;
		m_data = new char[m_length];
		strcpy(m_data, str.m_data);
	}

	String operator=(const String& str)
	{
		if (this == &str)
		{
			return (*this);
		}

		m_length = str.m_length;

		delete[] m_data;
		m_data = new char[m_length];
		strcpy(m_data, str.m_data);

		return (*this);
	}
	String(String&& str) noexcept
	{
		if (&str == this)
		{
			return ;
		}
		//take owner ship
		m_length = str.m_length;
		delete[] m_data;

		m_data = str.m_data;

		//take owner ship
		str.m_length = 0;
		str.m_data = nullptr;
	}
	String operator=(String&& str) noexcept
	{
		if (this == &str)
		{
			return (*this);
		}
		m_length = str.m_length;
		delete[] m_data;

		m_data = str.m_data;

		str.m_length = 0;
		str.m_data = nullptr;

		return (*this);
	}

	~String()
	{
		if (m_data)
		{
			delete[] m_data;
		}
	}

};

//int main()
//{
//	String st1;//default constructor will called
//	String st2("st2");//single parameterised constructor will called.
//	String *st3 = new String("santosh"); // sigle parameterised ctor will cal`l
//	String st4 = st2;//default copy ctor will called.
//	String st5; // parameterless ctor will be called
//	st5 = st4; // assigment operator will called
//
//	String st6 = std::move(st5); // copy move constructor will be called.
//	String st7;
//	st7 = std::move(st6);// move assigment operator will be called here.
//
//	return 0;
//}