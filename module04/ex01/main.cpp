#include "Form.hpp"
#include "Person.hpp"
#include "Room.hpp"
#include "Staff.hpp"

int main()
{
    StudentList::getInstance()->addElement(new Student("Bob"));
    std::cout << StudentList::getInstance()->operator[](0)->getName() << std::endl;
    StudentList::getInstance()->addElement(new Student("Alice"));
    std::cout << StudentList::getInstance()->operator[](1)->getName() << std::endl;
    StudentList::getInstance()->addElement(new Student("John"));
    std::cout << StudentList::getInstance()->operator[](2)->getName() << std::endl;
    StudentList::getInstance()->addElement(new Student("Jane"));
    std::cout << StudentList::getInstance()->operator[](3)->getName() << std::endl;

    StaffList::getInstance()->addElement(new Staff("Staff1"));
    std::cout << StaffList::getInstance()->operator[](0)->getName() << std::endl;
    StaffList::getInstance()->addElement(new Staff("Staff2"));
    std::cout << StaffList::getInstance()->operator[](1)->getName() << std::endl;
    StaffList::getInstance()->addElement(new Staff("Staff3"));
    std::cout << StaffList::getInstance()->operator[](2)->getName() << std::endl;
    StaffList::getInstance()->addElement(new Staff("Staff4"));
    std::cout << StaffList::getInstance()->operator[](3)->getName() << std::endl;
}