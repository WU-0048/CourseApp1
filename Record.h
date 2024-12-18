// Record.h
#pragma once
#include <string>
#include <ctime>
using namespace std;

class Record
{
private:
    static int nextId;
    int recordId;
    string studentId;
    string courseId;
    time_t recordDate;
public:
    Record(const string& studentId, const string& courseId);

    int getRecordId() const;
    string getStudentId() const;
    string getCourseId() const;
    string getRecordDate() const;

    void display() const;
};

