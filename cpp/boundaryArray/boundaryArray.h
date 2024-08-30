#ifndef BOUNDARYARRAY_H
#define BOUNDARYARRAY_H

#include "safeArray.h" // SafeArray 클래스가 정의된 헤더 파일 포함
#include "complex.h"   // Complex 클래스가 정의된 헤더 파일 포함

template <typename T>
class BoundaryArray : public SafeArray<T> {
private:
    int low_;  // 배열의 하한 경계

public:
    explicit BoundaryArray(int size = Array<T>::ARRAYSIZE);
    BoundaryArray(int low, int high);               // 하한과 상한을 받아 배열을 생성하는 생성자
    BoundaryArray(const T* pArr, int size, int low);

    bool operator == (const BoundaryArray<T>& rhs) const;

    T& operator [] (int index);
    const T& operator [] (int index) const;

    int lower() const;  // 배열의 하한을 반환하는 메서드
    int upper() const;  // 배열의 상한을 반환하는 메서드
};

// 구현부

// #include <cassert>

template <typename T>
BoundaryArray<T>::BoundaryArray(int size)
    : SafeArray<T>(size) // , low_(0)  // 기본 생성자: 하한을 0으로 설정
{
    low_ = 0;
}

template <typename T>
BoundaryArray<T>::BoundaryArray(int low, int high)
    : SafeArray<T>(high - low + 1) // , low_(low)
{
    low_ = low;
    // assert(low <= high);  // 경계 조건 확인
}

template <typename T>
BoundaryArray<T>::BoundaryArray(const T* pArr, int size, int low)
    : SafeArray<T>(pArr, size) // , low_(low)
{
    low_ = low;
    // assert(pArr != nullptr);  // 포인터가 nullptr이 아닌지 확인
}

template <typename T>
bool BoundaryArray<T>::operator == (const BoundaryArray<T>& rhs) const
{
    return this -> SafeArray<T>::operator == ( (SafeArray<T>)rhs );
}

template <typename T>
T& BoundaryArray<T>::operator [] (int index)
{
    return SafeArray<T>::operator [] (index - low_);
}

template <typename T>
const T& BoundaryArray<T>::operator [] (int index) const
{
    return SafeArray<T>::operator [] (index - low_);
}

template <typename T>
int BoundaryArray<T>::lower() const
{
    return low_;
}

template <typename T>
int BoundaryArray<T>::upper() const
{
    return low_ + this->Array<T>::size() - 1;
}

#endif // BOUNDARYARRAY_H
