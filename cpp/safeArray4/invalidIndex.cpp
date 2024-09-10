#include "invalidIndex.h"

InvalidIndex::InvalidIndex(int index)
: index_(index)
{

}    

int InvalidIndex::getIndex() const
//:
{
    return index_;
}