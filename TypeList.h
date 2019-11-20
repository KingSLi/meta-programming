#ifndef META_PROGRAMMING_TYPELIST_H
#define META_PROGRAMMING_TYPELIST_H

#include "TypeHelpers.h"

class NullType {};

/////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename... Types>
struct Typelist {};

namespace NTypeList {
/////////////////////////////////////////////////////////////////////////////////////////////////////
    template<typename TypedList, size_t index>
    struct TypeAt;

    template<typename Head, typename... Tail>
    struct TypeAt<Typelist<Head, Tail...>, 0> {
        using result = Head;
    };

    template<typename Head, typename... Tail, size_t index>
    struct TypeAt<Typelist<Head, Tail...>, index> {
        using result = typename TypeAt<Typelist<Tail...>, index - 1>::result;
    };
/////////////////////////////////////////////////////////////////////////////////////////////////////

    template<typename TypedList, typename T>
    struct TypeExists;

    template<typename T, typename... Tail>
    struct TypeExists<Typelist<T, Tail...>, T> {
        static constexpr size_t result = 1;
    };

    template<typename Head, typename... Tail, typename T>
    struct TypeExists<Typelist<Head, Tail...>, T> {
        static constexpr size_t result = TypeExists<Typelist<Tail...>, T>::result;
    };

    template<typename T>
    struct TypeExists<Typelist<>, T> {
        static constexpr size_t result = 0;
    };

/////////////////////////////////////////////////////////////////////////////////////////////////////

    template<typename TypedList, typename T>
    struct ListWithType;

    template<typename Head, typename... Tail, typename T>
    struct ListWithType<Typelist<Head, Tail...>, T> {
        using result = 
                typename std::conditional<TypeExists<Head, T>::result, Head, typename ListWithType<Typelist<Tail...>, T>::result>::type;
    };

    template<typename T>
    struct ListWithType<Typelist<>, T> {
        using result = NullType;
    };
    
/////////////////////////////////////////////////////////////////////////////////////////////////////

    template<typename TypedList, typename T>
    struct Append;

    template<typename... Types, typename T>
    struct Append<Typelist<Types...>, T> {
        using result = Typelist<Types..., T>;
    };

/////////////////////////////////////////////////////////////////////////////////////////////////////

    template<typename TypedList>
    struct Reverse;

    template<typename Head, typename... Tail>
    struct Reverse<Typelist<Head, Tail...> > {
        using RTail = typename Reverse<Typelist<Tail...> >::result;
        using result = typename Append<RTail, Head>::result;
    };

    template<>
    struct Reverse<Typelist<> > {
        using result = Typelist<>;
    };

/////////////////////////////////////////////////////////////////////////////////////////////////////

    template<typename TypedList>
    struct GetTail;

    template<typename Head, typename... Tail>
    struct GetTail<Typelist<Head, Tail...> > {
        using result = Typelist<Tail...>;
    };

/////////////////////////////////////////////////////////////////////////////////////////////////////

    template<typename... TypedLists>
    struct GetSupers;

    template<typename Head, typename... Tail, typename TypedList, typename... TypedLists>
    struct GetSupers<Typelist<Head, Tail...>, TypedList, TypedLists...> {
        using supersResult = typename GetSupers<TypedList, TypedLists...>::result;
        using supersResultHead = typename TypeAt<supersResult, 0>::result;
        using result = 
                typename std::conditional<SUPERSUBCLASS(Head, supersResultHead), Typelist<Head, Tail...>, supersResult>::type;
    };

    template<typename TypedList>
    struct GetSupers<TypedList> {
        using result = TypedList;
    };

}
#endif //META_PROGRAMMING_TYPELIST_H
