#include "employee.h"

std::ostream& operator << (std::ostream& out, const Employee& rhs)
{
    out << rhs.id_ << ", " << rhs.name_ << ", ";
    out << ((rhs.pManager_ ) ? rhs.pManager_ -> name_ : "-----");
    return out;
}

Employee::Employee(int id, String name, const Employee *p)
: id_(id), name_(name), pManager_(p)
{
    
}

int Employee::getId() const
{
    return id_;
}
String Employee::getName() const
{
    return name_;
}
const Employee* Employee::getPManager() const
{
    return pManager_;
}