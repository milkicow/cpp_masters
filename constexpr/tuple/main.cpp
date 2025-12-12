#include <boost/hana.hpp>

namespace hana = boost::hana;

template <typename Tuple> consteval auto sorted_tuple(const Tuple &tuple) {
  constexpr auto type_size = [](auto type) {
    if constexpr (hana::traits::is_void(type)) {
      return hana::size_c<0>;
    } else {
      return hana::sizeof_(type);
    }
  };

  return hana::sort(tuple, [type_size](auto type1, auto type2) {
    return hana::less(type_size(type1), type_size(type2));
  });
}

int main() {
  constexpr auto types = hana::tuple_t<int, char, std::uint32_t, void, char, long,
                                       uint64_t, int64_t, void>;
  constexpr auto sorted_types = sorted_tuple(types);
  constexpr auto sorted_types_ref =
      hana::tuple_t<void, void, char, char, int, uint32_t, long, uint64_t,
                    int64_t>;

  static_assert(sorted_types == sorted_types_ref);
  return 0;
}
