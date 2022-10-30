#pragma once
#include <stdexcept>
class NegativeNumEx : public std::runtime_error {
public:
    // constructor specifies default error message
    NegativeNumEx()
        : std::runtime_error{ "attempted to enter a negative number" } {}
};


