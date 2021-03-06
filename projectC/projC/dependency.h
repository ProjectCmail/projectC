#ifndef DEPENDENCY
#define DEPENDENCY
#pragma once
#include <string>
#include <sstream>

template<typename T> std::string to_string(const T& n)
{
    std::ostringstream stm;
    stm << n;
    return stm.str();
}

#endif // DEPENDENCY

