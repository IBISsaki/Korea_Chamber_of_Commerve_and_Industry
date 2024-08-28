#ifndef ENPLOYEE_H
#define ENPLOYEE_H
#include <iostream>
#include "string.h"

class Employee {
friend std::ostream& operator << (std::ostream& out, const Employee& rhs);

private:
    int id_;
    String name_;
    const Employee *pManager_;

    Employee(const Employee& rhs);                  // 사용안함
    Employee& operator = (const Employee& rhs);     // 사용안함

public:
    Employee(int id, String name, const Employee *p);
    //~Employee() {}

    // Employee* operator&() { return this; }
    // const Employee* operator&() { return this; }

    int getId() const;
    String getName() const;
    const Employee *getPManager() const;
};



#endif