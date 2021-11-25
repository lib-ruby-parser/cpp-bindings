#ifndef LIB_RUBY_PARSER_UTILS_HPP
#define LIB_RUBY_PARSER_UTILS_HPP

#include <cassert>
#include <cstring>
#include <cstdint>
#include <utility>

#define BLOB(T)                       \
    extern "C"                        \
    {                                 \
        struct T##Blob                \
        {                             \
            uint8_t bytes[sizeof(T)]; \
        };                            \
    }

template <typename T, typename B>
B into_blob(T t)
{
    assert(sizeof(T) == sizeof(B));

    union U
    {
        T t;
        B b;

        U() { std::memset(this, 0, sizeof(U)); }
        ~U() {}
    };

    U u;
    u.t = std::move(t);
    return u.b;
}

template <typename B, typename T>
T from_blob(B b)
{
    assert(sizeof(T) == sizeof(B));

    union U
    {
        T t;
        B b;

        U() { std::memset(this, 0, sizeof(U)); }
        ~U() {}
    };

    U u;
    u.b = b;
    return std::move(u.t);
}

#define LIST_IMPL(LIST, ITEM, DROP)                     \
    LIST::LIST(ITEM *ptr_,                              \
               size_t len_,                             \
               size_t capacity_) : ptr(ptr_),           \
                                   capacity(capacity_), \
                                   len(len_) {}         \
                                                        \
    extern "C"                                          \
    {                                                   \
        void DROP(LIST *list);                          \
    }                                                   \
    LIST::~LIST()                                       \
    {                                                   \
        DROP(this);                                     \
        this->ptr = nullptr;                            \
        this->len = 0;                                  \
        this->capacity = 0;                             \
    }                                                   \
    LIST::LIST(LIST &&other)                            \
    {                                                   \
        this->ptr = other.ptr;                          \
        this->len = other.len;                          \
        this->capacity = other.capacity;                \
                                                        \
        other.ptr = nullptr;                            \
        other.len = 0;                                  \
        other.capacity = 0;                             \
    }                                                   \
    LIST &LIST::operator=(LIST &&other)                 \
    {                                                   \
        this->ptr = other.ptr;                          \
        this->len = other.len;                          \
        this->capacity = other.capacity;                \
                                                        \
        other.ptr = nullptr;                            \
        other.len = 0;                                  \
        other.capacity = 0;                             \
                                                        \
        return *this;                                   \
    }                                                   \
    class Ignore##LIST                                  \
    {                                                   \
    }

#endif // LIB_RUBY_PARSER_UTILS_HPP
