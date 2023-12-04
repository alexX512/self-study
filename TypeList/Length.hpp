#pragma once

#include "TypeList.hpp"

template <typename TList>
struct Length;

template <typename... Types>
struct Length<TypeList<Types...>>
{
    static constexpr std::size_t value = sizeof...(Types);
};

template <typename TList>
inline constexpr std::size_t Length_v = Length<TList>::value;
