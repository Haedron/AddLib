#pragma once

/* 
 * File:   Namespace.hpp
 * Author: sbidny
 *
 * Created on January 25, 2011, 11:14 AM
 */

#if !defined(NAMESPACE_HPP)
#define	NAMESPACE_HPP

#if !defined(NAMESPACE)
#define NAMESPACE AddLib
#endif

#if !defined(NAMESPACE_START)
#define NAMESPACE_START namespace AddLib {
#endif

#if !defined(NAMESPACE_END)
#define NAMESPACE_END }
#endif

NAMESPACE_START
NAMESPACE_END

using namespace NAMESPACE;

#endif	/* NAMESPACE_HPP */
