#pragma once

#include <iostream>
#include <string>
#include <map>

struct Article {
    std::string name;
    int price;

    Article() : name(""), price(0) { std::cout << "article default constructor" << std::endl; }
    Article(std::string name, int price) : name(name), price(price) { std::cout << "article(std::string name, int price)" << std::endl; }
    Article(const Article &other) : name(other.name), price(other.price) { std::cout << "article(const article &other)" << std::endl; }

    Article(Article &&other) : name(other.name), price(other.price) { std::cout << "article(const article &&other)" << std::endl; }

    ~Article() { std::cout << "article destructor" << std::endl; };

    Article *operator=(const Article *other) {
        std::cout << "article operator=" << std::endl;
        return new Article(other->name, other->price);
    }
    Article operator=(const Article &other) {
        std::cout << "article operator=" << std::endl;
        return Article(other.name, other.price);
    }

    bool operator==(const Article &other) const {
        return this->name == other.name && this->price == other.price;
    }
    bool operator<(const Article &other) const {
        return this->name < other.name;
    }

    friend std::ostream &operator<<(std::ostream &os, const Article &article) {
        os << "Article name: " << article.name << std::endl;
        os << "Article price: " << article.price << std::endl;
        return os;
    }
};

class Command {
    private:
        int _id;
        std::string _date;
        std::string _client;
        std::map<Article, int> _articles;

    public:
        Command() : _id(0), _date(""), _client("") { std::cout << "Command default constructor" << std::endl; }
        Command(int id, std::string date, std::string client, std::map<Article, int> articles) : _id(id), _date(date), _client(client), _articles(articles) {
            std::cout << "Command(int id, std::string date, std::string client, std::map<std::string, int> articles)" << std::endl;
            }
        Command(int id, std::string date, std::string client, Article& article, int quantity) : _id(id), _date(date), _client(client), _articles() {
            _articles[article] = quantity;
            std::cout << "Command(int id, std::string date, std::string client, Article& article, int quantity)" << std::endl;
            }
        Command(int id, std::string date, std::string client, Article&& article, int quantity) : _id(id), _date(date), _client(client), _articles() {
            _articles[std::move(article)] = quantity;
            std::cout << "Command(int id, std::string date, std::string client, Article&& article, int quantity)" << std::endl;
            }
        Command(const Command &other) : _id(other._id), _date(other._date), _client(other._client), _articles(other._articles) {
            std::cout << "Command(const Command &other)" << std::endl;
            }
        Command(Command &&other) : _id(std::move(other._id)), _date(std::move(other._date)), _client(std::move(other._client)), _articles(std::move(other._articles)) {
            std::cout << "Command(const Command &&other)" << std::endl;
            }
        virtual ~Command() {
            std::cout << "Command destructor" << std::endl;
            this->_articles.clear();
            };
        
        Command *operator=(const Command *other) {
            std::cout << "Command operator=" << std::endl;
            return new Command(other->get_id(), other->get_date(), other->get_client(), other->get_articles());
        }

        int get_id() const { return _id; }
        std::string get_date() const { return _date; }
        std::string get_client() const { return _client; }
        std::map<Article, int> get_articles() const { return _articles; }
        const std::map<Article, int> &get_articles() { return _articles; }

        void set_id(int id) { _id = id; }
        void set_date(std::string date) { _date = date; }
        void set_client(std::string client) { _client = client; }
        void set_articles(std::map<Article, int> articles) { _articles = articles; }

        int get_total_price() const {
            int total_price = 0;
            for (auto it = _articles.begin(); it != _articles.end(); it++) {
                total_price += it->first.price * it->second;
            }
            return total_price;
        }

        friend std::ostream &operator<<(std::ostream &os, const Command &command) {
            os << "Command id: " << command._id << std::endl;
            os << "Command date: " << command._date << std::endl;
            os << "Command client: " << command._client << std::endl;
            os << "Command articles: " << std::endl;
            for (auto it = command._articles.begin(); it != command._articles.end(); it++) {
                os << "    " << it->first.name << " " << it->second << std::endl;
            }
            return os;
        }

};