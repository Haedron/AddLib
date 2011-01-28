#pragma once

/* 
 * File:   Objectify.hpp
 * Author: sbidny
 *
 * Created on January 25, 2011, 11:29 AM
 */

#ifndef OBJECTIFY_HPP
#define	OBJECTIFY_HPP

#include "Namespace.hpp"
#include "Object.h"

NAMESPACE_START

template <typename Target>
class Objectify: public Target, public Object {};

NAMESPACE_END

#endif                                  // #if !defined(OBJECTIFY_HPP)
