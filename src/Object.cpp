#include "Object.h"
#include "Class.hpp"
#include "Pointer.hpp"

Object::Object(const std::string &name = "", const Class *myClass = NULL):
        _name(name),
        _class(myClass),
        _pointer(new Pointer(this)) {}

Object::~Object() {
    delete _pointer;
    _pointer = NULL;
}

bool Object::equals(const Object &other) const {
    return (this == &other);
}

Class Object::getClass() {
    return *_class;
}

std::string Object::toString() {
    return _class->toString() + "@" + _pointer->toString();
}

std::string Object::getName() {
    return _name;
}
