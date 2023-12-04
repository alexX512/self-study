#pragma once

#include "TypeList.hpp"

template<typename Element, typename TList>
struct PushFront;

template<typename Element, typename... TypeListElements>
struct PushFront<Element, TypeList<TypeListElements...>>
{
    using Type = TypeList<Element, TypeListElements...>;
};
