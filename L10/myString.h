#pragma once
#define _CRT_SECURE_NO_WARNINGS
//using namespace std;
#include <iostream>

class MyString
{
    char* m_pStr;	//строка-член класса
	//friend class BD;
public:
//MyString();

MyString(const char* str=nullptr);
MyString(char*&& str);
MyString(const MyString& n_str);
MyString(MyString&& n_str);
const char* GetString()const;
const char* GetString();
void SetNewString(const char* str);
void AddString(const char* str);
friend MyString concat(const char*, ...);// !! посл.аргумент - 0
void Swap(MyString&);


 char* operator= (const char*);
 MyString& operator= (const MyString&);
 MyString& operator= (MyString&&);
 MyString& operator= (char*&&);
 friend std::ostream& operator<< (std::ostream&, const MyString&);
 friend std::ostream& operator<< (std::ostream&, const MyString*);
 MyString& operator+= (const MyString&);
 MyString operator+ (const MyString&)const;
 bool operator<(const MyString&)const;
 inline const char* operator*(MyString&) { return m_pStr; }

~MyString();
};


