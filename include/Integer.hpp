#pragma once

/* 
 * File:   Integer.hpp
 * Author: sbidny
 *
 * Created on January 27, 2011, 11:36 AM
 */

#if !defined(INTEGER_HPP)
#define	INTEGER_HPP

#include "Number.hpp"
#include "Convert.hpp"

NAMESPACE_START

class Integer: public Number<int> {
public:

    Integer(const int &value, const std::string &name = "Integer", const Class *myClass = _class): Number<int>(value, name, myClass) {}

private:

    const static Class _class("Integer");
};

NAMESPACE_END

#endif                                  // #if !defined(INTEGER_HPP)

