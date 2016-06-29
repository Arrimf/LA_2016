#include <string>
#include "myString.h"
#include <iostream>

using namespace std;
#define _CRT_SECURE_NO_WARNINGS

// Определение конструктора.
//MyString::MyString(){
//	m_pStr = nullptr;
//}
MyString::MyString(const char* str){
	if (str) {
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	else { m_pStr = nullptr; }
}
MyString::MyString(char*&& str) {
	if (str) {
		m_pStr = const_cast<char*> (str);
		str = nullptr;
	}
	else { m_pStr = nullptr; }
}
MyString::MyString(const MyString & str) {
	if (str.m_pStr) {
		m_pStr = new char[strlen(str.m_pStr) + 1];
		strcpy(m_pStr, str.m_pStr);
	}
	else { m_pStr = nullptr; }
}
MyString::MyString(MyString&& str) {
	if (str.m_pStr) {
		m_pStr = str.m_pStr;
		str.m_pStr = nullptr;
	}
	else { m_pStr = nullptr; }
}

// Определение деструктора.
MyString::~MyString() {
	delete m_pStr;
}

//////////////////////////////////////
const char* MyString::GetString () const{
	if (this) {
		return m_pStr;
	}
	else { return nullptr; }
}
const char* MyString::GetString(){
	if (this) {
		return m_pStr;
	}
	else { return nullptr; }
}

void MyString::SetNewString(const char* str) {
	delete[] m_pStr;
	if (str) {
		m_pStr = new char[strlen(str) + 1];
		strcpy_s(m_pStr, strlen(str) + 1, str);
	}
	else { m_pStr = nullptr; }
}

void MyString::AddString(const char* str) {
	if (str) {
	char*tmp = new char[strlen(m_pStr) + strlen(str)+1];
	strcpy(tmp, m_pStr);
	strcat(tmp,str);
	delete[] m_pStr;
	m_pStr = tmp;
	}
	//else { m_pStr = nullptr; }
}
void MyString::Swap(MyString& other){
	char*tmp = m_pStr;
	m_pStr = other.m_pStr;
	other.m_pStr = tmp;
}

char* MyString::operator= (const char* str){
	if(str){
		//SetNewString(str);
		delete[] m_pStr;
		m_pStr = new char [strlen(str) + 1];
		strcpy(m_pStr,str);
	}
	else { m_pStr = nullptr; }
	return m_pStr;
}
MyString& MyString::operator= (const MyString& other){
	if (m_pStr != other.m_pStr){
		if(other.m_pStr){
			delete[] m_pStr;
			m_pStr = new char[strlen(other.m_pStr) + 1];
			strcpy(m_pStr, other.m_pStr);
		}
		else { m_pStr = nullptr; }
	}
	return *this;
}
MyString& MyString::operator= (MyString&& other){
	if (m_pStr != other.m_pStr){
		this->Swap(other);
		return *this;
	}
}

MyString& MyString::operator=(char*&& str){
	if (str) {
		m_pStr = const_cast<char*> (str);
		str = nullptr;
	}
	else { m_pStr = nullptr; }
	return *this;
}

MyString concat(const char*s1, ...) {
	const char** str_mas = &s1;
	int len = 0;  
	while (*str_mas) {
		len += strlen(*str_mas++);
	}
	char*tmp = new char[len + 1];
	tmp[0] = '\0';
	str_mas = &s1;
	while (*str_mas) {
		strcat(tmp, *str_mas++);
	}
	return MyString(std::move(tmp));
}
//ostream& MyString::operator<< (ostream& os) {
//	os << m_pStr;
//	return os;
//}

ostream& operator<< (ostream& os, const MyString& mStr) {
	if (mStr.GetString()) {
		os << mStr.GetString();
	}
	return os;
}
std::ostream & operator<<(std::ostream& os, const MyString* pStr){
	return os << *pStr;
}
MyString& MyString::operator+= (const MyString& other) {
	this->AddString(other.m_pStr);
	return *this;
}

MyString MyString::operator+ (const MyString& other)const {
	return concat(this->m_pStr , other.m_pStr,0);
}

bool MyString::operator<(const MyString& other) const
{
	return strcmp(m_pStr,other.m_pStr) < 0;
}

//MyString MyString::operator+ (const MyString& other)const {
//	MyString tmp(*this);
//	  tmp.AddString(other.m_pStr);
//	  return tmp;
//}
