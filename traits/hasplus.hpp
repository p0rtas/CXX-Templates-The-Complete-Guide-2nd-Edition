#include <type_traits> // for true_type, false_type, and void_t
#include <utility> // for declval

// primary template:
template <typename, typename, typename = std::void_t<>>
struct HasPlusT : std::false_type {
};

// partial specialization (may be SFINAE'd away):
template <typename T1, typename T2>
struct HasPlusT<T1, T2, std::void_t<decltype(std::declval<T1>() + std::declval<T2>())>>
    : std::true_type {
};
