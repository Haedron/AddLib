/* 
 * File:   Container.hpp
 * Author: sbidny
 *
 * Created on February 19, 2011, 2:12 AM
 */

#ifndef CONTAINER_HPP
#define	CONTAINER_HPP

#include <string>
#include <algorithm>
#include <iterator>

class Container: public Object {
public:

    // Type Definitions

    typedef typename Alloc::value_type value_type;
    typedef typename Alloc::pointer pointer;
    typedef typename Alloc::const_pointer const_pointer;
    typedef typename Alloc::reference reference;
    typedef typename Alloc::const_reference const_reference;
    typedef Alloc allocator_type;
    typedef typename Alloc::size_type size_type;
    typedef typename Alloc::difference_type difference_type;
    typedef std::iterator<
            std::random_access_iterator_tag,
            value_type,
            difference_type,
            pointer,
            reference> iterator;
    typedef std::iterator<
            std::random_access_iterator_tag,
            value_type,
            difference_type,
            const_pointer,
            const_reference> const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

    // Destructor

    virtual ~Container() {}

    // Methods

    virtual Container& operator =(const Container &rhs) = 0;

    iterator begin() {

    }

    const_iterator begin() const {

    }

    iterator end() {

    }

    const_iterator end() const {

    }

    reverse_iterator rbegin() {
        return std::reverse_iterator<iterator>(begin());
    }

    const_reverse_iterator rbegin() const {
        return std::reverse_iterator<const_iterator>(begin());
    }

    reverse_iterator rend() {
        return std::reverse_iterator<iterator>(end());
    }

    const_reverse_iterator rend() const {
        return std::reverse_iterator<const_iterator>(end());
    }

    size_type size() const {

    }

    size_type max_size() const {
        return std::min<size_type>(
                m_allocator.max_size(),
                std::numeric_limits<difference_type>::max());
    }

    void resize(const size_type &aSize, const value_type &aValue) {
        if (aSize > size()) {
            if (aSize > capacity) {
                reserve(aSize);
            }

            insert(end(), aSize - size(), aValue);
        } else {
            iterator e = end();
            erase(e - (size() - sz), e);
        }
    }

    bool empty() const {
        return size() == 0;
    }

    reference front() {

    }

    const_reference front() const {

    }

    reference back() {

    }

    const_reference back() const {

    }

    assign

    void push_back(const value_type &aValue) {

    }

    void pop_back() {

    }

    insert

    erase

    void swap(Container &aContainer) {

    }

    void clear() {
        
    }

    allocator_type get_allocator() const {
        return m_allocator;
    }

    reference
    const_reference
    iterator
    const_iterator
    size_type
    difference_type
    value_type
    allocator_type
    pointer
    const_pointer
    reverse_iterator
    const_reverse_iterator

    optional

    array_range
    const_array_range
    capacity_type


    C#
    Capacity
    Count
    Add
    Clear
    Clone
    Contains
    Equals
    Insert
    Remove
    RemoveAt
    Reverse
    Sort
    ToString
    ToArray
    TrimToSize

    Optional

    operator +=
    append
    replace
    copy
    swap
    c_str
    data
    find
    rfind
    find_first_of
    find_last_of
    find_first_not_of
    find_last_not_of
    substr
    compare
    capacity
    reserve
    operator []
    at
    push_front
    pop_front
    splice
    remove
    remove_if
    unique
    merge
    sort
    reverse
    length
    linearize
    is_linearized
    rotate
    full
    set_capacity
    rset_capacity
    rresize
    rinsert
    rerase
    erase_begin
    erase_end
    operator ==
    operator <
    operator !=
    operator >
    operator <=
    operator >=
};

#endif	/* CONTAINER_HPP */

