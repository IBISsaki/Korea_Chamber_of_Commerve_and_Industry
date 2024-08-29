#ifndef SAFEARRAY_H
#define SAFEARRAY_H

class SafeArray {
// friend ;
private:
    static const int ARRAYSIZE;

    int *pArr_;
    int size_;

public:
    explicit SafeArray(int size = ARRAYSIZE);
    SafeArray(const int *pArr, int size);
    SafeArray(const SafeArray& rhs);
    ~SafeArray();

    SafeArray& operator = (const SafeArray& rhs);

    bool operator == (const SafeArray& rhs) const;

    int& operator [] (int index);
    const int& operator[] (int index) const;

    int size() const;
};


#endif