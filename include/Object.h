#pragma once

/*
 * File:   Object.hpp
 * Author: sbidny
 *
 * Created on January 25, 2011, 11:36 AM
 */

#ifndef OBJECT_HPP
#define	OBJECT_HPP

#include <string>

#include "Namespace.hpp"
#include "Convert.hpp"

NAMESPACE_START

class Class;
class Pointer;

class Object {
public:

    Object(const std::string &name = "", const Class *myClass = NULL);

    virtual ~Object() {}

    bool equals(const Object &other) const;

    Class getClass();

    virtual std::string toString();

    std::string getName();

private:

    std::string _name;
    Class *_class;
    Pointer *_pointer;
};

NAMESPACE_END

#endif                                  // #if !defined(OBJECT_HPP)
