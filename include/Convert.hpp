#pragma once

#if !defined(CONVERT_HPP)
#define CONVERT_HPP

#include <sstream>
#include "Namespace.hpp"

NAMESPACE_START
namespace System {

class Convert {
public:

    template <typename T>
    int ToInt(const T &value) {
        int rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    unsigned int ToUInt(const T &value) {
        unsigned int rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    long ToLong(const T &value) {
        long rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    unsigned long ToULong(const T &value) {
        unsigned long rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    long long ToLongLong(const T &value) {
        long long rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    unsigned long long ToULongLong(const T &value) {
        unsigned long long rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    short ToShort(const T &value) {
        short rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    unsigned short ToUShort(const T &value) {
        unsigned short rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    bool ToBoolean(const T &value) {
        bool rv = false;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    uint8_t ToByte(const T &value) {
        uint8_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    char ToChar(const T &value) {
        char rv = '\0';
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    double ToDouble(const T &value) {
        double rv = 0.;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    int8_t ToInt8(const T &value) {
        int8_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    int16_t ToInt16(const T &value) {
        int16_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    int32_t ToInt32(const T &value) {
        int32_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    int64_t ToInt64(const T &value) {
        int64_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    int8_t ToSByte(const T &value) {
        int8_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    float ToSingle(const T &value) {
        float rv = 0.;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    std::string ToString(const T &value) {
        return ChangeType<T, std::string > (value);
    }

    template <typename T>
    uint8_t ToUInt8(const T &value) {
        uint8_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    uint16_t ToUInt16(const T &value) {
        uint16_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    uint32_t ToUInt32(const T &value) {
        uint32_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    uint64_t ToUInt64(const T &value) {
        uint64_t rv = 0;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T>
    float ToFloat(const T &value) {
        float rv = 0.;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T, typename R>
    R ChangeType(const T &value) {
        R rv;
        ChangeType(value, rv);
        return rv;
    }

    template <typename T, typename R>
    void ChangeType(const T &value, R &rv) {
        std::stringstream ss;
        ss << value;
        ss >> rv;
    }
};

}                                       // namespace System
NAMESPACE_END

#endif                                  // #if !defined(CONVERT_HPP)
