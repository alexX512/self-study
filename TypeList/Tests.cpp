#include "TypeList.hpp"
#include "Erase.hpp"
#include "Length.hpp"

#include <string>


using ShortBoolStringType = TypeList<short, bool, std::string>;

static_assert(Length_v<ShortBoolStringType> == 3);

using ShortStringType = Erase<short, ShortBoolStringType>::Type;
static_assert(Length_v<ShortStringType> == 2);

int main()
{
}