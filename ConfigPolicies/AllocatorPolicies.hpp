#pragma once

#include <string>

struct StdAllocator
{
    const std::string name = "StdAllocator";
};

struct JemallocAllocator
{
    const std::string name = "JemallocAllocator";
};

struct InternalAllocator
{
    const std::string name = "InternalAllocator";
};
