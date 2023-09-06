//String.cpp

#include "String.h"
#include <bits/stdc++.h>
#define MIN(X,Y) (X >= Y? Y:X)

using namespace stu;
String::String()
    :StringPtr{nullptr}
{}

unsigned long long String::Getlen() const
{
    return this->m_len;
}

namespace stu
{
String StrCpy(String &dest, const String &source)
    {
        char *temp = source.StringPtr;
        delete[] dest.StringPtr;
        dest.m_len=source.m_len;
        dest.StringPtr = new char[dest.m_len+1];
        memset(dest.StringPtr,0,dest.m_len+1); //初始化为0
        for(int i=0;i<dest.m_len+1;i++)
        {
            dest.StringPtr[i] = *(temp++);
        }
        return dest;
    }

    int StrCmp(String &str1 , String &str2)
    {
            char *s1=str1.StringPtr;
            char *s2=str2.StringPtr;
            for(int i=0 ; i < MIN(str1.m_len,str2.m_len)+1 ;++i)
            {
                if(*(s1) > *(s2)) return 1;
                else if(*(s1) < *(s2)) return -1;
                if((i == MIN(str1.m_len,str2.m_len))&&(str1.m_len == str2.m_len)) return 0;
                s1++;s2++;
            }
    }

    String StrCat(String &dest ,const String &source)
    {
    /*
     dest需要被拓宽，所以需要重新为dest分配内存
     由于不应该直接操作dest.StringPtr和source.StringPtr，需要保存原dest同时还需要两个指针去指向dest和source
     */
        String StrAdd;
        StrAdd.m_len = dest.m_len + source.m_len;
        StrAdd.StringPtr = new char[StrAdd.m_len+1];
        char *CopyAdd = StrAdd.StringPtr;
        char *CopyDes = dest.StringPtr;
        char *CopySou = source.StringPtr;
        memset(StrAdd.StringPtr,0,StrAdd.m_len+1);
        for(int i=0; i < StrAdd.m_len ;i++)
        {
            if(i < dest.m_len)
            *(CopyAdd++) = *(CopyDes++);
            else
            {
                *(CopyAdd++) = *(CopySou++);
            }
        }
        StrAdd.StringPtr[StrAdd.m_len+1] = '\0';
        delete[] dest.StringPtr;
        dest.m_len = StrAdd.m_len;
        dest.StringPtr = new char[dest.m_len+1];
        memset(dest.StringPtr,0,dest.m_len+1);
        StrCpy(dest,StrAdd);
        return dest;
    }

}

String &String::operator=(const String& NewStr)
{
    if(this != &NewStr)
    {
        delete[] this->StringPtr;
        if(!NewStr.StringPtr)
        {
            this->StringPtr = nullptr;
        }
        else
        {
            this->m_len = strlen(NewStr.StringPtr);
            this->StringPtr = new char[this->m_len+1];
            stu::StrCpy(*this, NewStr);
        }
    }
    return *this;
}
String String::operator+(const String& Other)
{
    String NewStr;
    NewStr.StringPtr = new char [Other.m_len+this->m_len+1];
    stu::StrCpy(NewStr,*this);
    stu::StrCat(NewStr,Other);
    return NewStr;
}

String &String::operator+=(const String& Other)
{
    if(this->m_len + Other.m_len > this->m_len)
    {
        String CopyStr;
        CopyStr.m_len = this->m_len;
        CopyStr.StringPtr = new char[this->m_len + 1];
        memset(CopyStr.StringPtr,0,CopyStr.m_len+1); //初始化为0
        StrCpy(CopyStr, *this); //备份原有字符串

        delete[] this->StringPtr;
        this->m_len = CopyStr.m_len + Other.m_len;            //拓宽字符串
        this->StringPtr = new char[this->m_len + 1];
        memset(this->StringPtr,0,this->m_len+1); //初始化为0
        StrCpy(*this,CopyStr);
    }
    StrCat(*this,Other);
    return *this;
}

namespace stu
{
    std::ostream &operator<<(std::ostream &out, String& Str)
    {
            out << Str.StringPtr;
            return out;
    }


    std::istream &operator>>(std::istream &in, String &Str)
    {
        if (Str.StringPtr != nullptr)
        {
            delete[] Str.StringPtr;
            Str.StringPtr = nullptr;
            Str.m_len = 0;
        }
        char copy[88] = {0};
         std::cin >> copy;
        Str.m_len = strlen(copy);
        Str.StringPtr = new char[strlen(copy) + 1];
        strcpy(Str.StringPtr, copy);
        return in;
   }
}

char String::operator[](int i) const
{
    return StringPtr[i];
}

char & String::operator[](int i)
{
    return StringPtr[i];
}

String::String(const char* str)
{
    this->m_len = strlen(str);
    this->StringPtr = new char[m_len+1];
    memset(this->StringPtr,0,this->m_len+1);
    for(int i=0;i< this->m_len+1;i++)
        this->StringPtr[i] = str[i];
}

String::~String()
{
    this->StringPtr = nullptr;
    delete[] this->StringPtr;
}

