#include <stdexcept>

class invalid_coordinates_error: public std::runtime_error {
public:
	invalid_coordinates_error(const char* errMessage) :
			std::runtime_error(errMessage) {
	}
};

class invalid_format_error: public std::runtime_error {
public:
	invalid_format_error(const char* errMessage) :
			std::runtime_error(errMessage) {
	}
};

class invalid_move_error: public std::runtime_error {
public:
	invalid_move_error(const char* errMessage) :
			std::runtime_error(errMessage) {
	}
};

class invalid_piece_error: public std::runtime_error {
public:
	invalid_piece_error(const char* errMessage) :
			std::runtime_error(errMessage) {
	}
};
