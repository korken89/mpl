//          Copyright Odin Holmes 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

#include <type_traits>

#include "../algorithm/fold_right.hpp"
#include "../functional/call.hpp"
#include "../types/list.hpp"

namespace kvasir {
	namespace mpl {
		namespace detail {
			template <typename T, typename U>
			struct split_push;
			template <typename... Ls, typename... Ts, typename U>
			struct split_push<list<list<Ts...>, Ls...>, U> {
				using type = list<list<U, Ts...>, Ls...>;
			};

			template <typename T>
			struct split_next;
			template <typename... Ls>
			struct split_next<list<Ls...>> {
				using type = list<list<>, Ls...>;
			};

			template <template <typename...> class F>
			struct split_if_pred {
				template <typename T, typename U>
				using f = typename std::conditional<F<U>::value, split_next<T>,
				                                    split_push<T, U>>::type::type;
			};
		}
		template <typename List, template <typename...> class F>
		using split_if =
		        c::call<c::fold_right<detail::split_if_pred<F>>,
		                List, list<list<>>>;
	}
}
