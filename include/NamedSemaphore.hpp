/* 
 * File:   NamedSemaphore.hpp
 * Author: sbidny
 *
 * Created on May 29, 2011, 3:30 PM
 */

#ifndef NAMEDSEMAPHORE_HPP
#define	NAMEDSEMAPHORE_HPP

#include <boost/interprocess/sync/named_semaphore.hpp>

#include "Namespace.hpp"

NAMESPACE_START

typedef boost::interprocess::named_semaphore NamedSemaphore;

NAMESPACE_END

#endif	/* NAMEDSEMAPHORE_HPP */

