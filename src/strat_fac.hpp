#ifndef STRAT_FAC_HPP
#define STRAT_FAC_HPP

#include <string>
#include <unordered_map>

#include "abstract_stratagy.hpp"

#include "fifo.hpp"
#include "optimal.hpp"
#include "LRU.hpp"

#define STRATAGY_TABLE \
X("L", LRU) \
X("O", OPTIMAL) \
X("F", FIFO)

#define X(a, b) b,
enum STRATAGY_TO_USE {
	STRATAGY_TABLE
};
#undef X

#define X(a, b) {a, b},
static std::unordered_map<std::string, enum STRATAGY_TO_USE> STRAT_STRING_TO_ENUM = {
	STRATAGY_TABLE
};
#undef X

class strat_fac {
public:
	static abstract_stratagy * get_stratagy(std::string stratagy);
};

#endif /* STRAT_FAC_HPP */
