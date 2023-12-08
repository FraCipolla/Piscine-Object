#pragma once

#include "Singetons.hpp"
class Professor;
class Student;

enum class FormType
{
	CourseFinished,
	NeedMoreClassRoom,
	NeedCourseCreation,
	SubscriptionToCourse,
};

class Course
{
private:
	std::string _name;
	Professor* _responsable;
	std::vector<Student*> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
public:
	Course(std::string p_name) : _name(p_name), _maximumNumberOfStudent(-1), _numberOfClassToGraduate(0) {};
	Course(std::string p_name, int max) : _name(p_name), _maximumNumberOfStudent(max), _numberOfClassToGraduate(0) {}
	
	virtual ~Course() {};

	void assign(Professor* p_professor) {
		this->_responsable = p_professor;
	};
	void subscribe(Student* p_student) {
		if (this->_students.size() < (size_t)this->_maximumNumberOfStudent || this->_maximumNumberOfStudent < 0)
			this->_students.push_back(p_student);
		else
			std::cout << "Maximum number of students reached!" << std::endl;
	};
};

class Form
{
private:
	FormType _formType;
public:
	Form(FormType p_formType) : _formType(p_formType) {}

	virtual void execute() = 0;
};

class CourseFinishedForm : public Form
{
	private:

	public:
		void execute();
};

class NeedMoreClassRoomForm : public Form
{
	private:

	public:
		void execute();
};

class NeedCourseCreationForm : public Form
{
	private:

	public:
		void execute();
};

class SubscriptionToCourseForm : public Form
{
	private:

	public:
		void execute();
};

class CourseList : public Singleton<Course*>
{
	friend class Singleton<Course*>;
};