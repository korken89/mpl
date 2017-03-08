//          Copyright Chiel Douwes 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE.md or copy at
//          http://www.boost.org/LICENSE_1_0.txt)
#pragma once

namespace kvasir {
	namespace mpl {
		namespace c {
			template<typename Combiner, typename...Cs>
			struct fork {
				template<typename...Ts>
				using f = typename Combiner::template f<typename Cs::template f<Ts...>...>;
			};
		}
	}
}
