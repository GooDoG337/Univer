#ifndef STUDENT_H
#define STUDENT_H
#include <QString>
class Student
{
private:
    QString faculty;
    QString name;
public:
    Student();
    Student(QString, QString);
    QString getName() const;
    QString getFaculty() const;
};

#endif // STUDENT_H
