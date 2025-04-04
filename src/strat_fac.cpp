#include "strat_fac.hpp"

abstract_stratagy * strat_fac::get_stratagy(std::string stratagy) {
	if (!STRAT_STRING_TO_ENUM.count(stratagy)) return NULL;
	enum STRATAGY_TO_USE stratagy_enum = STRAT_STRING_TO_ENUM[stratagy];
	switch (stratagy_enum) {
		#define X(a, b) case b: return new class b(); break;
			STRATAGY_TABLE
		#undef X
		default:
			return NULL;
	}
}
