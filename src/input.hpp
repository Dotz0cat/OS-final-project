#ifndef INPUT_HPP
#define INPUT_HPP

#include <string>
#include <cctype>

#include "strat_fac.hpp"
#include "abstract_stratagy.hpp"

/*
 * ACCEPTING_ALGO:
 * 	Wants the algroithumn to use
 *	ie. L, F, O, etc
 *	defines the stratagy to use
 * ACCEPTING_SIZE:
 *	Wants the size of the page buffer? to use
 *	Immediantly after accepting_algro
 * ACCEPTING_PAGES:
 *	Wants the pages to process
 *	Only after ACCEPTING_ALGO and ACCEPTING_SIZE
 * INPUT_ERROR:
 *	There was unexpected input or EOF
*/

enum input_state {
	ACCEPTING_ALGO,
	ACCEPTING_SIZE,
	ACCEPTING_PAGES,
	INPUT_ERROR
};

class input {
	private:
		enum input_state state;
		abstract_stratagy *stratagy;
	public:
		input();
		~input();
		int handle_input(std::string str);
		void set_error(const char *error);
};

#endif /* INPUT_HPP */