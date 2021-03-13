#ifndef FWA_CORE_ALIGNMENT_HPP
#define FWA_CORE_ALIGNMENT_HPP


// align_t

WHOLE_UL(align, align, FWA_STD::size_t);


// max align

strct alignas(next_pow2(alignof(FWA_STD::max_align_t))) max_align_t
{
    byte_t data[next_pow2(alignof(FWA_STD::max_align_t))];
};

let_cmp max_align{align_t{alignof(max_align_t)}};


FWA_CORE_TEST_CASE("alignment")
{
    REQUIRES(is_pow2(max_align));
}


// aligned

template<size_t size, size_t align>
class alignas(align) my_aligned_storage
{
    std::byte val[size] {std::byte{0}};


public:
    constexpr inline my_aligned_storage() noexcept = default;

    template<typename T>
    typename std::enable_if_t<
            sizeof(T) == size &&
            alignof(T) == align &&
            std::is_trivially_copyable_v<T>,
            my_aligned_storage&>
    inline operator=(const T& other) noexcept
    {
        std::memcpy(val, &other, size);
        return *this;
    }

    template<
            typename T,
            std::enable_if_t<
                    sizeof(T) == size &&
                    alignof(T) == align &&
                    std::is_trivially_copyable_v<T>,
                    int> = 0>
    inline my_aligned_storage(const T& other) noexcept
    {
        *this = other;
    }

    template<
            typename T,
            std::enable_if_t<
                    sizeof(T) == size &&
                    alignof(T) == align &&
                    std::is_trivially_constructible_v<T> &&
                    std::is_trivially_copyable_v<T>,
                    int> = 0>
    explicit inline operator T() const noexcept
    {
        T dst;
        std::memcpy(&dst, val, size);
        return dst;
    }
};

tmp<size_t Size = single, align_t Align = max_align>
typ(aligned_nnt) = FWA_STD::aligned_storage_t<Size, Align>;

tmp<align_t Align = max_align>
typ(aligned_nt) = FWA_STD::aligned_storage_t<single, Align>;


#endif // FWA_CORE_ALIGNMENT_HPP
