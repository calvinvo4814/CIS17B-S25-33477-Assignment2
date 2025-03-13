#pragma once
#ifndef FACULTY_H
#define FACULTY_H

#include "User.h"

class Faculty : public User
{
public:
    //Public member for Faculty
    Faculty(string name);
    string getUserType() const override;
};

#endif 