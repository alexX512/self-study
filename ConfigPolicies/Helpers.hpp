#pragma once

#include "AllocatorPolicies.hpp"
#include "CachePolicies.hpp"
#include "Config.hpp"
#include "ErrorHandlingPolicies.hpp"
#include "Runner.hpp"

#include <stdexcept>

namespace
{
    template<typename... Policies>
    BaseRunnerPtr getRunnerWithErrorHandlingPolicy(const RunnerConfig& config)
    {
        if (config.errorHandlingPolicy == "THROW")
        {
            return std::make_unique<Runner<Policies..., ThrowErrorPolicy>>();
        }
        else if (config.errorHandlingPolicy == "BREAK")
        {
            return std::make_unique<Runner<Policies..., ThrowErrorPolicy>>();
        }
        else
        {
            throw std::runtime_error("Incorrect error handling policy: " + config.errorHandlingPolicy);
        }
    }

    template<typename... Policies>
    BaseRunnerPtr getRunnerWithCachePolicy(const RunnerConfig& config)
    {
        if (config.cachePolicy == "LRU")
        {
            return getRunnerWithErrorHandlingPolicy<Policies..., LruCache>(config);
        }
        else if (config.cachePolicy == "SLRU")
        {
            return getRunnerWithErrorHandlingPolicy<Policies..., SlruCache>(config);
        }
        else if (config.cachePolicy == "ARC")
        {
            return getRunnerWithErrorHandlingPolicy<Policies..., ArcCache>(config);
        }
        else
        {
            throw std::runtime_error("Incorrect cache policy: " + config.cachePolicy);
        }
    }

    template<typename... Policies>
    BaseRunnerPtr getRunnerWithAllocatorPolicy(const RunnerConfig& config)
    {
        if (config.allocatorPolicy == "STD")
        {
            return getRunnerWithCachePolicy<Policies..., StdAllocator>(config);
        }
        else if (config.allocatorPolicy == "JEMALLOC")
        {
            return getRunnerWithCachePolicy<Policies..., JemallocAllocator>(config);
        }
        else if (config.allocatorPolicy == "INTERNAL")
        {
            return getRunnerWithCachePolicy<Policies..., InternalAllocator>(config);
        }
        else
        {
            throw std::runtime_error("Incorrect allocator policy: " + config.allocatorPolicy);
        }
    }
}

BaseRunnerPtr getRunnerByConfig(const RunnerConfig& config)
{
    return getRunnerWithAllocatorPolicy<>(config);
}