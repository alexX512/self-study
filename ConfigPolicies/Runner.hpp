#pragma once

#include <memory>
#include <string>

class BaseRunner
{
public:
    virtual std::string run() = 0;
};

using BaseRunnerPtr = std::unique_ptr<BaseRunner>;

template<typename Cache, typename Allocator, typename ErrorHandler>
class Runner : public BaseRunner
{
public:
    std::string run() override {
        // Run some code with specified policies
        return cache.name + " " + allocator.name + " " + errorHandler.name;
    }

private:
    Cache cache;
    Allocator allocator;
    ErrorHandler errorHandler;
};