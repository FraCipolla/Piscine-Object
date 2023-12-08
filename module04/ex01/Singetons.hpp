#pragma once

#include <vector>
#include <iostream>

template <typename T>
class Singleton
{
    private:
        Singleton() {};
        static std::vector<T> _list;
        static Singleton* _instance;
    public:
        static Singleton* getInstance()
        {
            if (_instance == nullptr) {
                std::cout << "Creating new instance" << std::endl;
                _instance = new Singleton();
            }
            return _instance;
        }
        Singleton(Singleton const&) = delete;
        Singleton& operator=(Singleton const&) = delete;
        Singleton(Singleton&&) = delete;
        Singleton& operator=(Singleton&&) = delete;

        T getList() const { return this->_list; }
        void addElement(T element) { this->_list.push_back(element); }
        void delElement(T element) { this->_list.remove(element); }

        T operator[](int index) { return this->_list[index]; }
};

template <typename T>
Singleton<T>* Singleton<T>::_instance = nullptr;

template <typename T>
std::vector<T> Singleton<T>::_list = std::vector<T>();