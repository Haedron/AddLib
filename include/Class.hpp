#pragma once

/*
 * File:   Class.hpp
 * Author: sbidny
 *
 * Created on January 25, 2011, 12:01 PM
 */

#if !defined(CLASS_HPP)
#define	CLASS_HPP

#include "Object.h"

NAMESPACE_START

class Class: public Object {
public:

    Class(const std::string &name): Object(name) {}

    std::string toString() {
        return getName();
    }
};

NAMESPACE_END

#endif                                  // #if !defined(CLASS_HPP)
