#pragma once

#include "ILogger.hpp"

class HeaderLogger : public ILogger {
    public:
        HeaderLogger(ILogger * logger) : _logger(logger) {
            std::cout << "HeaderLogger constructor called" << std::endl;
        };
        ~HeaderLogger() { 
            std::cout << "HeaderLogger destructor called" << std::endl;
        };

        void write(std::string const & message) {
            _logger->write("[HEADER] " + message);
        };
    private:
        ILogger * _logger;
};