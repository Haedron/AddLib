#pragma once

/*
 * File:   Class.hpp
 * Author: sbidny
 *
 * Created on January 25, 2011, 12:01 PM
 */

#if !defined(CLASS_HPP)
#define	CLASS_HPP

#include "Object.hpp"

NAMESPACE_START
namespace java {
namespace lang {

class Class: public Object {
public:

    std::string toString() {
        return getName();
    }
};

}                                       // namespace lang
}                                       // namespace java
NAMESPACE_END

#endif                                  // #if !defined(CLASS_HPP)
