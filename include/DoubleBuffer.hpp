/* 
 * File:   DoubleBuffer.hpp
 * Author: sbidny
 *
 * Created on May 29, 2011, 3:08 PM
 */

#ifndef DOUBLEBUFFER_HPP
#define	DOUBLEBUFFER_HPP

#include "Namespace.hpp"
#include "SharedSemaphore.hpp"

NAMESPACE_START

template <typename Queue, typename Semaphore = SharedSemaphore(0)>
class DoubleBuffer {
public:

    bool pop() {
        
    }

    bool push() {
        semaphore.post();
    }

    bool tryPop() {
        if (semaphore.try_wait()) {
            return false;
        }

        return true;
    }

    bool timedPop() {
        
    }

private:

    Queue queue1;
    Queue queue2;
    Queue *read;
    Queue *write;
    SharedSemaphore semaphore;
};

NAMESPACE_END

#endif	/* DOUBLEBUFFER_HPP */
