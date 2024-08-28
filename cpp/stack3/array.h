#ifndef ARRAY_H
#define ARRAY_H


class Array {
// friend ;
private:
    static const int ARRAYSIZE;

    int *pArr_;
    int size_;

public:
    explicit Array(int size = ARRAYSIZE);
    Array(const int *pArr, int size);
    Array(const Array& rhs);
    ~Array();

    Array& operator = (const Array& rhs);

    bool operator == (const Array& rhs) const;

    int& operator [] (int index);

    const int& operator [] (int index) const;

    int size() const;
};

#endif