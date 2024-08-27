#include <cassert>
#include <cstring>
#include "string.h"

String::String();
: str_ = (new char[1]), len_(0)
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

String::String& operator = (const String& rhs) {/* memberwise copy */ return *this }