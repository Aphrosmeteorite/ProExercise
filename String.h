//String.h
/*
    将String类写入stu的命名空间
*/

#ifndef STRINGCLASS_STRING_H
#define STRINGCLASS_STRING_H
#include <iostream>
namespace stu
{
    class String
    {
    private:

        unsigned long long m_len{0};
        char *StringPtr;

    public:
        unsigned long long Getlen() const;
        friend String StrCpy(String &dest,const String &source);
        friend int StrCmp(String &str1 , String &str2);
        friend String StrCat(String &dest ,const String &source);
        String(const char str[]);
        String();
        ~String();

    public:
        friend std::istream &operator>>(std::istream &in, String &Str);
        friend std::ostream &operator<<(std::ostream &out, String &Str);
        String &operator=(const String &NewStr);
        String operator+(const String &Other);
        String &operator+=(const String &Other);

    public:
        char operator[](int i) const;
        char &operator[](int i);
    };
}
#endif //STRINGCLASS_STRING_H
