#pragma once

#include <vector>
#include "Singetons.hpp"

class Person;
class Course;
class Form;

class Room
{
private:
	long long ID;
	static long long _counter;
	std::vector<Person*> _occupants;

public:
	Room() : ID(_counter++) {};
	
	long long getID() { return this->ID; };

	bool canEnter(Person*);
	void enter(Person*);
	void exit(Person*);
	
	void printOccupant() {
		std::cout << "Room " << this->ID << " occupants:" << std::endl;
		for (auto it = this->_occupants.begin(); it != this->_occupants.end(); it++)
			std::cout << (*it)->getName() << std::endl;
	};
};

long long Room::_counter = 0;

class Classroom : public Room
{
private:
	Course* _currentRoom;

public:
	Classroom();

	void assignCourse(Course* p_course) {
		this->_currentRoom = p_course;
	};
};

class SecretarialOffice: public Room
{
	private:
		std::vector<Form*> _archivedForms;
	public:
};

class HeadmasterOffice : public Room
{
	private:

	public:
};

class StaffRestRoom : public Room
{
	private:

	public:
};

class Courtyard : public Room
{
	private:

	public:
};

class RoomList : public Singleton<Room*>
{
	friend class Singleton<Room*>;
};