#pragma once

/* 
 * File:   Pointer.hpp
 * Author: sbidny
 *
 * Created on January 27, 2011, 12:15 PM
 */

#if !defined(POINTER_HPP)
#define POINTER_HPP

#include "Object.h"
#include "Number.hpp"
#include "Convert.hpp"

NAMESPACE_START

class Pointer: public Object {
public:

    Pointer(const void * const value):
            Object("", "Pointer"),
            _pointer(value) {}

    std::string toString() {
        return Convert::ToString(_pointer);
    }

private:

    const void * const _pointer;
};

NAMESPACE_END

#endif                                  // #if !defined(POINTER_HPP)
