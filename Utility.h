// Utility.h
#pragma once
#include <string>

enum class Department {
    ComputerScience,
    ElectricalEngineering,
    InformationManagement,
    ElectronicEngineering,
    Last // �T�O���o�ӪT�|��
};

enum class ClassName {
    _1A,
    _1B,
    _2A,
    _2B,
	_3A,
    _3B,
    _4A,
    _4B,
    Last // Add this member to fix the error E0135
};

class Utility {
public:
    static std::string toString(Department department);
    static std::string toString(ClassName className);
};


