#pragma once

#include <iostream>
#include <string>

#include "Command.hpp"

class PackageReductionDiscountCommand : public Command {
    public:
        PackageReductionDiscountCommand() : Command() { std::cout << "PackageReductionDiscountCommand default constructor" << std::endl; }
        PackageReductionDiscountCommand(int id, std::string date, std::string client, std::map<Article, int>&& articles) : Command(id, date, client, articles) {
            std::cout << "PackageReductionDiscountCommand(int id, std::string date, std::string client, std::map<std::string, int> articles)" << std::endl;
        }
        PackageReductionDiscountCommand(int id, std::string date, std::string client, Article&& article, int quantity) : Command(id, date, client, article, quantity) {
            std::cout << "PackageReductionDiscountCommand(int id, std::string date, std::string client, std::string article, int quantity)" << std::endl;
        }
        PackageReductionDiscountCommand(const PackageReductionDiscountCommand &other) : Command(other) {
            std::cout << "PackageReductionDiscountCommand(const PackageReductionDiscountCommand &other)" << std::endl;
            }
        PackageReductionDiscountCommand(const PackageReductionDiscountCommand &&other) : Command(other) {
            std::cout << "PackageReductionDiscountCommand(const PackageReductionDiscountCommand &&other)" << std::endl;
            }
        PackageReductionDiscountCommand(const Command &other) : Command(other) {
            std::cout << "PackageReductionDiscountCommand(const Command &other)" << std::endl;
            }
        PackageReductionDiscountCommand(Command &&other) : Command(other) {
            std::cout << "PackageReductionDiscountCommand(Command &&other)" << std::endl;
            }
        ~PackageReductionDiscountCommand() { std::cout << "PackageReductionDiscountCommand destructor" << std::endl; };

        PackageReductionDiscountCommand *operator=(const Command *other) {
            std::cout << "PackageReductionDiscountCommand operator=" << std::endl;
            return new PackageReductionDiscountCommand(other->get_id(), other->get_date(), other->get_client(), other->get_articles());
        }

        int get_total_price() const {
            int total_price = 0;
            auto articles = this->get_articles();
            for (auto it = articles.begin(); it != articles.end(); it++) {
                total_price += it->first.price * it->second;
            }
            return total_price > 150 ? total_price - 10 : total_price;
        }
};