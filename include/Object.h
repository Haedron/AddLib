#pragma once

/*
 * File:   Object.hpp
 * Author: sbidny
 *
 * Created on January 25, 2011, 11:36 AM
 */

#ifndef OBJECT_HPP
#define	OBJECT_HPP

/*- HEADER FILES -------------------------------------------------------------*/

// System Header Files

#include <string>

// Other Header Files

#include "Namespace.hpp"

NAMESPACE_START

class Class;

class Object {
public:

    Object(const std::string &aName = "");

    virtual ~Object();

    bool equals(const Object &another) const;

    const Class &getClass() const;

    virtual std::string toString() const;

    virtual std::string getName() const;

    virtual uintptr_t hashCode() const;

    virtual bool operator ==(const Object &another) const;

protected:

    static const Class * const __class__;

    std::string __name__;
};

NAMESPACE_END

#endif                                  // #if !defined(OBJECT_HPP)
