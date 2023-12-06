#include "Config.hpp"
#include "Helpers.hpp"
#include "Runner.hpp"

#include <cassert>

int main() {
    RunnerConfig config{
        .allocatorPolicy ="JEMALLOC",
        .cachePolicy = "ARC",
        .errorHandlingPolicy = "THROW"
    };

    auto runner = getRunnerByConfig(config);
    auto runnerPolicies = runner->run();

    assert(runnerPolicies == "JemallocAllocator ArcCache ThrowErrorPolicy");
}