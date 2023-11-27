#pragma once

#include <iostream>
#include <string>
#include "ILogger.hpp"

class OstreamLogger : public ILogger {
    public:
        OstreamLogger(std::ostream & stream) : _stream(stream) {
            std::cout << "OstreamLogger constructor called" << std::endl;
        };
        ~OstreamLogger() { 
            std::cout << "OstreamLogger destructor called" << std::endl;
        };

        void write(std::string const & message) {
            _stream << message << std::endl;
        };
    private:
        std::ostream & _stream;
};