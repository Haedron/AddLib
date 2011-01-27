#pragma once

/* 
 * File:   Number.hpp
 * Author: sbidny
 *
 * Created on January 27, 2011, 11:37 AM
 */

#if !defined(NUMBER_HPP)
#define	NUMBER_HPP

#include "Namespace.hpp"
#include "Object.hpp"
#include "Convert.hpp"

NAMESPACE_START
namespace java {
namespace lang {

template <typename T>
class Number: public Object {
public:

    Number(const T &value) {
        _number = value;
    }

    virtual ~Number() {}

    bool setNumber(const T &value) {
        _number = value;

        return true;
    }

    std::string toString() {
        return toString(_number);
    }

    std::string toString(const T &_value) {
        return System::Convert::ToString(_value);
    }

    virtual double doubleValue() {
        return System::Convert::ToDouble(_number);
    }

    virtual float floatValue() {
        return System::Convert::ToDouble(_number);
    }

    virtual int intValue() {
        return System::Convert::ToInt(_number);
    }

    virtual long longValue() {
        return System::Convert::ToLong(_number);
    }

    virtual short shortValue() {
        return System::Convert::ToShort(_number);
    }

    virtual long long longLongValue() {
        return System::Convert::ToLongLong(_number);
    }

private:

    T _number;
};

}                                       // namespace lang
}                                       // namespace java
NAMESPACE_END

#endif                                  // #if !defined(NUMBER_HPP)
