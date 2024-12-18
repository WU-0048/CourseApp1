#pragma once
#include "Person.h"
#include "Utility.h"
#include "Course.h"
#include <string>
#include <vector>
using namespace std;

class Teacher : public Person
{
private:
	string teacherId;
	Department department;
	ClassName className;
	vector<Course> teachingCourses;

public:
	Teacher(const string& id, const string& lastName, const string& firstName, const string& gender, const string birthDate, const string& teacherId, Department department, ClassName className, const vector<Course>& courses);

	// getter
	string getTeacherId() const;
	Department getDepartment() const;
	ClassName getClassName() const;
	vector<Course> getCourses() const;

	// setter
	void setTeacherId(const string& teacherId);
	void setDepartment(Department department);
	void setClassName(ClassName className);
	void setCourses(const vector<Course>& courses);

	void display() const;
};
