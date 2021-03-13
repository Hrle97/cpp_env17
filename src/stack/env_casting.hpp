#ifndef ENV_CASTING_HPP
#define ENV_CASTING_HPP

// bit cast

// stolen from: https://en.cppreference.com/w/cpp/numeric/bit_cast
// constexpr support needs compiler magic

COND_TMP_BINARY((
    (sizeof(TLhs) == sizeof(TRhs)) &&
    (ENV_STD::is_trivially_copyable_v<TRhs>)&&(ENV_STD::is_trivially_copyable_v<TLhs>)&&(ENV_STD::is_trivially_constructible_v<TLhs>)))
fun inl bit_cast(const TRhs &from) noexcept->TLhs
{
    TLhs to;
    std::memcpy(&to, &from, sizeof(TLhs));
    return to;
}

ENV_TEST_CASE("bit cast")
{
    let u = bit_cast<uint8_t, int8_t>(-1);
    REQUIRE(u);
}

// clamp cast

tmp<res_name, name T>
    cmp_fn clamp_cast(arithmetic_c<T> from) noex->deduc_res(T)
{
    if_cmp(ENV_STD::is_same_v<TRes, T> || ENV_STD::is_same_v<TRes, nores_t>)
    {
        ret from;
    }
    else if_cmp(ENV_STD::is_same_v<TRes, bool>)
    {
        ret !!from;
    }
    else if_cmp(is_unsigned_g<TRes> || is_unsigned_g<T>)
    {
        let cmp max = ENV_STD::numeric_limits<TRes>::max();
        ret scast<TRes>(from > max ? max : from);
    }
    else
    {
        let cmp max = ENV_STD::numeric_limits<TRes>::max();
        let cmp min = ENV_STD::numeric_limits<TRes>::min();

        ret scast<TRes>((from > max) ? max : (from < min) ? min
                                                          : from);
    }
}

TEST_CASE("clamp_cast")
{
    REQUIRE_EQ(clamp_cast<uint8_t>(322), 255);
    REQUIRE_EQ(clamp_cast<uint16_t>(70000), 65535);
    REQUIRE_EQ(clamp_cast<int16_t>(-70000), -32768);
}

// underlying cast

tmp<name T> cmp_fn underlying_cast(enum_c<T> _enum) noex->ENV_STD::underlying_type_t<T>
{
    ret scast<ENV_STD::underlying_type_t<T>>(_enum);
}

ENV_TEST_CASE("underlying cast")
{
    UNIQUE(my_size, ENV_STD::size_t);
    obj cmp my_size_t a{10};

    REQUIRES(underlying_cast(a) == 10);
}

#endif // ENV_CASTING_HPP