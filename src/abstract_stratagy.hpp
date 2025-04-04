#ifndef ABSTRACT_STRATAGY_HPP
#define ABSTRACT_STRATAGY_HPP

class abstract_stratagy {
private:
	unsigned long page_faults = 0u;
	unsigned long pages_handled = 0u;
	unsigned long size = 0u;

public:
	virtual ~abstract_stratagy() = 0;
	void set_size(unsigned long size) { this->size = size;}
	unsigned long get_size() {return this->size;}
	virtual void add_page(unsigned int page) = 0;
};

#endif /* ABSTRACT_STRATAGY_HPP */
