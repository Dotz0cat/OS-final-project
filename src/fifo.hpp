#ifndef FIFO_HPP
#define FIFO_HPP

#include "abstract_stratagy.hpp"

class FIFO : public abstract_stratagy {
	public:
		FIFO();
		~FIFO();
		void add_page(unsigned int page);
};

#endif /* FIFO_HPP */