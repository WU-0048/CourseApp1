#include <string>
#include <iostream>
#include <vector>
//#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

#include "Record.h"
#include "Utility.h"
#include "CourseApp1.h"
using namespace std;

// 新增全域變數來儲存學生、老師、課程、選課紀錄的資料
vector<Student> students;
vector<Teacher> teachers;
vector<Course> courses;
vector<Record> records;

// 函數原型宣告
void initializeData();
void displayMenu();
void listStudents();
void listCourses();
void listTeachers();
void listRecords();

int main()
{
	initializeData();
	displayMenu();
}

void initializeData()
{
	//Person person1("A123456789", "Chen", "Jason", "M", "1999-01-01");

	//Person* person2 = new Person();
	//person2->setId("B987654321");
	//person2->setLastName("Wang");
	//person2->setFirstName("David");
	//person2->setGender("M");
	//person2->setBirthDate("1999-12-31");

	//person1.display();
	//cout << endl;
	//person2->display();

	//Student student1("A123456789", "陳", "小明", "男", "1999-01-01", "S001", Department::ComputerSciece, ClassName::_1A);
	//student1.display();

	//cout << endl;
	//Course course1("C001", "C++ Programming", "這門課程教授C++程式語言");
	//Course course2("C002", "Java Programming", "這門課程教授Java程式語言");
	//Course course3("C003", "Python Programming", "這門課程教授Python程式語言");
	//course1.display();
	//course2.display();
	//course3.display();

	//vector<Course> teacher1_courses = { course1, course2, course3 };

	//Teacher teacher1("T123456789", "王", "大富", "男", "1980-7-1", "T001", Department::ComputerSciece, ClassName::_1A, teacher1_courses);

	//cout << "----------------" << endl;
	//teacher1.display();

	// 新增5筆課程資料
	courses.push_back(Course("C001", "C++ Programming", "這門課程教授C++程式語言"));
	courses.push_back(Course("C002", "Java Programming", "這門課程教授Java程式語言"));
	courses.push_back(Course("C003", "Python Programming", "這門課程教授Python程式語言"));
	courses.push_back(Course("C004", "C# Programming", "這門課程教授C#程式語言"));
	courses.push_back(Course("C005", "Visual Basic Programming", "這門課程教授Visual Basic程式語言"));

	// 新增5筆學生資料
	students.push_back(Student("S001", "陳", "小明", "男", "1999-01-01", "S001", Department::ComputerSciece, ClassName::_1A));
	students.push_back(Student("S002", "林", "小華", "男", "1999-02-02", "S002", Department::ElectricalEngineering, ClassName::_1A));
	students.push_back(Student("S003", "黃", "小美", "女", "1999-03-03", "S003", Department::InformationManagement, ClassName::_1B));
	students.push_back(Student("S004", "張", "小強", "男", "1999-04-04", "S004", Department::ComputerSciece, ClassName::_2A));
	students.push_back(Student("S005", "李", "小花", "女", "1999-05-05", "S005", Department::ElectronicEngineering, ClassName::_2B));

	// 新增2筆老師資料
	vector<Course> teacher1_courses = { courses[0], courses[1], courses[2] };
	teachers.push_back(Teacher("T001", "王", "大富", "男", "1980-7-1", "T001", Department::ComputerSciece, ClassName::_1A, teacher1_courses));
	vector<Course> teacher2_courses = { courses[3], courses[4] };
	teachers.push_back(Teacher("T002", "李", "大貴", "男", "1985-5-5", "T002", Department::InformationManagement, ClassName::_1B, teacher2_courses));

	// 新增10筆選課紀錄
	records.push_back(Record("S001", "C001"));
	records.push_back(Record("S001", "C002"));
	records.push_back(Record("S002", "C001"));
	records.push_back(Record("S002", "C003"));
	records.push_back(Record("S003", "C002"));
	records.push_back(Record("S003", "C003"));
	records.push_back(Record("S004", "C003"));
	records.push_back(Record("S004", "C004"));
	records.push_back(Record("S005", "C004"));
	records.push_back(Record("S005", "C005"));
}

void displayMenu() {
	int choice;
	do {
		std::cout << "=========================" << endl;
		std::cout << "1. 列出學生資料" << endl;
		std::cout << "2. 列出課程資料" << endl;
		std::cout << "3. 列出教師資料" << endl;
		std::cout << "4. 列出選課紀錄" << endl;
		std::cout << "5. 查詢學生紀錄" << endl;
		std::cout << "6. 查詢課程紀錄" << endl;
		std::cout << "7. 查詢教師紀錄" << endl;
		std::cout << "8. 查詢選課紀錄" << endl;
		std::cout << "9. 新增學生資料" << endl;
		std::cout << "0. 退出" << endl;
		std::cout << "請選擇操作: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "列出學生資料" << endl;
			listStudents();
			break;
		case 2:
			std::cout << "列出課程資料" << endl;
			listCourses();
			break;
		case 3:
			std::cout << "列出教師資料" << endl;
			listTeachers();
			break;
		case 4:
			std::cout << "列出選課紀錄" << endl;
			listRecords();
			break;
		case 5:
			std::cout << "查詢學生紀錄" << endl;
			break;
		case 6:
			std::cout << "查詢課程紀錄" << endl;
			break;
		case 7:
			std::cout << "查詢教師紀錄" << endl;
			break;
		case 8:
			std::cout << "查詢選課紀錄" << endl;
			break;
		case 9:
			std::cout << "新增學生資料" << endl;
			break;
		case 0:
			std::cout << "退出" << endl;
			break;
		default:
			std::cout << "無效選擇" << endl;
			break;
		}
	} while (choice != 0);
}


void listStudents() {
	std::cout << "學生資料總共有" << students.size() << "筆" << endl;
	std::cout << "----------------" << endl;
	for (auto student : students) {
		student.display();
		std::cout << endl;
	}
	std::cout << endl;
}

void listTeachers() {
	std::cout << "教師資料總共有" << teachers.size() << "筆" << endl;
	std::cout << "----------------" << endl;
	for (auto teacher : teachers) {
		teacher.display();
		std::cout << endl;
	}
	std::cout << endl;
}

void listRecords() {
	std::cout << "選課紀錄總共有" << records.size() << "筆" << endl;
	std::cout << "----------------" << endl;
	for (const auto& record : records) {
		// 找到學生姓名
		string studentName;
		for (const auto& student : students) {
			if (student.getStudentId() == record.getStudentId()) {
				studentName = student.getLastName() + student.getFirstName();
				break;
			}
		}
		std::cout << "學生姓名: " << studentName << ", ";
		const_cast<Record&>(record).display(); // 使用const_cast移除const限定詞
		std::cout << endl;
	}
	std::cout << endl;
}

void listCourses() {
	std::cout << "課程資料總共有" << courses.size() << "筆" << endl;
	std::cout << "----------------" << endl;
	for (const auto& course : courses) {
		course.display();
		std::cout << endl;
	}
	std::cout << endl;
}
void displayMenu() {
	int choice;
	do {
		std::cout << "=========================" << endl;
		std::cout << "1. 列出學生資料" << endl;
		std::cout << "2. 列出課程資料" << endl;
		std::cout << "3. 列出教師資料" << endl;
		std::cout << "4. 列出選課紀錄" << endl;
		std::cout << "5. 查詢學生紀錄" << endl;
		std::cout << "6. 查詢課程紀錄" << endl;
		std::cout << "7. 查詢教師紀錄" << endl;
		std::cout << "8. 查詢選課紀錄" << endl;
		std::cout << "9. 新增學生資料" << endl;
		std::cout << "0. 退出" << endl;
		std::cout << "請選擇操作: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "列出學生資料" << endl;
			listStudents();
			break;
		case 2:
			std::cout << "列出課程資料" << endl;
			listCourses();
			break;
		case 3:
			std::cout << "列出教師資料" << endl;
			listTeachers();
			break;
		case 4:
			std::cout << "列出選課紀錄" << endl;
			listRecords();
			break;
		case 5:
			std::cout << "查詢學生紀錄" << endl;
			queryStudent();
			break;
		case 6:
			std::cout << "查詢課程紀錄" << endl;
			break;
		case 7:
			std::cout << "查詢教師紀錄" << endl;
			break;
		case 8:
			std::cout << "查詢選課紀錄" << endl;
			break;
		case 9:
			std::cout << "新增學生資料" << endl;
			addStudent();
			break;
		case 0:
			std::cout << "退出" << endl;
			break;
		default:
			std::cout << "無效選擇" << endl;
			break;
		}
	} while (choice != 0);
}

void queryStudent()
{
	string studentId;
	std::cout << "請輸入學生編號: ";
	std::cin >> studentId;

	bool found = false;
	for (const auto& student : students) {
		if (student.getStudentId() == studentId) {
			student.display();
			found = true;
			break;
		}
	}
	if (!found)
		std::cout << "找不到學號為" << studentId << "的學生" << endl;
}

void addStudent()
{
	string studentId, lastName, firstName, id, birthDate, gender;
	int departmentChoice, classNameChoice;

	cout << "身分證字號: ";
	cin >> id;
	cout << "姓: ";
	cin >> lastName;
	cout << "名: ";
	cin >> firstName;
	cout << "性別： ";
	cin >> gender;
	cout << "生日: ";
	cin >> birthDate;
	cout << "學號: ";
	cin >> studentId;

	for (int i = 0; i < static_cast<int>(Department::Last); i++) {
		cout << i << ". " << Utility::toString(static_cast<Department>(i)) << endl;
	}
	cout << "請選擇科系: ";
	cin >> departmentChoice;
	Department department = static_cast<Department>(departmentChoice);

	cout << "班級: " << endl;
	for (int i = 0; i < static_cast<int>(ClassName::Last); i++) {
		cout << i << ". " << Utility::toString(static_cast<ClassName>(i)) << endl;
	}
	cout << "請選擇班級: ";
	cin >> classNameChoice;
	ClassName className = static_cast<ClassName>(classNameChoice);

	students.push_back(Student(id, lastName, firstName, gender, birthDate, studentId, department, className));
}

    void addStudent()
    {
        string studentId, lastName, firstName, id, birthDate, gender;
        int departmentChoice, classNameChoice;

		std:: cout << "身分證字號: ";
        cin >> id;
        cout << "姓: ";
        cin >> lastName;
        cout << "名: ";
        cin >> firstName;
        cout << "性別： ";
        cin >> gender;
        cout << "生日: ";
        cin >> birthDate;
        cout << "學號: ";
        cin >> studentId;

        for (int i = 0; i < static_cast<int>(Department::Last); i++) {
            cout << i << ". " << Utility::toString(static_cast<Department>(i)) << endl;
        }
        cout << "請選擇科系: ";
        cin >> departmentChoice;
        Department department = static_cast<Department>(departmentChoice);

        cout << "班級: " << endl;
        for (int i = 0; i < static_cast<int>(ClassName::Last); i++) {
            cout << i << ". " << Utility::toString(static_cast<ClassName>(i)) << endl;
        }
        cout << "請選擇班級: ";
        cin >> classNameChoice;
        ClassName className = static_cast<ClassName>(classNameChoice);

        students.push_back(Student(id, lastName, firstName, gender, birthDate, studentId, department, className));
    }
}
void addStudent()
{
	string studentId, lastName, id, birhDate,gender;
	int departmentChoice, classNameChoice;

	cout << "身分證字號: ";
	cin >> id;
	cout << "姓: ";
	cin >> lastName;
	cout << "名: ";
	cin >> firstName;
	cout << "性別： ";
	cin >> gender;
	cout << "生日: ";
	cin >> birthDate;
	cout << "學號: ";
	cin >> studentId;


	for (int i = 0; i < static_cast<int>(Department::Last); i++) {
		cout << i << ". " << Utility::toString(static_cast<Department>(i)) << endl;
	}
	cout << "請選擇科系: ";
	cin >> departmentChoice;
	Department department = static_cast<Department>(departmentChoice);

	cout << "班級: " << endl;
	for (int i = 0; i < static_cast<int>(ClassName::Last); i++) {
		cout << i << ". " << Utility::toString(static_cast<ClassName>(i)) << endl;
	}
	cout << "請選擇班級: ";
	cin >> classNameChoice;
	ClassName className = static_cast<ClassName>(classNameChoice);

	students.push_back(Student(id, lastName, firstName, gender, birthDate, studentId, department, className));
}
