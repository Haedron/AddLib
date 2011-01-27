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
namespace java {
namespace lang {

class Integer: public Number<int> {
public:

    Integer(const int &value): Number<int>(value) {}
};

}                                       // namespace lang
}                                       // namespace java
NAMESPACE_END

#endif                                  // #if !defined(INTEGER_HPP)

