#ifndef ENV_ITERATOR_STANDARD_REQUIREMENTS_HPP
#define ENV_ITERATOR_STANDARD_REQUIREMENTS_HPP


ENV_DETAIL_BEGIN

// the standard iterator traits are just empty for non-iterator types and,
// therefore, won't fail for non-iterators
// sfinae friendly
EXPR_TMP_UNARY(TYPE_EXPR(name ENV_STD::iterator_traits<T>::value_type))
strct iterator_traits_gt
{
private:
    typ(std_traits_t) = ENV_STD::iterator_traits<T>;

public:
    typ(value_t) = name      std_traits_t::value_type;
    typ(difference_t) = name std_traits_t::difference_type;
    typ(reference_t) = name  std_traits_t::reference;
    typ(pointer_t) = name    std_traits_t::pointer;
    typ(category_t) = name   std_traits_t::iterator_category;

    // needed for unordered associative containers
    COND_CLASS_CHECK(
            is_same,
            (name TOther),
            (TOther),

            same_vt<name iterator_traits_gt::value_t,
                    name TOther::value_t>,

            same_vt<name iterator_traits_gt::difference_t,
                    name TOther::difference_t>,

            same_vt<name iterator_traits_gt::reference_t,
                    name TOther::reference_t>,

            same_vt<name iterator_traits_gt::pointer_t,
                    name TOther::pointer_t>,

            same_vt<name iterator_traits_gt::category_t,
                    name TOther::category_t>);
};

// base because some requirements have more nuance when
// it comes to dereferencing and incrementing
COND_CHECK_UNARY(
        is_std_legacy_iterator_lifetime,
        is_std_copy_constructible_gs<T>,
        is_std_copy_assignable_gs<T>,
        is_std_destructible_gs<T>,
        is_std_swappable_gs<T>);

COND_CHECK_UNARY(
        is_std_base_legacy_iterator,
        is_std_legacy_iterator_lifetime_gs<T>,
        TYPE_COND(iterator_traits_gt<T>));

ENV_DETAIL_END


ENV_TEST_BEGIN

typ(iterator_value_t) = int;
// notes: https://en.cppreference.com/w/cpp/container/unordered_set
typ(forward_iterator_t) = ENV_STD::unordered_set<iterator_value_t>::iterator;
// notes: https://en.cppreference.com/w/cpp/container/set
typ(bidirectional_iterator_t) = ENV_STD::set<iterator_value_t>::iterator;
// notes: https://en.cppreference.com/w/cpp/container/vector
typ(random_access_iterator_t) = ENV_STD::vector<iterator_value_t>::iterator;
// notes: https://en.cppreference.com/w/cpp/container/vector
typ(contiguous_iterator_t) = ENV_STD::vector<iterator_value_t>::iterator;

ENV_TEST_END


// notes: https://en.cppreference.com/w/cpp/named_req/Iterator
COND_CHECK_UNARY(
        is_std_legacy_iterator,
        detail::is_std_base_legacy_iterator_gs<T>,

        /* these have way more preconditions like being a valid iterator which
         * are not possible to check. */

        /* dereferencing past the end or before begin is implementation defined
         * behaviour */
        EXPR_COND(*declvall<T>()),

        /* incrementing past the end or before begin is undefined behaviour */
        same_vt<decl(++declvall<T>()), T&>);

ENV_TEST_CASE("legacy iterator")
{
    STD_REQUIRE(is_std_legacy_iterator_g<test::forward_iterator_t>);
    STD_REQUIRE(is_std_legacy_iterator_g<test::bidirectional_iterator_t>);
    STD_REQUIRE(is_std_legacy_iterator_g<test::random_access_iterator_t>);
    STD_REQUIRE(is_std_legacy_iterator_g<test::contiguous_iterator_t>);
    STD_REQUIRE(is_std_legacy_iterator_g<int*>);
    STD_REQUIRE(detail::is_std_legacy_iterator_lifetime_g<int>);
    STD_REQUIRE_FALSE(detail::is_std_base_legacy_iterator_g<int>);
    STD_REQUIRE_FALSE(is_std_legacy_iterator_g<int>);
}


// notes: https://en.cppreference.com/w/cpp/named_req/OutputIterator
COND_CHECK_UNARY(
        is_std_legacy_output_iterator,
        detail::is_std_base_legacy_iterator_gs<T>,
        dis_vt<ENV_STD::is_pointer<T>, ENV_STD::is_class<T>>,

        /* the standard requires that there be
         * any assignment operator with a dereference */
        /* this is bad because it doesn't check for templates */
        /* EXPR_BOOL(&decl(*declvall<T>())::operator=) */
        /* also, this has more preconditions that are impossible to check */
        EXPR_COND(*declvall<T>()),

        /* this has more preconditions that are impossible to check. */
        /* surprisingly, there are different requirements for these. */
        same_vt<decl(++declvall<T>()), T&>,
        ENV_STD::is_convertible<decl(declvall<T>()++), const T&>

        /* the last expression is a combination of
         * dereferencing, incrementing, and assignment */
        /* again, it is impossible to check because
         * the assignment is impossible to check properly */
);

ENV_TEST_CASE("output iterator")
{
    STD_REQUIRE(is_std_legacy_output_iterator_g<test::forward_iterator_t>);
    STD_REQUIRE(is_std_legacy_output_iterator_g<test::bidirectional_iterator_t>);
    STD_REQUIRE(is_std_legacy_output_iterator_g<test::random_access_iterator_t>);
    STD_REQUIRE(is_std_legacy_output_iterator_g<test::contiguous_iterator_t>);
    STD_REQUIRE(is_std_legacy_output_iterator_g<int*>);
    STD_REQUIRE_FALSE(is_std_legacy_output_iterator_g<int>);
}


// notes: https://en.cppreference.com/w/cpp/named_req/InputIterator
COND_CHECK_UNARY(
        is_std_legacy_input_iterator,
        detail::is_std_base_legacy_iterator_gs<T>,

        /* this has more preconditions that are impossible to check. */
        is_std_equality_comparable_gs<T>,
        ENV_STD::is_convertible<
                decl(declval<const T>() != declval<const T>()),
                bool>,

        same_vt<decl(*declval<const T>()),
                name detail::iterator_traits_gt<T>::reference_t>,

        ENV_STD::is_convertible<
                name detail::iterator_traits_gt<T>::reference_t,
                name detail::iterator_traits_gt<T>::value_t>,

        imply_vt<ENV_STD::is_class<T>, has_arrow_operator_gs<T>>,

        /* this has more preconditions that are impossible to check. */
        /* surprisingly, there are different requirements for these. */
        same_vt<decl(++declvall<T>()), T&>,

        ENV_STD::is_convertible<
                decl(*declvall<T>()++),
                name detail::iterator_traits_gt<T>::value_t>,

        EXPR_COND(
                (void) *declval<const T>(),
                (void) ++declvall<T>(),
                (void) declvall<T>()++));

ENV_TEST_CASE("input iterator")
{
    STD_REQUIRE(is_std_legacy_input_iterator_g<test::forward_iterator_t>);
    STD_REQUIRE(is_std_legacy_input_iterator_g<test::bidirectional_iterator_t>);
    STD_REQUIRE(is_std_legacy_input_iterator_g<test::random_access_iterator_t>);
    STD_REQUIRE(is_std_legacy_input_iterator_g<test::contiguous_iterator_t>);
    STD_REQUIRE(is_std_legacy_input_iterator_g<int*>);
    STD_REQUIRE_FALSE(is_std_legacy_input_iterator_g<int>);
}


// notes: https://en.cppreference.com/w/cpp/named_req/ForwardIterator
COND_CHECK_UNARY(
        is_std_legacy_forward_iterator,
        is_std_legacy_input_iterator_gs<T>,
        is_std_default_constructible_gs<T>,

        /* there is a multipass guarantee requirement that is a bit complex and
         * impossible to check */

        /* this refers to the mutability of the iterator
         * it can be mutable or immutable */
        /* in the standard it should be mutable only if it's an output iterator,
         * but since all of these checks are not complete, I just leave this */
        dis_vt<same_vt<name detail::iterator_traits_gt<T>::reference_t,
                       name detail::iterator_traits_gt<T>::value_t&>,
               same_vt<name       detail::iterator_traits_gt<T>::reference_t,
                       const name detail::iterator_traits_gt<T>::value_t&>>,

        /* equality and inequality have a precondition since C++14 that
         * I don't necessarily understand */
        /* "Equality and inequality comparison is defined over all
         * iterators for the same underlying sequence and
         *  the value initialized-iterators (since C++14)." */

        /* I checked that these are compatible with
         * the input and output iterator requirements */
        same_vt<decl(declvall<T>()++), T>,

        same_vt<decl(*declvall<T>()++),
                name detail::iterator_traits_gt<T>::reference_t>);

ENV_TEST_CASE("forward iterator")
{
    STD_REQUIRE(is_std_legacy_forward_iterator_g<test::forward_iterator_t>);
    STD_REQUIRE(is_std_legacy_forward_iterator_g<test::bidirectional_iterator_t>);
    STD_REQUIRE(is_std_legacy_forward_iterator_g<test::random_access_iterator_t>);
    STD_REQUIRE(is_std_legacy_forward_iterator_g<test::contiguous_iterator_t>);
    STD_REQUIRE(is_std_legacy_forward_iterator_g<int*>);
    STD_REQUIRE_FALSE(is_std_legacy_forward_iterator_g<int>);
}


// notes: https://en.cppreference.com/w/cpp/named_req/BidirectionalIterator
COND_CHECK_UNARY(
        is_std_legacy_bidirectional_iterator,
        is_std_legacy_forward_iterator_gs<T>,

        /* decrementing past the end or before begin is undefined behaviour */

        /* this has a lot more requirements that are impossible to check */
        same_vt<decl(--declvall<T>()), T&>,

        ENV_STD::is_convertible<decl(declvall<T>()--), const T&>,

        same_vt<decl(*declvall<T>()--),
                name detail::iterator_traits_gt<T>::reference_t>);

ENV_TEST_CASE("bidirectional iterator")
{
    // it seems that this is a bit implementation defined
    //    STD_REQUIRE_FALSE(is_std_legacy_bidirectional_iterator_gs<
    //                      test::forward_iterator_t>);
    STD_REQUIRE(is_std_legacy_bidirectional_iterator_g<
                test::bidirectional_iterator_t>);
    STD_REQUIRE(is_std_legacy_bidirectional_iterator_g<
                test::random_access_iterator_t>);
    STD_REQUIRE(is_std_legacy_bidirectional_iterator_g<
                test::contiguous_iterator_t>);
    STD_REQUIRE(is_std_legacy_bidirectional_iterator_g<int*>);
    STD_REQUIRE_FALSE(is_std_legacy_bidirectional_iterator_g<int>);
}


// notes: https://en.cppreference.com/w/cpp/named_req/RandomAccessIterator
COND_CHECK_UNARY(
        is_std_legacy_random_access_iterator,
        is_std_legacy_bidirectional_iterator_gs<T>,

        /* any kind of going past the end or before begin is undefined behaviour */

        /* increment has a few more requirements that are impossible to check */
        same_vt<decl(declvall<T>() +=
                     declval<name detail::iterator_traits_gt<T>::
                                     difference_t>()),
                T&>,

        same_vt<decl(declval<const T>() +
                     declval<name detail::iterator_traits_gt<T>::
                                     difference_t>()),
                T>,

        same_vt<decl(declval<name detail::iterator_traits_gt<T>::
                                     difference_t>() +
                     declval<const T>()),
                T>,

        /* decrement has a few more requirements that are impossible to check */
        /* surprisingly, there is no requirement for the
         * inverse subtraction operator */
        same_vt<decl(declvall<T>() -=
                     declval<name detail::iterator_traits_gt<T>::
                                     difference_t>()),
                T&>,

        same_vt<decl(declval<const T>() -
                     declval<name detail::iterator_traits_gt<T>::
                                     difference_t>()),
                T>,

        same_vt<decl(declval<const T>() - declval<const T>()),
                name detail::iterator_traits_gt<T>::difference_t>,

        /* subscript */
        ENV_STD::is_convertible<
                decl(declval<const T>()[declval<
                        name detail::iterator_traits_gt<T>::
                                difference_t>()]),
                name detail::iterator_traits_gt<T>::reference_t>,

        /* other than having to be a total order,
         * these have a few more requirements */
        ENV_STD::is_convertible<
                decl(declval<const T>() < declval<const T>()),
                bool>,

        ENV_STD::is_convertible<
                decl(declval<const T>() > declval<const T>()),
                bool>,

        ENV_STD::is_convertible<
                decl(declval<const T>() <= declval<const T>()),
                bool>,

        ENV_STD::is_convertible<
                decl(declval<const T>() >= declval<const T>()),
                bool>);

ENV_TEST_CASE("random access iterator")
{
    // it seems that this is a bit implementation defined
    //    STD_REQUIRE_FALSE(is_std_legacy_random_access_iterator_gs<
    //                      test::forward_iterator_t>);
    //    STD_REQUIRE_FALSE(is_std_legacy_random_access_iterator_gs<
    //                      test::bidirectional_iterator_t>);
    STD_REQUIRE(is_std_legacy_random_access_iterator_g<
                test::random_access_iterator_t>);
    STD_REQUIRE(is_std_legacy_random_access_iterator_g<
                test::contiguous_iterator_t>);
    STD_REQUIRE(is_std_legacy_random_access_iterator_g<int*>);
    STD_REQUIRE_FALSE(is_std_legacy_random_access_iterator_g<int>);
}


#if ENV_CPP >= 17

// notes: https://en.cppreference.com/w/cpp/named_req/ContiguousIterator
COND_CHECK_UNARY(
        is_std_legacy_contiguous_iterator,
        is_std_legacy_random_access_iterator_gs<T>,

        /* it says in the standard that int should be any integral and
         * that the actual result should be equal,
         * but I think this is good enough for a compile time check */
        same_vt<decl(*(declval<T>() + int{})),
                decl(*(ENV_STD::addressof(*declval<T>()) + int{}))>);

ENV_TEST_CASE("contiguous iterator")
{
    // it seems that this is a bit implementation defined
    //    STD_REQUIRE_FALSE(is_std_legacy_contiguous_iterator_gs<
    //                      test::forward_iterator_t>);
    //    STD_REQUIRE_FALSE(is_std_legacy_contiguous_iterator_gs<
    //                      test::bidirectional_iterator_t>);
    //    STD_REQUIRE_FALSE(is_std_legacy_contiguous_iterator_gs<
    //                      test::random_access_iterator_t>);
    // according to: https://en.cppreference.com/w/cpp/container/vector
    // vector doesn't have to have a contiguous iterator...
    //    STD_REQUIRE(is_std_legacy_contiguous_iterator_gs<
    //                test::contiguous_iterator_t>);
    STD_REQUIRE(is_std_legacy_contiguous_iterator_g<int*>);
    STD_REQUIRE_FALSE(is_std_legacy_contiguous_iterator_g<int>);
}

#endif // ENV_CPP17


#endif // ENV_ITERATOR_STANDARD_REQUIREMENTS_HPP
