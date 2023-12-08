#pragma once

#include <vector>
#include <string>
#include "Singetons.hpp"

class Room;
class Form;
class Course;
class Classroom;

class Person
{
private:
	std::string _name;
	Room* _currentRoom;
public:
	Person(std::string p_name) : _name(p_name) {};
	~Person() {};
	Room* room() {return (_currentRoom);}

	std::string getName() {return (_name);}

};

class Student : public Person
{
private:
	std::vector<Course*> _subscribedCourse;

public:
	Student(std::string p_name) : Person(p_name) {};
	void attendClass(Classroom* p_classroom);
	void exitClass();
	void graduate(Course* p_course);
};

class StudentList : public Singleton<Student*>
{
	friend class Singleton<Student*>;
};