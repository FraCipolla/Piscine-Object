#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "ILogger.hpp"

class FileLogger : public ILogger {
    public:
        FileLogger(std::string const & filename) : _filename(filename) {
            std::cout << "FileLogger constructor called" << std::endl;
        };
        ~FileLogger() { 
            std::cout << "FileLogger destructor called" << std::endl;
        };

        void write(std::string const & message) {
            std::ofstream output_file(_filename, std::ios::app);
            if (output_file.is_open()) {
                output_file << message << std::endl;
                output_file.close();
            } else {
                std::cout << "Unable to open file" << std::endl;
            }
        };
    private:
        std::string _filename;
};