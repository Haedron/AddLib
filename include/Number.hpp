#pragma once

/* 
 * File:   Number.hpp
 * Author: sbidny
 *
 * Created on January 27, 2011, 11:37 AM
 */

#if !defined(NUMBER_HPP)
#define	NUMBER_HPP

#include <string>

#include "Namespace.hpp"
#include "Class.hpp"
#include "Object.h"
#include "Convert.hpp"

NAMESPACE_START

template <typename T>
class Number: public Object {
public:

    Number(const T &value, const std::string &name = "Number", const Class *myClass = _class): Object(name, myClass) {
        _number = value;
    }

    virtual ~Number() {}

    bool setNumber(const T &value) {
        _number = value;

        return true;
    }

    const T &getNumber() const {
        return _number;
    }

    std::string toString() const {
        return toString(_number);
    }

    static std::string toString(const T &_value) const {
        return Convert::ToString(_value);
    }

    virtual double doubleValue() const {
        return Convert::ToDouble(_number);
    }

    virtual float floatValue() const {
        return Convert::ToFloat(_number);
    }

    virtual int intValue() const {
        return Convert::ToInt(_number);
    }

    virtual long longValue() const {
        return Convert::ToLong(_number);
    }

    virtual short shortValue() const {
        return Convert::ToShort(_number);
    }

    virtual long long longLongValue() const {
        return Convert::ToLongLong(_number);
    }

private:

    const static Class _class("Number");

    T _number;
};

NAMESPACE_END

#endif                                  // #if !defined(NUMBER_HPP)
