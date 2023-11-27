#pragma once

#include <iostream>
#include <list>
#include "Worker.hpp"

class Workshop  {
    private:
        std::list<Worker *> workers;
        int nWorkers;
        int nTools;
    
    public:
        Workshop() : nWorkers(0), nTools(0) { std::cout << "Workshop constructor" << std::endl; };
        ~Workshop() { std::cout << "Workshop destructor" << std::endl; };

        void registerWorker(Worker &worker) {
            this->workers.push_back(&worker);
            this->nWorkers++;
            }
        void releaseWorker(Worker &worker) {
            this->workers.remove(&worker);
            this->nWorkers--;
            }

        void executeWorkDay() {
            for (std::list<Worker *>::iterator it = this->workers.begin(); it != this->workers.end(); it++) {
                (*it)->work();
            }
        }
};