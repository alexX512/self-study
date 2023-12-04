#pragma once

#include "TypeList.hpp"
#include "PushFront.hpp"

#include <type_traits>

template<typename T, class TList>
struct Erase;

template<typename T>
struct Erase<T, TypeList<>>
{
   using Type = TypeList<>;
};

template<typename T, typename Head, typename... Tail>
struct Erase<T, TypeList<Head, Tail...>>
{
    using TailTypeList = TypeList<Tail...>;
    using TailEraseType = typename Erase<T, TailTypeList>::Type;

    using Type = std::conditional<std::is_same_v<T, Head>, TailTypeList, typename PushFront<Head, TailEraseType>::Type>;
};


template<typename T, class TList>
struct EraseAll;

template<typename T>
struct EraseAll<T, TypeList<>>
{
    using Type = TypeList<>;
};

template<typename T, typename Head, typename... Tail>
struct EraseAll<T, TypeList<Head, Tail...>>
{
    using TailEraseAllType = typename EraseAll<T, TypeList<Tail...>>::Type;
    using Type = std::conditional<std::is_same_v<T, Head>, TailEraseAllType, typename PushFront<Head, TailEraseAllType>::Type>;
};