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
#include "Class.hpp"
#include "Convert.hpp"
#include "Pointer.hpp"

NAMESPACE_START
namespace java {
namespace lang {

class Object {
public:

    Object(const std::string &myName): _name(myName), _pointer(this) {}

    virtual ~Object() {}

    bool equals(const Object &other) const {
        return (this == &other);
    }

    Class getClass() {
        return _class;
    }

    virtual std::string toString() {
        return _class.toString() + "@" + _pointer.toString();
    }

    std::string getName() {
        return _name;
    }

protected:



private:

    std::string _name;
    Class _class;
    Pointer _pointer;
};

}
}
NAMESPACE_END

#endif	/* OBJECT_HPP */
