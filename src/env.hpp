#ifndef ENV_HPP
#define ENV_HPP

#include "structure/env_structure.hpp"

ENV_NAMESPACE_BEGIN

ENV_TEST_SUITE_BEGIN("env");

#include "macros/env_macros.hpp"
#include "meta/env_meta.hpp"
#include "traits/env_traits.hpp"
// #include "stack/env_stack.hpp"
// #include "ops/env_ops.hpp"
// #include "heap/env_heap.hpp"
// #include "proxies/env_proxies.hpp"
// #include "iteration/env_iteration.hpp"

ENV_TEST_SUITE_END();

ENV_NAMESPACE_END

#endif // ENV_HPP