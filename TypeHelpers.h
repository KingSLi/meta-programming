//
// Created by Maksim Polyanskiy on 2019-11-20.
//

#ifndef META_PROGRAMMING_TYPEHELPERS_H
#define META_PROGRAMMING_TYPEHELPERS_H

template <class T, class U>
class Conversion {
    typedef char Small;
    class Big { char dummy[2]; };
    static Small Test(U);
    static Big Test(...);
    static T MakeT();
public:
   static constexpr size_t exists = sizeof(Test(MakeT())) == sizeof(Small);
   static constexpr bool sameType = false;
};

////////////////////////////////////////////////////////////////////////////////

template <class T>
class Conversion<T, T> {
public:
    static constexpr size_t exists = 1;
    static constexpr bool sameType = true;
};

#define SUPERSUBCLASS(T, U) \
    (Conversion<const U*, const T*>::exists && \
    !Conversion<const T*, const void*>::sameType)


////////////////////////////////////////////////////////////////////////////////

template <typename T>
struct Type2Type {
    using type = T;
};

#endif //META_PROGRAMMING_TYPEHELPERS_H
