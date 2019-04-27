#include <iostream>
#include <stack>

int main()
{
    struct Student
    {
        std::string Name;
        unsigned int Age;
        float gpa;
    } CurrentStudent;

    std::stack <Student> Students;

    if (Students.size() > 0) std::cout << "Student's Name: " << Students.top().Name << ", Student's Age: " << Students.top().Age << ", Student's GPA: " << Students.top().gpa << "\n";

    CurrentStudent.Name = "Mo";
    CurrentStudent.Age = 18;
    CurrentStudent.gpa = 4.0;
    Students.push(CurrentStudent);

    if (Students.size() > 0) std::cout << "Student's Name: " << Students.top().Name << ", Student's Age: " << Students.top().Age << ", Student's GPA: " << Students.top().gpa << "\n";

    CurrentStudent.Name = "Larry";
    CurrentStudent.Age = 17;
    CurrentStudent.gpa = 3.6;
    Students.push(CurrentStudent);

    if (Students.size() > 0) std::cout << "Student's Name: " << Students.top().Name << ", Student's Age: " << Students.top().Age << ", Student's GPA: " << Students.top().gpa << "\n";

    CurrentStudent.Name = "Curly";
    CurrentStudent.Age = 18;
    CurrentStudent.gpa = 3.4;
    Students.push(CurrentStudent);

    if (Students.size() > 0) std::cout << "Student's Name: " << Students.top().Name << ", Student's Age: " << Students.top().Age << ", Student's GPA: " << Students.top().gpa << "\n";

    Students.pop();

    if (Students.size() > 0) std::cout << "Student's Name: " << Students.top().Name << ", Student's Age: " << Students.top().Age << ", Student's GPA: " << Students.top().gpa << "\n";

    Students.pop();

    if (Students.size() > 0) std::cout << "Student's Name: " << Students.top().Name << ", Student's Age: " << Students.top().Age << ", Student's GPA: " << Students.top().gpa << "\n";

    Students.pop();

    if (Students.size() > 0) std::cout << "Student's Name: " << Students.top().Name << ", Student's Age: " << Students.top().Age << ", Student's GPA: " << Students.top().gpa << "\n";

    return 0;
}

