#include <cassert>
#include <cstring>
#include "string.h"

std::ostream& operator << (std::ostream& out, const String& rhs)
{
    return out << rhs.str_;
}

String::String()
: str_(new char[1]), len_(0)
{
    assert(str_ );
    str_[0] = '\0';
}

String::String(const char *s)
: str_(new char[strlen(s) + 1]), len_ (strlen(s))
{
    assert(str_ );
    strcpy(str_, s);
}

String::~String()
{
    delete [] str_;
}

String::String(const String& rhs)
: str_(new char[rhs.len_ + 1]), len_(rhs.len_)
{
    assert(str_ );
    strcpy(str_, rhs.str_);
}

String& String::operator = (const String& rhs) 
{
    if(this != &rhs) {      // self assignment test! ex) s1 = s1; 자기 자신을 치환하려 할때 원본이 지워지는걸 막기 위함
        delete [] str_; 
        str_ = new char[rhs.len_ + 1];
        assert(str_);
        strcpy(str_, rhs.str_);
        len_ = rhs.len_;
    }
    return *this;
}

bool String::operator == (const String& rhs) const
{
    return strcmp(str_, rhs.str_) == 0;
}

const String String::operator + (const String& rhs) const
{
    // char buf[len_ + rhs.len_ + 1];
    char *buf = new char[len_ + rhs.len_ + 1];
    strcpy(buf, str_);
    strcat(buf, rhs.str_);

    String result(buf);
    delete [] buf;

    return result;
}

const char *String::c_str() const
{
    return str_;
}

int String::length() const
{
    return len_;
}