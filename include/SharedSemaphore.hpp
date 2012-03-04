/* 
 * File:   SharedSemaphore.hpp
 * Author: sbidny
 *
 * Created on May 29, 2011, 3:23 PM
 */

#ifndef SHAREDSEMAPHORE_HPP
#define	SHAREDSEMAPHORE_HPP

#include <boost/interprocess/sync/interprocess_semaphore.hpp>

#include "Namespace.hpp"

NAMESPACE_START

typedef boost::interprocess::interprocess_semaphore SharedSemaphore;

NAMESPACE_END

#endif	/* SHAREDSEMAPHORE_HPP */
