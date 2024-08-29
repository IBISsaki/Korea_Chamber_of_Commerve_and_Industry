#include <cassert>
#include "safeArray.h"

// const int SafeArray::ARRAYSIZE = 100;

SafeArray::SafeArray(int size)
: Array(size)
// : pArr_(new int[size]), size_(size)
{
    // assert(pArr_ );
}

SafeArray::SafeArray(const int *pArr, int size)
: Array(pArr, size)
// : pArr_(new int[size]), size_(size)
{
    // assert(pArr_ );

    // for(int i = 0; i < size; ++i) {
    //     pArr_[i] = pArr[i];
    // }
}

SafeArray::SafeArray(const SafeArray& rhs)
: Array( (Array)rhs )       // slicing
// : pArr_(new int[rhs.size_]), size_(rhs.size_)
{
    // assert(pArr_ );

    // for(int i = 0; i < rhs.size_; ++i) {
    //     pArr_[i] = rhs.pArr_[i];
    // }
}

SafeArray::~SafeArray()
{
    // Array::~Array() 자동 호출
    // delete [] pArr_;
}

SafeArray& SafeArray::operator = (const SafeArray& rhs)
{
    // if(this != &rhs) {
    //     delete [] pArr_;
    //     pArr_ = new int[rhs.size_];
    //     assert(pArr_ );
    //     size_ = rhs.size_;

    //     for(int i = 0; i < rhs.size_; ++i) {
    //         pArr_[i] = rhs.pArr_[i];
    //     }
    // }
    this -> Array::operator = ( (Array)rhs );

    return *this;
}

bool SafeArray::operator == (const SafeArray& rhs) const
{
    // if(size_ != rhs.size_) {
    //     return false;
    // }

    // int i;
    // for(i = 0; i < rhs.size_; ++i) {
    //     if(pArr_[i] != rhs.pArr_[i]) {
    //         break;
    //     }
    // }

    // return (i == rhs.size_);
    return this -> Array::operator == ( (Array)rhs );
}

int& SafeArray::operator [] (int index)
{
    assert(index >= 0 && index < this -> Array::size());
    
    return this -> Array::operator[](index);
    // return pArr_[index];
}

const int& SafeArray::operator[] (int index) const
{
    assert(index >= 0 && index < this -> Array::size());

    return this -> Array::operator[](index);
    // return pArr_[index];
}

// int SafeArray::size() const
// {
//     return size_;
// }