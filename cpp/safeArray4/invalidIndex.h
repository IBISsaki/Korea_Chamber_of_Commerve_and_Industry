#ifndef INVALIDINDEX_H
#define INVALIDINDEX_H

class InvalidIndex
{
private:
    int index_;

public:
    InvalidIndex(int index);

    int getIndex() const;
};

#endif