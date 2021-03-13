#ifndef ENV_SIZE
#define ENV_SIZE

WHOLE_UL(size, s, ENV_STD::size_t);

let_cmp empty{0_s}, single{1_s}, dual{2_s}, triple{3_s};

tmp<name T> let_cmp size_of_g = size_t{sizeof(T)};

WHOLE_UL(rank, r, ENV_STD::size_t);

let_cmp rank_zero{0_r}, rank_one{1_r}, rank_two{2_r}, rank_three{3_r};

tmp<name... T> let_cmp rank_of_v = rank_t{sizeof...(T)};

#if ENV_CPP >= 17
tmp<deduc... V> let_cmp rank_of_a = rank_t{sizeof...(V)};
#else  // ENV_CPP >= 17
tmp<int... V> let_cmp rank_of_a = rank_t{sizeof...(V)};
#endif // ENV_CPP >= 17

WHOLE_UL(arity, a, ENV_STD::size_t);

let_cmp nullary{0_a}, unary{1_a}, binary{2_a}, ternary{3_a};

tmp<name T> let_cmp arity_of_g = arity_t{argument_count_g<callable_r<T>>};

#endif // ENV_SIZE