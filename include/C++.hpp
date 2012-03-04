#pragma once

/* 
 * File:   C++.hpp
 * Author: sbidny
 *
 * Created on November 17, 2011, 10:52 PM
 */

#if !defined(CPLUSPLUS_HPP)
#define CPLUSPLUS_HPP

template <typename Ptr>
void delete2(Ptr &ptr) {
//    assert(ptr != NULL);
    delete ptr;
    ptr = NULL;
}

template <typename Ptr>
void delete2(Ptr *&ptr) {
//    assert(ptr != NULL);
    delete ptr;
    ptr = NULL;
}

template <typename Ptr>
void delete2Array(Ptr &ptr) {
//    assert(ptr != NULL);
    delete[] ptr;
    ptr = NULL;
}

template <typename Ptr>
void delete2Array(Ptr *&ptr) {
//    assert(ptr != NULL);
    delete[] ptr;
    ptr = NULL;
}

#endif                                  // #if !defined(CPLUSPLUS_HPP)
