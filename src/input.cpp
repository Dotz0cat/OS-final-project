#include "input.hpp"

input::input() {
	this->state = ACCEPTING_ALGO;
	this->stratagy = NULL;
}

input::~input() {
	delete stratagy;
}

int input::handle_input(std::string str) {
	int only_alpha = 1;
	int only_num = 1;

	switch (this->state) {
		case (ACCEPTING_ALGO):
			if (str.empty()) {
				set_error("expected a non empty string");
				return -1;
			}

			for (char c : str) {
				only_alpha &= std::isalpha(c);
			}
			if (!only_alpha) {
				set_error("string did not contain only alpha characters");
				return -1;
			}
			else {
				this->stratagy = strat_fac::get_stratagy(str);
				if (this->stratagy == NULL) {
					set_error("invalid algroitum");
					return -1;
				}
				this->state = ACCEPTING_SIZE;
				return 0;
			}
			break;
		case (ACCEPTING_SIZE):
			if (str.empty()) {
				set_error("expected a non empty string");
				return -1;
			}

			for (char c : str) {
				only_num &= std::isdigit(c);
			}
			if (!only_num) {
				set_error("string did not contain only numeric characters");
				return -1;
			}
			else {
				unsigned long size = strtoll(str.c_str(), NULL, 0);
				this->stratagy->set_size(size);
				this->state = ACCEPTING_PAGES;
			}

			break;
		case (ACCEPTING_PAGES):
			if (str.empty()) {
				set_error("expected a non empty string");
				return -1;
			}

			for (char c : str) {
				only_num &= std::isdigit(c);
			}
			if (!only_num) {
				set_error("string did not contain only numeric characters");
				return -1;
			}
			else {
				unsigned long page = strtoll(str.c_str(), NULL, 0);
				this->stratagy->add_page(page);
				return 0;
			}

			break;
		case (INPUT_ERROR):
		default:
			return -1;
			break;
	}

	return 0;
}

void input::set_error(const char *error) {
	this->state = INPUT_ERROR;
	fprintf(stderr, "%s\n", error);
}