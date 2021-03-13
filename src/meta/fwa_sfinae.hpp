#ifndef FWA_CORE_SFINAE_HPP
#define FWA_CORE_SFINAE_HPP


// variadic

tmp<name... T>
strct variadic_vt;

tmp<>
strct variadic_vt<>
{
    cmp_obj static FWA_STD::uintmax_t rank{0};

    tmp<FWA_STD::uintmax_t Index>
    typ(at_nt) = fail_t;

    typ(last_t) = fail_t;

    tmp<FWA_STD::uintmax_t Index>
    let_cmp static has_n = false;
};

tmp<name T>
strct variadic_vt<T>
{
    cmp_obj static FWA_STD::uintmax_t rank{1};

    tmp<FWA_STD::uintmax_t Index>
    typ(at_nt) = FWA_STD::conditional_t<Index == 0, T, fail_t>;

    typ(last_t) = T;

    tmp<FWA_STD::uintmax_t Index>
    let_cmp static has_n = Index == 0;
};

tmp<name THead, name... TRest>
strct variadic_vt<THead, TRest...>
{
    cmp_obj static FWA_STD::uintmax_t rank{sizeof...(TRest) + 1};

    tmp<FWA_STD::uintmax_t Index>
    typ(at_nt) = FWA_STD::conditional_t<Index == 0, THead, name variadic_vt<TRest...>::tmp at_nt<Index - 1>>;

    typ(last_t) = name variadic_vt<TRest...>::last_t;

    tmp<FWA_STD::uintmax_t Index>
    let_cmp static has_n = !FWA_STD::is_same_v<at_nt<Index>, fail_t>;
};

FWA_CORE_TEST_CASE ("variadic")
{
    REQUIRE_EQT(variadic_vt<int, double, float>::at_nt<2>, float);
    REQUIRE_EQT(variadic_vt<int, double, float>::at_nt<3>, fail_t);
    REQUIRE_EQT(variadic_vt<int, double, float>::last_t, float);
    REQUIRE_EQT(variadic_vt<int>::last_t, int);
    REQUIRE_EQT(variadic_vt<>::last_t, fail_t);
    REQUIRE_EQT(variadic_vt<>::at_nt<534>, fail_t);
}


// require

tmp<name TCondition, name TResult>
strct require_ggs : public FWA_STD::enable_if<TCondition::value, TResult> { };

tmp<name TCondition, name TResult>
typ(require_ggt) = FWA_STD::enable_if_t<TCondition::value, TResult>;

tmp<name TCondition>
typ(require_gs) = FWA_STD::enable_if<TCondition::value, success_t>;

tmp<name TCondition>
typ(require_gt) = FWA_STD::enable_if_t<TCondition::value, success_t>;

FWA_CORE_TEST_CASE ("require")
{
    REQUIRE_EQT(require_ggt<FWA_STD::true_type, int>, int);
}


tmp<bool Condition, name TResult>
strct require_ngs : public FWA_STD::enable_if<Condition, TResult> { };

tmp<bool Condition, name TResult>
typ(require_ngt) = FWA_STD::enable_if_t<Condition, TResult>;

tmp<bool Condition>
typ(require_ns) = FWA_STD::enable_if<Condition, success_t>;

tmp<bool Condition>
typ(require_nt) = FWA_STD::enable_if_t<Condition, success_t>;

FWA_CORE_TEST_CASE ("require")
{
    REQUIRE_EQT(require_ngt < true, int >, int);
}


#if FWA_CPP >= 17

tmp<bool Condition, deduc Result>
strct require_nns;

tmp<deduc Result>
strct require_nns<true, Result> : value_nt<Result> { };

tmp<deduc Result>
strct require_nns<false, Result> { };

tmp<bool Condition, deduc Result>
let_cmp require_nn{require_nns<Condition, Result>::value};

tmp<bool Condition>
let_cmp require_n{require_nn<Condition, success>};

FWA_CORE_TEST_CASE ("require")
{
    REQUIRE_EQ(require_nn < true, 1 >, 1);
    REQUIRE_EQ(require_n < true >, success);
}

#endif // FWA_CPP >= 17


// declval

tmp<name T>
callb declval() noex -> T;

// reference collapsing rules are applied on these

tmp<name T>
callb declvall() noex -> FWA_STD::add_lvalue_reference_t<T>;

tmp<name T>
callb declvalr() noex -> FWA_STD::add_rvalue_reference_t<T>;

FWA_CORE_TEST_CASE ("declval")
{
    SUBCASE("value")
    {
        REQUIRE_EQT(decl(declval<int>()), int);
        REQUIRE_EQT(decl(declval<int&>()), int &);
        REQUIRE_EQT(decl(declval<int&&>()), int &&);
    }

    SUBCASE("lvalue")
    {
        REQUIRE_EQT(decl(declvall<int>()), int &);
        REQUIRE_EQT(decl(declvall<int&>()), int &);
        REQUIRE_EQT(decl(declvall<int&&>()), int &);
    }

    SUBCASE("rvalue")
    {
        REQUIRE_EQT(decl(declvalr<int>()), int &&);
        REQUIRE_EQT(decl(declvalr<int&>()), int &);
        REQUIRE_EQT(decl(declvalr<int&&>()), int &&);
    }
}


// consume

tmp<name... T> cmp_callb hoard(T...) noex -> bool { ret true; }

FWA_CORE_TEST_CASE("hoard")
{
    REQUIRE_EQT(decl(hoard(1, 2, 3)), bool);
    REQUIRE_EQT(decl(hoard(1.02, 3)), bool);
    REQUIRE_EQT(decl(hoard("aa", 'v')), bool);
}

tmp<name... T> cmp_callb consume(T&& ...) noex -> bool { ret true; }

FWA_CORE_TEST_CASE("consume")
{
    REQUIRE_EQT(decl(consume(1, 2, 3)), bool);
    REQUIRE_EQT(decl(consume(1.02, 3)), bool);
    REQUIRE_EQT(decl(consume("aa", 'v')), bool);
}


// implies

cmp_fn implies(bool if_true, bool this_is_true) { ret !if_true || this_is_true; }

FWA_CORE_TEST_CASE("implies")
{
    REQUIRE(implies(true, true));
    REQUIRE_FALSE(implies(true, false));
    REQUIRE(implies(false, true));
    REQUIRE(implies(false, false));
}


// qualified

tmp<name T>
cmp_obj bool is_qualified_g{FWA_STD::is_reference_v<T> || FWA_STD::is_const_v<T> || FWA_STD::is_volatile_v<T>};

tmp<name T> typ(unqualified_gt) = FWA_STD::remove_cv_t<FWA_STD::remove_reference_t<T>>;

FWA_CORE_TEST_CASE("qualified")
{
    REQUIRE_EQT(unqualified_gt<int>, int);
    REQUIRE_EQT(unqualified_gt<const int>, int);
    REQUIRE_EQT(unqualified_gt<const int&>, int);
    REQUIRE_EQT(unqualified_gt<int&&>, int);
    REQUIRE_EQT(unqualified_gt<volatile int&&>, int);

    REQUIRES_FALSE(is_qualified_g<int>);
    REQUIRES(is_qualified_g<const int>);
    REQUIRES(is_qualified_g<const int&>);
    REQUIRES(is_qualified_g<int&&>);
    REQUIRES(is_qualified_g<volatile int&&>);
}


#endif // FWA_CORE_SFINAE_HPP
