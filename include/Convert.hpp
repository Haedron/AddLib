#pragma once

#if !defined(CONVERT_HPP)
#define CONVERT_HPP

#include <sstream>
#include "Namespace.hpp"
#include "Object.h"

NAMESPACE_START

class Convert {
public:

    template <typename T>
    static int ToInt(const T &value) {
        int rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static unsigned int ToUInt(const T &value) {
        unsigned int rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static long ToLong(const T &value) {
        long rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static unsigned long ToULong(const T &value) {
        unsigned long rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static long long ToLongLong(const T &value) {
        long long rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static unsigned long long ToULongLong(const T &value) {
        unsigned long long rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static short ToShort(const T &value) {
        short rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static unsigned short ToUShort(const T &value) {
        unsigned short rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static bool ToBoolean(const T &value) {
        bool rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static uint8_t ToByte(const T &value) {
        uint8_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static char ToChar(const T &value) {
        char rv = '\0';
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static double ToDouble(const T &value) {
        double rv = 0.;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static int8_t ToInt8(const T &value) {
        int8_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static int16_t ToInt16(const T &value) {
        int16_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static int32_t ToInt32(const T &value) {
        int32_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static int64_t ToInt64(const T &value) {
        int64_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static int8_t ToSByte(const T &value) {
        int8_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static float ToSingle(const T &value) {
        float rv = 0.;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static std::string ToString(const T &value) {
        return ChangeType<T, std::string > (value);
    }

    template <typename T>
    static uint8_t ToUInt8(const T &value) {
        uint8_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static uint16_t ToUInt16(const T &value) {
        uint16_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static uint32_t ToUInt32(const T &value) {
        uint32_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static uint64_t ToUInt64(const T &value) {
        uint64_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    static float ToFloat(const T &value) {
        float rv = 0.;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T, typename R>
    static R ChangeType(const T &value) {
        R rv;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T, typename R>
    static void ChangeType(const T &value, R &rv) {
        std::stringstream ss;
        ss << value;
        ss >> rv;
    }
};

NAMESPACE_END

#endif                                  // #if !defined(CONVERT_HPP)
