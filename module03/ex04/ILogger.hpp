#pragma once

#include <iostream>

class ILogger {
    public:
        virtual ~ILogger() {};
        virtual void write(std::string const & message) = 0;
};