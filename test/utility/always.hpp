//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include <kvasir/mpl/utility/always.hpp>

namespace {
	namespace mpl = kvasir::mpl;

	static_assert(std::is_same<mpl::always<int>::template f<void>, int>::value, "");

	template <typename T>
	struct foo {
		static_assert(mpl::eager::always_false<T>::value,
		              "always_false should not have been instantiated");
	};
}
