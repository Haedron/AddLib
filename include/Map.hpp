/* 
 * File:   Map.hpp
 * Author: sbidny
 *
 * Created on March 12, 2011, 12:52 AM
 */

#ifndef MAP_HPP
#define	MAP_HPP

template <typename Key, typename Value>
class Map {
public:
    virtual void clear() = 0;

    virtual bool containsKey(const Key &key) = 0;

    virtual bool containsValue(const Value &value) = 0;

    virtual Set entrySet() = 0;

    virtual bool equals(const Map &other) = 0;
};

#endif	/* MAP_HPP */

