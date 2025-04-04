#ifndef OPTIMAL_HPP
#define OPTIMAL_HPP

#include "abstract_stratagy.hpp"

class OPTIMAL : public abstract_stratagy {
	public:
		OPTIMAL();
		~OPTIMAL();
		void add_page(unsigned int page);
};

#endif /* OPTIMAL_HPP */