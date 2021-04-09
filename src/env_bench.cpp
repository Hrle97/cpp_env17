#define ENV_MESSAGES

#include <env/env.hpp>


void bench(env::bench::State& state)
{
    for ([[maybe_unused]] auto _ : state)
    {
        std::vector<int> a{100};
        std::fill(a.begin(), a.end(), 1);
        env::bench::DoNotOptimize(a.data());
        env::bench::ClobberMemory();
    }
}

BENCHMARK(bench);


BENCHMARK_MAIN();