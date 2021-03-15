#ifndef ENV_TUPLE_HPP
#define ENV_TUPLE_HPP


// implementations

ENV_DETAIL_BEGIN

// normal

tmp<name TElements>
typ(pair_gt) = ENV_STD::pair<TElements, TElements>;

tmp<name TFirst, name TSecond>
typ(pair_ggt) = ENV_STD::pair<TFirst, TSecond>;

tmp<size_t Size, name TElements>
typ(array_ngt) = ENV_STD::array<TElements, Size>;

tmp<name... TElements>
typ(tuple_vt) = ENV_STD::tuple<TElements...>;

// view

tmp<name TElements>
typ(view_pair_gt) = ENV_STD::pair<ptr_gt < TElements>, ptr_gt <TElements>>;

tmp<name TFirst, name TSecond>
typ(view_pair_ggt) = ENV_STD::pair<ptr_gt < TFirst>, ptr_gt <TSecond>>;

tmp<size_t Size, name TElements>
typ(view_array_ngt) = ENV_STD::array<ptr_gt < TElements>, Size>;

tmp<name... TElements>
typ(view_tuple_vt) = ENV_STD::tuple<ptr_gt < TElements>...>;

// poly

tmp<name TElements>
typ(poly_pair_gt) = ENV_STD::pair<poly_gt < TElements>, poly_gt <TElements>>;

tmp<name TFirst, name TSecond>
typ(poly_pair_ggt) = ENV_STD::pair<poly_gt < TFirst>, poly_gt <TSecond>>;

tmp<size_t Size, name TElements>
typ(poly_array_ngt) = ENV_STD::array<poly_gt < TElements>, Size>;

tmp<name... TElements>
typ(poly_tuple_vt) = ENV_STD::tuple<poly_gt < TElements>...>;


// variadic

ENV_CLANG_SUPPRESS_PUSH("OCUnusedTemplateParameterInspection")

tmp<name, name = success_t>
strct tuple_vs;

tmp<>
strct tuple_vs<variadic_vt<>>
{
    tmp<
            tmp<name, name> class TPair,
            tmp<size_t, name> class TArray,
            tmp<name...> class TTuple>
    typ(result_ffft) = TTuple<>;
};

tmp<name THead, name... TRest>
strct tuple_vs<
        variadic_vt < THead, TRest...>,
success_vt<COND_TYPE(!ENV_STD::conjunction_v < ENV_STD::is_same < THead, TRest >...> && sizeof...(TRest) != 1)>>
{
tmp<
        tmp<name, name> class TPair,
        tmp<size_t, name> class TArray,
        tmp<name...> class TTuple>
typ(result_ffft) = TTuple<THead, TRest...>;
};

tmp<name TFirst, name TSecond>
strct tuple_vs<variadic_vt < TFirst, TSecond>>
{
tmp<
        tmp<name, name> class TPair,
        tmp<size_t, name> class TArray,
        tmp<name...> class TTuple>
typ(result_ffft) = TPair<TFirst, TSecond>;
};

tmp<name THead, name... TRest>
strct tuple_vs<
        variadic_vt < THead, TRest...>,
success_vt<COND_TYPE(ENV_STD::conjunction_v < ENV_STD::is_same < THead, TRest >...> && sizeof...(TRest) != 1)>>
{
tmp<
        tmp<name, name> class TPair,
        tmp<size_t, name> class TArray,
        tmp<name...> class TTuple>
typ(result_ffft) = TArray<size_t{sizeof...(TRest) + 1}, THead>;
};


// sized

tmp<size_t Size, name TElements>
strct tuple_ngt
{
    tmp<
            tmp<name, name> class TPair,
            tmp<size_t, name> class TArray>
    typ(result_fft) = TArray<Size, TElements>;
};

tmp<name TElements>
strct tuple_ngt<dual, TElements>
{
    tmp<
            tmp<name, name> class TPair,
            tmp<size_t, name> class TArray>
    typ(result_fft) = TPair<TElements, TElements>;
};

ENV_CLANG_SUPPRESS_POP

ENV_DETAIL_END


// abstract

// variadic

tmp<name... TElements>
typ(tuple_vt) =
name detail::tuple_vs<variadic_vt < TElements...>>::
tmp result_ffft<detail::pair_ggt, detail::array_ngt, detail::tuple_vt>;

tmp<name... TElements>
typ(view_tuple_vt) =
name detail::tuple_vs<variadic_vt < TElements...>>::
tmp result_ffft<detail::view_pair_ggt, detail::view_array_ngt, detail::view_tuple_vt>;

tmp<name... TElements>
typ(poly_tuple_vt) =
name detail::tuple_vs<variadic_vt < TElements...>>::
tmp result_ffft<detail::poly_pair_ggt, detail::poly_array_ngt, detail::poly_tuple_vt>;

ENV_TEST_CASE("variadic tuple")
{
    REQUIRE_EQT(tuple_vt<int, float>, detail::pair_ggt < int, float >);
    REQUIRE_EQT(tuple_vt<int, int, int>, detail::array_ngt < triple, int >);
    REQUIRE_EQT(tuple_vt<int, float, int>, detail::tuple_vt < int, float, int >);
}

tmp<name... TElements>
cmp_fn tpl(TElements&& ...elements) noex -> ENV::tuple_vt<ENV::remove_ref_gt<TElements>...>
{
    ret {ENV_STD::forward<TElements>(elements)...};
}

ENV_TEST_CASE("variadic tuple construction")
{
    let _empty = tpl();
    nonce(_empty);
    let _pair = tpl(1, 2.0);
    nonce(_pair);
    let _array = tpl(1, 2, 3);
    nonce(_array);
    let _tuple = tpl(1, 2.0, 3);
    nonce(_tuple);

    REQUIRE_EQT(decltype(_empty), const detail::tuple_vt<>);
    REQUIRE_EQT(decltype(_pair), const detail::pair_ggt<int, double>);
    REQUIRE_EQT(decltype(_array), const detail::array_ngt<triple, int>);
    REQUIRE_EQT(decltype(_tuple), const detail::tuple_vt<int, double, int>);
}


// sized

tmp<size_t Size, name TElements>
typ(tuple_ngt) =
name detail::tuple_ngt<Size, TElements>::
tmp result_fft<detail::pair_ggt, detail::array_ngt>;

tmp<size_t Size, name TElements>
typ(view_tuple_ngt) =
name detail::tuple_ngt<Size, TElements>::
tmp result_fft<detail::view_pair_ggt, detail::view_array_ngt>;

tmp<size_t Size, name TElements>
typ(poly_tuple_ngt) =
name detail::tuple_ngt<Size, TElements>::
tmp result_fft<detail::poly_pair_ggt, detail::poly_array_ngt>;

ENV_TEST_CASE("sized tuple")
{
    REQUIRE_EQT(tuple_ngt<dual, int>, detail::pair_ggt < int, int >);
    REQUIRE_EQT(tuple_ngt<4_s, int>, detail::array_ngt < 4_s, int >);
}

ENV_DETAIL_BEGIN

// MSVC has an internal compiler error if we just use sizeof... on non-type packs here

COND_TMP((name TElements, name... TArgs, ENV_STD::size_t... Indices),
         (ENV_STD::is_constructible_v<TElements, const TArgs& ...>))
cmp_fn tpl(ENV_STD::index_sequence<Indices...>, const TArgs& ...args)
noexpr(TElements{args...}) -> ENV::tuple_ngt<scast<size_t>(ENV::rank_of_a<Indices...>), TElements>
{
    ret {ENV::first_gvt<TElements, decltype(Indices)>{args...} ...};
}

COND_TMP((name TElements, ENV_STD::size_t... Indices), (ENV_STD::is_copy_constructible_v < TElements > ))
cmp_fn tpl(ENV_STD::index_sequence<Indices...>, const TElements& to_copy)
noexpr(TElements{to_copy}) -> ENV::tuple_ngt<scast<size_t>(ENV::rank_of_a<Indices...>), TElements>
{
    ret {ENV::first_gvt<TElements, decltype(Indices)>{to_copy}...};
}

COND_TMP((name TElements, ENV_STD::size_t... Indices), (ENV_STD::is_default_constructible_v < TElements > ))
cmp_fn tpl(ENV_STD::index_sequence<Indices...>)
noexpr(TElements{ }) -> ENV::tuple_ngt<scast<size_t>(ENV::rank_of_a<Indices...>), TElements>
{
    ret {ENV::first_gvt<TElements, decltype(Indices)>{ }...};
}

ENV_DETAIL_END

COND_TMP((size_t Size, name TElements, name... TArgs),
         (ENV_STD::is_constructible_v<TElements, TArgs...> && Size != empty))
cmp_fn tpl(TArgs&& ...args) noexpr(TElements{TElements{args...}})
{
    ret detail::tpl<TElements>(ENV_STD::make_index_sequence<Size>{ }, ENV_STD::forward<TArgs>(args)...);
}

COND_TMP((size_t Size, name TElements), (ENV_STD::is_copy_constructible_v < TElements > && Size != empty))
cmp_fn tpl(const TElements& to_copy) noexpr(TElements{to_copy})
{
    ret detail::tpl<TElements>(ENV_STD::make_index_sequence<Size>{ }, to_copy);
}

COND_TMP((size_t Size, name TElements), (ENV_STD::is_default_constructible_v < TElements > && Size != empty))
cmp_fn tpl() noexpr(TElements{TElements{ }})
{
    ret detail::tpl<TElements>(ENV_STD::make_index_sequence<Size>{ });
}

COND_TMP((size_t Size, name TElements = nil_t), (Size == empty))
cmp_fn tpl() noex { ret tuple_ngt<empty, TElements>{ }; }

ENV_TEST_CASE("sized tuple construction")
{
    let _empty = tpl<empty>();
    nonce(_empty);
    let _pair_copied = tpl<dual>(1);
    nonce(_pair_copied);
    let _array_forwarded = tpl<10_s, tuple_vt<int, int>>(1, 2);
    nonce(_array_forwarded);
    let _array_default = tpl<10_s, int>();
    nonce(_array_default);

    REQUIRE_EQT(decltype(_empty), const detail::array_ngt<empty, nil_t>);
    REQUIRE_EQT(decltype(_pair_copied), const detail::pair_ggt<int, int>);
    REQUIRE_EQT(decltype(_array_forwarded), const detail::array_ngt<10_s, detail::pair_ggt<int, int>>);
    REQUIRE_EQT(decltype(_array_default), const detail::array_ngt<10_s, int>);
}


// pair hash

ENV_STD_BEGIN

tmp<name TFirst, name TSecond>
strct hash<ENV::detail::pair_ggt<TFirst, TSecond>>
{
    typ(subject_t) = ENV::detail::pair_ggt<TFirst, TSecond>;

    ON_COND
    (ENV::is_hashable_g < typename subject_t::first_type > && ENV::is_hashable_g < typename subject_t::second_type >)
    cmp_fn op()(const ENV::detail::pair_ggt<TFirst, TSecond>& pair) const noex -> size_t
    {
        return ENV::hash(ENV_STD::get<0>(pair), ENV_STD::get<1>(pair));
    }
};

ENV_STD_END

ENV_TEST_CASE("pair hash")
{
    REQUIRE_EQ(hash(tpl(1, 2)), hash(tpl(1, 2)));
    REQUIRE_NE(hash(tpl(2, 1)), hash(tpl(1, 2)));
}

#endif // ENV_TUPLE_HPP
