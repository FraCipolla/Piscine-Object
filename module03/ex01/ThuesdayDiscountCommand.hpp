#pragma once

#include <iostream>
#include <string>

#include "Command.hpp"

class ThuesdayDiscountCommand : public Command {
    public:
        ThuesdayDiscountCommand() : Command() { std::cout << "ThuesdayDiscountCommand default constructor" << std::endl; }
        ThuesdayDiscountCommand(int id, std::string date, std::string client, std::map<Article, int>&& articles) : Command(id, date, client, articles) {
            std::cout << "ThuesdayDiscountCommand(int id, std::string date, std::string client, std::map<std::string, int> articles)" << std::endl;
        }
        ThuesdayDiscountCommand(int id, std::string date, std::string client, Article&& article, int quantity) : Command(id, date, client, article, quantity) {
            std::cout << "ThuesdayDiscountCommand(int id, std::string date, std::string client, Article&& article, int quantity)" << std::endl;
        }
        ThuesdayDiscountCommand(const ThuesdayDiscountCommand &other) : Command(other) {
            std::cout << "ThuesdayDiscountCommand(const ThuesdayDiscountCommand &other)" << std::endl;
            }
        ThuesdayDiscountCommand(ThuesdayDiscountCommand &&other) : Command(other) {
            std::cout << "ThuesdayDiscountCommand(const ThuesdayDiscountCommand &&other)" << std::endl;
            }
        ThuesdayDiscountCommand(const Command &other) : Command(other) {
            std::cout << "ThuesdayDiscountCommand(const Command &other)" << std::endl;
            }
        ThuesdayDiscountCommand(Command &&other) : Command(other) {
            std::cout << "ThuesdayDiscountCommand(Command &&other)" << std::endl;
            }
        ~ThuesdayDiscountCommand() { std::cout << "ThuesdayDiscountCommand destructor" << std::endl; };

        ThuesdayDiscountCommand *operator=(const Command *other) {
            std::cout << "ThuesdayDiscountCommand operator=" << std::endl;
            return new ThuesdayDiscountCommand(other->get_id(), other->get_date(), other->get_client(), other->get_articles());
        }


        int get_total_price() const {
            int total_price = 0;
            auto articles = this->get_articles();
            for (auto it = articles.begin(); it != articles.end(); it++) {
                total_price += it->first.price * it->second;
            }
            if (this->get_date().find("Tuesday") != std::string::npos) {
                return total_price * 0.9;
            }
            return total_price;
        }
};