#pragma once

#include <vector>
#include "Person.hpp"
#include "Form.hpp"
#include "Singetons.hpp"

class Staff : public Person
{
	private:

	public:
		Staff(std::string p_name) : Person(p_name) {}
		void sign(Form* p_form);
};

class Headmaster : public Staff
{
	private:
		std::vector<Form*> _formToValidate;
	public:
		void receiveForm(Form* p_form);
};

class Secretary : public Staff
{
	private:

	public:
		Form* createForm(FormType p_formType) {};
		void archiveForm() {};
};

class Professor : public Staff
{
	private:
		Course* _currentCourse;

	public:
		void assignCourse(Course* p_course) {
			this->_currentCourse = p_course;
		};
		void doClass() {
			
		};
		void closeCourse() {
			this->_currentCourse = NULL;
		};
};

class StaffList : public Singleton<Staff*>
{
	friend class Singleton<Staff*>;
};