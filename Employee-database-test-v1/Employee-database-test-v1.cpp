#include <iostream>
#include <iomanip>
#include <fstream>

int main ()
{
    std::fstream DatabaseFile;
    std::string EmployeeID, EmployeeName, EmployeeAddress, EmployeePhone, EmployeeDepartment;
    std::string EmployeePosition, EmployeeHiredDate, EmployeeRatePerDay, EmployeeRatePerHour, EmployeeOvertimeRate;
    const int ColumnPaddingSize = 17;

    DatabaseFile.open ("EmployeeDatabase.txt", std::fstream::in);

    if (!DatabaseFile.is_open())
    {
        std::cout << "Could not open the employee database\n";
        system("pause");
        return 0;
    }

    getline(DatabaseFile, EmployeeID, '|');
    getline(DatabaseFile, EmployeeName, '|');
    getline(DatabaseFile, EmployeeAddress, '|');
    getline(DatabaseFile, EmployeePhone, '|');
    getline(DatabaseFile, EmployeeDepartment, '|');
    getline(DatabaseFile, EmployeePosition, '|');
    getline(DatabaseFile, EmployeeHiredDate, '|');
    getline(DatabaseFile, EmployeeRatePerDay, '|');
    getline(DatabaseFile, EmployeeRatePerHour, '|');
    getline(DatabaseFile, EmployeeOvertimeRate, '|');

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Employee ID: ";
    std::cout << EmployeeID << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Name: ";
    std::cout << EmployeeName << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Address: ";
    std::cout << EmployeeAddress << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Contact Number: ";
    std::cout << EmployeePhone << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Department: ";
    std::cout << EmployeeDepartment << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Position: ";
    std::cout << EmployeePosition << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Date Started: ";
    std::cout << EmployeeHiredDate << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Rate Per Day: ";
    std::cout << EmployeeRatePerDay << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Rate Per Hour: ";
    std::cout << EmployeeRatePerHour << "\n";

    std::cout << std::setw(ColumnPaddingSize) << std::setfill (' ') << std::left << "Overtime Rate: ";
    std::cout << EmployeeOvertimeRate << "\n";


    DatabaseFile.close();
}
