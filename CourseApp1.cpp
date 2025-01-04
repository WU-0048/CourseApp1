#include <string>
#include <iostream>
#include <vector>
#include <fstream>
//#include "Person.h"
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

#include "Record.h"
#include "Utility.h"
#include "CourseApp1.h"

using namespace RecordNamespace;
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
void queryStudent();
void queryCourse();
void queryTeacher();
void queryRecord();
void addStudent();
void addTeacher();
void addCourse();
void addRecord();
void deleteStudent();
void deleteTeacher();
void deleteCourse();
void insertStudent();
void insertTeacher();
void insertCourse();
void saveRecordsToFile(const string& filename);

int main()
{
	initializeData();
	displayMenu();
}

void initializeData()
{
	// 新增5筆課程資料
	courses.push_back(Course("C001", "C++ Programming", "這門課程教授C++程式語言"));
	courses.push_back(Course("C002", "Java Programming", "這門課程教授Java程式語言"));
	courses.push_back(Course("C003", "Python Programming", "這門課程教授Python程式語言"));
	courses.push_back(Course("C004", "C# Programming", "這門課程教授C#程式語言"));
	courses.push_back(Course("C005", "Visual Basic Programming", "這門課程教授Visual Basic程式語言"));

	// 新增5筆學生資料
	students.push_back(Student("I001", "陳", "小明", "男", "1999-01-01", "S001", Department::ComputerScience, ClassName::_1A));
	students.push_back(Student("I002", "林", "小華", "男", "1999-02-02", "S002", Department::ElectricalEngineering, ClassName::_1A));
	students.push_back(Student("I003", "黃", "小美", "女", "1999-03-03", "S003", Department::InformationManagement, ClassName::_1B));
	students.push_back(Student("I004", "張", "小強", "男", "1999-04-04", "S004", Department::ComputerScience, ClassName::_2A));
	students.push_back(Student("I005", "李", "小花", "女", "1999-05-05", "S005", Department::ElectronicEngineering, ClassName::_2B));

	// 新增2筆老師資料
	vector<Course> teacher1_courses = { courses[0], courses[1], courses[2] };
	teachers.push_back(Teacher("T001", "王", "大富", "男", "1980-7-1", "T001", Department::ComputerScience, ClassName::_1A, teacher1_courses));
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
		std::cout << "10. 新增教師資料" << endl;
		std::cout << "11. 新增課程資料" << endl;
		std::cout << "12. 新增選課紀錄" << endl;
		std::cout << "13. 刪除學生資料" << endl;
		std::cout << "14. 刪除教師資料" << endl;
		std::cout << "15. 刪除課程資料" << endl;
		std::cout << "16. 插入學生資料" << endl;
		std::cout << "17. 插入教師資料" << endl;
		std::cout << "18. 插入課程資料" << endl;
		std::cout << "19. 儲存課程紀錄" << endl;
		std::cout << "0. 退出" << endl;
		std::cout << "請選擇操作: ";
		std::cin >> choice;

		switch (choice) {
		case 1:
			std::cout << "列出學生資料" << endl;
			listStudents();
			system("pause");
			break;
		case 2:
			std::cout << "列出課程資料" << endl;
			listCourses();
			system("pause");
			break;
		case 3:
			std::cout << "列出教師資料" << endl;
			listTeachers();
			system("pause");
			break;
		case 4:
			std::cout << "列出選課紀錄" << endl;
			listRecords();
			system("pause");
			break;
		case 5:
			std::cout << "查詢學生紀錄" << endl;
			queryStudent();
			system("pause");
			break;
		case 6:
			std::cout << "查詢課程紀錄" << endl;
			queryCourse();
			system("pause");
			break;
		case 7:
			std::cout << "查詢教師紀錄" << endl;
			queryTeacher();
			system("pause");
			break;
		case 8:
			std::cout << "查詢選課紀錄" << endl;
			queryRecord();
			system("pause");
			break;
		case 9:
			std::cout << "新增學生資料" << endl;
			addStudent();
			system("pause");
			break;
		case 10:
			std::cout << "新增教師資料" << endl;
			addTeacher();
			system("pause");
			break;
		case 11:
			std::cout << "新增課程資料" << endl;
			addCourse();
			system("pause");
			break;
		case 12:
			std::cout << "新增選課紀錄" << endl;
			addRecord();
			system("pause");
			break;
		case 13:
			std::cout << "刪除學生資料" << endl;
			deleteStudent();
			system("pause");
			break;
		case 14:
			std::cout << "刪除教師資料" << endl;
			deleteTeacher();
			system("pause");
			break;
		case 15:
			std::cout << "刪除課程資料" << endl;
			deleteCourse();
			system("pause");
			break;
		case 16:
			std::cout << "插入學生資料" << endl;
			insertStudent();
			system("pause");
			break;
		case 17:
			std::cout << "插入教師資料" << endl;
			insertTeacher();
			system("pause");
			break;
		case 18:
			std::cout << "插入課程資料" << endl;
			insertCourse();
			system("pause");
			break;
		case 19:
			std::cout << "儲存課程紀錄" << endl;
			saveRecordsToFile("records.txt");
			system("pause");
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
	std::cout << "按任意鍵繼續..." << endl;
	cin.ignore();
	cin.get();
}

void queryCourse()
{
	string courseId;
	std::cout << "請輸入課程編號: ";
	std::cin >> courseId;

	bool found = false;
	for (const auto& course : courses) {
		if (course.getCourseId() == courseId) {
			course.display();
			found = true;
			break;
		}
	}
	if (!found)
		std::cout << "找不到課程編號為" << courseId << "的課程" << endl;
	std::cout << "按任意鍵繼續..." << endl;
	cin.ignore();
	cin.get();
}

void queryTeacher()
{
	string teacherId;
	std::cout << "請輸入教師編號: ";
	std::cin >> teacherId;

	bool found = false;
	for (const auto& teacher : teachers) {
		if (teacher.getTeacherId() == teacherId) {
			teacher.display();
			found = true;
			break;
		}
	}
	if (!found)
		std::cout << "找不到教師編號為" << teacherId << "的教師" << endl;
	std::cout << "按任意鍵繼續..." << endl;
	cin.ignore();
	cin.get();
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

void queryRecord()
{
	string studentId, courseId;
	std::cout << "請輸入學生編號: ";
	std::cin >> studentId;
	std::cout << "請輸入課程編號: ";
	std::cin >> courseId;

	bool found = false;
	for (const auto& record : records) {
		if (record.getStudentId() == studentId && record.getCourseId() == courseId) {
			// 顯示選課紀錄
			record.display();

			// 找到學生姓名
			string studentName;
			for (const auto& student : students) {
				if (student.getStudentId() == studentId) {
					studentName = student.getLastName() + student.getFirstName();
					break;
				}
			}

			// 找到課程資訊
			for (const auto& course : courses) {
				if (course.getCourseId() == courseId) {
					std::cout << "學生姓名: " << studentName << endl;
					course.display();
					break;
				}
			}

			found = true;
			break;
		}
	}
	if (!found)
		std::cout << "找不到學生編號為" << studentId << "且課程編號為" << courseId << "的選課紀錄" << endl;
	std::cout << "按任意鍵繼續..." << endl;
	cin.ignore();
	cin.get();
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

void addTeacher()
{
	string teacherId, lastName, firstName, id, birthDate, gender;
	int departmentChoice, classNameChoice;
	vector<Course> courses;

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
	cout << "教師編號: ";
	cin >> teacherId;

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

	teachers.push_back(Teacher(id, lastName, firstName, gender, birthDate, teacherId, department, className, courses));
}

void addCourse()
{
	string courseId, courseName, courseDescription;
	cout << "課程代碼: ";
	cin >> courseId;
	cout << "課程名稱: ";
	cin >> courseName;
	cout << "課程描述: ";
	cin >> courseDescription;
	courses.push_back(Course(courseId, courseName, courseDescription));
}

void addRecord()
{
	string studentId, courseId;
	cout << "學生編號: ";
	cin >> studentId;
	cout << "課程編號: ";
	cin >> courseId;
	records.push_back(Record(studentId, courseId));
}

void deleteStudent()
{
    string studentId;
    std::cout << "請輸入要刪除的學生編號: ";
    std::cin >> studentId;

    auto it = std::remove_if(students.begin(), students.end(), [&](const Student& student) {
        return student.getStudentId() == studentId;
    });

    if (it != students.end()) {
        students.erase(it, students.end());
        std::cout << "學生資料已刪除" << endl;
    }
    else {
        std::cout << "找不到學號為" << studentId << "的學生" << endl;
    }
}

void deleteTeacher()
{
	string teacherId;
	std::cout << "請輸入要刪除的教師編號: ";
	std::cin >> teacherId;

	auto it = std::remove_if(teachers.begin(), teachers.end(), [&](const Teacher& teacher) {
		return teacher.getTeacherId() == teacherId;
		});

	if (it != teachers.end()) {
		teachers.erase(it, teachers.end());
		std::cout << "教師資料已刪除" << endl;
	}
	else {
		std::cout << "找不到教師編號為" << teacherId << "的教師" << endl;
	}
}

void deleteCourse()
{
	string courseId;
	std::cout << "請輸入要刪除的課程編號: ";
	std::cin >> courseId;

	auto it = std::remove_if(courses.begin(), courses.end(), [&](const Course& course) {
		return course.getCourseId() == courseId;
		});

	if (it != courses.end()) {
		courses.erase(it, courses.end());
		std::cout << "課程資料已刪除" << endl;
	}
	else {
		std::cout << "找不到課程編號為" << courseId << "的課程" << endl;
	}
}
void insertStudent()
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

	auto it = students.begin();
	students.insert(it, Student(id, lastName, firstName, gender, birthDate, studentId, department, className));
}

void insertTeacher()
{
	string teacherId, lastName, firstName, id, birthDate, gender;
	int departmentChoice, classNameChoice, position;
	vector<Course> courses;

	cout << "插入位置 (0-" << teachers.size() << "): ";
	cin >> position;
	if (position < 0 || position > teachers.size()) {
		cout << "無效位置" << endl;
		return;
	}

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
	cout << "教師編號: ";
	cin >> teacherId;

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

	auto it = teachers.begin();
	teachers.insert(it + position, Teacher(id, lastName, firstName, gender, birthDate, teacherId, department, className, courses));
}

void insertCourse()
{
	string courseId, courseName, courseDescription;
	int position;
	cout << "插入位置 (0-" << courses.size() << "): ";
	cin >> position;
	if (position < 0 || position > courses.size()) {
		cout << "無效位置" << endl;
		return;
	}
	cout << "課程代碼: ";
	cin >> courseId;
	cout << "課程名稱: ";
	cin >> courseName;
	cout << "課程描述: ";
	cin >> courseDescription;
	auto it = courses.begin();
	courses.insert(it + position, Course(courseId, courseName, courseDescription));
}


void saveRecordsToFile(const string& filename) {
	ofstream outFile(filename);
	if (!outFile) {
		cerr << "無法打開文件: " << filename << endl;
		return;
	}

	for (const auto& record : records) {
		// 查找學生
		auto studentIt = find_if(students.begin(), students.end(), [&record](const Student& student) {
			return student.getStudentId() == record.getStudentId();
			});

		// 查找課程
		auto courseIt = find_if(courses.begin(), courses.end(), [&record](const Course& course) {
			return course.getCourseId() == record.getCourseId();
			});

		if (studentIt != students.end() && courseIt != courses.end()) {
			outFile << "選課紀錄編號: " << record.getRecordId() << endl;
			outFile << "選課日期: " << record.getRecordDate() << endl;
			outFile << "學生資料:" << endl;
			outFile << "----------------" << endl;
			outFile << "學號: " << studentIt->getStudentId() << endl;
			outFile << "姓名: " << studentIt->getLastName() << studentIt->getFirstName() << endl;
			outFile << "性別: " << studentIt->getGender() << endl;
			outFile << "生日: " << studentIt->getBirthDate() << endl;
			outFile << "科系: " << Utility::toString(studentIt->getDepartment()) << endl;
			outFile << "班級: " << Utility::toString(studentIt->getClassName()) << endl;
			outFile << "----------------" << endl;
			outFile << "課程資料:" << endl;
			outFile << "----------------" << endl;
			outFile << "課程編號: " << courseIt->getCourseId() << endl;
			outFile << "課程名稱: " << courseIt->getCourseName() << endl;
			outFile << "課程描述: " << courseIt->getCourseDescription() << endl;
			outFile << "===================" << endl;
			outFile << endl;
		}
	}

	outFile.close();
	cout << "選課紀錄已保存到文件: " << filename << endl;
}


