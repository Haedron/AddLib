/*- HEADER FILES -------------------------------------------------------------*/

// Main Header File

#include "Object.h"

// Other Header Files

#include "Class.hpp"
#include "C++.hpp"
#include "Convert.hpp"

const Class * const Object::__class__ = new Class("Object");

/*- METHOD DEFINITIONS -------------------------------------------------------*/

Object::Object(const std::string &aName):
        __name__(aName) {}

Object::~Object() {}

bool Object::equals(const Object &another) const {
    return (this == &another);
}

const Class &Object::getClass() const {
    return *__class__;
}

std::string Object::toString() const {
    return __class__->toString() + "@" + Convert::ToString(this);
}

std::string Object::getName() const {
    return __name__;
}

uintptr_t Object::hashCode() const {
    return (uintptr_t) this;
}

bool Object::operator ==(const Object &another) const {
    return (this == &another);
}
