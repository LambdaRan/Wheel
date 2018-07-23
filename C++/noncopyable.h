
#ifndef _NONCOPYABLE_H
#define _NONCOPYABLE_H

namespace noncopyable_  // protection from unintended ADL
{
class noncopyable
{
protected:
#if __cplusplus >= 201103L
    constexpr noncopyable() = default;
    ~noncopyable() = default;
#else
    noncopyable() {}
    ~noncopyable() {}
#endif
#if __cplusplus >= 201103L
    noncopyable( const noncopyable& ) = delete;
    noncopyable& operator=( const noncopyable& ) = delete;
#else
private:  // emphasize the following members are private
    noncopyable( const noncopyable& );
    noncopyable& operator=( const noncopyable& );
#endif
};
}

typedef noncopyable_::noncopyable noncopyable;

#endif  // BOOST_CORE_NONCOPYABLE_HPP
