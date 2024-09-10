#include <cassert>
#include <cstring>
#include "stringRep.h"

StringRep::StringRep()
: str_(new char[1]), len_(0)
{
    assert(str_ );
    str_[0] = '\0';
}

StringRep::StringRep(const char *s)
: str_(new char[strlen(s) + 1]), len_ (strlen(s))
{
    assert(str_ );
    strcpy(str_, s);
}

StringRep::StringRep(const StringRep& rhs)
: str_(new char[rhs.len_ + 1]), len_(rhs.len_)
{
    assert(str_ );
    strcpy(str_, rhs.str_);
}

StringRep::~StringRep()
{
    delete [] str_;
}