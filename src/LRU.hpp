#ifndef LRU_HPP
#define LRU_HPP

#include "abstract_stratagy.hpp"

class LRU : public abstract_stratagy {
	public:
		LRU();
		~LRU();
		void add_page(unsigned int page);
};

#endif /* LRU_HPP */