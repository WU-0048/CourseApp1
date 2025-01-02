namespace RecordNamespace {
    class Record {
        static int nextId;
        int recordId;
        std::string studentId;
        std::string courseId;
        time_t recordDate;
    public:
        Record(const std::string& studentId, const std::string& courseId);
        int getRecordId() const;
        std::string getStudentId() const;
        std::string getCourseId() const;
        std::string getRecordDate() const;
        void display() const;
        void save(std::ofstream& out) const;
    };
}
