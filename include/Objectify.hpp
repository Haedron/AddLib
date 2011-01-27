/* 
 * File:   Objectify.hpp
 * Author: sbidny
 *
 * Created on January 25, 2011, 11:29 AM
 */

#ifndef OBJECTIFY_HPP
#define	OBJECTIFY_HPP

NAMESPACE_START

template <typename Target>
class Objectify: public Target, public Object {};

#endif	/* OBJECTIFY_HPP */
