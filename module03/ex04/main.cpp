#include "FileLogger.hpp"
#include "OstreamLogger.hpp"
#include "HeaderLogger.hpp"
#include <vector>

int main() {
    std::vector<ILogger *> loggers;
    loggers.push_back(new FileLogger("file.log"));
    loggers.push_back(new OstreamLogger(std::cout));
    loggers.push_back(new HeaderLogger(new FileLogger("file.log")));
    loggers.push_back(new HeaderLogger(new OstreamLogger(std::cout)));

    std::string messageArray[5] = {
        "Hello, world!",
        "Hello, pippo!",
        "Hello, topolino!",
        "Hello, minnie!",
        "Hello, pluto!"
    };

    for (std::vector<ILogger *>::iterator it = loggers.begin(); it != loggers.end(); it++) {
        for (int i = 0; i < 5; i++) {
            (*it)->write(messageArray[i]);
        }
    }
    loggers.clear();
    return 0;
}